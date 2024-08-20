#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>

using namespace std;

struct backtraking
{
    int llamadasRecursivas = 0;
    int caminosIncorrectos = 0;
    int retrocesos = 0;
};


bool FIND_PATH(int x, int y, backtraking &data, vector<vector<char>> &map){
    data.llamadasRecursivas++;
    if(x < 0 || y < 0 || x >= map[0].size() || y >= map.size()) {
        data.caminosIncorrectos++;
        return false;
    }
    if(map[y][x] == '#') {
        data.caminosIncorrectos++;
        return false;
    }
    if(map[y][x] == 'G') return true;
    if(map[y][x] == '+') return false;
    

    map[y][x] = '+';
    if(FIND_PATH(x+1,y, data, map) == true) return true; //Derecha
    if(FIND_PATH(x,y+1, data, map) == true) return true; //Abajo
    if(FIND_PATH(x,y-1, data, map) == true) return true; //Izquierda
    if(FIND_PATH(x-1,y, data, map) == true) return true; //Arriba

    map[y][x] = '.';
    data.retrocesos++;
    return false;
}


int main(){
    backtraking data;

    ifstream inputFile("laberinto.in");
    if (!inputFile.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }

    int xS, yS;
    inputFile >> xS >> yS;
    vector<vector<char>> mapa ( yS , vector<char> (xS)); 

    for (int i = 0; i < yS; i++){
        for (int z = 0; z < xS; z++){
            inputFile >> mapa[i][z];
        }
    }

    inputFile.close();
    
    auto inicio = chrono::high_resolution_clock::now();
    bool result = FIND_PATH(0, 0, data, mapa);
    auto fin = chrono::high_resolution_clock::now();

    auto duracion = chrono::duration_cast<chrono::microseconds>(fin - inicio);

    if(result == true){
        cout << "Salida encontrada" << endl << '[';
        for(int y = 0; y < mapa.size(); y++){
            for(int x = 0; x < mapa[0].size(); x++){
                cout << '\'' << mapa[y][x] << "\',";
            }
            cout << endl;
        }
        cout << ']' << endl;
        cout << "Informacion adicional:" << endl;
        cout << " -Llamadas recusivas: " << data.llamadasRecursivas << endl;
        cout << " -Caminos incorrectos: " << data.caminosIncorrectos << endl;
        cout << " -Retrocesos: " << data.retrocesos << endl;
        cout << " -Duracion: " << duracion.count() << " ms" << endl;
        
    }else{
        cout << "Salida no encontrada";
    }
    return 0;
}