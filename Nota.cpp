#include "Nota.h"
#include <iostream>

Nota::Nota(float nota, std::string curso){
    this->nota= nota;
    this->curso= curso;
    next= nullptr;
}

float Nota:: getNota(){
    return nota;
}
std::string Nota:: getCurso(){
    return curso;
}