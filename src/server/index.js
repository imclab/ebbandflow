var express = require('express');
var app = express();
var server = require('http').createServer(app);
var io = require('socket.io')(server);
var request = require('request');
//var http = require('http');
var bodyParser = require('body-parser');
var multer = require('multer');
var config = require('config');

//server.listen(1337);

//app.use(express.static(__dirname + '/public'));
app.use(express.static('src/public/'));

server.listen(1337, function() {
	console.log('listening on *:1337');
});

server.on('connection', function(socket) {
	console.log('new connection');
});