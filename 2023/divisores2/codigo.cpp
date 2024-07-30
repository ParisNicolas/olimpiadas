#include <iostream>
#include <vector>

using namespace std;

vector<int>  primos = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71}; //, 73, 79, 83, 89, 97};

int otroPrimo(){
    bool prim = true;
    for(int m = primos.back();; m++){
        for(int n = 0; n<primos.size()/2; n++){ 
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


//suma de divisores alta
int min_divisors(int N){ 
    if(N==1) return 1;

    int i = 0;
    while(i < primos.size()){
        if(primos[i] > N) break;
        if(N%primos[i] == 0){
            return N + min_divisors(N/primos[i]);
        }
        i++;
    }
    cout << "Buscando mas primos" << endl;
    while(N%otroPrimo() != 0);
    return N + min_divisors(N/primos.back());
}

int max_divisors(int N){
    if(N==1) return 1;

    int i = primos.size()-1;
    while(i >= 0){
        if(primos[i] > N/2 && primos[i] != N) {i--;continue;}
        if(N%primos[i] == 0){
            return N + max_divisors(N/primos[i]);
        }
        i--;
    }
    return 0;
}


int main(){

    int n = 379;

    while(n%otroPrimo() != 0);
    cout << primos.back();

    while(primos.back() < n/3){
        otroPrimo();
    }

    cout << endl << min_divisors(n) << endl;
    cout << max_divisors(n) << endl;

    return 0;
}