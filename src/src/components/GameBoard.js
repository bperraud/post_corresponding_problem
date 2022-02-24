import React, { Component } from 'react';
//import {getSession} from '@mysql/xdevapi';
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
        };
    }

    setTrigger = () =>{
        this.setState({helpButtonPopUp : !this.state.helpButtonPopUp})        
    }
/*
    async get_from_db() {
        const config = {
            password: '86Ex$y3s',
            user: 'pcp-user',
            host: 'pcp.digitelstudios.lu:3306',
            schema: 'pcp-db'
        };

        await getSession(config)
            .then(session => {
                return session.sql('select * from instances order by rand()')
                    .execute().then(session.close());
            })
            .then(result => {
                this.data = result.fetchOne()[1];
            }).catch(error => {
                // Use `error` here without `throw`ing -- report it, put it in a log, etc.
                console.log(error)
            });
    }
    */


    render(){
        return(
            <main>
                <div>                
                    <button className='gameButtons'>Load Instance</button>
                    <button className='gameButtons'>Start playing</button>
                    <button className='gameButtons' onClick={this.setTrigger}>Help ?</button>
                </div>
                    <div>
                        <Instance data="11,22,33,11,22,22,11,00"/>
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