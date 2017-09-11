## Use Mobile accelerometer to control robot car :
1. mobile read accelerometer value (x,y,z angle value) and send it to computer throw Udp protocol
2. ESP8266 take the value of accelerometer and decide the direction ,and send it to arduino
3  arduino run motors to make car robot move according to received direction.  

## Parts :  
- Esp8266 : wireless chip
- Arduino : controller
- motors : I take them from old car toy
- L293D : motor driver
- battery : old laptop battery

