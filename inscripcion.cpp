#include <iostream>
#include <string.h>
#include "inscripcion.h"

Inscripcion::Inscripcion() {}

Inscripcion::Inscripcion(Fecha fecha, Socio *socio)
{
    this->fecha = fecha;
    this->socio = socio;
}

Fecha Inscripcion::getFecha()
{
    return this->fecha;
}
void Inscripcion::setFecha(int dia, int mes, int anio, Fecha &fecha)
{
    fecha = Fecha(dia, mes, anio);
}

Socio *Inscripcion::getSocio()
{
    return this->socio;
}

void Inscripcion::setSocio(Socio *socio)
{
    this->socio = socio;
}

Inscripcion::~Inscripcion() {}

/*DtSocio* Inscripcion::getDtSocio(){
  return this->socio->getDtSocio();
}*/

/*
    De cada inscripción se conoce el socio.
    La clase del gimnasio a la cual se inscribe y fecha de realización
*/