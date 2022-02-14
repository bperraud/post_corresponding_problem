import {Instance, Pair} from 'post';
//import Pair from 'post';


class Game{
    constructor(_instance){
        this.instance = _instance;
        this.solution = new Solution(this.instance.getPairs())

    }

    isInputValid(input){
        if (input[0] == '-'|| input[0]== '+' && !isNaN(input.slice(1))){
            if (parseInt(input.slice(1))<this.instance.getSize()){
                return true;
            }
        }
        return false;
    }

    getUserInput(){
        console.log("Please type a command to construct a solution :")
        const input = prompt()
        while (!this.isInputValid(input)){
            console.log("Invalid syntax, please try again :")
            input = prompt()
        }
        this.play(input);

    }

    play(input){
        if (input[0]=='+'){
            let index = parseInt(input.slice(1));
            this.solution.push(index);
        }
        else if (input[0]=='-'){
            let index = parseInt(input.slice(1));
            this.solution.erase(index);

        }
 
    }

    gameLoop(){
        while (!this.solution.isWon()){
            this.instance.displayPairs();
            this.getUserInput();
            this.solution.displaySolution();
            this.solution.displayResult();

        }
    }
}

let pair1 = Pair('aa','bb')
let pair2 = Pair('bb','cc')
let pair3 = Pair('aa','kk')

let inst = new Instance(3,3, [pair1, pair2, pair3]);
let game = new Game(inst);
game.gameLoop();