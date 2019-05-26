#include "../solucion.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;


TEST(distanciaAuxTEST, distanciaUnoMismoEsCero){
    gps p1 = puntoGps(-33, -34);
    gps p2 = p1;

    EXPECT_NEAR(distMts(p1, p2), 0.0, 0.001);
}

TEST(distanciaAuxTEST, distanciaMoviendoEnLat){
    gps p1 = puntoGps(-33, -34);
    gps p2 = desviarPunto(p1, 100, 0);

    EXPECT_NEAR(distMts(p1, p2), 100.0, 0.01);
}

TEST(distanciaAuxTEST, distanciaMoviendoEnLng){
    gps p1 = puntoGps(-33, -34);
    gps p2 = desviarPunto(p1, 0, 100);

    EXPECT_NEAR(distMts(p1, p2), 100.0, 0.01);
}

TEST(distanciaAuxTEST, distanciaMoviendoEnLatYLng){
    gps p1 = puntoGps(-33, -34);
    gps p2 = desviarPunto(p1, 3., 4.);

    EXPECT_NEAR(distMts(p1, p2), 5.0, 0.01);
}