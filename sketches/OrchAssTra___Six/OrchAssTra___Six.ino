#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

// Variables

const int NUM_SWITCHES = 6; // NUMBER OF BUTTONS

int switches[NUM_SWITCHES] = {2,3,4,5,6,7}; // PIN NUMBERS FOR SWITCH ARRAY
int switchCC[NUM_SWITCHES] = {60, 61, 62, 63, 64, 65}; // MIDI NOTES
int switchState[NUM_SWITCHES];
int oGswitchState[NUM_SWITCHES] = {1};
 
//MIDI Defaults

#define defaultChannel 1 // MIDI Chan 1
#define maxVelocity 127 // Max Velocity
#define minVelocity 0 // Min Velocity
#define secretCC 66 // Secret 7th Tone

void setup() {
  MIDI.begin (MIDI_CHANNEL_OMNI); //start midi
  
  //configure pins >= 2 as an input and enable the internal pull-up resistor
  for ( int i = 0; i< NUM_SWITCHES; i++) {
    pinMode(switches[i], INPUT_PULLUP);
  }
  
}

void loop() {

// Switch checker for [i]

for (int i=0; i < NUM_SWITCHES; i++) {
  
  switchState[i] = digitalRead(switches[i]); // check button on Pin 2 

  if (switchState[i] != oGswitchState[i]) { // compare vs previous state and proceed if different
    
    if (switchState[i] == LOW) { // If the button on Pin i is pushed, send a CC note message 
     
     // Serial.print("yay!");
      fPlayNote(switchCC[i]); // call a function that sends a midi note
    
    } else { // If the button on Pin i is released, send a not off CC message 
      
      fStopNote(switchCC[i]);
    //  Serial.print("nay!");
    }
    // save the current state as the last state, for next time through the loop
    oGswitchState[i] = switchState[i];

   // Now check if all six buttons are pressed i.e. switchState is all low
  
   fSumSwitches(switchState[], NUM_SWITCHES);
    
 
   }

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

// Check if all 6 buttons are down

void fSumSwitches(int arr[], int size) {
    for (int i = 0 ; i < size; i++) {
      int sum = 6;
      sum = sum - arr[i]; // if you have >0, means at least switch is still HIGH or open
        if (sum == 0) {
       //   Serial.print("yaaaaaaaaaay");
          fPlayNote(secretCC);
        } else {
          fStopNote(secretCC);
        }
  }
}
