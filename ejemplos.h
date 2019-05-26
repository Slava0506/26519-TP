#include "auxiliares.h"
// Constants.h
#if !defined(MYLIB_CONSTANTS_H)
#define MYLIB_CONSTANTS_H 1

const gps P = puntoGps(-31.465027, -64.212973);
const gps CORDOBA_ESQ1 = puntoGps(-31.498085,-64.310360);
const gps CORDOBA_ESQ2 = puntoGps(get<0>(CORDOBA_ESQ1) + 0.18, get<1>(CORDOBA_ESQ1) + 0.25);

const recorrido RECORRIDO1 = {P,
                     desviarPunto(P, 1000, 0),
                     desviarPunto(P, 2000, 100),
                     desviarPunto(P, 3000, 0),
                     desviarPunto(P, 4000, 300),
                     desviarPunto(P, 5000, 0),
                     desviarPunto(P, 6000, 500),
                     desviarPunto(P, 7000, 0),
                     desviarPunto(P, 8000, 600),
                     desviarPunto(P, 9000, 0),
                     desviarPunto(P, 9000, 2000),
                     desviarPunto(P, 9000, 3000),
                     desviarPunto(P, 9000, 4000),
                     desviarPunto(P, 9000, 5000),
};

const recorrido RECORRIDO2 = {P,
                    desviarPunto(P, 0 ,1000),
                    desviarPunto(P, 0 ,2000),
                    desviarPunto(P, 0 ,3000),
                    desviarPunto(P, 0 ,4000),
                    desviarPunto(P, 0 ,5000),
                    desviarPunto(P, 100, 5000),
                    desviarPunto(P, 200, 4000),
                    desviarPunto(P, 300, 3000),
                    desviarPunto(P, 200, 2000),
                    desviarPunto(P, 100, 1000),
                    desviarPunto(P, 0, 0)
};

const recorrido RECORRIDO3 = {P,
                              desviarPunto(P, 1000 ,1000),
                              desviarPunto(P, 1000 ,2000),
                              desviarPunto(P, 1000 ,3000),
                              desviarPunto(P, 1000 ,4000),
                              desviarPunto(P, 1000 ,5000),
                              desviarPunto(P, 1000, 5000),
                              desviarPunto(P, 4000, 4000),
                              desviarPunto(P, 4000, 3000),
                              desviarPunto(P, 5000, 2000),
                              desviarPunto(P, 4000, 1000),
                              desviarPunto(P, 3000, 0)
};

#endif


