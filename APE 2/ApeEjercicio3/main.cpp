#include "Jean.h"

//Incluye el menu
int main() {
    Jean miJean;
    int opcion;

    do {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Ingresar datos del jean" << endl;
        cout << "2. Mostrar datos del jean" << endl;
        cout << "3. Lavar jean" << endl;
        cout << "4. Secar jean" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: miJean.registrarDatos(); break;
            case 2: miJean.mostrarDatos(); break;
            case 3: miJean.lavar(); break;
            case 4: miJean.secar(); break;
            case 5: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion no valida" << endl;
        }
    } while (opcion != 5);

    return 0;
}
