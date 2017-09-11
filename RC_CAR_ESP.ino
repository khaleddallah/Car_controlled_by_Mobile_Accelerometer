#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "**Tolib**";
const char* password = "zerohour";

WiFiUDP Udp;
unsigned int localUdpPort = 4210;  // local port to listen on
char incomingPacket[16];  // buffer for incoming packets


int testolo (char x[16]){
  String str(x);
  int ctl=0;
  if ((int)x[2]==45)
  {
    //if ((int)x[3]>=49)
    if(str.substring(3,6).toFloat()>=1.8)
    {

      if((int)x[10]==45)
      {
        if(str.substring(11,14).toFloat()>=1.8){ctl=9;}
        //if ((int)x[11]>=49){ctl=9;}
        else {ctl=3;}
      }
      else
      {
        if(str.substring(10,13).toFloat()>=1.8){ctl=7;}
        //if ((int)x[10]>=49) {ctl=7;}
        else  {ctl=3;}
      }
    }
    else
    {
      if((int)x[10]==45)
      {
        if(str.substring(11,14).toFloat()>=1.8){ctl=5;}
        //if ((int)x[11]>=49){ctl=5;}
        else {ctl=1;}
      }
      else
      {
        if(str.substring(10,13).toFloat()>=1.8){ctl=4;}
        //if ((int)x[10]>=49) {ctl=4;}
        else  {ctl=1;}
      }
    }
  }
  else
  {

    //if ((int)x[2]>=49)
    if(str.substring(2,5).toFloat()>=1.8)
    {

      if((int)x[9]==45)
      {
        if(str.substring(10,13).toFloat()>=1.8){ctl=8;}
        //if ((int)x[10]>=49){ctl=8;}
        else {ctl=2;}
      }
      else
      {
        if(str.substring(9,12).toFloat()>=1.8){ctl=6;}
        //if ((int)x[9]>=49) {ctl=6;}
        else  {ctl=2;}
      }
    }
    else
    {
      if((int)x[9]==45)
      {
        if(str.substring(10,13).toFloat()>=1.8){ctl=5;}
        //if ((int)x[10]>=49){ctl=5;}
        else {ctl=1;}
      }
      else
      {
        if(str.substring(9,12).toFloat()>=1.8){ctl=4;}
        //if ((int)x[9]>=49) {ctl=4;}
        else  {ctl=1;}
      }
    }
  }
 return ctl;
}

void setup()
{
  Serial.begin(115200);
  Serial.println();
  WiFi.softAP(ssid, password);
  delay(5000);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.printf("Connecting to %s ", ssid);
  Udp.begin(localUdpPort);
  delay(5000);
  Serial.printf("Now listening at IP %s, UDP port %d\n", myIP.toString().c_str(), localUdpPort);
}


void loop()
{
  int packetSize = Udp.parsePacket();
  if (packetSize)
  {
    // receive incoming UDP packets
    int len = Udp.read(incomingPacket,16);
    if (len > 0)
    {
      incomingPacket[len] = 0;
    }
    
    //Serial.write(incomingPacket);
    //////////////////////////////////
    //Serial.println();
  //  Serial.println("++++++++++++++++++++++++++");
    //Serial.println((int)incomingPacket[2]);
  //  Serial.println("packet: ");
  //  Serial.println(incomingPacket);
  //  Serial.print("ctl : ");
    Serial.print(testolo(incomingPacket));
  //  Serial.println();
  }
}
