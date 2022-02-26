import React, { Component } from 'react';
import './Popup.css'


class HelpPopup extends React.Component{
    constructor(props){
        super(props);
    }
    render(){
        return(
            <div className='popup'>
                <div className='pop-inner'>
                    <text className='instructions'>
                        Display some instructions to play the game..
                        display some instructions to play the game..
                        display some instructions to play the game..
                        display some instructions to play the game..
                        display some instructions to play the game..
                        display some instructions to play the game..
                        display some instructions to play the game..
                        {this.props.text}
                    </text>
                    <button className='closebtn' onClick={() => this.props.setTrigger()}> x </button>  
                </div>
            </div>
        );
    }
}





export default HelpPopup

