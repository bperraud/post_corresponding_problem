class Instance {
    constructor(size, width, alphabet, pairs) {
    this.size = size;
    this.width = width;
    this.alphabet = alphabet;
    this.pairs = pairs; // liste des blocs (ordre pas important + pas de duplication)
    }

    getSize(){
        return this.size;
    }

    getPairs(){
        return this.pairs;
    }

    // 1 si l'instance possède une solution, 0 sinon, -1 si on ne sait pas
    isSolvable(){
        
    }
}

// un bloc
class Pair {
    constructor(top, bottom){
    this.top = top;     // string (ou mot) du dessus
    this.bottom = bottom;   // string du dessous
    }

    getTop(){
        return this.top;
    }

    getBottom(){
        return this.bottom;
    }
}
    

class Solution {
    constructor(pairs){
        this.pairs = pairs; // liste des blocs (ordre important + duplication possible)
    }

    // ajoute à l'indice index dans la liste
    add(index, pair) {
        let tempPair = this.pairs[index];
        this.pairs[index] = pair;
        this.pairs.push(tempPair);        
    }

    //ajoute a la fin de la liste
    push(pair) {    // 
        this.pairs.push(pair);
    }

    //enchange un bloc à l'indice index avec un autre
    swap(index1, index2){
        let pair1 = this.pairs[index1];
        let pair2 = this.pairs[index2];
        this.pairs[index1] = pair2;
        this.pairs[index2] = pair1;
    }

    //supprime un bloc à l'indice index
    delete(index){ // On a le droit de supprimer ?

    }

    // 1 si la liste this.pairs forme une solution du problème de Post, 0 sinon
    isWon() {
        let top="";
        let bottom="";
        for (i=0;i<this.size;i++){
            let currentPair = this.pairs[i];
            top += currentPair.getTop();
            bottom += currentPair.getBottom();
        }
        return top == bottom;
    }
}
    
let first = new Instance(2, 2, new Pair("10", "1"));
    
console.log(first.size);
