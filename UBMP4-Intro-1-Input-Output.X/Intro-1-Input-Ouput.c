/*==============================================================================
Project: Intro-1-Input-Output
Date:    May 16, 2021
This example UBMP4 input and output program demonstrates pushbutton input, LED
(bit) output, port latch (byte) output, time delay functions, and simple 'if'
condition structures.
Additional program analysis and programming activities demonstrate byte output,
logical condition operators AND and OR, using delay functions to create sound,
and simulated start-stop button functionality.
==============================================================================*/
 
#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdbool.h"         // Include Boolean (true/false) definitions
 
#include    "UBMP4.h"           // Include UBMP4 constants and functions
 
// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.
 
unsigned char count; //counter for mode changing
unsigned char countR; //counter for reverse mode changing
unsigned char count1; //counter for alert function
unsigned char i; //used for flashing light functions
unsigned char c; //used for note functions
unsigned char a; //used for alert function
unsigned char mode = 0; //used for changing mode

void aSound() {
    for(c = 250; c != 0; c--) {
        BEEPER = !BEEPER;
        __delay_us(119.445515);
    }
}

void bSound() {
    for(c = 250; c != 0; c--) {
        BEEPER = !BEEPER;
        __delay_us(900);
    }
}

void alertSound() {
    for(c = 250; c != 0; c--) {
        BEEPER = !BEEPER;
        __delay_us(104.1666665);
    }

    LED3 = 1;
    __delay_ms(100);
    LED3 = 0;
    __delay_ms(50);

    for(c = 250; c != 0; c--) {
        BEEPER = !BEEPER;
        __delay_us(128.205128);
    }
}

void g4() {
   for(c = 250; c != 0; c--) {
       BEEPER = !BEEPER;
       __delay_us(1275.5);
       LED6 = !LED6;
   }
}
 
void a4() {
   for(c = 250; c != 0; c--) {
       BEEPER = !BEEPER;
       __delay_us(1136.363635);
       LED5 = !LED5;
   }
}
 
void c5s() {
   for(c = 250; c != 0; c--) {
       BEEPER = !BEEPER;
       __delay_us(901.924705);
       LED4 = !LED4;
   }
}
 
void b4() {
   for(c = 250; c != 0; c--) {
       BEEPER = !BEEPER;
       __delay_us(1012.391675);
       LED3 = !LED3;
   }
}

void e6() {
    for(c = 250; c != 0; c--) {
        BEEPER = !BEEPER;
        __delay_us(379.215933);
    }
}

void noteA() {
    for(c = 250; c != 0; c--) {
        BEEPER = !BEEPER;
        __delay_us(284.090909);
    }
}

void cs() {
    for(c = 250; c != 0; c--) {
        BEEPER = !BEEPER;
        __delay_us(225.4832105);
    }
}

void e() {
   for(c = 250; c != 0; c--) {
        BEEPER = !BEEPER;
        __delay_us(189.6079665);
    } 
}

void simonGame() {
    if(SW2 == 0) {
        e6();
    }
    if(SW3 == 0) {
        noteA();
    }
    if(SW4 == 0) {
        cs();
    }
    if(SW5 == 0) {
        e();
    }
}
 
void regular() {

   //Light part
   if(SW2 == 0 && SW3 != 0 && SW5 != 0) {
          LED3 = 1;
      } else if(SW2 != 0) {
          LED3 = 0;
      }
    
      if(SW3 == 0 && SW2 != 0 && SW4 != 0 && SW5 != 0) {
          LED4 = 1;
      } else if(SW3 != 0) {
          LED4 = 0;
      }
 
      if(SW4 == 0 && SW3 != 0 && SW5 != 0) {
          LED5 = 1;
      } else if(SW4 != 0) {
          LED5 = 0;
      }
 
      if(SW5 == 0 && SW2 != 0 && SW3 != 0 && SW4 != 0) {
          LED6 = 1;
      } else if(SW5 != 0) {
          LED6 = 0;
      }

      //Multi light
      if(SW2 == 0 && SW4 == 0) {
          LED3 = 1;
          LED5 = 1;
      } else if(SW2 != 0 && SW4 != 0) {
          LED3 = 0;
          LED5 = 0;
      }

      //BEEPER part
      if(SW5 == 0 && SW2 != 0 && SW3 != 0 && SW4 != 0)
       {
           BEEPER = !BEEPER;
           __delay_us(1275.5); //G4
       } else if(SW4 == 0 && SW2 != 0 && SW3 != 0 && SW5 != 0) {
           BEEPER = !BEEPER;
           __delay_us(1136.363635); //A4
       } else if(SW3 == 0 && SW2 != 0 && SW4 != 0 && SW5 != 0) {
           BEEPER = !BEEPER;
           __delay_us(901.924705); //C5#
       } else if(SW2 == 0 && SW3 != 0 && SW4 != 0 && SW5 != 0) {
           BEEPER = !BEEPER;
           __delay_us(1012.391675); //B4
       }
}
 
