#include <Arduino.h>
#define LED_BUILTIN 14
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <FastLED.h>
#define DATA_PIN 2
#define NUM_LEDS 8
CRGB leds[NUM_LEDS];
#define LED_TYPE WS2812B
LiquidCrystal_I2C lcd(0x27, 16, 2); //adres I2C, szerokość i wysokość wyświetlacza
#define SensorPin 0          // the pH meter Analog output is connected with the Arduino’s Analog
unsigned long int avgValue;  //Store the average value of the sensor feedback
int buf[10], temp;
int pH_Value;

void setup() {
lcd.init();
lcd.backlight();
lcd.setCursor(0, 0);
lcd.print("Hello, World!");
pinMode(13,OUTPUT);  
FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
FastLED.clear();
randomSeed(analogRead(2));

}

void loop() {
  // put your main code here, to run repeatedly:
 for(int i=0;i<10;i++)       //Get 10 sample value from the sensor for smooth the value
  { 
    buf[i]=analogRead(SensorPin);
    delay(10);
  }
  for(int i=0;i<9;i++)        //sort the analog from small to large
  {
    for(int j=i+1;j<10;j++)
    {
      if(buf[i]>buf[j])
      {
        temp=buf[i];
        buf[i]=buf[j];
        buf[j]=temp;
      }
    }
  }
  avgValue=0;
  for(int i=2;i<8;i++)                      //take the average value of 6 center sample
    avgValue+=buf[i];
  float phValue=(float)avgValue*5.0/1024/6; //convert the analog into millivolt
  phValue=3.5*phValue;                      //convert the millivolt into pH value
  lcd.clear();
  lcd.setCursor(0, 0);                  
  lcd.print("pH:");  
  lcd.print(phValue);
  if(0<=phValue&&phValue<1)
  {
    for(int i=0;i<NUM_LEDS;i++)
    {
      leds[i] = CRGB(28, 238, 37);
      FastLED.setBrightness(2);
      FastLED.show();
    }
  }
  else if(1<=phValue&&phValue<2)
  {
    for(int i=0;i<NUM_LEDS;i++)
    {
      leds[i] = CRGB(103,242,  36);
      FastLED.setBrightness(2);
      FastLED.show();
    }
  }
    else if(2<=phValue&&phValue<3)
  {
    for(int i=0;i<NUM_LEDS;i++)
    {
      leds[i] = CRGB(198,248,  17);
      FastLED.setBrightness(2);
      FastLED.show();
    }
  }
    else if(3<=phValue&&phValue<4)
  {
    for(int i=0;i<NUM_LEDS;i++)
    {
      leds[i] = CRGB(237,245,  28);
      FastLED.setBrightness(2);
      FastLED.show();
    }
  }
    else if(4<=phValue&&phValue<5)
  {
    for(int i=0;i<NUM_LEDS;i++)
    {
      leds[i] = CRGB(211,181,  53);
      FastLED.setBrightness(2);
      FastLED.show();
    }
  }
    else if(5<=phValue&&phValue<6)
  {
    for(int i=0;i<NUM_LEDS;i++)
    {
      leds[i] = CRGB(195,132,  65);
      FastLED.setBrightness(2);
      FastLED.show();
    }
  }
    else if(6<=phValue&&phValue<7)
  {
    for(int i=0;i<NUM_LEDS;i++)
    {
      leds[i] = CRGB(183,77,  73);
      FastLED.setBrightness(2);
      FastLED.show();
    }
  }
    else if(7<=phValue&&phValue<8)
  {
    for(int i=0;i<NUM_LEDS;i++)
    {
      leds[i] = CRGB(169,51,  75);
      FastLED.setBrightness(2);
      FastLED.show();
    }
  }
    else if(8<=phValue&&phValue<9)
  {
    for(int i=0;i<NUM_LEDS;i++)
    {
      leds[i] = CRGB(180,34,  107);
      FastLED.setBrightness(2);
      FastLED.show();
    }
  }
    else if(9<=phValue&&phValue<10)
  {
    for(int i=0;i<NUM_LEDS;i++)
    {
      leds[i] = CRGB(184,10,  183);
      FastLED.setBrightness(2);
      FastLED.show();
    }
  }

    else if(10<=phValue&&phValue<11)
  {
    for(int i=0;i<NUM_LEDS;i++)
    {
      leds[i] = CRGB(144,70,  205);
      FastLED.setBrightness(2);
      FastLED.show();
    }
  }
    else if(11<=phValue&&phValue<12)
  {
    for(int i=0;i<NUM_LEDS;i++)
    {
      leds[i] = CRGB(82, 57, 164);
      FastLED.setBrightness(2);
      FastLED.show();
    }
  }
    else if(12<=phValue&&phValue<13)
  {
    for(int i=0;i<NUM_LEDS;i++)
    {
      leds[i] = CRGB(81, 90, 162);
      FastLED.setBrightness(2);
      FastLED.show();
    }
  }
    else if(13<=phValue&&phValue<=14)
  {
    for(int i=0;i<NUM_LEDS;i++)
    {
      leds[i] = CRGB(69, 99, 157);
      FastLED.setBrightness(2);
      FastLED.show();
    }
  }
  digitalWrite(13, HIGH);       
  delay(800);
  digitalWrite(13, LOW);  
}