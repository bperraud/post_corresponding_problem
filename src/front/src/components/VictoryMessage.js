
import './VictoryMessage.css'
//import { VictoryMessage } from 'react-transition-state';
import useTransition from 'react-transition-state'; 
import HelpPopup from './HelpPopup';
import AnimatedText from 'react-animated-text-content';

function VictoryMessage(props) {
  const [state, toggle] = useTransition({ timeout: 850, preEnter: true });
  return (
    <div>
        <AnimatedText
            type="words" // animate words or chars
            animation={{
                x: '200px',
                y: '-20px',
                scale: 3,
                ease: 'ease-in-out'}}
            animationType="float"
            interval={0.5}
            duration={0.9}
            tag="h1"
            className="animated-paragraph"
            includeWhiteSpaces
            threshold={0.5}
            rootMargin="20%"
            >
            {props.specialText}
        </AnimatedText>
    </div>
  );
}

export default VictoryMessage;

