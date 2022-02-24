import { v4 as uuidv4 } from 'uuid';
import {DragDropContext, Droppable, Draggable} from 'react-beautiful-dnd'
import React from 'react';
import Domino from './Domino';


class Solution extends React.Component{
    constructor(props){
        super(props);
        this.state = {
                elements : this.props.elements         
                }
    }

    addElement(top, bottom){
        const obj = {id: uuidv4(), topText : top , bottomText : bottom}
        this.elements.push(obj)
    }

    handleOnDragEnd = (result) => {
        if (!result.destination) return;
        const items = Array.from(this.state.elements);
        const [reorderedItem] = items.splice(result.source.index, 1);
        items.splice(result.destination.index, 0, reorderedItem);
        this.setState({elements : items});
        console.log(items);
        console.log(this.state.elements);
      }

    handleClick = (e, index) => {
        switch (e.detail) {
          case 1:
            console.log("1 click ");
            break;
          case 2:
            const items = Array.from(this.state.elements);
            console.log(items.length);
            const item = items[index];
            items.splice(index, 0, { ...item, id: uuidv4() });
            this.setState({elements : items})
            break;
          default:
            return;
        }
      };



    render(){
        return (
            <div id='game'>
                <DragDropContext onDragEnd={this.handleOnDragEnd}>
                    <Droppable droppableId="elements" direction='horizontal'>
                    {(provided) => (
                        <ul className="elements" {...provided.droppableProps} ref={provided.innerRef}>
                        {this.state.elements.map(({id, topText, bottomText}, index) => {
                            return (
                            <Draggable key={id} draggableId={id} index={index}>
                                {(provided) => (
                                <li
                                    ref={provided.innerRef} 
                                    {...provided.draggableProps} 
                                    {...provided.dragHandleProps}
                                    onClick={(e) => this.handleClick(e, index)}>
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
}

export default Solution