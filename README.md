# Fire Alarm System

Fire Alarm System using Internet of Things

# Table of contents
* [Report](#report)
* [Demo](#demo)
* [Installation](#installation)
  * [Sensor](#sensor)
  * [Cloud](#cloud)
  * [Client](#client)

## Report
Please refer to report for more information: https://github.com/Zayedkz/iot-project/blob/main/IoT%20Project%20Report%20-%20Google%20Docs.pdf

## Demo
Video demo: https://drive.google.com/file/d/1_W_i6Nz4x5kpOPhcMQ11RBGkAX6MEYsd/view

## Installation

### Sensor
Hook up the components of the sensor as shown in the picture below. 
![alt text](https://i.gyazo.com/fb76b1e2641caa060356c030f81c628c.png)
<br> Then upload the code in the sensor folder in this respository to the ESP8226 to start the sensor.

### Cloud
To start the cloud server, download the files in the Server folder and then run 'node index.js' to start the nodejs server. The server needs to be exposed to remote machines, we used ngrok to do that. Steps on how to install ngrok: https://ngrok.com/download

### Client
The client is basically a Node-RED environment, for steps on how to install Node-RED, go to: https://nodered.org/docs/getting-started/local
<br>Then download the file in the client folder and upload it to the Node-RED environment to show the UI.
![alt text](https://i.gyazo.com/5fbeaee43627924cb18f2f75c3db519c.png)
