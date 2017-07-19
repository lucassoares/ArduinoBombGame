const int redLed = 12;
const int greenLed = 10;
const int yellowLed = 11;
const int buzzer = 5;
const int signalBuzzer = 440;

void setup(){
  pinMode(redLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(yellowLed,OUTPUT);
}

void loop(){
  if(LedsStatus(1,1,1)){
     noTone(buzzer);
  }
  else if(LedsStatus(0,1,1)){
    noTone(buzzer);
  }
  else if(LedsStatus(0,0,1)){
    noTone(buzzer);
  }
  else if(LedsStatus(0,0,0)){
    noTone(buzzer);
  }
  else{
    tone(buzzer,signalBuzzer);
  }
}

boolean LedsStatus(int l1, int l2, int l3){
  boolean status;
  if(digitalRead(yellowLed) == l1 && digitalRead(redLed) == l2 && digitalRead(greenLed) == l3)
  {
    status = true;
  }
  else{
    status = false;
  }
  return status;
}
