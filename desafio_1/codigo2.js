let primos = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71]; //, 73, 79, 83, 89, 97];



function cadenas(a){
    if(a==1){
        return 1;
    }

    let sum = a;
    for(let n = 0; n<primos.length; n++){ 
        if(a % primos[n] == 0){
            //sum += a/primos[n];
            sum += cadenas(a/primos[n]);
            return sum
        }
    }
    console.log("Mutiplo no encontrado")
}

function otroPrimo(){
    let prim = true;
    for(let m = primos[primos.length-1]; m<1000000; m++){
        for(let n = 0; n<primos.length; n++){ 
            if(m % primos[n] == 0){
                prim=false;
            }
        }
        if(prim){
            primos.push(m);<    z<
            return m
        } 
        prim=true;
    }
}

console.log(cadenas(60));
console.log(otroPrimo());