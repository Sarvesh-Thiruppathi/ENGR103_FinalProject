# ENGR103 Final Project - Pattern Matching Gamer

### Overview of Concept
When the game starts, the board will display a pattern using the NeoPixel Strip. The player is tasked with memorizing the pattern and then utilizing a combination of inputs (buttons and switches) to recreate the pattern.
<hr>
### Difficulty Progression and Scoring
The game will start with only a single NeoPixel and as the user progresses through levels, the number of NeoPixels used for the pattern will increase until the player reaches a stage where all ten NeoPixel are being used. Scoring will be based on the how many Pixels are correctly matched. Only one point can be earned on level one, two on level two and so on until the player reaches level ten by which point a total of fifty-five points.
<hr>
### Controls

![Annotated Diagram of CPX Board](https://github.com/Sarvesh-Thiruppathi/ENGR103_FinalProject/assets/27435723/3ea50835-a2f0-4f86-aa0c-f5697d13ea53)

**Left Button:** Used as a cursor to select the Pixel. The highlighted pixel can be identified by the blinking blue Pixel.

**Right Button:** Used to change the color of the slected Pixel. The options are in the following order: Off -> White -> Red

**Switch:** Flipping the switch advances the game to the next stage. It is used to start entering patterns once the player has memorized the pattern. Once the play finished entering the pattern, the switch can be pushed again to submit pattern for scoring and advancing to the next level.
<hr>
### Score Display
![Base Two Score Display](https://github.com/Sarvesh-Thiruppathi/ENGR103_FinalProject/assets/27435723/2ebb11db-e508-4a26-b842-ae22126b00f3)

Eight NeoPixels will be used to display the score using Base 2. Red indicates that the value coressponding to that Pixel is active.
<hr>

### Project Specifications:

Outputs: NeoPixel and Speaker
Input: Buttons and Switch
