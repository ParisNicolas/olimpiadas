#include <vector>
#include <iostream>

using namespace std;

int thor(vector<int> a, vector<int> f, vector<int> p, int D)
{
    int combinaciones = 0;

    for (int i = 0; int(a.size()); i++)
    {
        int objVal = (a[i]*f[i])/D;
        for(int j = 0; int(p.size()); j++){
            if(p[j] <= objVal) 
                combinaciones++;
        }
    }
    return combinaciones;
}


int main (){
    int n, m, D;
    cin >> n >> m >> D;
    vector<int> a(n);
    vector<int> f(n);
    vector<int> p(m);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> f[i];
    }
    for(int i = 0; i < m; i++){
        cin >> p[i];
    }
    cout << thor(a, f, p, D);

    return 0;
}