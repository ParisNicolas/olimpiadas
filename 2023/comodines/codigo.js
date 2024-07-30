/*
let arr = [[2,4,5],
           [3,0,4],
           [2,4,5],
           [0,4,5],
           [1,1,4]];
*/

let arr = [
    [2, 4, 5, 3, 0, 4, 2, 4, 5, 0],
    [0, 4, 5, 1, 1, 4, 3, 0, 4, 2],
    [2, 4, 5, 0, 4, 5, 2, 4, 5, 0],
    [0, 4, 5, 3, 0, 4, 2, 4, 5, 0],
    [2, 4, 5, 1, 1, 4, 3, 0, 4, 2],
    [2, 4, 5, 3, 0, 4, 2, 4, 5, 0],
    [2, 4, 5, 3, 0, 4, 2, 4, 5, 0],
    [2, 4, 5, 3, 0, 4, 2, 4, 5, 0],
    [2, 4, 5, 3, 0, 4, 2, 4, 5, 0],
    [2, 4, 5, 3, 0, 4, 2, 4, 5, 0]
];



let visited,zeros = [];

visited = arr.map(() => arr[0].map(() => 0));

function expandVirus(x, y, cardNum){
    if(x<0 || x>=arr[0].length || y<0 || y>=arr.length) return 0;
    if(visited[y][x]) return 0;
    if(arr[y][x] != cardNum && arr[y][x] != 0) return 0;

    if(arr[y][x] == 0) zeros.push([x, y]);
    visited[y][x] = true;
    let numOfCards = 1;

    numOfCards += expandVirus(x+1, y, cardNum);
    numOfCards += expandVirus(x-1, y, cardNum);
    numOfCards += expandVirus(x, y+1, cardNum);
    numOfCards += expandVirus(x, y-1, cardNum);

    return numOfCards;
}

function comodines(){
    let maxCardNum = [0, 0];

    for(let y = 0; y < arr.length; y++){
        for(let x = 0; x < arr[0].length; x++){
            let num = arr[y][x];
            let result = expandVirus(x, y, num);
            if(result > maxCardNum[0]){
                maxCardNum[0]=result;
                maxCardNum[1]=num;
            }
            for (let i in zeros) {
                visited[zeros[i][1]][zeros[i][0]] = false;
            }
            zeros = [];
        }
    }
    return maxCardNum;
}



console.log(comodines());
console.log(visited);
