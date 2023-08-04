#include <iostream>
#include <string>

using namespace std;

int primos[100000] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71}; //, 73, 79, 83, 89, 97];


//Funcion recursiva para encontrar el Multiplo mas grande utilizando los numeros primos
int cadenas(int a){
    //CASO BASE
    if(a==1){
        return 1;
    }

    //CASO RECURSIVO
    int sum = a;
    for(int n : primos){ 
        if(a % n == 0){
            sum += cadenas(a/n);
            return sum;
        }
    }
    cout << "error";
    return 0;
}

int main (){
    //RESULTADOS
    cout << cadenas(60) << endl;
}
