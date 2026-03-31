#ifndef JEAN_H
#define JEAN_H
#include <iostream>
#include <string>

using namespace std;

class Jean {
private:

    string codigo, color, talla, estadoTela;
    bool tenido;
    int cantidadTenidos, cantidadBotones, humedad;
    double precio;

public:
    Jean(); // Constructor

    // Métodos principales
    void registrarDatos();
    void mostrarDatos();
    void lavar();
    void secar();
};

#endif
