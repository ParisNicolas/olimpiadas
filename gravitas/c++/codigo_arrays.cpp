#include <iostream>
#include <vector>

using namespace std;

#define ly 5
#define lx 9

char* arr[lx] = {{'.','.','.','<','>','.','.','.','.'},
                    {'<','>','.','.','<','>','.','A','.'},
                    {'.','.','<','>','.','A','.','V','.'},
                    {'.','.','.','.','.','V','.','.','.'},
                    {'.','<','>','.','.','.','.','.','.'}};

void move_V(int y, int x, char (*g)[lx]){
    g[y][x] = 'A';
    g[y-1][x] = '.';
    g[y+1][x] = 'V';
}
        
void move_H(int y, int x, char (*g)[lx]){
    g[y][x] = '.';    g[y+1][x] = '<';
    g[y][x+1] = '.';  g[y+1][x+1] = '>';
}

char** gravitas(char g[ly][lx]){
    for(int y = ly-2; y >= 0; y--){
        for(int x = 0; x < lx; x++){
            
            if(g[y][x] == '<'){
                int newY = y;
                while(g[newY+1][x] == '.' && g[newY+1][x+1] == '.'){
                    move_H(newY, x, g);
                    newY++;
                    if(newY+1 == ly) break;
                }
            }
            else if(g[y][x] == 'V'){
                int newY = y;
                while(g[newY+1][x] == '.'){
                    move_V(newY, x, g);
                    newY++;
                    if(newY+1 == ly) break;
                }
            }
        }
    }
    return g;
}

int main(){

    char** result = gravitas(arr);
    
    for(int i = 0; i < ly; i++){
        for(int m = 0; m < lx; m++){
            cout << result[i][m];
        }
        cout << endl;
    }

    return 0;
}