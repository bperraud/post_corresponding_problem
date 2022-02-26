import React from 'react'
import Domino from './Domino';
import HelpPopup from './HelpPopup'
import { v4 as uuidv4 } from 'uuid';
import {DragDropContext, Droppable, Draggable} from 'react-beautiful-dnd'

class Instance extends React.Component {

    constructor(props){
        super(props);
        this.state = {
            dominos : [],
            addedDominos : [],
            won : false
        }
        this.convertStringToArray();

    }

    convertStringToArray(){
        const ConvertedData = this.props.data.split(",");
        if (ConvertedData.length%2 === 0){
            for (let i=0; i < ConvertedData.length ; i+=2){
                const Obj = {id: uuidv4(), topText : ConvertedData[i] , bottomText : ConvertedData[i+1]}
                this.state.dominos.push(Obj)
            }
        }
    }
  
    addToSolution = (e, _top, _bottom) =>{
        switch(e.detail){
            case 1:
                break;
            case 2:
                const obj = {id : uuidv4(), topText: _top, bottomText :_bottom}
                const temp = [...this.state.addedDominos]
                temp.push(obj);
                this.setState({ addedDominos : temp})
                break;
            default:
                return;
        }
    }

    handleOnDragEnd = (result) => {
        if (!result.destination) return;
        const items = Array.from(this.state.addedDominos);
        const [reorderedItem] = items.splice(result.source.index, 1);
        items.splice(result.destination.index, 0, reorderedItem);
        this.setState({addedDominos : items});
      }

    handleClick = (e, index) => {
        switch (e.detail) {
          case 1:
            break;
          case 2:
            const items = Array.from(this.state.addedDominos);
            items.splice(index,1);
            this.setState({addedDominos : items})
            break;
          default:
            return;
        }
      };

      isWon(){
          var top = "";
          var bottom = "";
          for (let i = 0; i<this.state.addedDominos.length; i++){
                top += this.state.addedDominos[i].topText;
                bottom += this.state.addedDominos[i].bottomText;
          }
          console.log("top : "+ top)
          console.log("bottom : "+ bottom)
          this.state.won = top === bottom;
          console.log("won : "+this.state.won)
          return top === bottom && top !== "";
      }

    setTrigger = () => {
        this.setState({won : false})
        this.setState({addedDominos : []})
    }


    render(){
        return (
            <div>
                <div>Instance :</div>
                <div id='game'>
                    <ul className="elements">
                        {this.state.dominos.map(({topText, bottomText}, index) => {
                            return (
                                <li>
                                    <div onClick={(e) => this.addToSolution(e,topText, bottomText)}>
                                    <Domino topText={topText} bottomText={bottomText}></Domino>
                                    </div>
                                </li>
                                )
                            }
                        )
                    }
                    </ul>
                </div>
                <div>
                    Solution : 
                   
                </div>
                <div id='game'>
                <DragDropContext onDragEnd={this.handleOnDragEnd}>
                    <Droppable droppableId="elements" direction='horizontal'>
                    {(provided) => (
                        <ul className="elements" {...provided.droppableProps} ref={provided.innerRef}>
                        {this.state.addedDominos.map(({id, topText, bottomText}, index) => {
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
            {this.isWon() && <HelpPopup setTrigger={this.setTrigger}text = "You won"/>}
            </div>
        )
    }
}





export default Instance