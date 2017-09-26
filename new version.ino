const int redLed = 12;
const int greenLed = 9;
const int yellowLed = 11;
const int blueLed = 10;
const int buzzer = 3;
const int signalBuzzer = 440;
const int btnPin = 2;
int position = 0;

long previousMillis = 0;  
long buzzerInterval = 60000;

void setup(){
  Serial.begin(9600);
  Serial.println("Hello");
  position = 0;
  pinMode(btnPin,INPUT_PULLUP);
  pinMode(redLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(yellowLed,OUTPUT);
  pinMode(blueLed,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(btnPin), Sequencia, RISING);
}

void Sequencia(){
  if(position > 3){
    position = 0;
  }
  else{
    position += 1;
  }
  Serial.println(position);
}

void loop(){
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > buzzerInterval){
    previousMillis = currentMillis;
    tone(buzzer,signalBuzzer);
    Serial.println("Tocou");
  }
  else if(currentMillis - previousMillis > 1000){
    noTone(buzzer);
    Serial.println("Desligou");
  }

 
  switch(position){
    case 1:
      Orders(yellowLed, redLed, greenLed, blueLed);
    break;
    case 2:
      Orders(redLed,yellowLed,greenLed, blueLed);
    break;
    case 3:
      Orders(greenLed,yellowLed, redLed, blueLed);
    break;
  }
}

void Orders(int n1, int n2, int n3, int n4){
  if(LedsStatus(n1, n2, n3, n4,1,1,1,1)){
     noTone(buzzer);
     //Serial.println("Todos conectados");
  }
  else if(LedsStatus(n1, n2, n3,n4,0,1,1,1)){
    noTone(buzzer);
    //Serial.println("Tirou o primeiro");
  }
  else if(LedsStatus(n1, n2, n3,n4,0,0,1,1)){
    noTone(buzzer);
    //Serial.println("Tirou o segundo");
  }
  else if(LedsStatus(n1, n2, n3,n4,0,0,0,1)){
    noTone(buzzer);
    //Serial.println("Tirou o terceiro");
  }
  else if(LedsStatus(n1, n2, n3,n4,0,0,0,0)){
    noTone(buzzer);
    //Serial.println("Tirou o quarto");
  }
  else{
    tone(buzzer,signalBuzzer);
    //Serial.println("Errou a ordem");
  }
}

boolean LedsStatus(int n1, int n2, int n3, int n4,int l1, int l2, int l3, int l4){
  boolean status;
  if(digitalRead(n1) == l1 && digitalRead(n2) == l2 && digitalRead(n3) == l3 && digitalRead(n4) == l4){
    status = true;
  }
  else{
    status = false;
  }
  return status;
}
