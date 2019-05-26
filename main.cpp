#include <iostream>
#include "gtest/gtest.h"
#include "solucion.h"
#include "auxiliares.h"
#include "ejemplos.h"

int main(int argc, char **argv) {
    std::cout << "Implementando TPI!!" << std::endl;
    testing::InitGoogleTest(&argc, argv);


    escribirRecorridos({RECORRIDO1, RECORRIDO2, RECORRIDO3}, "recorridos.csv");
    cout << "Recorridos grabados en ./transporteUrbano/recorridos.csv" << endl;

    // Descomentar cuando implementen la grilla
    //    grilla g = construirGrilla( CORDOBA_ESQ1, CORDOBA_ESQ2, 18, 25);
    //    escribirGrilla(g, "grilla.csv");
    //    cout << "Grilla grabada en ./transporteUrbano/grilla.csv" << endl;

    RUN_ALL_TESTS();

    return 0;
}