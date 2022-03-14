import React, { Component } from 'react';
import VictoryMessage from './VictoryMessage';
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
                        {this.props.text}
                        <VictoryMessage specialText={this.props.specialText}></VictoryMessage>
                        
                    </text>
                    <button className='closebtn' onClick={() => this.props.setTrigger()}> x </button>  
                </div>
            </div>
        );
    }
}





export default HelpPopup

