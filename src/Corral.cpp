#include "../include/Corral.hpp"
#include <iostream>
#include <sstream>

using namespace ftxui;
using namespace std::chrono_literals;

static std::vector<std::string> dividirLineas(const std::string& texto) {
    std::vector<std::string> lineas;
    std::stringstream ss(texto);
    std::string linea;
    while (std::getline(ss, linea)) lineas.push_back(linea);
    while (!lineas.empty() && lineas.front().empty()) lineas.erase(lineas.begin());
    while (!lineas.empty() && lineas.back().empty()) lineas.pop_back();
    return lineas;
}

static void limpiar(Screen& pantalla) {
    for (int y = 0; y < pantalla.dimy(); ++y)
        for (int x = 0; x < pantalla.dimx(); ++x) {
            auto& p = pantalla.PixelAt(x, y);
            p.character = U' ';
            p.background_color = Color::Black;
            p.foreground_color = Color::Default;
        }
}

static void dibujar(Screen& pantalla, int fila, int col, const std::string& arte, Color color) {
    auto lineas = dividirLineas(arte);
    for (int y = 0; y < (int)lineas.size(); ++y)
        for (int x = 0; x < (int)lineas[y].size(); ++x) {
            int px = col + x;
            int py = fila + y;
            if (px >= 0 && py >= 0 && px < pantalla.dimx() && py < pantalla.dimy()) {
                auto& p = pantalla.PixelAt(px, py);
                p.character = lineas[y][x];
                p.foreground_color = color;
            }
        }
}

void Corral::ejecutarAnimacion() {
    auto pantalla = Screen::Create(Dimension::Fixed(90), Dimension::Fixed(30));
    auto pajaro = GestorDibujos::obtenerPajaro();
    auto sorprendido = GestorDibujos::obtenerPajaroSorprendido();
    auto manzana = GestorDibujos::obtenerManzana();
    auto pistola = GestorDibujos::obtenerPistola();
    auto angel = GestorDibujos::obtenerAngel();
    auto sol = GestorDibujos::obtenerSol();
    auto nube = GestorDibujos::obtenerNube();
    auto cazador = GestorDibujos::obtenerCazador();
    auto arbol = GestorDibujos::obtenerArbol();
    const auto frame = 100ms;
    while (true) {
        int birdX = 20, birdY = 2;
        int appleX = 58, appleY = 20;
        int gunX = 68, gunY = 6;
        int angelX = 12, angelY = appleY - 6;
        for (int y = birdY; y <= appleY - 6; ++y) {
            limpiar(pantalla);
            dibujar(pantalla, 1, 70, sol.obtenerArte(), Color::Yellow);
            dibujar(pantalla, 2, 40, nube.obtenerArte(), Color::GrayLight);
            dibujar(pantalla, 10, 35, arbol.obtenerArte(), Color::Green);
            dibujar(pantalla, y, birdX, pajaro.obtenerArte(), Color::Yellow);
            dibujar(pantalla, appleY, appleX, manzana.obtenerArte(), Color::Red);
            pantalla.Print();
            std::cout << pantalla.ResetPosition() << std::flush;
            std::this_thread::sleep_for(frame);
        }
        for (int i = 0; i < 10; ++i) {
            limpiar(pantalla);
            dibujar(pantalla, 1, 70, sol.obtenerArte(), Color::Yellow);
            dibujar(pantalla, 2, 40, nube.obtenerArte(), Color::GrayLight);
            dibujar(pantalla, 10, 35, arbol.obtenerArte(), Color::Green);
            dibujar(pantalla, appleY - 6, birdX, (i % 2 ? sorprendido.obtenerArte() : pajaro.obtenerArte()), Color::Yellow);
            dibujar(pantalla, appleY, appleX, manzana.obtenerArte(), Color::Red);
            dibujar(pantalla, gunY + 8, gunX - 8, cazador.obtenerArte(), Color::White);
            pantalla.Print();
            std::cout << pantalla.ResetPosition() << std::flush;
            std::this_thread::sleep_for(frame);
        }
        for (int i = 0; i < 14; ++i) {
            limpiar(pantalla);
            dibujar(pantalla, 1, 70, sol.obtenerArte(), Color::Yellow);
            dibujar(pantalla, 2, 40, nube.obtenerArte(), Color::GrayLight);
            dibujar(pantalla, 10, 35, arbol.obtenerArte(), Color::Green);
            dibujar(pantalla, gunY, gunX, pistola.obtenerArte(), Color::GrayLight);
            dibujar(pantalla, appleY - 6, birdX, sorprendido.obtenerArte(), Color::Yellow);
            dibujar(pantalla, appleY, appleX, manzana.obtenerArte(), Color::Red);
            dibujar(pantalla, gunY + 8, gunX - 8, cazador.obtenerArte(), Color::White);
            if (i % 2 == 0) dibujar(pantalla, gunY + 1, gunX - 10, "*** BANG! ***", Color::RedLight);
            pantalla.Print();
            std::cout << pantalla.ResetPosition() << std::flush;
            std::this_thread::sleep_for(frame);
        }
        for (int y = angelY; y >= 1; --y) {
            limpiar(pantalla);
            dibujar(pantalla, 1, 70, sol.obtenerArte(), Color::Yellow);
            dibujar(pantalla, 2, 40, nube.obtenerArte(), Color::GrayLight);
            dibujar(pantalla, 10, 35, arbol.obtenerArte(), Color::Green);
            dibujar(pantalla, y, angelX, angel.obtenerArte(), Color::White);
            pantalla.Print();
            std::cout << pantalla.ResetPosition() << std::flush;
            std::this_thread::sleep_for(frame);
        }
        std::this_thread::sleep_for(1000ms);
    }
}
