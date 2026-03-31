#include "Jean.h"
#include <iostream>

using namespace std;

// Constructor
Jean::Jean() {
    codigo = "";
    color = "";
    talla = "";
    tenido = false;
    cantidadTenidos = 0;
    precio = 0.0;
    cantidadBotones = 0;
    humedad = 0;
    estadoTela = "Nuevo";
}

// Registrar Datos
void Jean::registrarDatos() {
    cout << "Ingrese el codigo del Jean: ";
    cin >> codigo;
    cout << "Ingrese el color: ";
    cin >> color;
    cout << "Ingrese la cantidad de tenidos iniciales: ";
    cin >> cantidadTenidos;
    cout << "Ingrese el porcentaje de humedad (0-100): ";
    cin >> humedad;
    cout << "Datos registrados correctamente." << endl;
}

// Mostrar Datos
void Jean::mostrarDatos() {
    cout << "\n------ REPORTE DEL JEAN ------" << endl;
    cout << "Codigo: " << codigo << endl;
    cout << "Color: " << color << endl;
    cout << "Cantidad de tenidos: " << cantidadTenidos << endl;
    cout << "Humedad actual: " << humedad << "%" << endl;
    cout << "------------------------------" << endl;
}

//REGLA
void Jean::lavar() {
    if (cantidadTenidos > 0) {
        cantidadTenidos--; // Restamos 1
        humedad = 100;    // Se moja al lavarlo
        cout << "LAVADO: Se perdio un tenido. Ahora tiene: " << cantidadTenidos << endl;
    } else {
        cout << "El jean ya no tiene color que perder." << endl;
    }
}

// REGLA
void Jean::secar() {
    if (humedad > 0) {
        humedad -= 25;
        if (humedad < 0) humedad = 0;
        cout << "SECANDO: Humedad actual baja a: " << humedad << "%" << endl;
    } else {
        cout << "El jean ya esta completamente seco." << endl;
    }
}
