class Instance {
    constructor(size, width, pairs) {
    this.size = size;
    this.width = width;
    this.pairs = pairs;
    }
      


}

class Pair {
    constructor(top, bottom){
    this.top = top;
    this.bottom = bottom;  
    }  
}
    
class Solution {
    isWon() {
        return 1;
    }
}
    
let first = new Instance(2, 2, new Pair("10", "1"));
    
console.log(first.size);
