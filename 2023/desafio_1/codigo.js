let primos = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97];


function cadenas(a){
    if(a==1){
        return [];
    }

    let n = 0;
    let mult = [];
    while(n<primos.length){
        if(a%primos[n] == 0){
            mult.push(a/primos[n]);
            mult = mult.concat(cadenas(mult[mult.length-1]));
            return mult
        }
        n++
    }
    console.log("Mutiplo no encontrado")
}

console.log(cadenas(33));