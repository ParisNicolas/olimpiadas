#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef const vector<int> cvi;

//Condicion especial para el sort(), para operar con pairs
bool comparar(const pair<int,int>& a, const pair<int,int>& b){
    return a.second > b.second;
}

//Algoritmo de resolucion de laberintos adaptado 
bool FIND_PATH(vector<string>& map, cvi& fila, cvi& col, int jugador, int d, int x, int y){
    if(x < 0 || y < 0 || x >= map[0].size() || y >= map.size()) return false; //Fuera del mapa
    if(map[y][x] == 'X') return false; //Obstaculo
    if(map[y][x] == '+') return false; //Huellas (por donde ya paso)

    //Calculo de distancia
    int dist = abs(x-col[jugador])+abs(y-fila[jugador]);
    if(dist > d+2) return false; //Muy lejos

    //Es alcanzable
    if(dist <= 2) {
        //Comprueba si hay un jugador en esa posicion
        bool ocupa = false;
        for(int i=1; i<fila.size(); i++){
            if(fila[i] == y && col[i] == x){
                ocupa = true;
            }
        }
        return !ocupa;
    }
    
    map[y][x] = '+'; //Coloca una huella
    if(FIND_PATH(map,fila,col,jugador, d-1, x+1,y) == true) return true; //Derecha
    if(FIND_PATH(map,fila,col,jugador, d-1, x,y+1) == true) return true; //Abajo
    if(FIND_PATH(map,fila,col,jugador, d-1, x,y-1) == true) return true; //Arriba
    if(FIND_PATH(map,fila,col,jugador, d-1, x-1,y) == true) return true; //Izquierda

    map[y][x] = '.'; //Desmarca la huella
    return false;
}



int sanar(cvi& fila, cvi& col, cvi& vidaInicial, cvi& vidaActual, int d, vector<string>& mapa){
    int n = fila.size(); //Cantidad de jugadores
    int yKhris = fila[0];
    int xKhris = col[0];

    //Calculo de la vida faltante de cada jugador ordenadas de mayor a menor
    //Se guarda a su vez su indice original para poder acceder datos del jugador mas tarde
    vector<pair<int,int>> vidaFaltante;
    for(int i=0; i<n; i++){
        vidaFaltante.push_back(make_pair(i, vidaInicial[i]-vidaActual[i]));
    }
    sort(vidaFaltante.begin(), vidaFaltante.end(), comparar);

    //Empiezo a comprobar si los jugadores estan al alcance de Khris
    for(int i=0; i<n; i++){
        int indiceJuagador = vidaFaltante[i].first; //Indice del jugador en cuestion
        pair<int, int> posicionFinal; //Posicion final de khris (se pasa por referencia)

        //Compruebo si el jugador es alcanzable, sino paso al siguiente
        if(FIND_PATH(mapa, fila, col, indiceJuagador, d, xKhris, yKhris) == false){
            continue;
        }

        //ES ALCANZABLE//
        //Limito la curacion a 10
        if(vidaFaltante[i].second > 10) return 10;
        else return vidaFaltante[i].second;
    } 

    //KHRIS NO PUDO HACER NADA//
    return 0;
}

int main(){

    //NumJugadores, cantFilas, cantColumnas
    int n,r,c,d;
    cin >> n >> r >> c;

    //Datos de los jugadores
    vector<int> fila(n), col(n), vidaInicial(n), vidaActual(n);
    for (int i=0; i<n; i++){
        cin >> fila[i] >> col[i] >> vidaInicial[i] >> vidaActual[i];
    }

    //cantMovimientos
    cin >> d;

    //Mapa de obstaculos
    vector<string> mapa(r);
    for (int i=0; i<r; i++){
        cin >> mapa[i];
    }

    //Resultado
    int resultado = sanar(fila, col, vidaInicial, vidaActual, d, mapa);
    cout << "Cant. max que khris puede sanar: " << resultado;

    return 0;
}