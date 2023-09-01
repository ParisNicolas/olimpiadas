#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool binarySearch(vector<int> arr, int N){
    int middle = arr.size()/2;
    int middleNum = arr[middle];

    if(middleNum == N) return true;
    if(middle == 0) return false;
   
    if(middleNum > N){
        vector<int> mitad(arr.begin(), arr.begin() + middle);
        return binarySearch(mitad, N);
    }
    else{
        vector<int> mitad(arr.begin() + middle, arr.end());
        return binarySearch(mitad, N);
    }
    
}

int main() 
{
    vector<int> arr = {2,4,13,8,0,17,1};

    sort(arr.begin(), arr.end());

    if(binarySearch(arr, 1)) cout << "encontrado" << endl;
    else cout << "no encontrado" << endl;
    return 0;
}