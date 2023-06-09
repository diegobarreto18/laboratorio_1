#include <iostream>
#include <string.h>
#include "DtEntrenamiento.h"

DtEntrenamiento::DtEntrenamiento() {}

DtEntrenamiento::DtEntrenamiento(int id, string nombre, Turno turno,bool enRambla):DtClase(id, nombre, turno)
{
  this->enRambla = enRambla;
}

bool DtEntrenamiento::getEnRambla()
{
  return this->enRambla;
}
void DtEntrenamiento::setEnRambla(bool enRambla)
{
  this->enRambla = enRambla;
}

DtEntrenamiento::~DtEntrenamiento() {}

DtClase* DtEntrenamiento :: getDtClase(){
  DtEntrenamiento* dtentrenamiento = new DtEntrenamiento(this->getId(),this->getNombre(),this->getTurno(),this->getEnRambla());
  return dtentrenamiento;
}

ostream &operator <<(ostream &salida, DtEntrenamiento& entrenamiento){
  DtClase &dte = dynamic_cast<DtClase &>(entrenamiento);
  if (entrenamiento.enRambla == true){
      cout << dte << "En rambla: " << "Si" << endl;
  }else{
      cout << dte << "En rambla: " << "No" << endl;
  }
 
  return salida;
}