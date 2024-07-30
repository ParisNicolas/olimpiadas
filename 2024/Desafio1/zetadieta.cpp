#include <iostream>

using namespace std;

long zetadieta(int C, int P, int G){
    long cant_banana = C/27;
    long cant_atun = P/30;
    if (C%27 != 0) cant_banana++;
    if (P%30 != 0) cant_atun++;

    long cal_banana = cant_banana*105;
    long cal_atun = cant_atun*120;
    long cal_aceite = G*9;

    return cal_banana + cal_atun + cal_aceite;
}

int main(){
    int C, P, G;
    cin >> C >> P >> G;
    long result = zetadieta(C,P,G);

    cout << "La persona ingerira " << result << " calorias";
    return 0;
}