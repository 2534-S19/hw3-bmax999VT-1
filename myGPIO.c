/*
 * GPIO.c
 *
 *  Created on:
 *      Author:
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    // Launchpad S1
    P1DIR = P1DIR & ~BIT1;
    P1REN = P1REN | BIT1;
    P1OUT = P1OUT | BIT1;
    checkStatus_LaunchpadS1();

    // Launchpad S2
    P1DIR = P1DIR & ~BIT4;
    P1REN = P1REN | BIT4;
    P1OUT = P1OUT | BIT4;
    checkStatus_LaunchpadS2();

    // Boosterpack S1
    P5DIR = P5DIR & ~BIT1;
    P5REN = P5REN | BIT1;
    P5OUT = P5OUT | BIT1;
    checkStatus_BoosterpackS1();


    // Boosterpack S2
    P3DIR = P3DIR & ~BIT5;
    P3REN = P3REN | BIT5;
    P3OUT = P3OUT | BIT5;
    checkStatus_BoosterpackS2();


    // Launchpad LED1
    P1DIR = P1DIR | BIT0;

    // Launchpad LED2 Red
    P2DIR = P2DIR | BIT0;

    // Launchpad LED2 Green
    P2DIR = P2DIR | BIT1;

    // Launchpad LED2 Blue
    P2DIR = P2DIR | BIT2;

    // Boosterpack LED Red
    P2DIR = P2DIR | BIT6;

    // Boosterpack LED Green
    P2DIR = P2DIR | BIT4;

    // Boosterpack LED Blue
    P5DIR = P5DIR | BIT6;

    // Turn off all LEDs at the start.

    turnOff_LaunchpadLED1();
    turnOff_LaunchpadLED2Red();
    turnOff_LaunchpadLED2Green();
    turnOff_LaunchpadLED2Blue();
    turnOff_BoosterpackLEDRed();
    turnOff_BoosterpackLEDGreen();
    turnOff_BoosterpackLEDBlue();
}

// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    if((P1IN & BIT1) == BIT1)
    {
        return BIT1; //Button S1 is released.
    }
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    if((P1IN & BIT4) == BIT4)
    {
        return BIT4; //Button S2 is released.
    }
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    if((P5IN & BIT1) == BIT1)
    {
        return BIT1; //Button S1 is released.
    }
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    if((P3IN & BIT5) == BIT5)
    {
        return BIT5; //Button S2 is released.
    }
}

// TODO: Create a function to turn on Launchpad LED1. Done.
void turnOn_LaunchpadLED1()
{
    P1OUT = P1OUT | BIT0;
}

// TODO: Create a function to turn off Launchpad LED1. Done.
void turnOff_LaunchpadLED1()
{
    P1OUT = P1OUT & ~BIT0;
}

// TODO: Create a function to turn on the Red Launchpad LED2. Done.
void turnOn_LaunchpadLED2Red()
{
    P2OUT = P2OUT | BIT0;
}

// TODO: Create a function to turn off the Red Launchpad LED2. Done.
void turnOff_LaunchpadLED2Red()
{
    P2OUT = P2OUT & ~BIT0;
}

// TODO: Create a function to turn on the Green Launchpad LED2. Done.
void turnOn_LaunchpadLED2Green()
{
    P2OUT = P2OUT | BIT1;
}

// TODO: Create a function to turn off the Green Launchpad LED2. Done.
void turnOff_LaunchpadLED2Green()
{
    P2OUT = P2OUT & ~BIT1;
}

// TODO: Create a function to turn on the Blue Launchpad LED2. Done.
void turnOn_LaunchpadLED2Blue()
{
    P2OUT = P2OUT | BIT2;
}

// TODO: Create a function to turn off the Blue Launchpad LED2. Done.
void turnOff_LaunchpadLED2Blue()
{
    P2OUT = P2OUT & ~BIT2;
}

// TODO: Create a function to turn on the Red Boosterpack LED2. Done.
void turnOn_BoosterpackLEDRed()
{
    P2OUT = P2OUT | BIT6;
}

// TODO: Create a function to turn off the Red Boosterpack LED2. Done.
void turnOff_BoosterpackLEDRed()
{
    P2OUT = P2OUT & ~BIT6;
}

// TODO: Create a function to turn on the Green Boosterpack LED2. Done.
void turnOn_BoosterpackLEDGreen()
{
    P2OUT = P2OUT | BIT4;
}

// TODO: Create a function to turn off the Green Boosterpack LED2. Done.
void turnOff_BoosterpackLEDGreen()
{
    P2OUT = P2OUT & ~BIT4;
}

// TODO: Create a function to turn on the Blue Boosterpack LED2. Done.
void turnOn_BoosterpackLEDBlue()
{
    P5OUT = P5OUT | BIT6;
}

// TODO: Create a function to turn off the Blue Boosterpack LED2. Done.
void turnOff_BoosterpackLEDBlue()
{
    P5OUT = P5OUT & ~BIT6;
}
