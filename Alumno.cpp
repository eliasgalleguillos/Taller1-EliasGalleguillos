#include "Alumno.h"
#include <iostream>

Alumno::Alumno(int id, std::string nombre, std::string apellido, std::string carrera, std::string fechaDeIngreso){
    this->id= id;
    this->nombre= nombre;
    this->apellido= apellido;
    this->carrera= carrera;
    this->fechaDeIngreso= fechaDeIngreso;
    listaNotas= nullptr;
    listaCursos= nullptr;
    next= nullptr;
}

int Alumno::getId(){
    return id;
}

std::string Alumno::getNombre(){
    return nombre;
}

std::string Alumno::getApellido(){
    return apellido;
}

std::string Alumno::getCarrera(){
    return carrera;
}

std::string Alumno::getFechaDeIngreso(){
    return fechaDeIngreso;
}

Nota* Alumno:: getListaNotas(){
    return listaNotas;
}

Curso* Alumno:: getListaCursos(){
    return listaCursos;
}

void Alumno::setCurso(Curso* c){
    if(listaCursos==nullptr){
        listaCursos=c;
        return;
    }
    
    Nota* aux= listaCursos;
    
    while(aux->next !=nullptr){
        aux= aux->next;
    }
    aux->next= n;
}

void Alumno::setNotas(Nota* n){
    if(listaNotas==nullptr){
        listaNotas=n;
        return;
    }
    
    Nota* aux= listaNotas;
    
    while(aux->next !=nullptr){
        aux= aux->next;
    }
    aux->next= n;
}