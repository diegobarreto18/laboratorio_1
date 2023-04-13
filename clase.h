#ifndef CLASE
#define CLASE

#include "define.h"
#include <iostream>
#include <string.h>
#include "DtClase.h"



using namespace std;

class Clase
{
private:
    int id;
    string nombre;
    Turno turno;

public:
    Clase();
    Clase(int id, string nombre, Turno turno);
    int getId();
    void setId(int id);
    string getNombre();
    void setNombre(string nombre);
    Turno getTurno();
    void setTurno(Turno turno);
    ~Clase();
    virtual int cupo() = 0;
};

#endif
