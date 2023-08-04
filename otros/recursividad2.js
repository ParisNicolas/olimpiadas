let array = [7,6,3,4,1,5];

function order(arr, n){
    if(arr.length - n < 1){
        return arr;
    }

    
    return order(maxToEnd(arr, n+1), n+1); 
}

function maxToEnd(arr, n){
    let i = 0;
    while(i<arr.length - n){
        if(arr[i] > arr[i+1]){
            let aux = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = aux;
        }
        i++;
    }
    return arr;
}

console.log(order(array, 0));