#include <LiquidCrystal.h>          //the liquid crystal library contains commands for printing to the display

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);   // tell the RedBoard what pins are connected to the display
int button[] = {2, 4, 6};
String MenuOptions[] = {"G=UP, B=Down", "Sequence.....", "Reaction.....", "Random......"};
int CurrentMenu=0;
int pressedButton = 4;        //a variable to remember which button is being pressed. 4 is the value if no button is being pressed.
bool isPlaying = false;


//===========BEFORE UPLOADING, SET LED AND BUTTON PINS FOR YOUR ARDUINO CONFIGURATION HERE================
const int leftLEDPin = A2;
const int midLEDPin = A3;
const int rightLEDPin = A4;
const int leftButtonPin = 2;
const int midButtonPin = 4;
const int rightButtonPin = 6;

int q = 0;
int game_on = 0;
int wait = 0;
int currentlevel = 6; //Determines how long the pattern will be. 
long rand_num = 0; 
int rando = 0; 
int pinandtone = 0; 
int right = 0; 
int speedfactor = 3; 

int buttonState[] = {0,0,0};         
int lastButtonState[] = {0};    
int buttonPushCounter[] = {0}; 

const int button1 = 2;           
const int button2 = 4;          
const int button3 = 6;                  
  
const int led1 = A2;             
const int led2 = A3;             
const int led3 = A4;  

//======================END==========================================================



void setup() {
  lcd.begin(16, 2);                 //tell the lcd library that we are using a display that is 16 characters wide and 2 characters high
  lcd.clear();                      //clear the display


  int pressedButton = 5;        //a variable to remember which button is being pressed. 4 is the value if no button is being pressed.
  //set all of the button pins to input_pullup (use the built-in pull-up resistors)

  randomSeed(analogRead(5));

}

void loop() {
  // put your main code here, to run repeatedly:
  if (isPlaying == false){
  
    lcd.setCursor(0, 0);              //set the cursor to the 0,0 position (top left corner)
    lcd.print("Select a game!");       //print hello, world! starting at that position
    lcd.setCursor(0, 1);              //move the cursor to the first space of the bottom row
  
    
    lcd.print(MenuOptions[CurrentMenu]);
    //lcd.print (buttonCheck());
  
    if (CurrentMenu > 3){
      CurrentMenu = 0;
    }
    if (CurrentMenu < 0){
      CurrentMenu = 3;
    }
  
    if (buttonCheck() != 5) {
        if (buttonCheck() == 0){
         CurrentMenu++;
         delay(500); 
        }
        if (buttonCheck() == 2){
         CurrentMenu--;
         delay(500); 
        }
        if (CurrentMenu == 4){
          CurrentMenu=0;
         delay(500);
          }
        if (buttonCheck() == 1){
          if (CurrentMenu == 0){
            //GameOne();
          }
          if (CurrentMenu == 1){
            GameTwo();
          }
          if (CurrentMenu == 2) {
            GameThree();
          }
          if (CurrentMenu == 3) {
            if(random(0,3) == 0){
              //GameOne();
            }
            if(random(0,3) == 1){
              GameTwo();
            }
            if(random(0,3) == 2){
              GameThree();
            }
          }
        }
      }
  }
}

int buttonCheck() {
  //check if any buttons are being pressed
  if (digitalRead(button[0]) == HIGH) {
    return 0;} 
  else if (digitalRead(button[1]) == HIGH) {
    return 1;}  
  else if (digitalRead(button[2]) == HIGH) {
    return 2;}
  else {
    return 5;}
}

//-----------------------------------------------counting game

//------------------------------------------------sequence game

