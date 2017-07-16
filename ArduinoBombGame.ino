const int leds[] = {12,11,10};
const int ledCount = 3;
const int buzzer = 5;
const int signal = 440;
int firstLed = 0;
int secondLed = 0;
int thirdLed = 0;

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
  for(int i = 0; i<ledCount; i++){
    pinMode(leds[i],OUTPUT);
  }

  firstLed = leds[random(0,3)];
  secondLed = leds[random(0,3)];

  while(secondLed == firstLed){
    secondLed = leds[random(0,3)];
  }

  thirdLed = leds[random(0,3)];

  while(thirdLed == secondLed || thirdLed == firstLed){
    thirdLed = leds[random(0,3)];
  }

  Serial.println(firstLed);
  Serial.println(secondLed);
  Serial.println(thirdLed);
  Serial.println("---------");
}

void loop()
{
  if(LedsStatus(1,1,1)){
    Serial.println("Todos os leds ligados");
    noTone(buzzer);
  }
  else if(LedsStatus(0,1,1)){
    Serial.println("Primeiro led retirado com sucesso");
    noTone(buzzer);
  }
  else if(LedsStatus(0,0,1)){
    Serial.println("Segundo led retirado com sucesso");
    noTone(buzzer);
  }
  else if(LedsStatus(0,0,0)){
    Serial.println("Terceiro led retirado com sucesso");
    noTone(buzzer);
  }
  else{
    Serial.println("Led errado foi removido");
    tone(buzzer,signal);
  }
}

boolean LedsStatus(int l1, int l2, int l3){
  boolean status;
  if(digitalRead(firstLed) == l1 && digitalRead(secondLed) == l2 && digitalRead(thirdLed) == l3)
  {
    status = true;
  }
  else{
    status = false;
  }
  return status;
}

