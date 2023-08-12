let sum = 0;
            //4,3,2,1,0 posiciones
//let digits = [3,4,2,8,2].reverse(); //numero 34.282
let digits = [1,3,0].reverse();

let nulFunc = (a,b,c)=> a;

function escalone(n){
    if(n==0)
    sumer(7, 0, sumer);
}

function sumer(n, R = 0, F = nulFunc, s){
    if(n==1 || R>=1){
        return F(n);
    }
    return F(n) + sumer(n-1, R-1, F);
}

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
console.log(sum);
//console.log(sumer(7, 0, sumer));