#include "../solucion.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

template<typename T>
bool included(T elem, vector<T> container){
    for (int i = 0; i < container.size(); ++i) {
        if (container[i] == elem){return true;}
    }
    return false;
}

template<typename T>
void ASSERT_ELEMENTS(vector<T> container, vector<T> elems) {
    for(int i = 0; i < elems.size(); i++ ) {
        ASSERT_TRUE(included(elems[i], container));
    }

}

using namespace std;

const gps P = puntoGps(-31.465027, -64.212973);
const recorrido R = {P,
                     desviarPunto(P, 1000, 0),
                     desviarPunto(P, 2000, 0),
                     desviarPunto(P, 3000, 0),
                     desviarPunto(P, 4000, 0),
                     desviarPunto(P, 5000, 0),
                     desviarPunto(P, 6000, 0),
                     desviarPunto(P, 7000, 0),
                     desviarPunto(P, 8000, 0),
                     desviarPunto(P, 9000, 0),
                      };

const recorrido RRulos = {P,
                     desviarPunto(P, 1000, 0),
                     desviarPunto(P, 2000, 0),
                     desviarPunto(P, 3000, 0),
                     desviarPunto(P, 4000, 0),
                     desviarPunto(P, 5000, 0),
                     desviarPunto(P, 5000, 100),
                     desviarPunto(P, 4000, 100),
                     desviarPunto(P, 3000, 100),
                     desviarPunto(P, 2000, 100),
                     desviarPunto(P, 1000, 100),
                     desviarPunto(P, 0, 0)
};



TEST(recorridoNoCubiertoTEST, viajePerfecto){
    viaje v = {};
    for(int i = 0; i < R.size(); i++){
        v.push_back(medicion(i, R[i]));
    }

    EXPECT_EQ(recorridoNoCubierto(v, R, 10).size(), 0);
}

TEST(recorridoNoCubiertoTEST, viajeConImperfeccionesMenoresAlUmbral){
    viaje v = {};
    vector<int> desvios(R.size(), 0);
    desvios[1] = 90;
    desvios[5] = 30;
    desvios[7] = -90;

    for(int i = 0; i < R.size(); i++){
        v.push_back(medicion(i, desviarPunto(R[i], 0, desvios[i])));
    }

    EXPECT_EQ(recorridoNoCubierto(v, R, 100).size(), 0);
}

TEST(recorridoNoCubiertoTEST, viajeConImperfeccionesMayoresAlUmbral){
    viaje v = {};
    vector<int> desvios(R.size(), 0);
    desvios[0] = 390;
    desvios[1] = 30;
    desvios[2] = -190;
    desvios[3] = -390;

    for(int i = 0; i < R.size(); i++){
        v.push_back(medicion(i, desviarPunto(R[i], 0, desvios[i])));
    }

    vector<gps> res = recorridoNoCubierto(v, R, 100);
    EXPECT_EQ(res.size(), 3);
    ASSERT_ELEMENTS(res, {R[3], R[0], R[2]});

}


TEST(recorridoNoCubiertoTEST, recorridoVacio){
    viaje v = {};
    vector<int> desvios(R.size(), 0);
    desvios[1] = 190;
    desvios[5] = 30;
    desvios[7] = -190;

    for(int i = 0; i < R.size(); i++){
        v.push_back(medicion(i+1, desviarPunto(R[i], 0, desvios[i])));
    }

    v.push_back(medicion(0, desviarPunto(R[0], 300, 500)));
    v.push_back(medicion(R.size(), desviarPunto(R[R.size()-1], 200, 230)));

    vector<gps> res = recorridoNoCubierto(v, {}, 100);
    EXPECT_EQ(res.size(), 0);
}

TEST(recorridoNoCubiertoTEST, viajeMasLargo){
    viaje v = {};
    vector<int> desvios(R.size(), 0);
    desvios[1] = 190;
    desvios[5] = 30;
    desvios[7] = -190;

    for(int i = 0; i < R.size(); i++){
        v.push_back(medicion(i+1, desviarPunto(R[i], 0, desvios[i])));
    }

    v.push_back(medicion(0, desviarPunto(R[0], 300, 500)));
    v.push_back(medicion(R.size(), desviarPunto(R[R.size()-1], 200, 230)));

    vector<gps> res = recorridoNoCubierto(v, R, 100);
    EXPECT_EQ(res.size(), 2);
    ASSERT_ELEMENTS(res, {R[7], R[1]});

}

TEST(recorridoNoCubiertoTEST, viajeMasCorto){
    viaje v = {};
    vector<int> desvios(R.size(), 0);
    desvios[5] = 30;
    desvios[7] = -190;

    for(int i = 1; i < R.size() - 1; i++){
        v.push_back(medicion(i, desviarPunto(R[i], 0, desvios[i])));
    }

    vector<gps> res = recorridoNoCubierto(v, R, 100);
    EXPECT_EQ(res.size(), 3);

    ASSERT_ELEMENTS(res, {R[0], R[7], R[R.size()-1]});

}

TEST(recorridoNoCubiertoTEST, viajeTramposo){
    viaje v = {};

    for(int i = 0; i < RRulos.size() /2; i++){
        v.push_back(medicion(i, desviarPunto(RRulos[i], 0, 50)));
    }

    vector<gps> res = recorridoNoCubierto(v, RRulos, 100);
    EXPECT_EQ(res.size(), 0);

}
