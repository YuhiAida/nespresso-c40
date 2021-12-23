int hofflargo=8000;
int hoffcorto=6000;
int onShort=9000;
int onLarge=8500;

void setup() {
pinMode(19, OUTPUT); //relay1, heater
pinMode(17, OUTPUT); //relay2, pump
pinMode(6, INPUT_PULLUP);  //button1 corto
pinMode(5, INPUT_PULLUP);  //button2 largo
pinMode(3, OUTPUT); //led1 corto
pinMode(2, OUTPUT); //led2 largo
digitalWrite(19, HIGH);
digitalWrite(17, HIGH);
digitalWrite(3, LOW);
digitalWrite(2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int button1=digitalRead(6); //corto
  int button2=digitalRead(5); //largo

  if (button1==LOW) { //CORTO
    digitalWrite(3, HIGH); //turn on led for short coffe
    digitalWrite(19, LOW); //Turns on the heater x secs
    digitalWrite(17, LOW); //Turns on the pump x secs
    delay(onShort);
    digitalWrite(19, HIGH); //Turns off heater
    delay(hofflargo);  //cooldown heater
    digitalWrite(19, LOW); //Turns on heater again
    delay(onShort);
    digitalWrite(19, HIGH); //Turns off heater
    delay(hofflargo);  //cooldown heater
    digitalWrite(19, LOW); //Turns on heater again
    delay(onShort);
    digitalWrite(19, HIGH); //Turns off heater   
    delay(2000);
    digitalWrite(17, HIGH); //Turns off pump
    digitalWrite(3, LOW); //Turn off led for short coffe
    delay(1000);
    
    
  }else if (button2==LOW) { //LARGO
    digitalWrite(2, HIGH); //turn on led for short coffe
    digitalWrite(19, LOW); //Turns on the heater 3 secs(pre heat)
    //delay(2000);
    digitalWrite(17, LOW); //Turns on the pump 15 secs
    delay(onLarge);
    digitalWrite(19, HIGH); //Turns off heater
    delay(hofflargo);  //cooldown heater
    digitalWrite(19, LOW); //Turns on heater again
    delay(onLarge);
    digitalWrite(19, HIGH); //Turns off heater
    delay(hofflargo);  //cooldown heater
    digitalWrite(19, LOW); //Turns on heater again
    delay(onLarge);
    digitalWrite(19, HIGH); //Turns off heater
    delay(hofflargo);  //cooldown heater
    digitalWrite(19, LOW); //Turns on heater again
    delay(onLarge);
    digitalWrite(19, HIGH); //Turns off heater
    delay(hofflargo);  //cooldown 
    digitalWrite(19, LOW); //Turns on heater again
    delay(onLarge);
    digitalWrite(19, HIGH); //Turns off heater  
    delay(hofflargo);  //cooldown 
    digitalWrite(19, LOW); //Turns on heater again
    delay(onLarge);
    digitalWrite(19, HIGH); //Turns off heater
    delay(hofflargo);  //cooldown heater
    digitalWrite(19, LOW); //Turns on heater again
    delay(onLarge);
    digitalWrite(19, HIGH); //Turns off heater
    delay(hofflargo);  //cooldown heater
    digitalWrite(19, LOW); //Turns on heater again
    delay(onLarge);
    digitalWrite(19, HIGH); //Turns off heater    
    delay(2000);
    digitalWrite(17, HIGH); //Turns off pump
    digitalWrite(2, LOW);
    delay(1000);
    }

}
