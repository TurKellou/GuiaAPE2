#include <iostream>
using namespace std;

string cedula;
int cuentas = 0;
float saldo[3];

void crearCuenta() {
    if (cuentas >= 3) {
        cout << "No es posible crear una cuenta. Limite alcanzado"<<endl;
        return;
    }

    cout << "Ingrese el dinero inicial de la cuenta: "<<endl;
    cin >> saldo[cuentas];

    cuentas++;
    cout << "Cuenta creada con exito."<<endl;
}

void menuCuenta(int index) {
    int op;
    float monto;

    do {
        cout << "--- Cuenta " << index + 1 << " ---";
        cout << "Saldo actual: " << saldo[index] << endl;
        cout << "1. Recibir dinero"<<endl;
        cout << "2. Enviar dinero"<<endl;
        cout << "3. Transferir a otra cuenta"<<endl;
        cout << "4. Volver"<<endl;
        cout << "Seleccione una opcion: "<<endl;
        cin >> op;

        switch (op) {
            case 1:
                cout << "Ingrese monto a depositar: "<<endl;
                cin >> monto;
                if (monto > 0) {
                    saldo[index] += monto;
                    cout << "Deposito exitoso."<<endl;
                } else {
                    cout << "Monto invalido."<<endl;
                }
                break;

            case 2:
                cout << "Ingrese monto a retirar: "<<endl;
                cin >> monto;
                if (monto > 0 && monto <= saldo[index]) {
                    saldo[index] -= monto;
                    cout << "Retiro exitoso."<<endl;
                } else {
                    cout << "Fondos insuficientes o monto invalido."<<endl;
                }
                break;

            case 3: {
                if (cuentas < 2) {
                    cout << "No hay otra cuenta para transferir."<<endl;
                    break;
                }

                int destino;
                cout << "Seleccione cuenta destino: "<<endl;
                for (int i = 0; i < cuentas; i++) {
                    if (i != index) {
                        cout << i + 1 << ". Cuenta " << i + 1 << endl;
                    }
                }

                cin >> destino;

                if (destino < 1 || destino > cuentas || destino - 1 == index) {
                    cout << "Cuenta destino invalida."<<endl;
                    break;
                }

                cout << "Ingrese monto a transferir: "<<endl;
                cin >> monto;

                if (monto > 0 && monto <= saldo[index]) {
                    saldo[index] -= monto;
                    saldo[destino - 1] += monto;
                    cout << "Transferencia exitosa."<<endl;
                } else {
                    cout << "Fondos insuficientes o monto invalido."<<endl;
                }

                break;
            }

            case 4:
                cout << "Regresando..."<<endl;
                break;

            default:
                cout << "Opcion invalida"<<endl;
        }

    } while (op != 4);
}

void seleccionarCuenta() {
    if (cuentas == 0) {
        cout << "No existe ninguna cuenta. Debes crear una."<<endl;
        return;
    }

    cout << "Seleccione la cuenta: "<<endl;
    for (int i = 0; i < cuentas; i++) {
        cout << i + 1 << ". Cuenta " << i + 1 << endl;
    }

    int op;
    cout << "Ingrese una opcion: "<<endl;
    cin >> op;

    if (op < 1 || op > cuentas) {
        cout << "Cuenta invalida"<<endl;
        return;
    }

    menuCuenta(op - 1);
}

void bancoMenu() {
    int op;

    do {
        cout << "\n--------------BANCO------------"<<endl;
        cout << "Bienvenido nuevamente"<<endl;
        cout << "1. Crear cuenta"<<endl;
        cout << "2. Seleccionar cuenta"<<endl;
        cout << "3. Salir"<<endl;
        cout << "Seleccione una opcion: "<<endl;
        cin >> op;

        switch (op) {
            case 1:
                crearCuenta();
                break;

            case 2:
                seleccionarCuenta();
                break;

            case 3:
                cout << "Saliendo del programa..."<<endl;
                break;

            default:
                cout << "Opcion invalida"<<endl;
        }

    } while (op != 3);
}

int main() {
    cout << "--------------BANCO------------"<<endl;
    cout << "Ingrese su cedula: "<<endl;
    cin >> cedula;

    bancoMenu();

    return 0;
}
