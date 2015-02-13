//common directoris of serial port
// var serialDir = '/dev/tty.usbmodem14111';  (left port)
// var serialDir = '/dev/tty.usbmodem15111';	(right port)

//sets up serial port to arduino
var serialport = require("serialport");
var SerialPort = serialport.SerialPort; 

//creates a new serial port
var sp = new SerialPort('/dev/tty.usbmodem145111', {
	baudrate: 57600,
  	parser: serialport.parsers.readline("\n"),
  	dataBits: 8,
    parity: 'none',
    stopBits: 1,
	flowControl: false,
}, function(error) {
    if (error) {
      console.log('Arduino Not Connected!');
      console.log(error);
    }
  }
);

//opens the serial port
sp.on('open', function(error){
	if ( error ) {
    	console.log('serial failed to open: '+ error);
	} else {
		console.log('Serial Port Open');
	    sp.on('data', function(data) {
       		console.log('Arduino Says: ' + data);
		});
	};
});

//this function is called in piserver index, to send the tideData array to arduino
function serialSend(data) {

		sp.write(data, function(error) {
			if (error) {
				console.log('no response from arduino');
			} else {
				console.log('Sending to Arduino: ' + data);
			}		
		});
	
}

module.exports = {
	serialSend: serialSend
};
