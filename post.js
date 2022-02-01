class Instance {
    constructor(size, width, alphabet, pairs) {
    this.size = size;
    this.width = width;
    this.alphabet = alphabet;
    this.pairs = pairs; // liste des blocs (ordre pas important + pas de duplication)
    }

    // 1 si l'instance possède une solution, 0 sinon, -1 si on ne sait pas
    isSolvable(){
        return 1;
    }
}

// un bloc
class Pair {
    constructor(top, bottom){
    this.top = top;     // string (ou mot) du dessus
    this.bottom = bottom;   // string du dessous
    }  
}
    
class Solution {
    constructor(pairs){
        this.pairs = pairs; // liste des blocs (ordre important + duplication possible)
    }

    // ajoute à l'indice index dans la liste
    add(index) {

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

    // 1 si la liste this.pairs forme une solution du problème de Post, 0 sinon
    isWon() {
        return 1;
    }
}
    
let first = new Instance(2, 2, new Pair("10", "1"));
    
console.log(first.size);
