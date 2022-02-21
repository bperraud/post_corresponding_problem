import './App.css';
import {DragDropContext, Droppable, Draggable} from 'react-beautiful-dnd'
import React, { useState } from 'react';
import Domino from './components/Domino';
import Navbar from './components/Navbar'
import ContactForm from './components/ContactForm'
import GameBoard from './components/GameBoard';

const finalElements = [
  {
    id: '0',
    topText: 'A',
    bottomText: 'B'
  },
  {
    id: '1',
    topText: 'C',
    bottomText: 'D'
  },
  {
    id: '2',
    topText: 'E',
    bottomText: 'F'
  }
]

function App() {
  const [elements, updateElements] = useState(finalElements);

  function handleOnDragEnd(result) {
    if (!result.destination) return;

    const items = Array.from(elements);
    const [reorderedItem] = items.splice(result.source.index, 1);
    items.splice(result.destination.index, 0, reorderedItem);

    updateElements(items);
  }
  return (
    <div className="App">
      <div className='Header'>
        <Navbar/>
        <GameBoard/>
        <ContactForm/>
      </div>
      <DragDropContext onDragEnd={handleOnDragEnd}>
          <Droppable droppableId="elements" direction='horizontal'>
            {(provided) => (
              <ul className="elements" {...provided.droppableProps} ref={provided.innerRef}>
                {elements.map(({id, topText, bottomText}, index) => {
                  return (
                    <Draggable key={id} draggableId={id} index={index}>
                      {(provided) => (
                        <li ref={provided.innerRef} {...provided.draggableProps} {...provided.dragHandleProps}>
                          <Domino topText={topText} bottomText={bottomText}></Domino>
                        </li>
                      )}
                    </Draggable>
                  );
                })}
                {provided.placeholder}
              </ul>
            )}
          </Droppable>
        </DragDropContext>
    </div>
  );
}

export default App;
