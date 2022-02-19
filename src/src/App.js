import './App.css';
import Domino from './components/Domino';

function App() {
  const elements = [["AB", "CD"], ["EF", "GH"], ["IJ", "KL"]];
  return (
    <div className="App">
      <ul>
        {elements.map((item, index) => <Domino topText={item[0]} bottomText={item[1]}/>)}
      </ul>  
    </div>
  );
}

export default App;
