let primos = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71];
function otroPrimo(){
    return "s";
}

function min_divisor(N){
    if(N==1){
        return 1;
    }

    let i = 0;
    while(i < primos.length){
        
        if(N%primos[i] == 0){
            return N + min_divisor(N/primos[i]);
        } 
        i++;
    }
    return otroPrimo();
}

console.log(min_divisor(6));