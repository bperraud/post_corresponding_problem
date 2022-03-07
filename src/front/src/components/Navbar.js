import React, { Component } from 'react';
import './Navbar.css'
import logo from './ulb-logo.png'

class Navbar extends React.Component {
    render() {
      return (
        <nav>
          <img src={logo} alt="Logo" />
          <p className='title'>Competitive Post Correspondance Problem Cup</p>
          <ul className='nav__links'>
              <li>Main</li>
              <li>About</li>
              <li>Contact</li>
          </ul>
        </nav>
      );
    }
  } 

 export default Navbar