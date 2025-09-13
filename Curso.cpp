#include "Curso.h"

Curso::Curso(int codigo, std::string nombre, int maxEstudiantes, std::string carrera, std::string profesor){
    this->codigo= codigo;
    this->nombre= nombre;
    this->maxEstudiantes= maxEstudiantes;
    estudiantes=0;
    this->carrera= carrera;
    this->profesor= profesor;
    next= nullptr;
}

int Curso:: getCodigo(){
    return codigo;
}

std::string Curso::getNombre(){
    return nombre;
}

std::string Curso:: getCarrera(){
    return carrera;
}

int Curso:: getMaxEstudiantes(){
    return maxEstudiantes;
}

std::string Curso::getProfesor(){
    return profesor;
}

void Curso:: agregarEstudiante(){
    estudiantes++;
}

void Curso:: eliminarEstudiante(){
    estudiantes= estudiantes-1;
}