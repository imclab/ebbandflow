var express = require('express');
var app = express();
var server = require('http').createServer(app);
var io = require('socket.io-client')
var request = require('request');
var http = require('http');
var arduinoSend = require('./arduinoSend')


server.listen(1337, function() {		//1337 for localhost, port 80 for actual deployment
	console.log('listening on *:1337');
});

app.use(express.static('public/'));

var app = {

	tideData: [			//array for storing sealevel.  Each letter corresponds to a buoy/motor
		[0, 'A'],
		[0, 'B'],
		[0, 'C'],
		[0, 'D'],
		[0, 'E'],
		[0, 'F'],
		[0, 'G'],
		[0, 'H']
		],
	
	init: function() {
		var _this = this;

		var socket = require('socket.io-client')('http://165.225.131.134:80');  //ip address of tideserver used during show at IMC

		socket.on('connect', function(){
			console.log('server connected');
		});

		socket.on('realtimeWaterLevel', function(msg){		//listen for 'realtimeWaterLevel' coming from tideserver
			_this.processData(msg);
		});

		setInterval( function() {
			_this.sendData();
		}, 1000)

	},

	processData: function(data) {
		var _this = this;

		var d = JSON.parse(data);

		var obj = {
			name: d.metadata.name,
			id : d.metadata.id,
			latitude : parseFloat(d.metadata.lat),
			longitude : parseFloat(d.metadata.lon), 
			t : d.data[0].t,
			s : d.data[0].s,
			f : d.data[0].f,
			seaLevel : parseFloat(d.data[0].v)	//send this to arduino
		};

		var waterLevel = obj.seaLevel;
		this.storeData(obj);

	},

	storeData: function(data) {
		var seaLevel = data.seaLevel;
		var _this = this;

		//stores all the sealevels in the tideData array
		if(data.name == 'Sandy Hook') {			//'A'
			_this.tideData[0][0] = data.seaLevel;
		}

		if(data.name == 'Village Cove, St Paul Island') {		//'B'
			_this.tideData[1][0] = data.seaLevel;
		}

		if(data.name == 'Nikiski') {					//'C'
			_this.tideData[2][0] = data.seaLevel;
		}

		if(data.name == 'Honolulu') {					//'D'
			_this.tideData[3][0] = data.seaLevel;
		}

		if(data.name == 'Key West') {					//'E'
			_this.tideData[4][0] = data.seaLevel;
		}

		if(data.name == 'Seattle') {					//'F'
			_this.tideData[5][0] = data.seaLevel;
		}

		if(data.name == 'Point Reyes') {				//'G'	
			_this.tideData[6][0] = data.seaLevel;
		}

		if(data.name == 'La Jolla') {					//'H'
			_this.tideData[7][0] = data.seaLevel;
		}

		if(data.name == 'Port Aransas') {				//'I'
			_this.tideData[8][0] = data.seaLevel;
		}

	},

	sendData: function() {								//combines tideData array into one long string and uses serialSend to push to Arduino
		var dataJoined = this.tideData.toString();
		var combined = dataJoined.replace(/,/g,'');
		arduinoSend.serialSend(combined);
	}
	
}

app.init();

