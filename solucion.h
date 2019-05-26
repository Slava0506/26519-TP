#ifndef TRANSPORTEURBANO_SOLUCION_H
#define TRANSPORTEURBANO_SOLUCION_H
#include "definiciones.h"
bool excesoDeVelocidad(viaje v);
tiempo tiempoTotal(viaje v);
distancia distanciaTotal(viaje v);
int flota(vector<viaje> v, tiempo t0, tiempo tf);
vector<gps> recorridoNoCubierto(viaje v, recorrido r, distancia u);
grilla construirGrilla(gps esq1, gps esq2, int n, int m);
vector<nombre> aPalabra(recorrido t, grilla g);
int cantidadDeSaltos(grilla g, viaje v);

//ENTRADA SALIDA
void escribirGrilla(grilla g, string nombreArchivo);
void escribirRecorridos(vector<recorrido> recorridos, string nombreArchivo);

// NO ES NECESARIO IMPLEMENTAR:
void completarHuecos(viaje& v, vector<int> faltantes);




#endif //TRANSPORTEURBANO_SOLUCION_H
