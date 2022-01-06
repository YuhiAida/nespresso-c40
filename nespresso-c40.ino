/*YuhiAida 
The large coffee is set to 100ml~ while the short is set to 50ml~
*/

#include "ClickButton.h"

//ShortCoffee
const int buttonPin1 = 6; 
ClickButton button1(buttonPin1, LOW, CLICKBTN_PULLUP);

//LargeCoffee
const int buttonPin2 = 5; 
ClickButton button2(buttonPin2, LOW, CLICKBTN_PULLUP);

// Arbitrary LED function 
int function1 = 0;
int function2 = 0;

int hOffShort=2000; //Cooldown time(OFF) for the heating element in a short coffee
int hOffLarge=3000; //Cooldown time(OFF) for the heating element in a large coffee 
int onShort=4000; //Time the heating element is ON when a short coffee is selected
int onLarge=5000; //Time the heating element is ON when a large coffee is selected

void setup()
{
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT); 
  pinMode(19, OUTPUT); //relay1, heater
  pinMode(17, OUTPUT); //relay2, pump 
  digitalWrite(19, HIGH);
  digitalWrite(17, HIGH);

  // Setup button timers (all in milliseconds / ms)
  // (These are default if not set, but changeable for convenience)
  button1.debounceTime   = 20;   // Debounce timer in ms
  button1.multiclickTime = 250;  // Time limit for multi clicks
  button1.longClickTime  = 1000; // time until "held-down clicks" register
  button2.debounceTime   = 20;   // Debounce timer in ms
  button2.multiclickTime = 250;  // Time limit for multi clicks
  button2.longClickTime  = 1000; // time until "held-down clicks" register
}

//  This is used in case you run out of water in the tank, the pump just won't load until you use this function
void LoadPump()
{
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);

  for (int i = 0; i < 20; i++)
  {
    digitalWrite(17, LOW);
    delay(50);
    digitalWrite(17, HIGH);
    delay(50);
  }
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
}

//  Now that the machine doesn't have a temperature regulator the first cup will be colder so 
//  with this you can heat the water and the heater before your first coffe or if you didn't use the machine for a period of time
void HeatWatter()
{
  digitalWrite(19, LOW);
  delay(3000);
  digitalWrite(19, HIGH);
}

void CooldownHeater()
{
  digitalWrite(3, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(17, LOW);
  delay(10000);
  digitalWrite(17, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
}

void ShortCoffe()
{
  digitalWrite(3, HIGH); //turn on led for short coffee
  digitalWrite(17, LOW); //Turns on the pump 
  digitalWrite(19, LOW); //Turns on the heater

    for (int i = 0; i < 5; i++)
    {
      delay(hOffShort); //Cooldown heater
      digitalWrite(19, LOW); //Turns on the heater
      delay(onShort); //Keep the heater on
      digitalWrite(19, HIGH); //Turns off heater
    }
    delay(500);
  digitalWrite(3, LOW); //Turn off led for short coffee
  digitalWrite(17, HIGH); //Turns off pump
}

void LargeCoffee()
{
  digitalWrite(2, HIGH); //turn on led for large coffee
  digitalWrite(17, LOW); //Turns on the pump 
  digitalWrite(19, LOW); //Turns on the heater

    for (int i = 0; i < 10; i++)
    {
      delay(hOffLarge);  //cooldown heater
      digitalWrite(19, LOW); //Turns on the heater
      delay(onLarge); //Keep the heater on
      digitalWrite(19, HIGH); //Turns off heater
    }
  delay(500);
  digitalWrite(17, HIGH); //Turns off pump
  digitalWrite(2, LOW); //Turn off led for large coffee  
}

void loop()
{
  // Update button state
  button1.Update();
  button2.Update();

  // Save click codes in function1/2, as click codes are reset at next Update()
  if (button1.clicks != 0) function1 = button1.clicks;
  if (button2.clicks != 0) function2 = button2.clicks;

  switch (function1)
  {
  case 1:
    ShortCoffe();
    function1 = 0;
    break;
  case -1:
    LoadPump();
    function1 = 0;
    break;
  default:
    break;
  }

  switch (function2)
  {
  case 1:
    LargeCoffee();
    function2 = 0;
    break;
  case -1:
    HeatWatter();
    function2 = 0;
    break;
  case 2:
    CooldownHeater();
    function2 = 0;
    break;
  default:
    break;
  }
}
