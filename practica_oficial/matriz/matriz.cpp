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
    
    resultadoEnArreglo[0] = sum;
    resultadoEnArreglo[1] = mult;
    resultadoEnArreglo[2] = max;
    resultadoEnArreglo[3] = min;
    resultadoEnMatriz.resize(2);
    resultadoEnMatriz[0].push_back(sum);
    resultadoEnMatriz[0].push_back(mult);
    resultadoEnMatriz[1].push_back(max);
    resultadoEnMatriz[1].push_back(min);
}
