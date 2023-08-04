let text = "hola3";

function lenght(t){
    if(1 == t.length){
        return 1;
    }

    return 1 + lenght(t.slice(1));
}

console.log(lenght(text));
