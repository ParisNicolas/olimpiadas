#include <vector>
#include <string>

using namespace std;

void duplilong(vector<string> &palabras, int K, vector<int> & longitudes)
{
    for (int i = 0; i < K; i++)
        longitudes[i] = palabras[i].length();
    
    while(K --> 0)
        *(palabras.end()-1-K) += *(palabras.end()-1-K);

    

    /* ASI ERA BONITO PERO AL HACER AL MISMO TIEMPO INFLUIA EN EL RESULTADO DEL OTRO
    while(K --> 0)
    {
        *(palabras.end()-1-K) += *(palabras.end()-1-K);
        longitudes[K] = palabras[K].length();
    }*/
}
