let sum = 0;
            //4,3,2,1,0 posiciones
//let digits = [3,4,2,8,2].reverse(); //numero 34.282
let digits = [1,9,4];


/*
N=8 --> s = 1 mini
N=7 --> s = 2 peque
N=6 --> s = 3 ciclo
N=5 --> s = 4 hiperciclc

R --> Limitante (default hasta 1)
*/
function sumer(n, s, R = -1){
    //Casos Base
    if(R==0 || n==9) return R; //n == 9?
    if(n==1 || s<1) return n;
    if(R==1){
        return sumer(n, s-1);
    }

    //Casos recursivos
    return sumer(n, s-1) + sumer(n-1, s, R-1);
}

let cicles = [];
for(let i = 0; i < digits.length; i++){
    if(i == digits.length-1 || i == digits.length-2){
        let base = 9-digits.length+i;
    let recursivity = digits.length-1-i;
    }
    let base = 11-digits.length+i;
    let recursivity = digits.length-1-i;
    if(i == digits.length-1 || i == digits.length-2) base--; //Artimaña para que funcione con los ultimos digitos que dan problemas
    
    //En caso de que sea mayor a su numero maximo de repeticiones se trunca a ese numero
    if(digits[i] > base && digits.length != 2){
        digits[i] = base;
    }

    //En caso de que los demas sean numeros no compatibles para una escalera se descartan
    //El siguiente es mas pequeño
    if(digits[i]<=digits[i-1]){
        break; //Ceros los demas
    }
    
    //Si es el primo lo pone directo
    //Si es otro lo sube restando el anterior y 1 para que solo haga con 57 y no 56
    //Si es el ultimo solo lo resta
    if(i != 0){
        let rest = digits[i]-digits[i-1];
        
        if(i == digits.length-1){
            cicles.push([base, recursivity, rest]);
        }else{
            cicles.push([base, recursivity, rest-1]);
        }
    }
    else{
        if(digits.length == 2){
            cicles.push([base, recursivity, digits[i]-1]);
        }else{
            cicles.push([base, recursivity, digits[i]]);
        }
    }
}

console.log(cicles);

cicles.map((d)=>{
    sum += sumer(d[0], d[1], d[2]);
});
console.log(sum);

/*
let cicles = digits.map((dig, i)=>{
    let d;
    if(dig <= 9-i){
        d = dig;
    }else{
        d = 9-i;
    }
    let rest = d-digits[i+1];

    if(i === digits.length-1){
        return d;
    }
    if(rest >=0 && i === 0){
        return rest;
    }
    else if(rest > 1){
        return rest-1;
    }
    else{
        return 0;
    }
    
});
console.log(cicles);

digits.map((d,i)=>{
    if(i == 0 && d>digits[i+1]){
        sum += d-digits[i+1];
    }
    else if (i==1 && d-1>digits[i+1]){
        sum += sumer(8, d-digits[i+1]);
    }
    else if (i==2){
        sum += sumer(7, d, sumer);
    }
    else if (i==3){
        for(let i = 6; i>=1; i--){
            sum += sumer(i, d, sumer);
        }
    }
});
console.log(sum);*/
//console.log(sumer(7, 0, sumer));*/