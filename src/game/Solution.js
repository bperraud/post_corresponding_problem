
export default class Solution {
    constructor(pairs){
        this.pairs = pairs; // liste des blocs (ordre important + duplication possible)
        this.solution = []
    }

    // ajoute à l'indice index dans la liste
    add(index) {
        let tempPair = this.pairs[index];
        this.pairs[index] = pair;
        this.pairs.push(tempPair);        
    }

    //ajoute a la fin de la liste l'element d'indice "index"
    push(index) {    // 
        this.solution.push(index)
    }

    erase(index) {
        this.solution.splice(index,1)
    }

    //enchange un bloc à l'indice index avec un autre
    swap(index1, index2){
        let pair1 = index1;
        let pair2 = index2;
        this.solution[index1] = pair2;
        this.solution[index2] = pair1;
    }

    //supprime un bloc à l'indice index

    isWon() {
        let top="";
        let bottom="";
        for (let i=0;i<this.size;i++){
            let currentPair = this.pairs[i];
            top += currentPair.getTop();
            bottom += currentPair.getBottom();
        }
        return top == bottom && this.pairs.length == this.solution.length;
    }

    displaySolution(){
        for(let i=0; i<this.solution.length;i++){
            process.stdout.write(`| ${this.pairs[this.solution[i]].getTop() + this.pairs[this.solution[i]].getTopPad()} |`)
        }
        console.log()
        for(let i=0; i<this.solution.length; i++){
            process.stdout.write(`| ${this.pairs[this.solution[i]].getBottom() + this.pairs[this.solution[i]].getBottomPad()} |`)
        }
        console.log()
    }

    displayResult(){
        let top = "";
        let bottom = "";
        for (let i = 0; i<this.solution.length; i++){
            top+=this.pairs[this.solution[i]].getTop();
            bottom+=this.pairs[this.solution[i]].getBottom();
        }
        console.log(top);
        console.log(bottom);
    }
}


