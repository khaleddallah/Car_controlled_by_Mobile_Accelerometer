## Use Mobile accelerometer to control robot car :
1. mobile read accelerometer value (x,y,z angle value) and send it to computer throw Udp protocol
2. ESP8266 take the value of accelerometer and decide the direction ,and send it to arduino
3  arduino run motors to make car robot move according to received direction.  

## technically :  
- in mobile section (android app) : there is accelerometer reader and Udp client .     
- in ESP8266 section : there is Udp server that recive accelerometer data from the mobile and send the commands to the arduino.      
- in Arduino section : it gets the commands and control motors debend on the commands.       


## Parts :  
- Esp8266 : wireless chip
- Arduino : controller
- motors : I take them from old car toy
- L293D : motor driver
- battery : old laptop battery

