#include <iostream>
#include <vector>

using namespace std;

void procesaMatriz(vector<vector<int> > matriz, vector<long long> &resultadoEnArreglo, vector<vector<long long> > &resultadoEnMatriz)
{

    long long sum=0, mult=1, max, min;
    max = min = matriz[0][0]; 
    
    int num;
    for (int i = 0; i < int(matriz.size()); i++)
    {
        for (int j = 0; j < int(matriz[0].size()); j++)
        {
            num = matriz[i][j];
            sum += num;
            mult *= num;
            if(num > max) max = num;
            if(num < min) min = num;
        }
    }
    
    resultadoEnArreglo.resize(4);
    resultadoEnArreglo[0] = sum;
    resultadoEnArreglo[1] = mult;
    resultadoEnArreglo[2] = max;
    resultadoEnArreglo[3] = min;
    resultadoEnMatriz.resize(2, vector<long long>(2, 0));
    resultadoEnMatriz[0][0] = sum;
    resultadoEnMatriz[0][1] = mult;
    resultadoEnMatriz[1][0] = max;
    resultadoEnMatriz[1][1] = min;
}
