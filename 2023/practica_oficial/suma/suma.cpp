#include <vector>

using namespace std;

long long suma(vector<int> v)
{
   // Aqui se debe implementar la funcion pedida en el enunciado
   //int size = v.size(); Ayuda una milesima en la optimizacion del codigo
   long long suma = 0;
   for(int i=0;i<int(v.size());i++) suma+=v[i];
   return suma;
}
