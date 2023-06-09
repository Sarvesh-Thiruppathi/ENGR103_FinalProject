//Functions to change volatile bools (flags) for button/switch changes to True
void button1Update() {
  button1PressFlag = true;
}

void button2Update() {
  button2PressFlag = true;
}

void switchUpdate() {
  switchChangeFlag = true;
}


//Generates a pattern and updates global bool
void generatePattern(int level) {
  int pixelsUsed = 0;
  
  while (pixelsUsed < level) {
    for (int i = 0; i <= 9 && pixelsUsed < level; i++)
    {
      int randValue = random(0, 3);
       {
        if ((randValue == 1 || randValue == 2) && (pattern[i] == 0)){
          pixelsUsed++;
          pattern[i] = randValue;
        }
      } 
    }
  }
}

//Resets the integer arrays by setting the pattern to all 0s
void resetPatterns(){
  for (int i = 0; i <= 9; i++)
  {
    pattern[i] = 0;
    userPattern[i] = 0;
  }

}

//Displays pattern on NeoPixels
void displayPattern(){
  CircuitPlayground.clearPixels();

  for (int i = 0; i<=9; i++)
  {
    if(pattern[i] == 0){

    }
    else if(pattern[i] == 1)
    {
      CircuitPlayground.setPixelColor(i, 255,255,255); //Set Color to White
    }
    else if(pattern[i] == 2)
    {
      CircuitPlayground.setPixelColor(i, 255,0,0); //Set Color to Red
    }
  }
}

void getUserInput() {
  CircuitPlayground.clearPixels();
  button1PressFlag = false;
  button2PressFlag = false;

  int pixel = 0;

  while (!switchChangeFlag){
    if (button1PressFlag) {
      button1PressFlag =  false;
      
      if (userPattern[pixel] == 0) {
        userPattern[pixel] = 1;
      }
      else if (userPattern[pixel] == 1) {
        userPattern[pixel] = 2;
      }
      else if (userPattern[pixel] == 2) {
        userPattern[pixel] = 0;
      }

    }
    else if (button2PressFlag) {
      button2PressFlag = false;
      pixel = (pixel + 1)%10;
    }

    CircuitPlayground.setPixelColor(pixel,0,0,100);
    responsiveDelay(300);

    if(userPattern[pixel] == 0){
      CircuitPlayground.setPixelColor(pixel,0,0,0);
    }
    else if(userPattern[pixel] == 1)
    {
      CircuitPlayground.setPixelColor(pixel, 255,255,255); //Set Color to White
    }
    else if(userPattern[pixel] == 2)
    {
      CircuitPlayground.setPixelColor(pixel, 255,0,0); //Set Color to Red
    }
    responsiveDelay(300);
  }
  switchChangeFlag = false;

}

//Calculates score. Each correct match gives one point.
int getLevelScore() {
  int score = 0;

  for (int i = 0; i <= 9; i++){
    if ((pattern[i] == userPattern[i]) && (pattern[i] != 0))
    {
      score++;
    }
  }
  return score;
}

//Displays score using pixels in Binary
void displayScore(int score) {

  if(score > 255 && score < 0)
  {
    return;
  }

  for(int i = 0; i <= 7; i++)
  {
    CircuitPlayground.setPixelColor(i, 255,255,255);
  }

  int leftOver = score;

  //Display number in base 2 using LEDs -- White = Not activated or 0, Red = Activated or 1
  while(leftOver != 0)
  {
    if (leftOver >= 128){
      CircuitPlayground.setPixelColor(7, 255,0,0);
      leftOver -= 128;
    }
    else if (leftOver >= 64){
      CircuitPlayground.setPixelColor(6, 255,0,0);
      leftOver -= 64;
    }
    else if (leftOver >= 32){
      CircuitPlayground.setPixelColor(5, 255,0,0);
      leftOver -= 32;
    }
    else if (leftOver >= 16){
      CircuitPlayground.setPixelColor(4, 255,0,0);
      leftOver -= 16;
    }
    else if (leftOver >= 8){
      CircuitPlayground.setPixelColor(3, 255,0,0);
      leftOver -= 8;
    }
    else if (leftOver >= 4){
      CircuitPlayground.setPixelColor(2, 255,0,0);
      leftOver -= 4;
    }
    else if (leftOver >= 2){
      CircuitPlayground.setPixelColor(1, 255,0,0);
      leftOver -= 2;
    }
    else if (leftOver >= 1){
      CircuitPlayground.setPixelColor(0, 255,0,0);
      leftOver -= 1;
    }
  }

  while(true)
  {
    //Waits forever
    delay(10);
  }

}

//Constantly checks if any buttons were pressed every 10ms. This causes buttton responsiveness to increase!
void responsiveDelay(int time){
  for(int i = 0; i<= int(time/10); i++)
  {
    if(!(button2PressFlag || button1PressFlag)){
      delay(10);
    }
    else
    {
      return;
    }
  }
}
