#include <iostream>
#include <string>

void menuAlumnos(Alumno* alum){
    int opcion;
    
    while(opcion<1 || opcion>3){
        
        std::cout << "Seleccione una opcion" << std::endl;
        std::cout << "1) Crear un alumno" << std::endl;
        std::cout << "2) Buscar un alumno" << std::endl;
        std::cout << "3) Eliminar un alumno" << std::endl;
        
        std::cin >> opcion;
    }
    
    if(opcion==1){
        std::string nombre, apellido, carrera, fechaIngreso;
        int id;
        
        std::cout << "Ingrese id del alumno" << std::endl;
        std::cin >> id;
        
        std::cout << "Ingrese nombre del alumno" << std::endl;
        std::cin >> nombre;
        
        std::cout << "Ingrese apellido del alumno" << std::endl;
        std::cin >> apellido;
        
        std::cout << "Ingrese carrera del alumno" << std::endl;
        std::cin >> carrera;
        
        std::cout << "Ingrese fecha de ingreso en el formato xx/xx/xxxx" << std::endl;
        std::cin >> fechaIngreso;
        
        if(alum==nullptr){
            alum= new Alumno(id, nombre, apellido, carrera, fechaIngreso);
        }
        
        Alumno* aux= alum;
        while(aux->next !nullptr){
            aux= aux->next;
        }
        aux->next= new Alumno(id, nombre, apellido, carrera, fechaIngreso);
        
    } else if(opcion==2){
        std::string opcion;
        
        std::cout << "Desea buscar por id o nombre" << std::endl;
        std::cin >> opcion;
        
        if(opcion.compare("id")==0){
            int idBuscador;
            std::cout << "Indique el id" << std::endl;
            std::cin >> idBuscador;
            
            Alumno* aux= alum;
            Alumno* buscado;
            
            if(aux==nullptr){
                std::cout << "No hay alumnos creados" << std::endl;
                return;
            }
            
            while(aux!=nullptr){
                if(aux->id==idBuscador){
                    buscado= aux;
                }
                aux= aux->next;
            }
            
            std::cout << "Alumno: " << buscado->nombre << buscado->apellido << std::endl;
            std::cout << "Carrera" << buscado->carrera << std::endl;
            std::cout << "Fecha de ingreso" <<buscado->fechaDeIngreso << std::endl;
            
        }else{
            std::string nombreBuscador;
            std::cout << "Indique el nombre" << std::endl;
            std::cin >> nombreBuscador;
            
            Alumno* aux= alum;
            
            if(aux==nullptr){
                std::cout << "No hay alumnos creados" << std::endl;
                return;
            }
            
            while(aux!=nullptr){
                if(aux->nombre.compare(nombreBuscador)==0){
                    std::cout << "Alumno: " << aux->nombre << aux->apellido << std::endl;
                    std::cout << "ID: " << aux->id << std::endl;
                    std::cout << "Carrera: " << aux->carrera << std::endl;
                    std::cout << "Fecha de ingreso: " << aux->fechaDeIngreso << std::endl;
                }
                aux= aux->next;
            }
        }
        
    } else(opcion==3){
        int buscarId;
        Alumno* buscado;
        
        std::cout << "Ingrese la id del alumno" << std::endl;
        std::cin >> buscarId;
        
        Alumno* aux= alum;
        Alumno* aux2;
            
        if(aux==nullptr){
            std::cout << "No hay alumnos creados" << std::endl;
            return;
        }
        if(aux->id==buscarId){
            Nota* notas= aux->getListaNotas();
            Nota* cabeza;
            
            while(aux!=nullptr){
                cabeza= aux;
                aux= aux->next;
                delete cabeza;
            }
            
            Curso* cursos= aux->getListaCursos();
            Curso* cursoAux= cursos;
            
            while(cursoAux!=nullptr){
                cursoAux->eliminarEstudiante();
                cursoAux= cursoAux->next;
            }
            delete aux;
        }
            
        while(aux->next->id != buscarId){
            aux= aux->next;
        }
        
        Nota* notas= aux->getListaNotas();
        Nota* cabeza;
            
        while(aux!=nullptr){
            cabeza= aux;
            aux= aux->next;
            delete cabeza;
        }
            
        Curso* cursos= aux->getListaCursos();
        Curso* cursoAux= cursos;
            
        while(cursoAux!=nullptr){
            cursoAux->eliminarEstudiante();
            cursoAux= cursoAux->next;
        }
        delete aux;
    }
    
}

