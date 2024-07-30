let primos = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71]; //, 73, 79, 83, 89, 97];

function otroPrimo(){
    let prim = true;
    for(let m = primos[primos.length-1]; m<1000000; m++){
        for(let n = 0; n<primos.length; n++){ 
            if(m % primos[n] == 0){
                prim=false;
            }
        }
        if(prim){
            primos.push(m);
            return m
        } 
        prim=true;
    }
}

function min_divisor(N){
    if(N==1) return 1;

    let i = 0;
    while(i < primos.length){
        if(primos[i] > N) break;
        if(N%primos[i] == 0){
            return N + min_divisor(N/primos[i]);
        }
        i++;
    }
    while(N%otroPrimo() != 0);
    return N + min_divisor(N/primos[primos.length-1]);
}


function max_divisor(N){
    if(N==1) return 1;

    let i = primos.length-1;
    while(i >= 0){
        if(primos[i] > N/2 && primos[i] != N) {i--;continue;}
        if(N%primos[i] == 0){
            return N + max_divisor(N/primos[i]);
        }
        i--;
    }
    return 0;
}

let n = 3473;
while(primos[primos.length-1] < n/2){
    otroPrimo();
}

console.log(min_divisor(n));
console.log(max_divisor(n));