//ATTiny85 Hello World
//Harmony Petty 

long int beginT = millis(); // Tracks the beginning time for the timer 

//Component Variables
int led = 1;
int button = 0;

//Debouncing Variables
int butState;
int prevState;
int curStep = 0;//Controls what step the circuit is in.
boolean lit = true; // controlls the status of the Led if blinking 


void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);
pinMode(button, INPUT);
}

void loop() {
  butState= digitalRead(button);
  
  //debouncing
  if (butState == 1 && prevState == 0){
    delay(10);//Used to debounce hardware
    curStep++;
    if(curStep > 2){
      curStep = 0;
    }
  }
  prevState = butState;

  //Finite State Machine to control the "step" of the LED
  switch (curStep){
    case 0: // Off Mode
    digitalWrite (led, LOW);
    break;
    case 1: // On Mode
    digitalWrite (led, HIGH);
    break;
    case 2: // Blinking Mode
    if (millis()- beginT > 200){
      if(lit){
        lit = !lit;
      }else {
        lit = !lit;
      }
      beginT=millis();
    }

    //Control status of LED
    if(lit){
      digitalWrite(led, HIGH);
    }else { 
      digitalWrite(led,LOW);
    }
    break;
  }
  }
