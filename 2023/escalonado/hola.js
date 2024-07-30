let sum = 0;
            //4,3,2,1,0 posiciones
//let digits = [3,4,2,8,2].reverse(); //numero 34.282
let digits = [1,2,0,9];


/*
N=8 --> s = 1 mini
N=7 --> s = 2 peque
N=6 --> s = 3 ciclo
N=5 --> s = 4 hiperciclc

R --> Limitante (default hasta 1)
*/
function sumer(n, s, R = -1){
    //Casos Base
    if(R==0) return R; //n == 9? Creo que no hace falta
    if(n==1 || s<1) return n;
    if(R==1){
        return sumer(n, s-1);
    }

    //Casos recursivos
    return sumer(n, s-1) + sumer(n-1, s, R-1);
}

function sumer(n, s, R = [-1]){
    //Casos Base
    if(R.length==1 && R[0] >= 0) return R[0]; //n == 9? Creo que no hace falta
    if(n==1 || s<1) return n;

    //Casos recursivos
    let suma = 0;
    if(R[0]!=0) suma += sumer(n, s-1); //Si las R no son 0 suma su ultimo recorrido normal
    if(R[0]==0 || R[0]==1){ //Si las R son 0 o 1 prepara para continuar con el siguiente bucle limitado (nueva R y profundidad-1)
        R.shift();
        s--;
    }
    else R[0]--; //Caso normal sigue restando a las repeticiones
    
    return suma + sumer(n-1, s, R);
}

let cicles = []; 
const lenght = digits.length;
let fillZero = false;
for(let i = 0; i < lenght; i++){
    if(fillZero){
        if(i >= lenght-3){
            cicles.push(0);
        }else{
            cicles.push(1);
        }
        
        continue;
    }

    if(lenght == 1){
        console.log("Numero menor a 10");
        cicles.push(0);
        break;
    }

    //Anterior mayor al siguiente, cadena rota
    if(digits[i]<=digits[i-1]){
        cicles.push(0);
        fillZero = true; //Rellenar con 1 los demas
        continue;
    }

    //Primer digito
    if(i == 0){
        if(lenght == 2){
            cicles.push(digits[i]-1);
        }else{
            cicles.push(digits[i]);
        }
    }
    else{
        let rest = digits[i]-digits[i-1];
        //Si es el ultimo digito
        if(i == lenght-1){
            cicles.push(rest);
        }else{
            cicles.push(rest-1); //-1
        }
        
    }
}

console.log(cicles);

if(lenght == 2){
    sum += sumer(8, 1, cicles);
}else{
    sum += sumer(8, lenght-1, cicles); //11-lenght
}
console.log(sum);

//329