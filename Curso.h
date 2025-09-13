#include <string>

class Curso
{
private:
    int codigo;
    std::string nombre;
    int maxEstudiantes;
    int estudiantes;
    std::string carrera;
    std::string profesor;
    Curso* next;
public:
    Curso(int, std::string, int, std::string, std::string);
    int getCodigo();
    std::string getNombre();
    int getMaxEstudiantes();
    std::string getCarrera();
    std::string getProfesor();
    void agregarEstudiante();
    void eliminarEstudiante();
    ~Curso();
};
