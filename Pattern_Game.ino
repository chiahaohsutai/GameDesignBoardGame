const int button1 = 2;           
const int button2 = 4;          
const int button3 = 6;                  
  
const int led1 = A2;             
const int led2 = A3;             
const int led3 = A4;                 

int game_on = 0;
int wait = 0;
int currentlevel = 8; //Determines how long the pattern will be. 
long rand_num = 0; 
int rando = 0; 
int pinandtone = 0; 
int right = 0; 
int speedfactor = 3; 
int gamestart = 0;

int buttonState[] = {0,0,0};         
int lastButtonState[] = {0};    
int buttonPushCounter[] = {0}; 

void setup() {
  randomSeed(analogRead(0));
  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {

int n_array[currentlevel];
int u_array[1];
int random_postion_in_n_array = 0; 
//Within the pattern, the arduino will never ask for the first or last LED that flashed. 
random_postion_in_n_array = random(1, currentlevel); 
int i;

if (gamestart == 0){
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

//The pattern of lights will stop at a ramdom color in the pattern
if (wait==2){
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
            wait = 0;
            }
        else{
            right = 0;
            i = 4;
            j = currentlevel;
            wait = 0;
        }
}
//If you lose, the LEDs will flash at the same time. This happens twice. 
if (right == 0){
  delay(500);
  i = 0;
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
       gamestart = 1;
}

// If you win, the LEDs will flash once in a row. 
if (right == 1){
    delay(500);
    wait = 0;
    game_on = 0;
    gamestart = 1;
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
    }
}
}
