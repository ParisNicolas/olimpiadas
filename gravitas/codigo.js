let arr = [['.','.','.','<','>','.','.','.','.'],
           ['<','>','.','.','<','>','.','A','.'],
           ['.','.','<','>','.','A','.','V','.'],
           ['.','.','.','.','.','V','.','.','.'],
           ['.','<','>','.','.','.','.','.','.']];

function move_V(y, x, g){
    g[y][x] = 'A';
    g[y-1][x] = '.';
    g[y+1][x] = 'V';
}
        
function move_H(y, x, g){
    g[y][x] = '.';    g[y+1][x] = '<';
    g[y][x+1] = '.';  g[y+1][x+1] = '>';
}

function gravitas(g){
    for(let y = g.length-2; y >= 0; y--){
        for(let x = 0; x < g[0].length; x++){
            
            if(g[y][x] == '<'){
                let newY = y;
                while(g[newY+1][x] == '.' && g[newY+1][x+1] == '.'){
                    move_H(newY, x, g);
                    newY++;
                    if(newY+1 == g.length) break;
                }
            }
            else if(g[y][x] == 'V'){
                let newY = y;
                while(g[newY+1][x] == '.'){
                    move_V(newY, x, g);
                    newY++;
                    if(newY+1 == g.length) break;
                }
            }
        }
    }
    return g;
}


gravitas(arr).map((l) => {let a=""; l.map((n) => a+=n); console.log(a)});