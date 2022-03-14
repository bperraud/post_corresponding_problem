import React from 'react'
import Domino from './Domino';
import HelpPopup from './HelpPopup'
import { v4 as uuidv4 } from 'uuid';
import {DragDropContext, Droppable, Draggable} from 'react-beautiful-dnd'
import VictoryMessage from './VictoryMessage';

class Instance extends React.Component {

    constructor(props){
        super(props);
        this.state = {
            dominos : [],
            addedDominos : [],
            won : false,
            topString : "",
            bottomString : "",
        }
    }


    convertStringToArray(){
        this.state.dominos = []
        const receiveddata = this.props.data;
        /*if (this.state.won){
             receiveddata =  "";
        }
        else{
            receiveddata =  this.props.data;
        }*/
        
        const dataToString = JSON.stringify(receiveddata)
        const ConvertedData = dataToString.split(",");
        if (ConvertedData.length%2 === 0){
            for (let i=0; i < ConvertedData.length ; i+=2){
                let top = ConvertedData[i].replace('"',"")
                let bottom = ConvertedData[i+1].replace('"',"")
                const Obj = {id: uuidv4(), topText : top , bottomText : bottom}
                this.state.dominos.push(Obj)
            }
        }
    }
  
    addToSolution = (e, _top, _bottom) =>{
        switch(e.detail){
            case 2:
                break;
            case 1:
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
          case 2:
            break;
          case 1:
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
          this.state.topString = top;
          this.state.bottomString = bottom;
          this.state.won = top === bottom;
          return top === bottom && top !== "";
      }

    setTrigger = () => {
        this.setState({won : false})
        this.setState({addedDominos : []})
        this.setState({dominos : []})
    }


    render(){
        if (!this.isWon()){this.convertStringToArray();}
        return (
            <div>
                <div id='game'>
                    {!this.isWon() &&
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
                    }
                </div>
                <div id='game'>
                
                {!this.isWon() && <DragDropContext onDragEnd={this.handleOnDragEnd}>
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
                </DragDropContext>}
                
            </div>
            
            {this.isWon() && <HelpPopup setTrigger={this.setTrigger} text={""} specialText={"CONGRATULATIONS ! YOU WON"}/>}
            
            <div className={this.isWon()? 'solutionWon' : 'solutionn'}>
                    <h3>Current Solution</h3>
                    <p className={this.isWon()? 'solutionTextWon' : 'solutionText'}>{this.state.topString}</p>
                    <br></br>
                    <p className={this.isWon()? 'solutionTextWon' : 'solutionText'}>{this.state.bottomString} </p>
            </div>
            <div>
                
            </div>
            </div>
        )
    }
}


export default Instance