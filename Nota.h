#include <string>

class Nota
{
private:
    float nota;
    std::string curso;
    Nota* next;
public:
    Nota(float, std::string);
    float getNota(); 
    std::string getCurso();
    ~Nota();
};

