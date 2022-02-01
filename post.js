class Instance {
    constructor(size, width, pairs) {
    this.size = size;
    this.width = width;
    this.pairs = pairs;
    }
      
    isWon() {
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

}
    
let first = new Instance(2, 2, new Pair("10", "1"));
    
console.log(first.size);
