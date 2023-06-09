#include <Adafruit_CircuitPlayground.h>

//Define Input Pins
const byte button1Pin = 4;
const byte button2Pin = 5;
const byte switchPin = 7;


//Setup Flags for Interrupts
volatile bool button1PressFlag = false;
volatile bool button2PressFlag = false;
volatile bool switchChangeFlag = false;

//Vars to store the pattern bool
int pattern[10] = {0,0,0,0,0,0,0,0,0,0};
int userPattern[10] = {0,0,0,0,0,0,0,0,0,0};

int level = 1; //Current level of player
int score = 0; //Current score of player

void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);
  CircuitPlayground.setBrightness(5);
  randomSeed(analogRead(A1)); //Use enverionmental randomness (electrical noise) as a seed for CPX Board to generate random patterns!


  //Setup Button and Switch Interupts
  attachInterrupt(digitalPinToInterrupt(button1Pin), button1Update, FALLING); 
  attachInterrupt(digitalPinToInterrupt(button2Pin), button2Update, FALLING);
  attachInterrupt(digitalPinToInterrupt(switchPin), switchUpdate, CHANGE);

  while(!Serial){
    //Wait until Serial Monitor Open
  }
}

void loop() {
  resetPatterns(); 

  if (level <=10){
    generatePattern(level);
    displayPattern();

    while(!switchChangeFlag){
      delay(10);
    }
    switchChangeFlag = false;

    getUserInput();
    
    score += getLevelScore();
    Serial.println(score);

    
    level++;
  }
  else
  {
    displayScore(score);
  }
  Serial.println("Level: " + String(level));
}