void menuCursos(Curso* curso, Alumno* alum){
    int opcion;
    
    while(opcion<1 || opcion>3){
        
        std::cout << "Seleccione una opcion" << std::endl;
        std::cout << "1) Crear un curso" << std::endl;
        std::cout << "2) Buscar un curso" << std::endl;
        std::cout << "3) Eliminar un curso" << std::endl;
        
        std::cin >> opcion;
    }
    
    if(opcion==1){
        std::string nombre, carrera, profesor;
        int codigo, maxEstudiantes;
        
        std::cout << "Ingrese el codigo del curso" << std::endl;
        std::cin >> codigo;
        
        std::cout << "Ingrese nombre del curso" << std::endl;
        std::cin >> nombre;
        
        std::cout << "Ingrese carrera del curso" << std::endl;
        std::cin >> carrera;
        
        std::cout << "Ingrese el maximo de estudiantes del curso" << std::endl;
        std::cin >> maxEstudiantes;
        
        std::cout << "Ingrese el nombre del profesor del curso" << std::endl;
        std::cin >> profesor;
        
        if(curso==nullptr){
            curso= new Curso(codigo, nombre, maxEstudiantes, carrera, profesor);
        }
        
        Curso* aux= curso;
        while(aux->next !nullptr){
            aux= aux->next;
        }
        aux->next= new Curso(codigo, nombre, maxEstudiantes, carrera, profesor);
    } else if(opcion==2){
        
        std::string opcion;
        
        std::cout << "Desea buscar por codigo o nombre" << std::endl;
        std::cin >> opcion;
        
        if(opcion.compare("codigo")==0){
            int codigoBuscador;
            
            std::cout << "Indique el codigo" << std::endl;
            std::cin >> idBuscador;
            
            Curso* aux= curso;
            Curso* buscado;
            
            if(aux==nullptr){
                std::cout << "No hay cursos creados" << std::endl;
                return;
            }
            
            while(aux!=nullptr){
                if(aux->codigo==codigoBuscador){
                    buscado= aux;
                }
                aux= aux->next;
            }
            
            std::cout << buscado->nombre << std::endl;
            std::cout << "Carrera: " << buscado->carrera << std::endl;
            std::cout << "Profesor: " <<buscado->profesor << std::endl;
            
        }else{
            std::string nombreBuscador;
            std::cout << "Indique el nombre" << std::endl;
            std::cin >> nombreBuscador;
                
            Curso* aux= curso;
                
            if(aux==nullptr){
                std::cout << "No hay cursos creados" << std::endl;
                return;
            }
                
            while(aux!=nullptr){
                if(aux->nombre.compare(nombreBuscador)==0){
                    std::cout << aux->nombre << std::endl;
                    std::cout << "Codigo: " << aux->codigo << std::endl;
                    std::cout << "Carrera: " << aux->carrera << std::endl;
                    std::cout << "Profesor:  " << aux->profesor << std::endl;
                }
                aux= aux->next;
            }
        }
    }else{
        int buscarCodigo;
        Curso* buscado;
        
        std::cout << "Ingrese el codigo del curso" << std::endl;
        std::cin >> buscarCodigo;
        
        Curso* aux= curso;
        Curso* aux2;
            
        if(aux==nullptr){
            std::cout << "No hay cursos creados" << std::endl;
            return;
        }
        if(aux->codigo==buscarCodigo){
            Alumno* auxAlum= alum;
            while(auxAlum!=nullptr){
                Curso* ramos= auxAlum->getListaCursos();
                Curso* auxRamo= ramos;
                
                while(auxRamo->codigo!=buscarCodigo){
                    auxRamo= auxRamo->next;
                }
                auxAlum= auxAlum->next;
            }
        }
            
        while(aux->next->id != buscarId){
            aux= aux->next;
        }
        aux2= aux->next;
        aux->next= aux2->next;
        
        Nota* notas= aux->getListaNotas();
        Nota* cabeza;
            
        while(aux!=nullptr){
            cabeza= aux;
            aux= aux->next;
            delete cabeza;
        }
            
        Curso* cursos= aux->getListaCursos();
        Curso* cursoAux= cursos;
            
        while(cursoAux!=nullptr){
            cursoAux->eliminarEstudiante();
            cursoAux= cursoAux->next;
        }
        delete aux;
    }
}

void menuIns(){
    
}

void menuNotas(){
    
}

void menuReporte(){
    
}

void menu(Alumno* alum, Curso* curso){
    int opcion;
    
    
    
    while(opcion<1 || opcion>6){
        std::cout << "Seleccione una opcion" << std::endl;
        std::cout << "1) Manejo de alumnos" << std::endl;
        std::cout << "2) Manejo de cursos" << std::endl;
        std::cout << "3) Manejo de inscripciones" << std::endl;
        std::cout << "4) Manejo de notas" << std::endl;
        std::cout << "5) Consultas y reportes" << std::endl;
        std::cout << "6) Salir" << std::endl;
        
        std::cin >> opcion;
    }
    
    if(opcion==1){
        menuAlumnos(alum);
    }else if(opcion==2){
        menuCursos(curso, alum);
    }else if(opcion==3){
        menuIns();
    } else if(opcion==4){
        menuNotas();
    } else if(opcion==5){
        menuReporte();
    } else{
        std::cout << "Vuelva pronto" << std::endl;
    }
    
}

int main()
{
    Alumno* head= nullptr;
    Curso* curso= nullptr;
    menu(head, curso);

    return 0;
}