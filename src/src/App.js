import './App.css';
import { v4 as uuidv4 } from 'uuid';
import {DragDropContext, Droppable, Draggable} from 'react-beautiful-dnd'
import React, { useState } from 'react';
import Domino from './components/Domino';
import Navbar from './components/Navbar'
import ContactForm from './components/ContactForm'
import GameBoard from './components/GameBoard';
import Solution from './components/Solution';


class App extends React.Component {
  
  render(){
    return (
      <div className="App">
        <div className='Header'>
          <Navbar/>
          <GameBoard/>
        </div>
        <div id='game'>
        </div>
        <ContactForm/>
      </div>
    );
  }
}


export default App;
