//Fire Fighting Code
//Kevin Chow & Mohammad Biglari-Abhari
#include <Servo.h>

//Analogue input pin for the phototransistor
#define pin A10

///Initialising the servo motors
Servo myServo;
//The current pin for the servo motor
int servoPin = 4; //check whether this is actually free or not

//Initalised variables for the maximum light reading and also the position of that maximum light reading
int maxLightReading = 0;
int maxLightPos = 0;
bool oneRound = false;

void setup() 
{
  //Serial setting of 9600 for the baudrate
  Serial.begin (9600);
  //Setting A10 as an input
  pinMode (pin, INPUT); 
  //Setting up the servo motor
  myServo.attach(servoPin);
}

void loop() {
 if(oneRound == false){
  //For angle of 0 to 180, the servo will sweep through, read from the phototransistor and compare whether the reading is larger than the current stored value for
  //the largest light reading and also its corresponding position (this will not change if it is smaller or equal to)
  for (int i=0; i<=180; i++) {
    //Move to the current positon of i
    myServo.write(i);
    float voltage = analogRead(pin);
    if(voltage > maxLightReading){
      maxLightReading = voltage;
      maxLightPos = myServo.read();    
    }
    delay(20);
    oneRound = true;
    } 
  }
  //Move the servo to the position of the maximum light reading
  myServo.write(maxLightPos);
} 
/*



delay(100);
}
*/
