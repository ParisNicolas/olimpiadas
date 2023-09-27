#include <vector>
#include <string>

using namespace std;

vector<int> dameLongitudes(vector<string> v)
{
    // Aqui se debe implementar la solucion
    vector<int> longitudes(v.size());

    for(int i=0; i<int(v.size());i++)
        longitudes[i] = v[i].size();

    return longitudes;
}