void GameTwo() {
  isPlaying = true;
  lcd.clear();
//setup function
  randomSeed(analogRead(0));
  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  lcd.begin(16,2);
  lcd.clear();
//setup function  
  while (isPlaying == true){
int n_array[currentlevel];
int u_array[1];
int random_postion_in_n_array = 0; 
//Within the pattern, the arduino will never ask for the first or last LED that flashed. 
random_postion_in_n_array = random(1, currentlevel); 
int i;

// Generates random array of numbers and stores in n_array. 
if (game_on == 0){
for(i=0; i<currentlevel; i=i+1){
        n_array[i]=0;
        u_array[i]=0;
        rand_num = random(1,150);
        if (rand_num <= 50)
          rando=0;
        else if (rand_num>50 && rand_num<=100)
          rando=1;
        else if (rand_num>100 && rand_num<=150)
          rando=2;
        
         n_array[i]=rando;
      }
 game_on = 1; 
}

lcd.clear();
lcd.setCursor(0,0);
lcd.print("Try to remember");
lcd.setCursor(0,1);
lcd.print("the pattern");
delay(2000);
lcd.clear();
lcd.print("Push any button");
lcd.setCursor(0,1);
lcd.print("to Start");
while (digitalRead(2) == LOW && digitalRead(4) == LOW && digitalRead(6) == LOW)
{
  }
lcd.clear();
lcd.print("Get ready");
delay(2000);
lcd.clear();
lcd.print("Go!!");
delay(500);
lcd.clear();
delay(500);

//Flashes LEDs lights in accordance to the ramdom values stored in n_array
if (wait == 0){
 delay (200);
i = 0;
for (i = 0; i < currentlevel; i= i + 1){
      pinandtone = n_array[i];
      if (pinandtone+2 == 2){
        digitalWrite(A2, HIGH);
      delay(600);
      digitalWrite(A2, LOW);
      delay(100/speedfactor);
      }
      if (pinandtone+2 == 3){
        digitalWrite(A3, HIGH);
      delay(600);
      digitalWrite(A3, LOW);
      delay(100/speedfactor);
      }
      if (pinandtone+2 == 4){
        digitalWrite(A4, HIGH);
      delay(600);
      digitalWrite(A4, LOW);
      delay(100/speedfactor);
      }
    }
    wait = 2;
}

lcd.clear();
lcd.setCursor(0,0);
lcd.print("The LEDs will");
lcd.setCursor(0,1);
lcd.print("flash again now");
delay(2000);
lcd.clear();
lcd.print("Get ready!");
delay (1000);
lcd.clear();
delay(300);
//The pattern of lights will stop at a ramdom color in the pattern
if (wait==2)
{
  delay (1200);
i = 0;
  for (i = 0; i < random_postion_in_n_array; i= i + 1){
      pinandtone = n_array[i];
      if (pinandtone+2 == 2){
        digitalWrite(A2, HIGH);
      delay(600);
      digitalWrite(A2, LOW);
      delay(100/speedfactor);
      }
      if (pinandtone+2 == 3){
        digitalWrite(A3, HIGH);
      delay(600);
      digitalWrite(A3, LOW);
      delay(100/speedfactor);
      }
      if (pinandtone+2 == 4){
        digitalWrite(A4, HIGH);
      delay(600);
      digitalWrite(A4, LOW);
      delay(100/speedfactor);
      }
    }
    wait = 1;
 }
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Guess the next");
lcd.setCursor(0,1);
lcd.print("color");
delay(500);
//User will press a button. Arduino will store the input. And it will compare it with the missing LED color light.
i = 0;
int buttonchange = 0;  
int input_value = 0;    
int j = 0; 
while (j < 1){    
  //Arduino will read the when a button is pressed and it will store the value in the ButtonState array. 
    while (buttonchange == 0){
          for (i = 0; i < 3; i = i + 1){ 
          buttonState[i] = digitalRead(2*(i+1)); 
          buttonchange = buttonchange + buttonState[i];
        }
    }
    //If a button is pressed the correcponding LED light will flash.
     if (buttonState[0] == HIGH){
            digitalWrite(A2, HIGH);
            delay(300);
            digitalWrite(A2, LOW);
            wait = 0;
            //Stores the value of the button pressed in u_array.
            u_array[0]=0; 
            buttonState[0] = LOW;
            buttonchange = 0;
         }
         if (buttonState[1] == HIGH){
            digitalWrite(A3, HIGH);
            delay(300);
            digitalWrite(A3, LOW);
            wait = 0;
            //Stores the value of the button pressed in u_array.
            u_array[0]=1; 
            buttonState[1] = LOW;
            buttonchange = 0;
         }
         if (buttonState[2] == HIGH){
            digitalWrite(A4, HIGH);
            delay(300);
            digitalWrite(A4, LOW);
            wait = 0;
            //Stores the value of the button pressed in u_array.
            u_array[0]=2; 
            buttonState[2] = LOW;
            buttonchange = 0;
         }
//If statements for if you win or loose
        if (u_array[0] == n_array[random_postion_in_n_array]){
            j++;  
            right = 1;
            game_on = 0;
            }
        else{
            right = 0;
            i = 4;
            j = currentlevel;
            wait = 0;
            game_on = 0;
        }
}
//If you lose, the LEDs will flash at the same time. This happens twice. 
if (right == 0){
  delay(500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("You Lose :(");
  delay(800);
  i = 0;
  game_on = 0;
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  digitalWrite(A4, HIGH);
   delay(200);
   digitalWrite(A2, LOW);
   digitalWrite(A3, LOW);
   digitalWrite(A4, LOW);
   delay(200);
   digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  digitalWrite(A4, HIGH);
   delay(200);
   digitalWrite(A2, LOW);
   digitalWrite(A3, LOW);
   digitalWrite(A4, LOW);
       game_on = 0;
       isPlaying = false;
}

// If you win, the LEDs will flash once in a row. 
if (right == 1){
    delay(500);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("You Win! :)");
    delay(800);
    wait = 0;
    game_on = 0;
   digitalWrite(A2, HIGH);
   delay(200);
   digitalWrite(A2, LOW);
   digitalWrite(A3, HIGH);
   delay(200);
   digitalWrite(A3, LOW);
   digitalWrite(A4, HIGH);
   delay(200);
   digitalWrite(A4, LOW);
   delay(1500);
   isPlaying = false;
    }
   
//GAME CODE END    
    
  if (digitalRead(button[0]) == HIGH && digitalRead(button[1]) == HIGH and digitalRead(button[2] == HIGH)){
    Reset();
    }
  }
}
//------------------------------------------------sequence game end
//------------------------------------------------reaction time

void GameThree() {
  isPlaying = true;
  lcd.clear();

  LiquidCrystal lcd(13, 12, 11, 10, 9, 8);   // tell the RedBoard what pins are connected to the display

  int long ranDelay = 0;
  int sensorValue = 0;
  float realTime;

  Serial.begin(9600);
  pinMode(A3, OUTPUT);
  pinMode(4, INPUT_PULLUP); 
  lcd.begin(16, 2);                 //tell the lcd library that we are using a display that is 16 characters wide and 2 characters high
  lcd.clear();                      //clear the display
  
  while (isPlaying == true){
    
    //GAME CODE BEGINS HERE

  lcd.setCursor(0,0);
  lcd.print("Push Red button");
  lcd.setCursor(0,1);
  lcd.print("to start game");
  delay(1000);
  
  while (digitalRead(4)== LOW) 
  {
  }
  delay(800);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("*To stop timer");
  lcd.setCursor(0,1);
  lcd.print("push red button*");
  delay(4000);
  lcd.clear();
  lcd.print("Get ready!");
  delay(1500);
  lcd.clear();
  lcd.print("Get set!");
  delay(1500);
  ranDelay = random(5000);
  delay(ranDelay);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Go!");
  
  realTime = millis();
  digitalWrite(A3, LOW);
 
  
  while (digitalRead(4)== LOW) 
  {
  }
  analogWrite(A3, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Your time was");
  realTime = millis()-realTime;
  lcd.setCursor(0,1);
  lcd.print(realTime/1000,2);
  //Serial.println(" seconds");
 delay(8000); 
 lcd.clear();
 isPlaying = false;
  
  //GAME CODE END
    
 if (digitalRead(button[0]) == HIGH && digitalRead(button[1]) == HIGH && digitalRead(button[2] == HIGH)){
 Reset();
    }
  }
}

//----------------------------------------------------reaction time game end

void Reset() {
  lcd.clear();
  isPlaying = false;
  lcd.setCursor(0, 0);
  
}

/*
//-----------------------------------------Functions for counting game

void updateLed_A_State(int led_A_Interval) {

  if (led_A_State == LOW) {
    if (currentMillis - previousLed_A_Millis >= led_A_Interval) {
       led_A_State = HIGH;
       r++;
       previousLed_A_Millis += led_A_Interval;
    }
  }
  else {
    if (currentMillis - previousLed_A_Millis >= blinkDuration) {
       led_A_State = LOW;
       previousLed_A_Millis += blinkDuration;
    } 
  }    
}

//========================================

void updateLed_B_State(int led_B_Interval) {

  if (led_B_State == LOW) {
    if (currentMillis - previousLed_B_Millis >= led_B_Interval) {
       led_B_State = HIGH;
       g++;
       previousLed_B_Millis += led_B_Interval;
    }
  }
  else {
    if (currentMillis - previousLed_B_Millis >= blinkDuration) {
       led_B_State = LOW;
       previousLed_B_Millis += blinkDuration;
    }
  }    
}

//========================================

void updateLed_C_State(int led_C_Interval) {

  if (led_C_State == LOW) {
    if (currentMillis - previousLed_C_Millis >= led_C_Interval) {
       led_C_State = HIGH;
       b++;
       previousLed_C_Millis += led_C_Interval;
    }
  }
  else {
    if (currentMillis - previousLed_C_Millis >= blinkDuration) {
       led_C_State = LOW;
       previousLed_C_Millis += blinkDuration;
    }
  }    
}

//========================================

void switchLeds() {
      // this is the code that actually switches the LEDs on and off

  digitalWrite(led_A_Pin, led_A_State);
  digitalWrite(led_B_Pin, led_B_State);
  digitalWrite(led_C_Pin, led_C_State);
}

//------------------------------------------end functions for counting game
*/
