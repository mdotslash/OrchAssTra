#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

// Variables

int switchA = 2; //seat switch A
int switchB = 3; //seat switch B
int switchC = 4; //seat switch C
int switchD = 5; //seat switch D
int switchE = 6; //seat switch E
int switchF = 7; //seat switch F

// Button Testers Default State
int oGswitchAstate = HIGH; // og value of button on pin2
int oGswitchBstate = HIGH; // og value of button on pin3
int oGswitchCstate = HIGH; // og value of button on pin4
int oGswitchDstate = HIGH; // og value of button on pin5
int oGswitchEstate = HIGH; // og value of button on pin6
int oGswitchFstate = HIGH; // og value of button on pin7
 
//MIDI Control Numbers
#define switchA_CC 60 // C4
#define switchB_CC 61 // C#4
#define switchC_CC 62 // D4
#define switchD_CC 63 // E4
#define switchE_CC 64 // F4
#define switchF_CC 65 // G#
#define defaultChannel 1 // MIDI Chan 1
#define maxVelocity 127 // Max Velocity
#define minVelocity 0 // Min Velocity

void setup() {
  MIDI.begin (MIDI_CHANNEL_OMNI); //start midi
  
  //configure pin 2+ as an input and enable the internal pull-up resistor

  pinMode(switchA, INPUT_PULLUP); //connect to switch A pin 2
  pinMode(switchB, INPUT_PULLUP); //connect to switch B pin 3
  pinMode(switchC, INPUT_PULLUP); //connect to switch C pin 4
  pinMode(switchD, INPUT_PULLUP); //connect to switch C pin 5
  pinMode(switchE, INPUT_PULLUP); //connect to switch C pin 6
  pinMode(switchF, INPUT_PULLUP); //connect to switch C pin 7
}

void loop() {

// Switch 2

int switch_state = digitalRead(switchA); // check button on Pin 2 

if (switch_state != oGswitchAstate) { // compare vs previous state and proceed if different
  
  if (switch_state == LOW) { // If the button on Pin2 is pushed, send a CC note message 
   
    fPlayNote(switchA_CC); // call a function that sends a midi note
  
  } else { // If the button on Pin2 is released, send a not off CC message 
    
    fStopNote(switchA_CC);
  }
  // save the current state as the last state, for next time through the loop
  oGswitchAstate = switch_state;
  }


// Switch 3

int switchB_state = digitalRead(switchB); // check button on Pin 3 

if (switchB_state != oGswitchBstate) { // compare vs previous state and proceed if different
  
  if (switchB_state == LOW) { // If the button on Pin3 is pushed, send a CC note message 
   
    fPlayNote(switchB_CC); // call a function that sends a midi note
  
  } else { // If the button on Pin3 is released, send a not off CC message 
    
    fStopNote(switchB_CC);
  }
  // save the current state as the last state, for next time through the loop
  oGswitchBstate = switchB_state;
  }

// Switch 4

int switchC_state = digitalRead(switchC); // check button on Pin 4

if (switchC_state != oGswitchCstate) { // compare vs previous state and proceed if different
  
  if (switchC_state == LOW) { // If the button on Pin4 is pushed, send a CC note message 
   
    fPlayNote(switchC_CC); // call a function that sends a midi note
  
  } else { // If the button on Pin4 is released, send a not off CC message 
    
    fStopNote(switchC_CC);
  }
  // save the current state as the last state, for next time through the loop
  oGswitchCstate = switchC_state;
  }

// Switch 5

int switchD_state = digitalRead(switchD); // check button on Pin 5

if (switchD_state != oGswitchDstate) { // compare vs previous state and proceed if different
  
  if (switchD_state == LOW) { // If the button on Pin5 is pushed, send a CC note message 
   
    fPlayNote(switchD_CC); // call a function that sends a midi note
  
  } else { // If the button on Pin5 is released, send a not off CC message 
    
    fStopNote(switchD_CC);
  }
  // save the current state as the last state, for next time through the loop
  oGswitchDstate = switchD_state;
  }

  // Switch 6

int switchE_state = digitalRead(switchE); // check button on Pin 6

if (switchE_state != oGswitchEstate) { // compare vs previous state and proceed if different
  
  if (switchE_state == LOW) { // If the button on Pin 6 is pushed, send a CC note message 
   
    fPlayNote(switchE_CC); // call a function that sends a midi note
  
  } else { // If the button on Pin5 is released, send a not off CC message 
    
    fStopNote(switchE_CC);
  }
  // save the current state as the last state, for next time through the loop
  oGswitchEstate = switchE_state;
  }

  // Switch 7

int switchF_state = digitalRead(switchF); // check button on Pin 7

if (switchF_state != oGswitchFstate) { // compare vs previous state and proceed if different
  
  if (switchF_state == LOW) { // If the button on Pin 7 is pushed, send a CC note message 
   
    fPlayNote(switchF_CC); // call a function that sends a midi note
  
  } else { // If the button on Pin5 is released, send a not off CC message 
    
    fStopNote(switchF_CC);
  }
  // save the current state as the last state, for next time through the loop
  oGswitchFstate = switchF_state;
  }

}

// play function

void fPlayNote(int ccNote) {
  MIDI.sendNoteOn(ccNote, maxVelocity, defaultChannel);
}

// stop function

void fStopNote(int ccNote) {
  MIDI.sendNoteOn(ccNote, minVelocity, defaultChannel);
}

// factory functions


// fSwitchCheck checks the state of a button

//int fSwitchCheck(int switchX, int midiX){ 
//  int xOld;
//  result = x * y;
//  return result;
//
//}
