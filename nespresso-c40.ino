/*YuhiAida 
The large coffe is set to 100ml~ while the short is set to 50ml~
*/

int hOffShort=2000; //Cooldown time(OFF) for the heating element in a short coffe
int hOffLarge=4000; //Cooldown time(OFF) for the heating element in a large coffe 
int onShort=4000; //Time the heating element is ON when a short coffe is selected
int onLarge=9000; //Time the heating element is ON when a large coffe is selected

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
  // put your main code here, to run repeatedly:
  int button1=digitalRead(6); //short coffe
  int button2=digitalRead(5); //large coffe

  if (button1==LOW) { //short
    digitalWrite(3, HIGH); //turn on led for short coffe
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
    digitalWrite(3, LOW); //Turn off led for short coffe
    delay(1000);
    
    
  }else if (button2==LOW) { //largo
    digitalWrite(2, HIGH); //turn on led for short coffe
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
    delay(2000);
    digitalWrite(17, HIGH); //Turns off pump
    digitalWrite(2, LOW);
    delay(1000);
    }

}
