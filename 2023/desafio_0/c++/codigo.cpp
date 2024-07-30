#include <iostream> //For console output (COUT)
#include <string> //For string type and methods
#include <fstream> //For reading and writing files
#include <algorithm> //For remove_if method

using namespace std;

int main (){
    short N, T, key[9];
    string keyT, text, out;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    //Reading Inputs from file
    ifstream inputFile("codigo.in");
    inputFile >> N >> keyT >> T;
    getline(inputFile >> ws, text);
    inputFile.close();
    
    //Transform keyText into keyArray
    for(int i = 0; i < N; i++){
        key[i] = keyT[i] - '0';
    }

    //Remove spaces
    text.erase(remove_if(text.begin(), text.end(), ::isspace), text.end());

    //Recorrer letras
    for(int i = 0; i<text.size(); i++){
        char letter = text[i];
        char newLetter = alphabet[(key[i%N] +  alphabet.find(letter))%26];
        out += newLetter;
    }

    //cout <<N<<endl <<T<<endl <<key[0]<<key[1]<<endl <<text<<endl;
    ofstream outputFile("codigo.out");
    outputFile << out;
    outputFile.close();
    cout << out;

    return 0;
}