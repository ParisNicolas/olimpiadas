//Cifrado cesar modificado

//N --> son los digitos de la clave
//La clave son una serie de desplazamientos (ej: 421)
//La clave se aplica secuencialmente al texto

//Por ejemplo tenes hola y se aplica el desplazamiento
//A "h" se aplica 4, a "o" el 2, a "l" el 1 y a "o" de nuevo 4


//=====================================
//Definiendo datos
let N = 3;
let key = "012";
let T = 34;
let text = "YO HE LOGRADO ENCENDER UNA CERILLA";
text = text.split(/\s+/).join('');


let alphabet = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","U","V","W","X","Y","Z"];


function encode(){
    //Revisar entrada
    if(!(N >= 1 && N <=9)){
        console.log("Longitud de clave no aceptada"); 
        return
    }
    if(!(T >= 1 && N <=10000)){
        console.log("Longitud de palabra no aceptada"); 
        return
    }

    let out = "";

    //Recorrer letras
    for(let i = 0; i<text.length; i++){
        //Letra a modificar y nuevo indice segun el desplazamiento correspondiente
        let letter = text[i];
        let newIndex = (Number(key[(i%N)]) + alphabet.indexOf(letter))%25;

        //Nueva letra
        let newLetter = alphabet[newIndex];
        out += newLetter;
    }

    return out;
}

console.log(encode());