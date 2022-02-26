import React from 'react'
import './HelpPopup.css'
import './GameBoard'
class ContactForm extends React.Component {
    constructor(){
        super();
        this.state = {
            submitted : false,
            name : "",
            email : "",
            objet : "",
            emailtext:""
        }
    }

    render(){
        return(
            
            <div>
                <h1>Contact Us</h1>
                <div>
                    <input className='textinput' placeholder='Your Name'></input>
                    <input className='textinput' placeholder='Your Email'></input>
                </div>
                <div>
                <input className='textinput' placeholder='Object' size={51}></input>
                </div>
                <div>
                <textarea className='textbox' placeholder='White your text here'></textarea>
                </div>
                <button className='gameButtons'>SUBMIT</button>
            </div>
            
            
            
            
        );
    }
}



export default ContactForm