#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)

string procesatexto(string texto, vector<string> comandos){
    for(string comando : comandos){
        if(comando == "INTERCAMBIA"){
            for(char& c : texto){
                if(isupper(c)){
                    c = tolower(c);
                }
                else if(islower(c)){
                    c = toupper(c);
                }  
            }
        }

        if(comando == "BORRAULTI"){
            if(!texto.empty()){
                texto.pop_back();
            }
        }

        if(comando == "BORRAPRI"){
            if(!texto.empty()){
                texto.erase(0, 1);
            }
        }

        if(comando == "DUP"){
            texto += texto;
        }

        if(comando == "ROTA"){
            if(!texto.empty()){
                texto.push_back(texto[0]);
                texto.erase(0,1);
            }
        }

        if(comando == "INVERTIR"){
            reverse(texto.begin(), texto.end());
        }

        if(comando == "CHAUAGUS"){
            string auxText = texto;
            for(char& c : auxText){
                c = tolower(c);
            }
            size_t pos = auxText.find("agus");
            
            if(pos != string::npos){
                texto.erase(pos, 4);
            }
        }

        if(comando.compare(0, 7, "AGREGA-")){
            texto += comando.substr(7);
        }

        if(comando.compare(0, 4, "DUP-")){
            size_t second_dash = comando.find('-', 4);

            size_t i = stoi(comando.substr(4, second_dash-5));
            size_t j = stoi(comando.substr(second_dash+1));

            texto.insert(j, texto.substr(i-1, j-i-1));
        }

        if(comando.compare(0, 9, "INVERTIR-")){
            
        }

        if(comando.compare(0, 6, "BORRA-")){
            
        }

        if(comando.compare(0, 5, "CHAU-")){
            
        }
    }


    return texto;
}

int main(){
    /*
    string texto; cin >> texto;

    int T; cin >> T;

    vector<string> comandos(T);

    forn(i,T){
        cin >> comandos[i];
    }*/

   string texto = "xxabcefyy";
   //vector<string> comandos = {"INVERTIR", "CHAUAGUS","INVERTIR", "CHAUAGUS", "BORRA-24", "BORRAULTI", "INVERTIR", "BORRAULTI", "INTERCAMBIA", "INVERTIR"}

    vector<string> comandos = {"AGREGAR"};
    cout << endl << procesatexto(texto, comandos) << endl;

    return 0;
}