void HPBD() {
   if(SW2 == 0 && SW3 == 0) {
               LED3 = 0;
               LED4 = 0;
               LED5 = 0;
               LED6 = 0;
              
               g4();
               __delay_ms(50);
               g4();
               __delay_ms(200);
               a4();
               __delay_ms(200);
               g4();
               __delay_ms(200);
               c5s();
               __delay_ms(300);
               b4();
           }
}
 
void flashing1() {
    i = 0;
 
   if(SW2 == 0 && SW4 == 0 && (SW3 != 0 && SW5 != 0)) {
        LED3 = 1;
        LED5 = 1;
        
        //flashing
        LED4 = 1;
        __delay_ms(100);
        LED6 = 1;
        __delay_ms(100);
        LED4 = 0;
        __delay_ms(100);
        LED6 = 0;
        __delay_ms(100);

        //make sound
        BEEPER = !BEEPER;
        __delay_us(1012.391675); //B4
        BEEPER = !BEEPER;
        __delay_us(1136.363635); //A4
    }

    if(SW2 == 0 && SW3 == 0 && SW4 == 0 && SW5 == 0) {
        i = 1;
    } else if(SW2 != 0 && SW3 != 0 && SW4 != 0 && SW5 != 0) {
        i = 0;
    }

    if(i == 1) {
        LED3 = 1;
        __delay_ms(100);
        LED4 = 1;
        __delay_ms(100);
        LED5 = 1;
        __delay_ms(100);
        LED6 = 1;
        __delay_ms(100);
        LED3 = 0;
        __delay_ms(100);
        LED4 = 0;
        __delay_ms(100);
        LED5 = 0;
        __delay_ms(100);
        LED6 = 0;
        __delay_ms(100);
    }
}

void flashing2() {
    //Checking part
    if(SW2 == 0) {
        i = 1;
    } else if(SW3 == 0) {
        i = 0;
    }

    //Pattern part
    if(i == 1) {
        LED3 = 1;
        __delay_ms(100);
        LED4 = 1;
        LED6 = 1;
        __delay_ms(100);
        LED5 = 1;
        __delay_ms(100);
        LED3 = 0;
        __delay_ms(100);
        LED4 = 0;
        LED6 = 0;
        __delay_ms(100);
        LED5 = 0;
        __delay_ms(100);
    } else if(i == 0) {
        LED3 = 0;
        LED4 = 0;
        LED5 = 0;
        LED6 = 0;
    }
}

void alert() {
    //Hold SW2
    if(SW2 == 0) {
        LED3 = 1;
        __delay_ms(1000);
        count1++;
    }

    //Press or Hold SW3
    if(SW3 == 0) {
        count1 = 0;
    }
    
    //Alert part
    if(count1 >= 5) {
        alertSound();
    }
}
 
void counter() {
   if(SW3 == 0 && SW5 == 0 && (SW2 != 0 && SW4 != 0)) {
          LED3 = 0;
          LED5 = 0;
          LED4 = 0;
          LED6 = 0;

          LED3 = 1;
          __delay_ms(250);
          LED3 = 0;
          LED4 = 1;
          __delay_ms(250);
          LED4 = 0;
          LED5 = 1;
          __delay_ms(250);
          LED5 = 0;
          LED6 = 1;
          __delay_ms(250);
          LED6 = 0;
          aSound();
          count++;
      }
}

void counterR() {
   if(SW3 == 0 && SW4 == 0 && (SW5 != 0 && SW2 != 0)) {
          LED3 = 0;
          LED5 = 0;
          LED4 = 0;
          LED6 = 0;

          LED5 = 1;
          __delay_ms(250);
          LED5 = 0;
          LED4 = 1;
          __delay_ms(250);
          LED4 = 0;
          LED3 = 1;
          __delay_ms(250);
          LED3 = 0;
          LED6 = 1;
          __delay_ms(250);
          LED6 = 0;
          aSound();
          countR++;
      }
}

