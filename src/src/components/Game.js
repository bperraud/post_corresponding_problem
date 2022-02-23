import React from 'react'
import HelpPopup from './HelpPopup'

class Game {
    constructor(props){
        super(props)
        this.state = {
            isWon : false,
            topString : "",
            bottomString : "",
        }
    }

    isWon(){
        if (this.state.topString == this.state.bottomString && this.state.bottomString != ""){
            this.setState({isWon : true})
            return true
        }
        return false
    }



    render(){
        return (
            <div>




            </div>
          );
    }

}


export default Game