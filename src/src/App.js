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
    topText: 'B',
    bottomText: 'CA'
  },
  {
    id: '1',
    topText: 'A',
    bottomText: 'AB'
  },
  {
    id: '2',
    topText: 'CA',
    bottomText: 'A'
  },
  {
    id: '3',
    topText: 'ABC',
    bottomText: 'C'
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
      </div>
      <div id='game'>
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
        <ContactForm/>
    </div>
  );
}

export default App;
