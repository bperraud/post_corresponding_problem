import React from 'react';
import { useStopwatch } from 'react-timer-hook';

function MyStopwatch(props) {
  const {
    seconds,
    minutes,
    hours,
  } = useStopwatch({autoStart: true});


  return (
    <div style={{textAlign: 'center'}}>
      <div style={{fontSize: '30px'}}>
        <span>{hours}</span>:<span>{minutes}</span>:<span>{seconds}</span>
      </div>
    </div>
  );
}

export default function App() {
  return (
    <div>
      <MyStopwatch />
    </div>
  );
}