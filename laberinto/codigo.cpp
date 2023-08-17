#include <iostream>
#include <string>

using namespace std;

//[2][0] fila 2, columna 0 (#)
//y, x

#define xSize 6
#define ySize 6
char map[xSize][ySize] = {'S','#','#','#','#','#',
                          '.','.','.','.','.','.',
                          '#','.','#','.','#','.',
                          '#','.','#','.','#','.',
                          '.','.','.','#','.','G',
                          '#','#','.','.','.','#'};


bool FIND_PATH(int x, int y){
    if(x < 0 || y < 0 || x >= xSize || y >= ySize) return false;
    if(map[y][x] == 'G') return true;
    if(map[y][x] == '#') return false;
    if(map[y][x] == '+') return false;

    map[y][x] = '+';
    if(FIND_PATH(x+1,y) == true) return true; //Derecha
    if(FIND_PATH(x,y+1) == true) return true; //Abajo
    if(FIND_PATH(x,y-1) == true) return true; //Izquierda
    if(FIND_PATH(x-1,y) == true) return true; //Arriba

    map[y][x] = '.';
    return false;
}


int main(){
    if(FIND_PATH(0, 0) == true){
        cout << "Salida encotrada" << endl << '[';
        for(int y = 0; y < ySize; y++){
            for(int x = 0; x < xSize; x++){
                cout << '\'' << map[y][x] << "\',";
            }
            cout << endl;
        }
        cout << ']';
    }else{
        cout << "Salida no encontrada";
    }
    return 0;
}