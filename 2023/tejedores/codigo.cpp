#include <iostream>
#include <fstream>

using namespace std;

int tejedores(int, int*);
int N;
int main(){
    ifstream inputFile("codigo.in");

    int K;
    int t[N];
    inputFile >> N >> K;
    for (int i = 0; i < N; i++) 
        inputFile >> t[i];
    inputFile.close();

    tejedores(K, t);

    return 0;
}

int tejedores(int K, int* t){
    int max;
    int average;
    for (int i = 0; i < N; i++)
        average += t[i];
        average /= K;
    
    int sum = t[0];
    for (int i = 0; i < N; i++){
        if(sum >= average){
            if(sum > max) max=sum;
        }
        else{
            sum+=
        }
    }

    return 0;
}