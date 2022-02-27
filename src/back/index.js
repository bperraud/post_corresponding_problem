
const mysql = require('mysql')
const express  = require('express')
const app = express();
const bodyParser = require('body-parser');
const cors = require('cors')

app.use(cors())
app.use(express.json());
app.use(bodyParser.urlencoded({extended : true}))



const connection = mysql.createConnection({
    password: '86Ex$y3s',
    user: 'pcp-user',
    host: 'pcp.digitelstudios.lu',
    port : '3306',
    database: 'pcp-db'
})

connection.connect()


app.listen(3001, () => {
    console.log("running on port 3001");
})


connection.query('SELECT * FROM instances AS solution', (err, rows, fields) => {
    if (err) throw err
    //console.log(err);
  
    result = rows;
  
    //res.send(result);
    console.log(result[0].pairs)
  }) 





app.get("/api/get", (req, res) =>{
    /*connection.query('SELECT * FROM instances AS solution', (err, rows, fields) => {
        if (err) throw err
        console.log(err);
      
        result = rows;
      */
        res.send(result[0].pairs);
        //console.log(result)
      //}) 
})




connection.end()