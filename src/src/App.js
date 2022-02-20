import './App.css';
import Domino from './components/Domino';
import Navbar from './components/Navbar'

function App() {
  const elements = [["AB", "CD"], ["EF", "GH"], ["IJ", "KL"]];
  return (

    

    <div className="App">
      <div className='Header'>
      <Navbar/>
      </div>
      <ul>
        {elements.map((item, index) => <Domino topText={item[0]} bottomText={item[1]}/>)}
      </ul>  
    </div>
  );
}

export default App;
