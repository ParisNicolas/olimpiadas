#include<iostream>
#include <fstream>
#include <vector>

using namespace std;

struct tanque{
    int superficie;
    int profundidad;
    int profundidadTub = 0;
    int alturaAgua = 0;
};  

int rellenar(vector<tanque> &E, vector<int> tanquesAllenar, int hTuberia, int &volRest){
    int cant = tanquesAllenar.size();
    vector<int> alturasExtras(cant);
    vector<int> volumenes(cant);
    int suma = 0;
    for(int i=0, t; i<cant; i++){
        t = tanquesAllenar[i];

        alturasExtras[i] = E[t].profundidad - E[t].alturaAgua - hTuberia;
        volumenes[i] = alturasExtras[i]*E[t].superficie;
        suma += volumenes[i];
    }
    
    if(suma > volRest){
        int sumSuperficies = 0;
        for(int i=0, t; i<cant; i++){
            t = tanquesAllenar[i];
            sumSuperficies += E[t].superficie;
        }
        int hAguaExtra = volRest/sumSuperficies;
        volRest = 0;
        for(int i=0, t; i<cant; i++){
            t = tanquesAllenar[i];
            E[t].alturaAgua += hAguaExtra;
        }
        return true;
    }

    for(int i=0, t; i<cant; i++){
        t = tanquesAllenar[i];

        E[t].alturaAgua += alturasExtras[i];
        volRest -= volumenes[i];
    }
    return false;

    /*
    for(int n : tanquesAllenar){
        int alturaExtra = E.profundidad - E.alturaAgua - hTuberia;
        int volumen = alturaExtra*E.superficie;
        if (volumen > volRest){
            E.alturaAgua += volRest/E.superficie;
            volRest = 0;
            return true;
        }else{
            E.alturaAgua += alturaExtra;
            volRest -= volumen;
            return false;
        }
    }*/
}


vector<int> continuarLlenado(int &Vol, vector<tanque> &E, int nE, bool dir, bool first=false){
    vector<int> tanquesActivos = {nE}; //Tanques que comparten agua
    int ultimoTanqueIzq = nE; //El ultimo tanque compartido, para continuar desde alli
    int ultimoTanqueDer = nE;

    int tuberiaIzq, tuberiaDer; //Alturas de tuberias izq y derecha
    int sig, sigTuberia; //Siguiente tanque y sig altura a analizar

    //Si es el primer tanque
    if(nE == 0){
        tuberiaIzq=0; //La tuberiaIzq no existe
        tuberiaDer=E[nE].profundidadTub;
        if(first) dir = true; //Define la direccion a la derecha (si es la primera iteracion)
    }

    //Si es el ultimo tanque
    else if(nE == E.size()-1){
        tuberiaIzq=E[nE-1].profundidadTub;
        tuberiaDer=0; //La tuberiaDer no existe
        if(first) dir = false; //Define la direccion a la izquierda (si es la primera iteracion)
    }

    else{
        tuberiaIzq = E[nE-1].profundidadTub;
        tuberiaDer = E[nE].profundidadTub;
    }

    //Comenzar a analizar y rellenar
    while(true){
        //tuberia izquierda predominante
        if (tuberiaIzq>tuberiaDer){
            sig = ultimoTanqueIzq-1; //Retrocede
            sigTuberia = tuberiaIzq;
            if(first) dir = false;
            if(dir == true){ //Si regresa a la tuberia anterior (viene de la izquierda (true == de izq a der))
                rellenar(E, tanquesActivos, sigTuberia, Vol); //Rellena
                return tanquesActivos; //Regresa
            }
        }
        //tuberia derecha predominante
        else if(tuberiaIzq<tuberiaDer) {
            sig = ultimoTanqueDer+1; //Avanza
            sigTuberia = tuberiaDer;
            if(first) dir = true;
            if(dir == false){ //Si regresa a la tuberia anterior (viene de la derecha (false == de der a izq))
                rellenar(E, tanquesActivos, sigTuberia, Vol); //Rellena
                return tanquesActivos; //Regresa
            }
        }
        //Misma altura, va hacia el tanque vacio
        else{
            if(dir == true){
                sig = ultimoTanqueDer+1;
                sigTuberia = tuberiaDer;
            }else{
                sig = ultimoTanqueIzq-1;
                sigTuberia = tuberiaIzq;
            }
        }

        //Rellena todos los tanques compartidos y aborta si se acaba el agua
        if(rellenar(E, tanquesActivos, sigTuberia, Vol)) return tanquesActivos;

        //Continua al siguiente con la misma direccion
        vector<int> tanquesEncadenados = continuarLlenado(Vol, E, sig, dir);
        //Añade los tanques compartidos cuando regresa
        tanquesActivos.insert(tanquesActivos.end(), tanquesEncadenados.begin(), tanquesEncadenados.end());
        //Si no queda agua aborta
        if(Vol == 0) return tanquesActivos;


        //if(ultimoTanque == E.size()-1 || ultimoTanque == 0) return tanquesActivos;
        //Actualizo las nuevas tuberias activas
        if(dir == true){
            ultimoTanqueDer = tanquesActivos.back();
            if(ultimoTanqueDer == E.size()-1) tuberiaDer = 0;
            else tuberiaDer = E[ultimoTanqueDer].profundidadTub;
        }
        if(dir == false){
            ultimoTanqueIzq = tanquesActivos.back();
            if(ultimoTanqueIzq == 0) tuberiaIzq = 0;
            else tuberiaIzq = E[ultimoTanqueIzq-1].profundidadTub;
        }
    }
}

int main(){
    ifstream inputFile("truchas.in");

    if (!inputFile.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }

    int n;  // Cantidad de estanques
    inputFile >> n;
 
    vector<tanque> estanques(n);

    // Leer los datos de los primeros n-1 estanques
    for (int i = 0; i < n - 1; ++i) {
        int s, pe, pc;
        inputFile >> s >> pe >> pc;
        estanques[i].superficie = s;
        estanques[i].profundidad = pe;
        estanques[i].profundidadTub = pc;
    }

    // Leer los datos del último estanque
    int s, pe;
    inputFile >> s >> pe;
    estanques[n - 1].superficie = s;
    estanques[n - 1].profundidad = pe;

    // Leer el volumen y el estanque donde se inicia el llenado
    int vol, nE;
    inputFile >> vol >> nE;
    nE--;

    inputFile.close();

    //Sumao la capacidad total de los estanques
    int volumenTotal = 0;
    for (int i = 0; i<n; i++){
        volumenTotal += estanques[i].profundidad * estanques[i].superficie;
    }
    //Si el volumen es mayor a la capacidad, entonces desborda
    if(vol >= volumenTotal){
        cout << "Hay desborde: " <<  vol-volumenTotal;
        return 0;
    }

    //Lleno el primer estanque (seleccionado)
    vector<int> tanquesConAgua = continuarLlenado(vol, estanques, nE, false, true);

    //Imprimo todos los estanques con agua
    cout << "Tanques con agua:\n";
    for (int T : tanquesConAgua){
        cout << "E" << T << ": " << estanques[T].alturaAgua << endl;
    }

    return 0;
}
