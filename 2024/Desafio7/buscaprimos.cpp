#include <iostream>
#include <string>
#include <vector>

using namespace std;


//Criba de Eratostenes para encontrar los numeros primos de 2 a 10000
vector<bool> criba (int n){
    //Vector de booleanos
    vector<bool> es_primo(n+1, true);

    //Inicializacion
    es_primo[0] = es_primo[1] = false;

    //Recorrer todos los numeros desde 2 a la raiz de
    for (int i = 2; i*i <= n; i++){
        if(es_primo[i]){
            //Si es primo, marco como falso todos sus multiplos
            for(int j = i*i; j <= n; j += i){
                es_primo[j] = false;
            }
        }
    }
    return es_primo;
}


vector<int> buscaprimos(string &s){
    //Saco los primos de 2 a 9999
    vector<bool> primos = criba(9999);

    size_t longitud = s.length();
    vector<int> res(4, 0);

    //Subcadenas de 1,2,3,4 digitos
    for(size_t i = 1; i<=4;i++){

        //Reccorro todas las subcadenas posibles
        for(size_t j = 0; j+i <= longitud; j++){
            int K = stoi(s.substr(j, i));
            if(primos.at(K)) res[i-1]++;
        }
    } 

    return res;
}

int main(){

    string s = "";
    cin >> s;

    //Arreglo de 4 elementos con los resultados
    vector<int> res = buscaprimos(s);

    cout << res[0] << res[1] << res[2] << res[3];

    return 0;
}
