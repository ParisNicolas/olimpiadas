#include <iostream>
#include <string>
#include <vector>

using namespace std;

int nulFunc(int a) {return a;}

int sumer(int n, int R = 0, int (* F)(int) = nulFunc){
    if(n==1 || R==1){
        return n;
    }
    return F(n) + sumer(n-1, R-1);
}

int main (){

    cout << sumer(8,0) << endl;

    return 0;
}