const mysql = require('mysql')
const express  = require('express')
const app = express();
const bodyParser = require('body-parser');
const cors = require('cors')

app.use(cors())
app.use(express.json());
app.use(bodyParser.urlencoded({extended : true}))


const connection = mysql.createPool({
    connectionLimit : 10,
    password: '86Ex$y3s',
    user: 'pcp-user',
    host: 'pcp.digitelstudios.lu',
    port : '3306',
    database: 'pcp-db'
})


async function get_random_from_db(client, selected_level) {
    // add parameter to define level, which influences on the query?

    let res = null;
    try{
        await connection.query('SELECT * FROM instances WHERE lvl='+selected_level+' AS solution order by RAND()', (err, rows, fields) => {
            if (err) throw err;
            //console.log(err);
            res = rows[0].pairs
            console.log(res)
            client.send(res)
        })

    }
    catch{
        console.log("Oof")
    }
}

app.listen(3001, () => {
    console.log("running on port 3001");
})

app.get("/api/get", (req, res) =>{

    get_random_from_db(res, 0);

})

app.get("/api/get/easy", (req, res) =>{

    get_random_from_db(res, 0);

})

app.get("/api/get/medium", (req, res) =>{

    get_random_from_db(res, 1);

})

app.get("/api/get/hard", (req, res) =>{

    get_random_from_db(res, 2);

})

