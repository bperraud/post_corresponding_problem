import React, { Component } from 'react';
import { useEffect } from 'react';
import axios from 'axios';
import './GameBoard.css'
import HelpPopup from './HelpPopup';
import Instance from './Instance';
import Solution from './Solution';
import Pair from "../game/Pair";

class GameBoard extends React.Component{
    constructor(props){
        super(props);
        this.state = {
            helpButtonPopUp: false,
            dataInstance : "",
        };
    }

    setTrigger = () =>{
        this.setState({helpButtonPopUp : !this.state.helpButtonPopUp})        
    }

    getfromback = () =>{
        this.setState({dataInstance : ""})
        axios.get('https://52.58.189.254:3001/api/get')
        .then((response)=>
        this.setState({dataInstance : response.data}))      
    }

    render(){
        return(
            <main>
                <div>                
                    <button className='gameButtons' onClick={this.getfromback}>Load Instance</button>
                    <button className='gameButtons'>Start playing</button>
                    <button className='gameButtons' onClick={this.setTrigger}>Help ?</button>
                </div>
                    <div>
                        instance : {this.state.dataInstance}
                        <Instance data={this.state.dataInstance}/>
                        {this.state.helpButtonPopUp && 
                        <HelpPopup setTrigger={this.setTrigger} text={"text test"}/>}
                        <div className='rectangle'>
                    </div>                                     
                </div>
            </main>
            
        );
    }
}

export default GameBoard