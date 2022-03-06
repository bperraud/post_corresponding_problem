import React, { Component } from 'react';
import { useEffect } from 'react';
import axios from 'axios';
import './GameBoard.css'
import HelpPopup from './HelpPopup';
import Instance from './Instance';
import Solution from './Solution';
import Timer from './Timer'

class GameBoard extends React.Component{
    constructor(props){
        super(props);
        this.state = {
            start : false,
            startTimer: false,
            helpButtonPopUp: false,
            dataInstance : "",
            selectedLevel : [false,false,false,false],
            level : 0,
            maxLevel : 3
        };
    }

    setTrigger = () =>{
        this.setState({helpButtonPopUp : !this.state.helpButtonPopUp})        
    }

    getfromback = () =>{
        this.setState({dataInstance : ""})
        axios.get('https://pcp-api.digitelstudios.lu/api/get')
        .then((response)=>
        this.setState({dataInstance : response.data}))      
    }

    handelLevelButton = (index) =>{
        let tmpState = [false, false, false,false]
        tmpState[index] = true
        this.setState({selectedLevel : tmpState});
    }

    displayLevelButtons = () =>{
        this.setState({start : true})
    }

    render(){
        return(
            <main>
                <div>                
                    <button className='gameButtons' onClick={this.getfromback}>Load Instance</button>
                    <button className='gameButtons' onClick={this.displayLevelButtons}>New Game</button>
                    <button className='gameButtons' onClick={this.setTrigger}>Help ?</button>
                </div>
                {this.state.start &&
                <div>
                    <div>
                        <button className={!this.state.selectedLevel[0] ?'levelButtonDisabled' : 'levelButtonEnabled'} onClick={() => this.handelLevelButton(0)}>Beginner</button>
                        <button className={!this.state.selectedLevel[1] ?'levelButtonDisabled' : 'levelButtonEnabled'} onClick={() => this.handelLevelButton(1)}>Intermediate</button>
                        <button className={!this.state.selectedLevel[2] ?'levelButtonDisabled' : 'levelButtonEnabled'} onClick={() => this.handelLevelButton(2)}>Hard</button>
                        <button className={!this.state.selectedLevel[3] ?'levelButtonDisabled' : 'levelButtonEnabled'} onClick={() => this.handelLevelButton(3)}>Pro</button>                
                    </div>
                    <div>
                        <button className={this.state.startTimer ? 'stopButton' :'startButton'} onClick={()=> this.setState({startTimer : !this.state.startTimer})}>{this.state.startTimer? 'Stop Playing' : 'Start Playing'}</button>
                    </div>
                        { this.state.startTimer &&
                        <Timer></Timer>
                        }
                </div>
                }   
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