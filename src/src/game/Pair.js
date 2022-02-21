export default class Pair {
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

    getTopPad(){
        let pad=""
        if (this.top.length < this.bottom.length){
            pad += ' '.repeat(this.bottom.length - this.top.length)
        }
        return pad
    }

    getBottomPad(){
        let pad=""
        if (this.top.length > this.bottom.length){
            pad += ' '.repeat(this.top.length - this.bottom.length)
        }
        return pad
    }


}
