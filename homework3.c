#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"

int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;

    // TODO: Declare the variables that main uses to interact with your state machine.

    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);

    while(1)
    {
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);
        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0. Done.
        // YOU MUST WRITE timer0expired IN myTimer.c

        if (timer0Expired())
        {
            count0 = count0 + 1;
        }



        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c

        if (timer1Expired())
        {
            buttonhistory << 1;
            int tempP5IN = P5IN;
            tempP5IN = tempP5IN & BIT1;
            tempP5IN >> 1;
            buttonhistory = buttonhistory | tempP5IN;
        }



        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.




        // TODO: If a completed, debounced button press has occurred, increment count1.




    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{
    switch (count & whiteMask)
    {
        case (offMask):
        {
            turnOff_LaunchpadLED2Red();
            turnOff_LaunchpadLED2Green();
            turnOff_LaunchpadLED2Blue();

            break;
        }
        case (redMask):
        {
            turnOn_LaunchpadLED2Red();
            turnOff_LaunchpadLED2Green();
            turnOff_LaunchpadLED2Blue();

            break;
        }
        case (greenMask):
        {
            turnOff_LaunchpadLED2Red();
            turnOn_LaunchpadLED2Green();
            turnOff_LaunchpadLED2Blue();

            break;
        }
        case (yellowMask):
        {
            turnOn_LaunchpadLED2Red();
            turnOn_LaunchpadLED2Green();
            turnOff_LaunchpadLED2Blue();

            break;
        }
        case (blueMask):
        {
            turnOff_LaunchpadLED2Red();
            turnOff_LaunchpadLED2Green();
            turnOn_LaunchpadLED2Blue();

            break;
        }
        case (magentaMask):
        {
            turnOn_LaunchpadLED2Red();
            turnOff_LaunchpadLED2Green();
            turnOn_LaunchpadLED2Blue();

            break;
        }
        case (cyanMask):
        {
            turnOff_LaunchpadLED2Red();
            turnOn_LaunchpadLED2Green();
            turnOn_LaunchpadLED2Blue();

            break;
        }
        case (whiteMask):
        {
            turnOn_LaunchpadLED2Red();
            turnOn_LaunchpadLED2Green();
            turnOn_LaunchpadLED2Blue();

            break;
        }

    }

}

// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count)
{
    switch (count & whiteMask)
        {
            case (offMask):
            {
                turnOff_BoosterpackLEDRed();
                turnOff_BoosterpackLEDGreen();
                turnOff_BoosterpackLEDBlue();

                break;
            }
            case (redMask):
            {
                turnOn_BoosterpackLEDRed();
                turnOff_BoosterpackLEDGreen();
                turnOff_BoosterpackLEDBlue();

                break;
            }
            case (greenMask):
            {
                turnOff_BoosterpackLEDRed();
                turnOn_BoosterpackLEDGreen();
                turnOff_BoosterpackLEDBlue();

                break;
            }
            case (yellowMask):
            {
                turnOn_BoosterpackLEDRed();
                turnOn_BoosterpackLEDGreen();
                turnOff_BoosterpackLEDBlue();

                break;
            }
            case (blueMask):
            {
                turnOff_BoosterpackLEDRed();
                turnOff_BoosterpackLEDGreen();
                turnOn_BoosterpackLEDBlue();

                break;
            }
            case (magentaMask):
            {
                turnOn_BoosterpackLEDRed();
                turnOff_BoosterpackLEDGreen();
                turnOn_BoosterpackLEDBlue();

                break;
            }
            case (cyanMask):
            {
                turnOff_BoosterpackLEDRed();
                turnOn_BoosterpackLEDGreen();
                turnOn_BoosterpackLEDBlue();

                break;
            }
            case (whiteMask):
            {
                turnOn_BoosterpackLEDRed();
                turnOn_BoosterpackLEDGreen();
                turnOn_BoosterpackLEDBlue();

                break;
            }
}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned char buttonhistory)
{
    typedef enum {UP, DOWN} buttonState;

    static buttonState test = UP;

    bool pressed = false;

    switch (test)
    {
        case UP:
            if (buttonhistory == PRESSED)
            {
                pressed = true;
                test = DOWN;
            }

            break;

        case DOWN:
            if (buttonhistory == UNPRESSED)
            {
                test = UP;
            }

            break;
    }
}
