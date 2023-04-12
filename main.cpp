#include <iostream>
#include <string.h>
#include "clase.h"
#include "DtClase.h"
#include "DtEntrenamiento.h"
#include "DtSocio.h"
#include "DtSpinning.h"
#include "spinning.h"
#include "entrenamiento.h"
#include "inscripcion.h"


#define MAX_SOCIOS 100
#define MAX_CLASES 100

struct Clases
{
    Clase *c[MAX_CLASES];
    int tope;

} colClases;

struct Socios
{
    Socio *s[MAX_SOCIOS];
    int tope;

} colSocios;

int obtenerId();

int obtenerId()
{
    return colClases.tope + 1;
}

void menu()
{
    system("clear");
    cout << "____________________________" << endl;
    cout << "_________MENU___________" << endl;
    cout << "1. Agregar Socio" << endl;
    cout << "2. Agregar Clase" << endl;
    cout << "3. Agregar Inscripcion" << endl;
    cout << "4. Borrar Inscripcion" << endl;
    cout << "5. Salir" << endl;
    cout << "OPCION: ";
}

void agregarSocio(string ci, string nombre);

void menuAgregarSocio()
{
    system("clear");
    cout << "___________________________" << endl;
    cout << "_______AGREGAR SOCIO________" << endl;

    string ci;
    string nombre;

    cout << "CI: ";
    cin >> ci;

    cout << "\nNOMBRE: ";
    cin >> nombre;

    try
    {
        agregarSocio(ci, nombre);
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
        system("sleep 5");
    }
}

void agregarSocio(string ci, string nombre)
{
    // Crea un nuevo socio en el sistema. En caso de ya existir, levanta excepción std::invalid_argument
    int i = 0;
    while (i < colSocios.tope && colSocios.s[i]->getNombre() != nombre)
        i++;
    if (i == colSocios.tope)
    {
        Socio *socio = new Socio(ci, nombre);
        colSocios.s[colSocios.tope] = socio;
        colSocios.tope++;
        cout << "Socio agregado con éxito" << endl;
        system("sleep 1");
    }
    else
    {
        throw invalid_argument("Ya existe un Socio con ese nombre!!");
    }
}

void agregarClase(DtClase &clase);

void menuAgregarClase()
{
    system("clear");
    cout << "___________________________" << endl;
    cout << "_______Agregar Clase________" << endl;

    string nombre;
    int turno, tipo, cantBici, rambla;
    bool enRambla;
    Turno turno_asign;

    cout << "Nombre de clase: ";
    cin >> nombre;

    int i = 0;
    while (i < colClases.tope && colClases.c[i]->getNombre() != nombre)
        i++;
    if (i == colClases.tope)
    {

        cout << "\nSeleccione turno de la clase";
        cout << "\n1)Mañana"
             << "\n2)Tarde"
             << "\n3)Noche" << endl;
        cin >> turno;

        switch (turno)
        {
        case 1:
            turno_asign = Turno(0);
            break;
        case 2:
            turno_asign = Turno(1);
            break;
        case 3:
            turno_asign = Turno(2);
            break;
        }

        cout << "\nSeleccione tipo de clase";
        cout << "\n1)Spinning"
             << "\n2)Entrenamiento" << endl;
        cin >> tipo;

        DtSpinning spinning;
        DtEntrenamiento entrenamiento;
        switch (tipo)
        {
        case 1:
            cout << "--- CANTIDAD BICICLETAS: ---" << endl;
            cin >> cantBici;
            spinning = DtSpinning(obtenerId(), nombre, turno_asign, cantBici);
            agregarClase(spinning);
            break;
        case 2:
            cout << "--- EN RAMBLA? ---" << endl;
            cout << "\n1)Si"
                 << "\n2)No" << endl;
            cin >> rambla;
            switch (rambla)
            {
            case 1:
                enRambla = true;
                break;
            case 2:
                enRambla = false;
                break;
            }
            entrenamiento = DtEntrenamiento(obtenerId(), nombre, turno_asign, enRambla);
            agregarClase(entrenamiento);
            break;
        }
    }
    else
    {
        throw invalid_argument("Ya existe una Clase con ese nombre!!");
    }
}

void agregarClase(DtClase &clase)
{
    try
    {
        DtSpinning &dts = dynamic_cast<DtSpinning &>(clase);
        Spinning *spinning = new Spinning(dts.getId(),
                                          dts.getNombre(),
                                          dts.getTurno(),
                                          dts.getCantBicicletas());
        colClases.c[colClases.tope] = spinning;
        colClases.tope++;
        cout << "Clase agregada con éxito" << endl;
        system("sleep 1");
    }
    catch (bad_cast)
    {
        try
        {
            DtEntrenamiento &dte = dynamic_cast<DtEntrenamiento &>(clase);
            Entrenamiento *entrenamiento = new Entrenamiento(dte.getId(), dte.getNombre(), dte.getTurno(), dte.getEnRambla());
            colClases.c[colClases.tope] = entrenamiento;
            colClases.tope++;
            cout << "Clase agregada con éxito" << endl;
            system("sleep 1");
        }
        catch (bad_cast)
        {
        }
    }
}

void agregarInscripcion(string ciSocio, int idClase, Fecha fecha);

void menuAgregarInscipcion()
{

    system("clear");
    cout << "___________________________" << endl;
    cout << "____AGREGAR INSCRIPCION___" << endl;
    string socio;
    cout << "Socio Ci: ";
    cin >> socio;
    int i = 0;
    while (i < colSocios.tope && colSocios.s[i]->getCi() != socio)
        i++;
    if (socio == colSocios.s[i]->getCi())
    {
        int clase;
        cout << "Clase Id: ";
        cin >> clase;
        
    }
    else
    {
        throw invalid_argument("No existe ese Socio!!");
    }
}

void agregarInscripcion(string ciSocio, int idClase, Fecha fecha)
{

    /*
        Crea una inscripción de un socio a una clase. La inscripción tiene lugar siempre y cuando el socio y
        la clase existan, de lo contrario se levanta una excepción std::invalid_argument. Si ya existe una
        inscripción de ese usuario para esa clase, o si el cupo de esa clase ya fue alcanzado, también se
        levanta una excepción std::invalid_argument.
    */
}

void borrarInscripcion(string ciSocio, int idClase)
{
    /*
        Borra la inscripción de un socio a una clase. Si no existe una inscripción de ese usuario para esa
        clase, se levanta una excepción std::invalid_argument.
    */
}

int main()
{
    colClases.tope = 0;
    colSocios.tope = 0;
    colInscripciones.tope = 0;
    menu();
    int opcion;
    cin >> opcion;
    while (opcion != 5)
    {
        switch (opcion)
        {
        case 1:
            menuAgregarSocio();
            menu();
            cin >> opcion;
            break;
        case 2:
            menuAgregarClase();
            menu();
            cin >> opcion;
            break;
        case 3:
            // menuAsignarMisionAVengador();
            break;
        case 4:
            // listarVengadores();
            break;
        }
    }
    cout << "CHAU!!!\n"
         << endl;
}
