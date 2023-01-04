## Game Design Board Game

### Project Description:

Designed and implemented a remote board game. The game is based around a heist theme. In the game, there are 2-4 players that will be competing against each other. The players will try to steal as much treasure as they can and the player with the most treasure will win. The players advance around the board by interacting with an Arduino UNO board. The board contains an LCD screen that acts as a front end for all the things the board can do. The players will have to play one of three mini games to advance in the board and collect treasure. 

### Arduino and C++ Components: 

This repository includes the code that the team utilized to play the board game. In order words, the repository contains the script that was uploaded into the Arduino UNO. I designed and implemented the pattern mini game as well as integrated my teammates code into a single running script. For the pattern game, the focus is the use of random numbers and generating a pattern of flashing lights in accordance with those numbers. Moreover, the program tracks these random numbers to respond accordingly to the user's input. One important constraint during the design of the program is the actual physical limitations of the hardware used. The Arduino UNO has a limited amount of output pins and places where the LED lights can be located. Hence, the design of the program and the final script had to be adjusted and modified to fulfill these constraints. 

### What is the "pattern mini game"?

For the pattern game you will be shown a pattern. You will then be shown the same pattern, but all the LEDs will shut off at a random point. At this point you are supposed to guess the next color in the pattern by pressing the button corresponding to that color LED. If you win, the LEDs will flash one at a time through all the colors, if you lose, all the LEDs will flash at the same time twice.

Image of the board:
![image](https://user-images.githubusercontent.com/89400862/210665979-075f742b-05ea-4a68-a90a-f13fcddad16e.png)
