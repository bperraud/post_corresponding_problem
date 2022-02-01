class Instance {
    constructor(size, width, alphabet, pairs) {
    this.size = size;
    this.width = width;
    this.alphabet = alphabet;
    this.pairs = pairs;
    }

    isSolvable(){
        return 1;
    }
}

class Pair {
    constructor(top, bottom){
    this.top = top;
    this.bottom = bottom;  
    }  
}
    
class Solution {
    constructor(pairs){
        this.pairs = pairs;
    }

    //ajoute a la fin de la liste
    push() {

    }

    //enchange un bloc à l'indice index avec un autre
    swap(index, pair){

    }

    //supprime un bloc à l'indice index
    delete(index){

    }

    isWon() {
        return 1;
    }
}
    
let first = new Instance(2, 2, new Pair("10", "1"));
    
console.log(first.size);
