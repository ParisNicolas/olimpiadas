#include <iostream>
#include <vector>
#include <string>

using namespace std;

//vector de vectores de caracteres
/*
vector<vector<char>> arr = {{'.','.','.','<','>','.','.','.','.'},
                            {'<','>','.','.','<','>','.','A','.'},
                            {'.','.','<','>','.','A','.','V','.'},
                            {'.','.','.','.','.','V','.','.','.'},
                            {'.','<','>','.','.','.','.','.','.'}};
*/

//Paso matriz por referencia (&) 
void move_V(int y, int x, vector<string>& g){
    g[y][x] = 'A';
    g[y-1][x] = '.';
    g[y+1][x] = 'V';
}
        
void move_H(int y, int x, vector<string>& g){
    g[y][x] = '.';    g[y+1][x] = '<';
    g[y][x+1] = '.';  g[y+1][x+1] = '>';
}


//Devuelvo un vector de 2 dimenciones y tomo otro como argumento pasandole el valor
//No haciendo referencia, podria pero quiero crear uno nuevo
vector<string> gravitas(vector<string> g){
    //recorro la matriz de abajo hacia arriva y de izquierda a derecha
    //Empiezo a bajar las flechas por la penultima fila
    for(int y = g.size()-2; y >= 0; y--){
        for(int x = 0; x < g[0].size(); x++){
            
            //Si es horizontal (Solo importa el comienzo)
            if(g[y][x] == '<'){
                int newY = y;
                while(g[newY+1][x] == '.' && g[newY+1][x+1] == '.'){
                    move_H(newY, x, g);
                    newY++;
                    if(newY+1 == g.size()) break;
                }
            }
            //Si es vertical (solo lo tira por debajo)
            else if(g[y][x] == 'V'){
                int newY = y;
                while(g[newY+1][x] == '.'){
                    move_V(newY, x, g);
                    newY++;
                    if(newY+1 == g.size()) break;
                }
            }
        }
    }
    return g;
}

int main(){

    int N;
    vector<string> arr;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string x;
        cin >> x;
        arr.push_back(x);
    }
    

    vector<string> result = gravitas(arr);
    
    cout << endl << "Result:" << endl;

    for(int i = 0; i < result.size(); i++){
        for(int m = 0; m < result[0].size(); m++){
            cout << result[i][m];
        }
        cout << endl;
    }

    return 0;
}