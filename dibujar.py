#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Ideas sacadas de https://www.jpytr.com/post/analysinggeographicdatawithfolium/
# Si quieren debugear pueden agregar la siguiente línea:
# import ipdb; ipdb.set_trace()
# en cualquier punto del código

import click

import pandas as pd
import matplotlib.pyplot as plt
import matplotlib as mpl
import folium

colors = [
    'red',
    'blue',
    'gray',
    'darkred',
    'lightred',
    'orange',
    'beige',
    'green',
    'darkgreen',
    'lightgreen',
    'darkblue',
    'lightblue',
    'purple',
    'darkpurple',
    'pink',
    'cadetblue',
    'lightgray',
    'black'
]


@click.command()
@click.option("--grilla", "-g", "grilla_fn", type=click.Path(exists=True), default="./transporteUrbano/grilla.csv")
@click.option("--recorridos", "-r", "recorridos_fn", type=click.Path(exists=True), default="./transporteUrbano/recorridos.csv")
@click.option("--mapa_output_fname", default="./mapa.html")
def main(grilla_fn, recorridos_fn, mapa_output_fname):
    """
    script escrito en python(3) para dibujar un mapa, una grilla y recorridos sobre esta

    Para ejecutarlo, escribir en la terminal:
    python dibujar.py

    Opcionalmente pueden pasar el output que hayan recibido de c++, por ejemplo:
    python dibujar.py --recorridos transporteUrbano/recorridos.csv --grilla transporteUrbano/grilla.csv

    La salida es un archivo HTML (mapa.html)
    """

    mapa = dibujar_mapa()

    if grilla_fn:
        grilla = pd.read_csv(grilla_fn, sep="\t", names=["lower_left_lat", "lower_left_lng", "upper_right_lat", "upper_right_lng", "name"], index_col=None)
        mapa = dibujar_grilla(mapa, grilla)

    if recorridos_fn:
        recorridos = pd.read_csv(recorridos_fn, sep="\t", names=["recorrido_id", "lat", "lng"], index_col=None)
        for i, rec in enumerate(recorridos.groupby("recorrido_id").apply(lambda r: list(zip(r.lat, r.lng)))):
            mapa = dibujar_recorrido(mapa, rec, color=colors[i])

    mapa.save(mapa_output_fname)
    print("Mapa guardado en: {}".format(mapa_output_fname))


def dibujar_mapa():
    mapa = folium.Map(location=(-31.30, -64.12),
                      zoom_start=11)
    return mapa


def dibujar_grilla(mapa, grilla):
    for i, celda in grilla.iterrows():
        upper_left = (celda["lower_left_lng"], celda["upper_right_lat"])
        upper_right = (celda["upper_right_lng"], celda["upper_right_lat"])
        lower_right = (celda["upper_right_lng"], celda["lower_left_lat"])
        lower_left = (celda["lower_left_lng"], celda["lower_left_lat"])

        coordinates = [
            upper_left,
            upper_right,
            lower_right,
            lower_left,
            upper_left
        ]
        geo_json = {"type": "FeatureCollection",
                    "properties": {
                        "name": celda["name"],
                    },
                    "features": [{
                        "type": "Feature",
                        "geometry": {
                            "type": "Polygon",
                            "coordinates": [coordinates],
                        }
                    }]
                   }

        color = plt.cm.Reds(i / len(grilla))
        color = mpl.colors.to_hex(color)

        gj = folium.GeoJson(geo_json,
                            style_function=lambda feature, color=color: {'fillColor': color,
                                                                         'color': "black",
                                                                         'weight': 2,
                                                                         'fillOpacity': 0.15,
                                                                         'dashArray': '5, 5',
                                                                         })
        popup = folium.Popup(geo_json["properties"]["name"])
        gj.add_child(popup)

        mapa.add_child(gj)

    return mapa


def dibujar_recorrido(mapa, recorrido, color="blue"):
    folium.PolyLine(recorrido, color=color, weight=2.5, opacity=1).add_to(mapa)
    for lat, lng in recorrido:
        folium.Marker(location=[lat, lng], icon=folium.Icon(color=color)).add_to(mapa)
    return mapa


main()
