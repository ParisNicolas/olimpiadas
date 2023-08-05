#include <iostream>
#include <string>
#include <vector>

using namespace std;

//int primos[100000 ];
vector<int>  primos = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71}; //, 73, 79, 83, 89, 97};
vector<int> multiplos;

int otroPrimo(){
    bool prim = true;
    for(int m = primos[primos.size()-1];; m++){
        for(int n = 0; n<primos.size()/3; n++){ 
            if(m % primos[n] == 0){
                prim=false;
            }
        }
        if(prim == 1){
            primos.push_back(m);
            return m;
        } 
        prim=true;
    }
}

//Funcion recursiva para encontrar el Multiplo mas grande utilizando los numeros primos
int cadenas(int a){
    multiplos.push_back(a);
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
    cout << "CONSEGIENDO MAS NUMEROS PRIMOS:" << endl;
    while(!(a % primos[primos.size()-1] == 0)){
        cout << "-" << otroPrimo() << endl;
    }
    return sum;
    cout << "MULTIPLO ENCONTRADO: " << primos[primos.size()-1] << endl;
    sum += cadenas(a/primos[primos.size()-1]);
    return sum;
}

int main (){
    //RESULTADOS
    cout << cadenas(485) << endl;
    cout << '[';
    for(int m : multiplos){
        cout << m <<','; 
    }
    cout << ']';
}
