#include <string>
#include <vector>

using namespace std;

string preguntar(int i);

int adivina() {
    int num = 5;
    string res;
    while(true){
        res = preguntar(num);
        if (res == "igual") 
            return num;
        else if (res == "mayor") 
            num ++;
        else 
            num--;
    }
}
