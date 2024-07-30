#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

int main(){
    vector<int> hola = {1,2,4321,5,7,6,9};
    
    stack<int> bob;
    bob.push(3);
    bob.push(4);
    bob.push(5);
    cout << "Pila: " << bob.top() << endl;

    queue<int> cuco;
    cuco.push(3);
    cuco.push(4);
    cuco.push(5);
    cout << "Cola: "  << cuco.front() << endl;

    int a=3,b=2;
    a.swap(b);
    cout << a << b << endl;

    cout << hola.size() << endl;
    return 0;
}