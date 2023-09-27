#include <iostream>
#include <string>
#include <vector>

using namespace std;

int adivina();

int secreto;
string preguntar(int pregunta) {
    if(pregunta < secreto) return "menor";
    if(pregunta > secreto) return "mayor";
    if(pregunta == secreto) return "igual";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> secreto;
    cout << adivina() << "\n";
}
