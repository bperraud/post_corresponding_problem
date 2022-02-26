import React, { Component } from 'react';
import './Navbar.css'
import logo from './logo.png'

class Navbar extends React.Component {
    
    render() {
      return ( 
        <nav>
            <h1 className='title'>Competitive Post Correspondance Problem Cup</h1>
            <ul className='list'>
                <li className='items'>Main</li>
                <li className='items'>About</li>
                <li className='items'>Contact</li>
            </ul>
            <img src={logo} alt="Logo" />
        </nav>
      );
    }
  } 

 export default Navbar