import React, { Component } from 'react';
import './GameBoard.css'
import HelpPopup from './HelpPopup';
import Instance from './Instance';
import Solution from './Solution';

class GameBoard extends React.Component{
    constructor(props){
        super(props);
        this.state = {
            helpButtonPopUp: false,
        };
    }

    setTrigger = () =>{
        this.setState({helpButtonPopUp : !this.state.helpButtonPopUp})        
    }

    render(){
        return(
            <main>
                <div>                
                    <button className='gameButtons'>Load Instance</button>
                    <button className='gameButtons'>Start playing</button>
                    <button className='gameButtons' onClick={this.setTrigger}>Help ?</button>
                </div>
                    <div>
                        {this.state.helpButtonPopUp && 
                        <HelpPopup setTrigger={this.setTrigger} text={"text test"}/>}
                        <div className='rectangle'>
                        <Instance data="1,2,3,4"/>
                        
                    </div>                                     
                </div>
            </main>
            
        );
    }
}

export default GameBoard