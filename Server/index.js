const express = require('express')
const app = express()
const port = 3000
const fs = require('fs');
const bodyParser = require('body-parser');

app.use(bodyParser.urlencoded({ extended: true }));
app.get('/', (req, res) => {
  res.end('Hello World!');
});

app.get("/get_temp", (req, res) => {
    fs.readFile(__dirname + '/' + 'readings.json', 'utf8', (err, data) => {
        res.end(data);
    });
});
app.post('/', (req, res) => {
    console.log('Got body:', req.body);
    let data = JSON.stringify(req.body);
    if (data.fireAlarm == 1) data.fireAlarm = 1;
    fs.writeFileSync('readings.json', data);
    res.sendStatus(200);
});
app.listen(port, () => {
    console.log(`app listening at http://localhost:${port}`)
  });
