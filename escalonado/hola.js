let sum = 0;
            //4,3,2,1,0 posiciones
//let digits = [3,4,2,8,2].reverse(); //numero 34.282
let digits = [1,9,0].reverse();


/*
N=8 --> s = 1 mini
N=7 --> s = 2 peque
N=6 --> s = 3 ciclo
N=5 --> s = 4 hiperciclc

R --> Limitante (default hasta 1)
*/
function sumer(n, s, R = 0){
    //Casos Base
    if(n==1 || s<1){
        return n;
    }else if(R==1){
        return sumer(n, s-1);
    }

    //Casos recursivos
    return sumer(n, s-1) + sumer(n-1, s, R-1);
}

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