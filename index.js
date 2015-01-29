var express = require('express');
var app = express();
var server = require('http').createServer(app);
var io = require('socket.io')(server);
var request = require('request');
//var http = require('http');
var bodyParser = require('body-parser');
var multer = require('multer');

//app.use(express.static(__dirname + '/public'));
app.use(express.static('public/'));
app.use(express.static('apps/tideserver/public/'));

//port used for deployment
server.listen(80, function() {
	console.log('listening on *:80');
});

// server.listen(1337, function() {
// 	console.log('listening on *:1337');
// });

server.on('connection', function(socket) {
	console.log('new connection');
});


//////////////////////////////////////
//									//
//									//
//  TIDESERVER BELOW THIS LINE 		//
//									//
//									//
//////////////////////////////////////

var _channels = {};
var _intervals = {};

var getDataInterval = 1 * 1000; 

var hours = 600;

var _endpoints = {
	'sandyhook_nj': 'http://tidesandcurrents.noaa.gov/api/datagetter?range=' + hours + '&station=8531680&product=water_level&application=NOS.COOPS.TAC.WL&datum=MLLW&units=english&time_zone=gmt&application=ports_screen&format=json',
	'village_cove_alaska': 'http://tidesandcurrents.noaa.gov/api/datagetter?range=' + hours + '&station=9464212&product=water_level&application=NOS.COOPS.TAC.WL&datum=MLLW&units=english&time_zone=gmt&application=ports_screen&format=json',
	'nikika_alaska': 'http://tidesandcurrents.noaa.gov/api/datagetter?range=' + hours + '&station=9455760&product=water_level&application=NOS.COOPS.TAC.WL&datum=MLLW&units=english&time_zone=gmt&application=ports_screen&format=json',
	'key_west_fl': 'http://tidesandcurrents.noaa.gov/api/datagetter?range=' + hours + '&station=8724580&product=water_level&application=NOS.COOPS.TAC.WL&datum=MLLW&units=english&time_zone=gmt&application=ports_screen&format=json',
	'honolulu_hi': 'http://tidesandcurrents.noaa.gov/api/datagetter?range=' + hours + '&station=1612340&product=water_level&application=NOS.COOPS.TAC.WL&datum=MLLW&units=english&time_zone=gmt&application=ports_screen&format=json',
	'seattle_wa': 'http://tidesandcurrents.noaa.gov/api/datagetter?range=' + hours + '&station=9447130&product=water_level&application=NOS.COOPS.TAC.WL&datum=MLLW&units=english&time_zone=gmt&application=ports_screen&format=json',
	'pt_reyes_ca': 'http://tidesandcurrents.noaa.gov/api/datagetter?range=' + hours + '&station=9415020&product=water_level&application=NOS.COOPS.TAC.WL&datum=MLLW&units=english&time_zone=gmt&application=ports_screen&format=json'
};

// server.listen(1337);

app.use(bodyParser.json()); // for parsing application/json
app.use(bodyParser.urlencoded({ extended: true })); // for parsing application/x-www-form-urlencoded
app.use(multer()); // for parsing multipart/form-data

app.use(express.static(__dirname + '/public/tideserver/'));

createChannel(_endpoints);

// Routes
app.use(function(req, res, next) {
  res.header("Access-Control-Allow-Origin", "*");
  res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
  next();
});

//runs every time a new form is submitted
app.post('/api/changeParameters', function (req, res) {

 	console.log(req.body);

 	res.status(200);
});

function createChannel(endpoints) {

	for(var name in endpoints) {
		
		var nsp = io.of(name);
		_channels[name] = nsp;

		nsp.on('connection', function(socket){
		  console.log('Someone connected to ' + socket.nsp.name);
		  console.log(socket.id);

		});

		_intervals[name] = getData(name, endpoints[name]);
	}

}

function getData(name, endpoint) {

	return setInterval(function() {

		request(endpoint,

		function(error, response, body) {

			if (!error && response.statusCode == 200) {
				_channels[name].emit('data', body); 
			}

		});

	}, getDataInterval);	

}

var getRealtimeData = {

	interval: 1000,

	realtime: [
		'http://tidesandcurrents.noaa.gov/api/datagetter?date=latest&station=8531680&product=one_minute_water_level&application=NOS.COOPS.TAC.WL&datum=MLLW&units=english&time_zone=gmt&application=ports_screen&format=json',
		'http://tidesandcurrents.noaa.gov/api/datagetter?date=latest&station=9464212&product=one_minute_water_level&application=NOS.COOPS.TAC.WL&datum=MLLW&units=english&time_zone=gmt&application=ports_screen&format=json'
	],

	init: function() {
		var _this = this;  

		setInterval(function(){
			_this.realtimeWaterLevel();
		}, this.interval);
	},
		
	realtimeWaterLevel: function () {

		var _this = this;

		for(var i = 0; i < this.realtime.length; i++) {

			request(this.realtime[i],

				function(error, response, body) {

					if (!error && response.statusCode == 200) {
						io.emit('realtimeWaterLevel', body);
						
						//parse and log
						var d = JSON.parse(body);
						// console.log(d);
						//console.log(d.metadata.name + ': ' + ' ' + d.data[0].v);
					}
			});
		}
	}
	
}

getRealtimeData.init();

