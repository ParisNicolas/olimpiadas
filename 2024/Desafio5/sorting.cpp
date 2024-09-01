#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortWithOneSegment(vector<int> arr, int n, int &inicio, int &fin){
    bool cambio = false;
    for(int i = 0; i<n; i++){
        //Empieza el segmento
        if(arr[i] > arr[i+1] && !cambio){
            cambio = true;
            inicio = i;
        }

        //Termina el segmento
        if(arr[i] < arr[i+1] && cambio){
            fin = i;
            break;
        }
    }

    reverse(arr.begin() + inicio, arr.begin() + fin + 1); 

    return is_sorted(arr.begin(), arr.end());
}

int main(){
    int inicio=0, fin=0;
    int n;
    cout << "Ingrese la cant de numeros del arreglo\n";
    cin >> n;


    vector<int> arr(n);
    cout << "\nIngrese los elementos:\n";
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

   if(sortWithOneSegment(arr, n, inicio, fin)){
        cout << endl << "yes" << endl;
        cout << inicio << " " << fin << endl;
   }else{
        cout << endl << "no" << endl;
   }

    return 0;
}