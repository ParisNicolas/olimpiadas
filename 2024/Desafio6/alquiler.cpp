#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Reserva {
    Fecha llegada;
    Fecha partida;
    string email;
};

bool operator<(const Fecha& f1, const Fecha& f2){
    if (f1.anio != f2.anio)
        return f1.anio < f2.anio;
    if (f1.mes != f2.mes)
        return f1.mes < f2.mes;
    return f1.dia < f2.dia;
}

bool operator>=(const Fecha& f1, const Fecha& f2){
    if (f1.anio != f2.anio)
        return f1.anio >= f2.anio;
    if (f1.mes != f2.mes)
        return f1.mes >= f2.mes;
    return f1.dia >= f2.dia;
}

bool compararPorFin(const Reserva &a, const Reserva &b) {
    return a.partida < b.partida;
}

//Maxima cantidad de confirmaciones para inquilinos
//No pueden superponerse, solo coincidir el dia de llegada o partida
//Uso un algoritmo Greedy (codicioso)
int alquiler(vector<Reserva> &reservas, vector<string> &confirmados){

    //Ordeno por la fecha de partida mas pronta
    sort(reservas.begin(), reservas.end(), compararPorFin);

    int cant = 0;
    Fecha finUltimoSeleccionado;
    finUltimoSeleccionado.anio = 1972;

    //Encuentro la opcion inmediata mas optima
    for(Reserva &reserva : reservas){
        //Verifico que las fechas del siguiente no se superpongan con el anterior
        if(reserva.llegada >= finUltimoSeleccionado){
            finUltimoSeleccionado = reserva.partida;
            confirmados.push_back(reserva.email);
            cant++;
        }
    }

    return cant;
}

int main(){
    ifstream inputFile("alquiler.in");
    if (!inputFile.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }

    int R;
    inputFile >> R;

    vector<Reserva> reservas(R);
    for(int i=0; i<R;i++){
        Reserva reserva;

        inputFile >> reserva.llegada.dia;
        inputFile >> reserva.llegada.mes;
        inputFile >> reserva.llegada.anio;
        inputFile >> reserva.partida.dia;
        inputFile >> reserva.partida.mes;
        inputFile >> reserva.partida.anio;
        inputFile >> reserva.email;

        reservas[i] = reserva;
    }
    inputFile.close();
    
    vector<string> confirmados;
    int C = alquiler(reservas, confirmados);

    cout << "Cantidad de alquileres: " << C << endl;
    for(string email : confirmados){
        cout << email << endl;
    }

    return 0;
}
