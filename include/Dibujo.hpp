#pragma once
#include <string>

class Dibujo {
private:
    std::string arte;
public:
    Dibujo(std::string arte);
    std::string obtenerArte();
};
