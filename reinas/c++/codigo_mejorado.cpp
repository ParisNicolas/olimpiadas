#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;




int main(){
    ifstream inputFile("reinas.in");
    ofstream ouputFile("reinas.out");

    int N, M;
    inputFile >> N >> M;


    vector<vector<int>> tablero(N, vector<int>(N));
    vector<pair<int, int>> reinas(M);
    
    
    for (int i = 0; i < M; i++){
        int x,y;
        inputFile >> y >> x;
        
        reinas[i] =  {x, y};
        tablero[y-1][x-1] = i+1;
    }

    
/*
    for (int i = 0; i < N; i++)
    {
        for (int n = 0; n < N; n++)
        {
            cout << tablero[i][n] << ' ';
        }
        cout << endl;
        
    }*/
    

    vector<vector<int>> conflicts(M);
    for (int i = 0; i < M; i++){
        int col = reinas[i].first-1;
        int row = reinas[i].second-1;

        for(int s=-1; s<=1; s+=2){
            for(int x=col+s; x<N && x>=0; x+=s){
                if(tablero[row][x]){
                    conflicts[i].push_back(tablero[row][x]);
                    break;
                }
            }
            for(int y=row+s; y<N && y>=0; y+=s){
                if(tablero[y][col]){
                    conflicts[i].push_back(tablero[y][col]);
                    break;
                }
            }
            for(int d=-1; d<=1; d+=2){
                int x = col+d;
                int y = row+s;
                while(y<N && y>=0 && x>=0 && x<N){
                    if(tablero[y][x]){
                        conflicts[i].push_back(tablero[y][x]);
                        break;
                    }
                    x+=d;
                    y+=s;
                }
            }
        }
        
    }

    for (int i = 0; i < M; i++){
        ouputFile << conflicts[i].size() << ' ';
        for(int c = 0; c<conflicts[i].size(); c++){
            //<< ' ' << conflicts[i][c]
            ouputFile << conflicts[i][c] << ' ';
        }
        ouputFile << '\n';
    }
    
    return 0;    
}