void changeMode() {
    //Change to mode 2
    if(count >= 3 && mode == 0) {
        bSound();
        LED3 = 0;
        LED4 = 1;
        LED5 = 0;
        LED6 = 0;
        __delay_ms(1000);
        LED4 = 0;
        mode = 1;
        count = 0;
    }

    //Change to mode 3
    else if(count >= 3 && mode == 1) {
        bSound();
        LED3 = 0;
        LED4 = 0;
        LED5 = 1;
        LED6 = 0;
        __delay_ms(1000);
        LED5 = 0;
        mode = 2;
        count = 0;
    }
    
    //Change to mode 4
    else if(count >= 3 && mode == 2) {
        bSound();
        LED3 = 0;
        LED4 = 0;
        LED5 = 0;
        LED6 = 1;
        __delay_ms(1000);
        LED6 = 0;
        mode = 3;
        count = 0;
    }
    
    //Change back to mode 1
    else if(count >= 3 && mode == 3) {
        bSound();
        LED3 = 1;
        LED4 = 0;
        LED5 = 0;
        LED6 = 0;
        __delay_ms(1000);
        LED4 = 1;
        mode = 0;
        count = 0;
    }
}

void changeModeReverse() {
    //Change to mode 2
    if(countR >= 3 && mode == 3) {
        bSound();
        LED3 = 0;
        LED4 = 0;
        LED5 = 1;
        LED6 = 0;
        __delay_ms(1000);
        LED4 = 1;
        mode = 2;
        countR = 0;
    }

    //Change to mode 1
    else if(countR >= 3 && mode == 2) {
        bSound();
        LED3 = 0;
        LED4 = 1;
        LED5 = 0;
        LED6 = 0;
        __delay_ms(1000);
        LED6 = 0;
        mode = 1;
        countR = 0;
    }
    
    //Change to mode 0
    else if(countR >= 3 && mode == 1) {
        bSound();
        LED3 = 1;
        LED4 = 0;
        LED5 = 0;
        LED6 = 0;
        __delay_ms(1000);
        LED5 = 0;
        mode = 0;
        countR = 0;
    }
    
    //Change back to mode 3
    else if(countR >= 3 && mode == 0) {
        bSound();
        LED3 = 0;
        LED4 = 0;
        LED5 = 0;
        LED6 = 1;
        __delay_ms(1000);
        LED4 = 0;
        mode = 3;
        countR = 0;
    }
}

void checkMode() {
    aSound();
    switch(mode) {
        case 0:
            LED3 = 1;
            __delay_ms(1000);
            LED3 = 0;
            break;
        case 1:
            LED4 = 1;
            __delay_ms(1000);
            LED4 = 0;
            break;
        case 2:
            LED5 = 1;
            __delay_ms(1000);
            LED5 = 0;
            break;
        case 3:
            LED6 = 1;
            __delay_ms(1000);
            LED6 = 0;
            break;
    }
}

void doStuff() {
    switch(mode) {
        case 0:
            regular();
            flashing1();
            break;
        case 1:
            regular();
            HPBD();
            break;
        case 2:
            regular();
            flashing2();
            break;
        case 3:
            regular();
            alert();
            break;
    }
}

void resetFunc() {
    if(SW1 == 0) {
        aSound();
        RESET();
    }
}

