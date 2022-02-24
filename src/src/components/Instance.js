import React from 'react'
import Domino from './Domino';
import { v4 as uuidv4 } from 'uuid';
import Solution from './Solution';

class Instance extends React.Component {

    constructor(props){
        super(props);
        this.state = {
            count : 0,
            dominos : [],
            addedDominos : []
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
  
    addToSolution = ( _top, _bottom) =>{
        const obj = {id : uuidv4(), topText: _top, bottomText :_bottom}
        this.state.addedDominos.push(obj);
        this.setState()

    }

    render(){
        return (
            <div>
                <div id='game'>
                    <ul className="elements">
                        {this.state.dominos.map(({topText, bottomText}, index) => {
                            return (
                                <li>
                                    <div onClick={() => this.addToSolution(topText, bottomText)}>
                                    <Domino topText={topText} bottomText={bottomText}></Domino>
                                    </div>
                                </li>
                                )
                            }
                        )
                    }
                    </ul>
                </div>
                <Solution elements={this.state.addedDominos}/>
            </div>
        )
    }
}





export default Instance