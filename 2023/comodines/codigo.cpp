#include <iostream>
#include <vector>
#include <utility> //para std::pair (pares de datos (x,y))

using namespace std;

typedef vector<vector<int>> vvi;
typedef pair<int, int> prii;

prii comodines();//int, int, vvi&
int expandVirus(int, int, int);//int, int, vvi&


const int N=10, M=10;
vvi arr = {
        {2, 4, 5, 3, 0, 4, 2, 4, 5, 0},
        {0, 4, 5, 1, 1, 4, 3, 0, 4, 2},
        {2, 4, 5, 0, 4, 5, 2, 4, 5, 0},
        {0, 4, 5, 3, 0, 4, 2, 4, 5, 0},
        {2, 4, 5, 1, 1, 4, 3, 0, 4, 2},
        {2, 4, 5, 3, 0, 4, 2, 4, 5, 0},
        {2, 4, 5, 3, 0, 4, 2, 4, 5, 0},
        {2, 4, 5, 3, 0, 4, 2, 4, 5, 0},
        {2, 4, 5, 3, 0, 4, 2, 4, 5, 0},
        {2, 4, 5, 3, 0, 4, 2, 4, 5, 0}};

vvi visited(N, vector<int>(M, 0));
vector<pair<int, int>> zeros;

int main(){
    /*
    cin >> N >> M;

    vvi grilla(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grilla[i][j];
        }
    }
    
    */
    prii result = comodines();
    cout << "Result: " << result.first << endl;
    cout << "Number: " << result.second << endl;

    return 0;
}


//, int N, int M, vvi& arr
int expandVirus(int x, int y, int cardNum){
    if(x<0 || x>=M || y<0 || y>=N) return 0;
    if(visited[y][x]) return 0;
    if(arr[y][x] != cardNum && arr[y][x] != 0) return 0;

    if(arr[y][x] == 0) zeros.push_back(make_pair(x, y));
    visited[y][x] = true;
    int numOfCards = 1;

    numOfCards += expandVirus(x+1, y, cardNum);
    numOfCards += expandVirus(x-1, y, cardNum);
    numOfCards += expandVirus(x, y+1, cardNum);
    numOfCards += expandVirus(x, y-1, cardNum);

    return numOfCards;
}

//int N, int M, vvi& grilla
prii comodines(){ 

   prii maxCardNum = {0, 0};

    for(int y = 0; y < N; y++){
        for(int x = 0; x < M; x++){
            int num = arr[y][x];
            int result = expandVirus(x, y, num);
            if(result > maxCardNum.first){
                maxCardNum.first=result;
                maxCardNum.second=num;
            }
            for(int i=0; i<zeros.size(); i++){
                visited[zeros[i].first][zeros[i].second] = false;
            }
            zeros.clear();
        }
    }
    return maxCardNum;
}