// The main function is required, and the program begins executing from here. 
int main(void)
{
   // Configure oscillator and I/O ports. These functions run once at start-up.
   OSC_config();               // Configure internal oscillator for 48 MHz
   UBMP4_config();             // Configure on-board UBMP4 I/O devices

   checkMode();
    
   // Code in this while loop runs repeatedly.
   while(1)
    {
 
      counter();
      counterR();
      changeMode();
      changeModeReverse();
 
      doStuff();
      
       // Add code for your Program Analysis and Programming Activities here:
       
       // Activate bootloader and play a sound if SW1 is pressed.
       resetFunc();
   }
}
/* Program Analysis
*
* 1. How many times do the LEDs flash if SW2 is quickly pressed and released?
*    Do the LEDs keep flashing when SW2 is held? Look at the program and
*    explain why this happens when SW2 is held.
*    All of the LEDs flash once if SW2 is quickly pressed and released.
*    Yes, they do. Because if the SW2 is held (SW2 == 0), the program will run the code inside the if statement.
*
* 2. Explain the difference between the statements: LED3 = 0; and LED3 = 1;
*    LED3 = 0 is when the LED is turned off and LED = 1 is when the LED is turned on.
*
* 3. What voltage do you expect the microcontroller to output to LED D3 when
*    the statement LED3 = 0; runs? What voltage do you expect the output to be
*    when the statement LED3 = 1; runs?
*    When the LED3 runs, the expected voltage would be 5V.
*
*    You can confirm the output voltage with a voltmeter if you have access
*    to one. If you tried that, did the voltage match your prediction?
*    Well, it closes enough (4.6V).
*
* 4. The statement 'if(SW2 == 0)' uses two equal signs, while the statement
*    'LED3 = 1;' uses a single equal sign. What operation is performed by one
*    equal sign? What operation is performed by two equal signs?
*    The single equal sign will change the value of a variable into a different value.
*    The double equal sign will do a comparison.
*
* 5. The following program code includes instructions that write to the PORTC
*    output latches directly. Try it by copying and pasting this code below
*    the existing SW2 'if' structure, at the location shown by the comment.
 
       if(SW3 == 0)
       {
           LATC = 0b00000000;
           __delay_ms(100);
           LATC = 0b11110000;
           __delay_ms(100);
       }
 
*    What happens when pushbutton SW3 is pressed? Identify at least one
*    advantage and one disadvantage of controlling the LEDs using 'LATC' writes
*    rather than through individual 'LEDn = x;' statements.
*    When SW3 is pressed, all of the LEDs flash.
*    The advantage is you can control all of the LEDs at the same time.
*    The disadvantage of this is you can't do anything else with other buttons.
*
* 6. Next, compare the operation of 'if' and 'while' structures to simulate
*    momentary buttons. Replace the code you added in 5, above, with this code:
 
       // Momentary button using if structure
       if(SW3 == 0)
       {
           LED4 = 1;
       }
       else
       {
           LED4 = 0;
       }
 
       // Momentary button using while structure
       while(SW4 == 0)
       {
           LED5 = 1;
       }
       LED5 = 0;
 
*    First, try pressing and releasing SW3 and SW4 one at a time.
*    Each button turns its assigned LED on.
*
*    Next, press and hold SW3 while pressing and releasing SW4. Does it work
*    as expected?
*    Yes, each button still turns its assigned LED on while being pressed.
*
*    Next, try press and holding SW4 while pressing and releasing SW3. Does it
*    work as expected? Explain the difference in operation between the 'if' and
*    'while' structures making up the momentary button code.
*
*    The LED4 is not turned on when SW3 is pressed while holding SW4. When SW4 is pressed,
*    it will keep the condition for the 'while' loop true, so it keeps running the code inside the loop,
*    and not the code inside the 'if' structure.
*
* 7. Let's explore logical conditions using 'if' statements. Replace the code
*    added in 6, above, with this nested if code to make a logical AND
*    condition that will light LED D4 only if both SW3 and SW4 are pressed:
 
       // Nested if 'AND' code
       if(SW3 == 0)
       {
           if(SW4 == 0)
           {
               LED4 = 1;
           }
           else
           {
               LED4 = 0;
           }
       }
       else
       {
           LED4 = 0;
       }
 
*    Test the code to ensure it works as expected. Does the order of the if
*    conditions matter? (eg. swap the conditional checks for SW3 and SW4)
*    The order of the if conditions don't matter because when I swap the SW3 to SW4 and vice versa, the code still works.
*
* 8. Next, replace the code from 7 with the following code which implements a
*    logical AND conditional operator composed of two ampersands '&&':
       // Conditional 'AND' code
       if(SW3 == 0 && SW4 == 0)
       {
           LED4 = 1;
       }
       else
       {
           LED4 = 0;
       }
 
*    Does '&&' work the same way as the nested if structures? Can you think of
*    at least one advantage of using a logical conditional operator instead of
*    nested if structures?
*    The '&&' work the same way as the nested if structures.
*    There is one obvious advantage that the code will be more impact using '&&' instead of the nested if structures.
*
* 9. Replace the double ampersand '&&' with double vertical bars '||)' to make
*    a logical OR conditional operator. Your code should look like this:
        // Conditional 'OR' code
       if(SW3 == 0 || SW4 == 0)
       {
           LED4 = 1;
       }
       else
       {
           LED4 = 0;
       }
 
*    Describe the conditions under which LED4 turns on.
*    Either SW3 or SW4 is pressed, or both of them are pressed, LED4 turns on.
*
*
* Programming Activities
*
* 1. The statement '__delay_ms(100);' creates a 100ms delay. Try changing one
*    or more of the delay values in the program to 500ms and see what happens.
*
*    Can the delay be made even longer? Try 1000 ms. How big can the delay be
*    before MPLAB-X produces an error message? (Hint: can you think of a fast
*    and efficient way of guessing an unknown number?)
*    LIMIT: 4205
*
* 2. The '__delay_ms();' function only accepts integers as delay values. To
*    make delays shorter than 1ms, specify a delay in microseconds using the
*    '__delay_us();' function. You won't be able to see such short LED flashes
*    with your eyes, but you could measure them using an oscilloscope, or hear
*    them if they are used to turn the piezo beeper on and off. Try this code:
       // Make a tone while SW5 is held
       if(SW5 == 0)
       {
           BEEPER = 1;
           __delay_us(567);
           BEEPER = 0;
           __delay_us(567);
       }
 
*    Try changing the delay values in both of the __delay_us(); functions.
*    Does the pitch of the tone increase or decrease if the delay value is
*    made smaller?
*    The smaller the delay, the higher the pitch.
*
* 3. This code demonstrates a more compact way of toggling the beeper output
*    using a logical NOT operator '!'. Replace the code above, with this code:
       // Make a tone while SW5 is held
       if(SW5 == 0)
       {
           BEEPER = !BEEPER;
           __delay_us(567);
       }
 
*    One difference between this code and the code in 2, above, is the state
*    of the BEEPER pin when SW5 is released. What state will the BEEPER output
*    be in after this code runs? While one advantage of this method is smaller
*    code, can you think of one or more disadvantages based on its output when
*    the button is released?
*    I think this will leave the output to ON (1). It is okay with the BEEPER
*    but not with the LEDs.
*    
*
* 4. Using modified versions of the original SW2 'if' structure, create a
*    program that makes a unique LED flashing pattern for each pushbutton.
*
*    Test each of your flashing patterns. Describe what happens when more than
*    one button is held. Do all of the patterns try to flash the LEDs at the
*    same time, or sequentially? Explain why this is.
*    Just one pattern will be on at a time. Because when you press a button,
*    it will go into a loop attach to that button.
*
* 5. Create a program that makes a different tone for each pushbutton.
*
*    Test each tone by pressing each button individually. Next, press two or
*    more buttons at the same time. Describe what the tone waveform would look
*    like when more than one button is held.
*    The sound would be somewhat like a clicking sound, or maybe just a weird sound.
*
* 6. Use individual 'if' structures to simulate 'Start' and 'Stop' buttons for
*    an industrial machine. LED D4 should turn on when SW3 is pressed, stay on
*    even after SW3 is released, and turn off when SW4 is pressed. Test your
*    program to make sure it works.
*    It works
*
* 7. Running your program from 6, above, describe what happens when both SW3
*    and SW4 are pressed. Does LED D4 stay on? If so, how does the brightness
*    of LED D4 compare between its normal on state following SW3 being pressed
*    to this new state when both SW3 and SW4 are bing held? Can you explain
*    why it changes?
*    When we do that, the LED4 will stay on but with very low brightness.
*    Because it run through two loops so quickly that the LED4 turn on and turn off rapidly.
*
* 8. As you can imagine, an industrial machine that is able to turn on even
*    while its 'Stop' button is pressed represents a significant safety hazard.
*    Using a logical conditional operator, modify the start-stop program from
*    activity 5 to make it safer. SW3 should only turn on LED D4 if SW4 is
*    released.
*    I had that in the regular() function. It won't play sound when there are multiple
*    buttons being pressed. It will only play individual sound that is assigned to each button.
*
* 9. LED D1 is normally used to indicate that a program is running, but it can
*    be controlled by your program as well. If you take a look at the UBMP4
*    schematic, you will see that LED D1's cathode (or negative) pin is
*    connected to the microcontroller instead of the anode (positive) pin as
*    with the other LEDs. This means that you need to make D1's output a zero
*    to turn D1 on. Try it! Make a program that controls or flashes LED D1.
*    Instead of using LED1 = 1 to turn on the LED, I used LED1 = 0 to turn it on.
*/
 

