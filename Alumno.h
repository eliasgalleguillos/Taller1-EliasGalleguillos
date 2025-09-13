#include <string>
#include "Nota.h"
#include "Curso.h"

class Alumno
{
private:
    int id;
    std::string nombre;
    std::string apellido;
    std::string carrera;
    std::string fechaDeIngreso;
    Nota* listaNotas;
    Curso* listaCursos;
    Alumno* next;
public:
    Alumno(int, std::string, std::string, std::string, std::string);
    int getId();
    std::string getNombre();
    std::string getApellido();
    std::string getCarrera();
    std::string getFechaDeIngreso();
    Nota* getListaNotas();
    Curso* getListaCursos();
    void setNotas(Nota*);
    void setCurso(Curso*);
    ~Alumno();
};
