#include "../include/Dibujo.hpp"

Dibujo::Dibujo(std::string arte) : arte(arte) {}

std::string Dibujo::obtenerArte() {
    return arte;
}
