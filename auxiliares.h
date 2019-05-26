#ifndef TRANSPORTEURBANO_AUXILIARES_H
#define TRANSPORTEURBANO_AUXILIARES_H

#include "definiciones.h"


double obtenerLatitud(gps posicion);
double obtenerLongitud(gps posicion);
gps obtenerPosicion(tuple<tiempo, gps> medicion);
tiempo obtenerTiempo(tuple<tiempo, gps> medicion);
double distEnKM(gps posicion1, gps posicion2);
gps desviarPunto(gps p, double desvioMtsLatitud, double desvioMtsLongitud);
double distMts(gps posicion1, gps posicion2);
gps puntoGps(double latitud, double longitud);
tuple<tiempo, gps> medicion(tiempo t, gps g);



#endif //TRANSPORTEURBANO_AUXILIARES_H
