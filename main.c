/*----------------------------------------------------------------------------
Final Project - Piano 
*----------------------------------------------------------------------------*/

#include "mbed.h"
#include "pindef.h"

// Define input bus
DigitalIn key_one(PA_10);
DigitalIn key_two(PB_3);
DigitalIn key_three(PB_5);
DigitalIn key_four(PB_4);

// Define variables
PwmOut speaker(PB_10);          // Define PWM speaker output
AnalogIn volume(PA_0);          // Define volume input one

float input;

/*----------------------------------------------------------------------------
MAIN function
*----------------------------------------------------------------------------*/

int main(){

   while(1){

       // Play the intro tune
       if (!key_one)
       {
           for(int i = 0; i < 3; i++){
               speaker.period(1.0/2637); // 0.3792ms Period
               speaker = (volume.read()); // Set volume
               wait(.68965517); // Wait the equivalent of a quarter note
               speaker = 0.0; // turn off audio
               wait(0.5);
           }

           speaker.period(1.0/1318.5); // 0.7584ms Period
           speaker = (volume.read()); // Set volume
           wait(.68965517);
           speaker = 0.0; // Turn off audio
           wait(0.5);

           for(int i = 0; i < 3; i++){
               speaker.period(1.0/2489.5); // 0.40169ms Period
               speaker = (volume.read()); // Set volume
               wait(.68965517);
               speaker = 0.0; // turn off audio
               wait(0.5);
           }

           speaker.period(1.0/1244.5); // 0.8035ms Period
           speaker = (volume.read()); // Set volume
           wait(.68965517);
           speaker = 0.0; // turn off audio
           wait(0.5);
          
           for(int i = 0; i < 3; i++){
               speaker.period(1.0/2217.5); // 0.45096ms Period
               speaker = (volume.read()); // Set volume
               wait(.68965517);
               speaker = 0.0; // turn off audio
               wait(0.5);
           }
          
           speaker.period(1.0/1108.7); // 0.90196ms Period
           speaker = (volume.read()); // Set volume
           wait(.68965517);
           speaker = 0.0; // turn off audio
           wait(0.5);
          
           for(int i = 0; i < 2; i++){
               speaker.period(1.0/1760.0); // 0.7584ms Period
               speaker = (volume.read()); // Set volume
               wait(.68965517);
               speaker = 0.0; // turn off audio
               wait(0.5);
           }
          
           speaker.period(1.0/1661.2); // 0.56818ms Period
           speaker = (volume.read()); // Set volume
           wait(.68965517);
           speaker = 0.0; // turn off audio
           wait(0.5);
          
           speaker.period(1.0/2637); // 0.37922ms Period
           speaker = (volume.read()); //set volume
           wait(.68965517);
           speaker=0.0; // turn off audio
           wait(0.5);
          
       }
      
       // Sweep up frequency
       if (!key_two)
       {
           for (int i = 100; i<6000; i=i+100)
           {
               speaker.period(1.0/float(i));
               speaker = 0.25;
               wait(.1);
           }
           speaker = 0.0; // turn off audio
           wait(0.05);
       }
      
       // Produce sound on button press
       if (!key_three)
       {
           speaker.period(1.0/1661.2); // 0.56818ms Period
           speaker = (volume.read()); //set volume
           wait(.5);
           speaker = 0.0; // turn off audio
           wait(0.05);
       }
      
       // Produce sound on button press
       if (!key_four)
       {
           speaker.period(1.0/2637); // 0.37922ms Period
           speaker = (volume.read()); //set volume
           wait(.5);
           speaker = 0.0; // turn off audio
           wait(0.05);
       }
   }
}

// *******************************ARM University Program Copyright � ARM Ltd 2016*************************************
