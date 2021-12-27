//Version 2.0
/*YuhiAida 
The large coffee is set to 100ml~ while the short is set to 50ml~
*/

int hOffShort=2000; //Cooldown time(OFF) for the heating element in a short coffee
int hOffLarge=3000; //Cooldown time(OFF) for the heating element in a large coffee 
int onShort=4000; //Time the heating element is ON when a short coffee is selected
int onLarge=7000; //Time the heating element is ON when a large coffee is selected


//Test new feature

const byte keyPin = 5; // The switch is connected to pin number 5
int pressTime = 0; // the counter that acounnt the pressing time

void setup() {

pinMode(keyPin, INPUT_PULLUP);
pinMode(19, OUTPUT); //relay1, heater
pinMode(17, OUTPUT); //relay2, pump
pinMode(6, INPUT_PULLUP);  //button1 short
pinMode(3, OUTPUT); //led1 short
pinMode(2, OUTPUT); //led2 largo
digitalWrite(19, HIGH);
digitalWrite(17, HIGH);
digitalWrite(3, LOW);
digitalWrite(2, LOW);
}

void loop() {
byte key = digitalRead(keyPin);
if (key == LOW) { // that means the key is pressed
pressTime++;
delay(1000); // works like a timer with one second steps
if (pressTime <= 2){
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(2,HIGH);
    digitalWrite(17, LOW); //Turns on the pump x secs
    delay(300);
    digitalWrite(17, HIGH); //Turns off the pump
    digitalWrite(2,LOW);
    delay(300);
  }
  pressTime=0;
}else{
    digitalWrite(2, HIGH); //turn on led for large coffee
    digitalWrite(17, LOW); //turn on the pump
  for (int i = 0; i < 9; i++)
  {
    digitalWrite(19, LOW); //turn on the heater 
    delay(onLarge);
    digitalWrite(19, HIGH); //turn off the heater
    delay(hOffLarge);  //cooldown heater
  }
  digitalWrite(2, LOW);
  digitalWrite(17, HIGH);
  digitalWrite(19, HIGH);
}
}
else if (key == HIGH) {// key is not pressed
pressTime=0;
}

}

//End of test

/*
void setup() {
pinMode(19, OUTPUT); //relay1, heater
pinMode(17, OUTPUT); //relay2, pump
pinMode(6, INPUT_PULLUP);  //button1 short
pinMode(5, INPUT_PULLUP);  //button2 largo
pinMode(3, OUTPUT); //led1 short
pinMode(2, OUTPUT); //led2 largo
digitalWrite(19, HIGH);
digitalWrite(17, HIGH);
digitalWrite(3, LOW);
digitalWrite(2, LOW);
}

void loop() {

 
  

  int button1=digitalRead(6); //short coffee
  int button2=digitalRead(5); //large coffee

  if (button1==LOW) { //short
    digitalWrite(3, HIGH); //turn on led for short coffee
    digitalWrite(19, LOW); //Turns on the heater x secs
    digitalWrite(17, LOW); //Turns on the pump x secs
    delay(onShort);
    digitalWrite(19, HIGH); //Turns off heater
    delay(hOffShort);  //cooldown heater
    digitalWrite(19, LOW); //Turns on heater again
    delay(onShort);
    digitalWrite(19, HIGH); //Turns off heater
    delay(hOffShort);  //cooldown heater
    digitalWrite(19, LOW); //Turns on heater again
    delay(onShort);
    digitalWrite(19, HIGH); //Turns off heater   
    delay(2000);
    digitalWrite(17, HIGH); //Turns off pump
    digitalWrite(3, LOW); //Turn off led for short coffee
    delay(1000);
    
    
  }else if (button2==LOW) { //largo
    digitalWrite(2, HIGH); //turn on led for large coffee
    digitalWrite(19, LOW); //Turns on the heater 3 secs(pre heat)
    //delay(2000);
    digitalWrite(17, LOW); //Turns on the pump 15 secs
    delay(onLarge);
    digitalWrite(19, HIGH); //Turns off heater
    delay(hOffLarge);  //cooldown heater
    digitalWrite(19, LOW); //Turns on heater again
    delay(onLarge);
    digitalWrite(19, HIGH); //Turns off heater
    delay(hOffLarge);  //cooldown heater
    digitalWrite(19, LOW); //Turns on heater again
    delay(onLarge);
    digitalWrite(19, HIGH); //Turns off heater
    delay(hOffLarge);  //cooldown heater
    /*
    digitalWrite(19, LOW); //Turns on heater again
    delay(onLarge);
    digitalWrite(19, HIGH); //Turns off heater
    delay(hOffLarge);  //cooldown 
    digitalWrite(19, LOW); //Turns on heater again
    delay(onLarge);
    digitalWrite(19, HIGH); //Turns off heater  
    delay(hOffLarge);  //cooldown 
    digitalWrite(19, LOW); //Turns on heater again
    delay(onLarge);
    digitalWrite(19, HIGH); //Turns off heater
    delay(hOffLarge);  //cooldown heater
    digitalWrite(19, LOW); //Turns on heater again
    delay(onLarge);
    digitalWrite(19, HIGH); //Turns off heater
    delay(hOffLarge);  //cooldown heater
    digitalWrite(19, LOW); //Turns on heater again
    delay(onLarge);
    digitalWrite(19, HIGH); //Turns off heater    
    */
    //delay(2000);
    //digitalWrite(17, HIGH); //Turns off pump
    //digitalWrite(2, LOW);
    //delay(1000);
    //}

//}
