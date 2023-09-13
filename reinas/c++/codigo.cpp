#include <iostream>
#include <fstream>
/*
#include <vector>
#include <utility>
*/

using namespace std;

int N, M;
struct coordenadas
{
    int x;
    int y;
};


int main(){
    ifstream inputFile("reinas.in");
    ofstream ouputFile("reinas.out");

    inputFile >> N >> M;
    

    int tablero[N][N] = {};
    coordenadas reinas[M];
    for (int i = 0; i < M; i++){
        int x,y;
        inputFile >> y >> x;
        reinas[i].x = x;
        reinas[i].y = y;
        tablero[y][x] = i+1;
    }

    int conflicts[M][8]; 
    int numOfConflicts[M];


    for (int i = 0; i < M; i++){
        int col = reinas[i].x-1;
        int row = reinas[i].y-1;
        int numConflicts = 0;

        for(int s=-1; s<=1; s+=2){
            for(int x=col+s; x<N && x>=0; x+=s){
                if(tablero[row][x]){
                    conflicts[i][numConflicts++] = tablero[row][x];
                    break;
                }
            }
            for(int y=row+s; y<N && y>=0; y+=s){
                if(tablero[y][col]){
                    conflicts[i][numConflicts++] = tablero[y][col];
                    break;
                }
            }
            for(int d=-1; d<=1; d+=2){
                int x = col+d;
                int y = row+s;
                while(y<N && y>=0 && x>=0 && x<N){
                    if(tablero[y][x]){
                        conflicts[i][numConflicts++] = tablero[y][x];
                        break;
                    }
                    x+=d;
                    y+=s;
                }
            } 
        }
        numOfConflicts[i] = numConflicts;
    }

    for (int i = 0; i < M; i++){
        ouputFile << numOfConflicts[i] << ' ';
        for(int c = 0; c<numOfConflicts[i]; c++){
            ouputFile << conflicts[i][c] << ' ';
        }
        ouputFile << '\n';
    }
    
    


    return 0;    
}

//int* findConflicts(const bool& tablero[N][N], coordenadas*);