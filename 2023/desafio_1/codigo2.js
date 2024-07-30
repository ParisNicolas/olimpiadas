let primos = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71]; //, 73, 79, 83, 89, 97];

//Variable de debug para saber que multiplos encontro 
let multiplos = [];


//Funcion recursiva para encontrar el Multiplo mas grande utilizando los numeros primos
function cadenas(a){
    multiplos.push(a);
    //CASO BASE
    if(a==1){
        return 1;
    }

    //CASO RECURSIVO
    let sum = a;
    for(let n = 0; n<primos.length; n++){ 
        if(a % primos[n] == 0){
            //sum += a/primos[n]; --> no hace falta ya lo suma "let sum = a" dentro de la recursividad
            sum += cadenas(a/primos[n]);
            return sum
        }
    }
    console.log("CONSEGIENDO MAS NUMEROS PRIMOS:")
    while(!(a % primos[primos.length-1] == 0)){
        console.log("-"+otroPrimo());
    }
    console.log("MULTIPLO ENCONTRADO: "+primos[primos.length-1]);
    sum += cadenas(a/primos[primos.length-1]);
    return sum
}


//Funcion encargada de encontrar mas numeros primos si es necesario
//Basicamente empieza donde termino el ultimo primo obtenido y divide el sigiente numero por todos los anteriores, si no es divisible, es primo.
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

//RESULTADOS
console.log("\n_" + cadenas(100000000000000000000) + "_ Es el resultado");
console.log(multiplos);