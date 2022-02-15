export default class Instance {
    constructor(size, width, pairs) {
    this.size = size;
    this.width = width;
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

    displayPairs(){
        for(let i=0; i<this.size; i++){
            process.stdout.write(`| ${this.pairs[i].getTop() + this.pairs[i].getTopPad()} |`)
        }

        console.log()
        for(let i=0; i<this.size; i++){
            process.stdout.write(`| ${this.pairs[i].getBottom() + this.pairs[i].getBottomPad()} |`)
        }
        console.log()
    }
}
