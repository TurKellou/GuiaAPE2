#include <iostream>
using namespace std;

int hora = 0, minutos = 0, segundos = 0;

int horaCambio(){
    cout<<"Ingrese la nueva hora: "<<endl;
    cin>>hora;
    cout<<"Ingrese los nuevos minutos: "<<endl;
    cin>>minutos;
    cout<<"Ingrese los nuevos segundos: "<<endl;
    cin>>segundos;
return 1;
}

void horaMenu(){
    cout<<"--------------HORA------------"<<endl;
    cout<<"Hora actual: "<<endl;
    cout<<"Hora: "<<hora<<" Minutos: "<<minutos<<" Segundos: "<<segundos<<endl;
    cout<<"¿Desea cambiar la hora? ""(Si = 1, No = 0)"""<<endl;
}

int main(){
    int op;
    do{
        horaMenu();
        cin>>op;
        switch(op){
            case 0 : {
            cout<<"Saliendo del programa..."<<endl;
            break;
            };
            case 1 : {
            horaCambio();
            break;
            };
        }
    } while (op != 0);
return 0;
}
