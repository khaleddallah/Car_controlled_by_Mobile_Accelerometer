#define FORWARD_PIN   (9)
#define BACKWARD_PIN (10)
#define LEFT_PIN     (11)
#define RIGHT_PIN    (12)
int i ;
void one (){
  digitalWrite(FORWARD_PIN,LOW);
  digitalWrite(BACKWARD_PIN,LOW);
  digitalWrite(LEFT_PIN,LOW);
  digitalWrite(RIGHT_PIN,LOW);
}

void tow (){
  digitalWrite(LEFT_PIN,LOW);
  digitalWrite(RIGHT_PIN,HIGH);
}

void three (){
  digitalWrite(RIGHT_PIN,LOW);
  digitalWrite(LEFT_PIN,HIGH);
}

void four (){
  digitalWrite(BACKWARD_PIN,LOW);
  digitalWrite(FORWARD_PIN,HIGH);
}

void five (){
  digitalWrite(FORWARD_PIN,LOW);
  digitalWrite(BACKWARD_PIN,HIGH);
}

void six (){
  digitalWrite(BACKWARD_PIN,LOW);
  digitalWrite(LEFT_PIN,LOW);
  digitalWrite(FORWARD_PIN,HIGH);
  digitalWrite(RIGHT_PIN,HIGH);
}

void seven (){
  digitalWrite(BACKWARD_PIN,LOW);
  digitalWrite(RIGHT_PIN,LOW);
  digitalWrite(FORWARD_PIN,HIGH);
  digitalWrite(LEFT_PIN,HIGH);;
}

void eight (){
  digitalWrite(FORWARD_PIN,LOW);
  digitalWrite(LEFT_PIN,LOW);
  digitalWrite(BACKWARD_PIN,HIGH);
  digitalWrite(RIGHT_PIN,HIGH);
}

void nine (){
  digitalWrite(FORWARD_PIN,LOW);
  digitalWrite(RIGHT_PIN,LOW);
  digitalWrite(BACKWARD_PIN,HIGH);
  digitalWrite(LEFT_PIN,HIGH); 
}


void setup() {
  Serial.begin(115200);
  pinMode(FORWARD_PIN, OUTPUT);
  pinMode(BACKWARD_PIN, OUTPUT);
  pinMode(LEFT_PIN, OUTPUT);
  pinMode(RIGHT_PIN, OUTPUT);
  pinMode(8, OUTPUT);  
  digitalWrite(8,HIGH);
    while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
 if (Serial.available() > 0) {
    i= Serial.read();
   
    if (i == 49){
      one();
    }
    
    else if (i == 50 ){
      tow();
    }
    
    else if (i == 51) {
      three();
    }
    
    else if (i == 52){
      four();
    }
    
    else if (i == 53){
      five();
    }

        
    else if (i == 54 ){
      six();
    }
    
    else if (i == 55) {
      seven();
    }
    
    else if (i == 56){
      eight();
    }
    
    else if (i == 57){
      nine();
    }
    else {
      one();
    }
 }
}
