"use strict";
import Pair from './Pair.js';
import Instance from './Instance.js';
import Solution from './Solution.js';
import promptSync from 'prompt-sync';
const prompt = promptSync();



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
        let input = prompt();
        while (!this.isInputValid(input)){
            console.log("Invalid syntax, please try again :")
            input = prompt();
        }
        this.play(input);

    }

    play(input){
        if (input[0]=='+'){
            let index = parseInt(input.slice(1));
            this.solution.push(index);
            console.log("++");
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
            console.log('\n \n \n')

        }   
    }
}

let pair1 = new Pair('aa','bb')
let pair2 = new Pair('bb','cc')
let pair3 = new Pair('aa','kk')

let inst = new Instance(3,3, [pair1, pair2, pair3]);
let game = new Game(inst);
game.gameLoop();