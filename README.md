EBB + FLOW

project + code by Dan Baker

dnbkr.com
crysalys.net

README

All code modules for Ebb + Flow:

1) 'tideserver' - lives in the cloud, acts as central server 
	('/index.js' and '/public/' files)

2) 'piserver' - lives on a local computer or raspberry pi.  This connects to the tideserver and listens for the weather data.  Connects to arduino through serial

3) 'seatrash.ino' - this is the code that is uploaded to the arduino.  Only modify this code after testing with 'seatrash_dev.ino'

4) 'seatrash_dev.ino' - this is the DEVELOPMENT code that is uploaded to the arduino.  This is for testing and debugging.  When ready, copy code to 'seatrash.ino' when finished.  Open a serial monitor to send commands to motors.  For example, to send a sample sea level reading to motor 'C', you would type '3.15C' and motor C will move to that corresponding height. 


165.225.131.134 ip address used for deployment during show.  Change this to whatever server is hosting


public/index.html and public/tideserver_app.js are for displaying the tide data in a web browser

/index.js is the 'tideserver' 


the code in 'arduino' folder are not part of the tideserver/piserver network

5) 'crochet.ino' - this is the arduino code for running the plastic bag web piece

6) 'resin_frames.ino' - this is the arduino code for running the backlit resin pieces in the white frames