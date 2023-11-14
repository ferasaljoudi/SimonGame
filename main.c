/*
****************************************************************************************************************************
A simple Simon game with 10 levels designed with C code using Keil uVision
Also using: 
	-STM32F103 Nucleo Board
	-Breadboard
	-4 LEDs with common Cathode to GND and the Anodes going through Isolated Resistor 270ohm to the output of the STM32
	-4 push buttons. For each one, one side is connected to GND 
		and the other side is going through 10Kohm Bussed Resistor to the input in the STM32
	-An extra red LED, this will blink for 3 seconds if a fail occurred, to tell the player that a fail occurred.
	
When the code runs, the 4 LEDs will keep running as a classic Cylon Eye Scanner
When the player pushes the blue button in the STM32, the classic Cylon Eye Scanner stops and the game starts by generating the first random light
The player has to mimic the light by pressing the appropriate button
The player has a limited time to press the button
If the player succeeds, then the game moves to round two and adds an LED to the sequence. This will continue for 10 rounds
If the player fails to mimic the pattern in the time allotted then the failure sequence occur
In the failure sequence, the separated red LED will be blinking for 3 seconds
Then the player will see the level he reached represented in binary by the 4 LEDs 
If the player completes 10 rounds successfully, then the 4 LEDs will be blinking on and off together
****************************************************************************************************************************
*/

#include <stdlib.h>
#include <stdbool.h>
#include "main.h"




void GPIO_ClockInitAndConfiguring(void);
unsigned int StartTheGame(void);
unsigned int genRand(unsigned int);
unsigned int turnRands(unsigned int);
unsigned int checkSelection(unsigned int);
void fail(void);
void passed(void);
void result(unsigned int);
void delay(unsigned int);


int main(void)
{
	unsigned int rands = 0;
	unsigned int checkButton1, checkButton2, checkButton3, checkButton4, checkButton5;
	unsigned int checkButton6, checkButton7, checkButton8, checkButton9, checkButton10;
	unsigned int statusIs = 0;
	unsigned int randNumber1, randNumber2, randNumber3, randNumber4, randNumber5;
	unsigned int randNumber6, randNumber7, randNumber8, randNumber9, randNumber10;
	unsigned int results = 0;

	//Set the clock and congigure the pins
	GPIO_ClockInitAndConfiguring();
	//Start the game and return rands to be used for generating the first raandom number
	rands = StartTheGame();
	
//-----------------------------------FIRST LEVEL-----------------------------------
	//Pass the rands to generate a random number and store the returned value which represents the LED number
	randNumber1 = genRand(rands);
	//Turn the corresponding LED On and Off once and store the returned value
	checkButton1 = turnRands(randNumber1);
	//Check if the player pressed the right button and store the returned value
	statusIs = checkSelection(checkButton1);
	//If the user failed, call the fail function then display the result
	//otherwise continue to the next level
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
//-----------------------------------SECOND LEVEL-----------------------------------
	//The level achieved by the player will be stored in results
	results += 1;
	delay(1500);
	turnRands(randNumber1);
	randNumber2 = genRand(statusIs);
	checkButton2 = turnRands(randNumber2);
	statusIs = checkSelection(checkButton1);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton2);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
//-----------------------------------THIRD LEVEL-----------------------------------
	results += 1;
	delay(1500);
	turnRands(randNumber1);
	turnRands(randNumber2);

	randNumber3 = genRand(statusIs);
	checkButton3 = turnRands(randNumber3);
	statusIs = checkSelection(checkButton1);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton2);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton3);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
//-----------------------------------FOURTH LEVEL-----------------------------------
	results += 1;
	delay(1500);
	turnRands(randNumber1);
	turnRands(randNumber2);
	turnRands(randNumber3);

	randNumber4 = genRand(statusIs);
	checkButton4 = turnRands(randNumber4);
	statusIs = checkSelection(checkButton1);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton2);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton3);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton4);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
//-----------------------------------FIFTH LEVEL-----------------------------------
	results += 1;
	delay(1500);
	turnRands(randNumber1);
	turnRands(randNumber2);
	turnRands(randNumber3);
	turnRands(randNumber4);

	randNumber5 = genRand(statusIs);
	checkButton5 = turnRands(randNumber5);
	statusIs = checkSelection(checkButton1);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton2);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton3);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton4);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton5);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
//-----------------------------------SIXTH LEVEL-----------------------------------
	results += 1;
	delay(1500);
	turnRands(randNumber1);
	turnRands(randNumber2);
	turnRands(randNumber3);
	turnRands(randNumber4);
	turnRands(randNumber5);

	randNumber6 = genRand(statusIs);
	checkButton6 = turnRands(randNumber6);
	statusIs = checkSelection(checkButton1);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton2);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton3);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton4);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton5);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton6);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
//-----------------------------------SEVENTH LEVEL-----------------------------------
	results += 1;
	delay(1500);
	turnRands(randNumber1);
	turnRands(randNumber2);
	turnRands(randNumber3);
	turnRands(randNumber4);
	turnRands(randNumber5);
	turnRands(randNumber6);

	randNumber7 = genRand(statusIs);
	checkButton7 = turnRands(randNumber7);
	statusIs = checkSelection(checkButton1);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton2);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton3);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton4);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton5);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton6);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton7);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
//-----------------------------------EIGHTH LEVEL-----------------------------------
	results += 1;
	delay(1500);
	turnRands(randNumber1);
	turnRands(randNumber2);
	turnRands(randNumber3);
	turnRands(randNumber4);
	turnRands(randNumber5);
	turnRands(randNumber6);
	turnRands(randNumber7);

	randNumber8 = genRand(statusIs);
	checkButton8 = turnRands(randNumber8);
	statusIs = checkSelection(checkButton1);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton2);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton3);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton4);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton5);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton6);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton7);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton8);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
//-----------------------------------NINTH LEVEL-----------------------------------
	results += 1;
	delay(1500);
	turnRands(randNumber1);
	turnRands(randNumber2);
	turnRands(randNumber3);
	turnRands(randNumber4);
	turnRands(randNumber5);
	turnRands(randNumber6);
	turnRands(randNumber7);
	turnRands(randNumber8);

	randNumber9 = genRand(statusIs);
	checkButton9 = turnRands(randNumber9);
	statusIs = checkSelection(checkButton1);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton2);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton3);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton4);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton5);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton6);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton7);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton8);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton9);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
//-----------------------------------TENTH LEVEL-----------------------------------
	results += 1;
	delay(1500);
	turnRands(randNumber1);
	turnRands(randNumber2);
	turnRands(randNumber3);
	turnRands(randNumber4);
	turnRands(randNumber5);
	turnRands(randNumber6);
	turnRands(randNumber7);
	turnRands(randNumber8);
	turnRands(randNumber9);

	randNumber10 = genRand(statusIs);
	checkButton10 = turnRands(randNumber10);
	statusIs = checkSelection(checkButton1);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton2);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton3);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton4);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton5);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton6);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton7);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton8);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton9);
	delay(800);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	statusIs = checkSelection(checkButton10);
	if (statusIs == 0)
	{
		fail();
		result(results);
		return 0;
	}
	results += 1;
	//Calling the passed function only if the player passed all levels
	passed();
	//If the player Won the game, no need for the results function
	//The 4 LEDs will be blinking On and Off togather by calling the passed function
	//result(results);
		
	return 0;
}
//-----------------------------------ENABILING&CONFIGURING FUNCTION-----------------------------------
void GPIO_ClockInitAndConfiguring(void)
{
	//This function will enable the clocks for ports A, B, and C
	//And it will configue the pins we are using
	//Then it will turn the green LED On in the STM32
	uint32_t clear0to3Bits = 0xFFFFFFF0;
	uint32_t clear4to7Bits = 0xFFFFFF0F;
	uint32_t clear16to19Bits = 0xFFF0FFFF;
	uint32_t clear20to23Bits = 0xFF0FFFFF;
	uint32_t clear24to27Bits = 0xF0FFFFFF;
	
	//turn on the clocks for Port A, B and Port C
	RCC->APB2ENR |= ((1 << 2) | (1 << 3) | (1 << 4));//setting bit 2, 3 and 4
	//congiguring PA0
	GPIOA->CRL &= clear0to3Bits;
	GPIOA->CRL |= 0x3;
	//congiguring PA1
	GPIOA->CRL &= clear4to7Bits;
	GPIOA->CRL |= (0x3 << 4);
	//congiguring PA4
	GPIOA->CRL &= clear16to19Bits;
	GPIOA->CRL |= (0x3 << 16);
	//congiguring PB0
	GPIOB->CRL &= clear0to3Bits;
	GPIOB->CRL |= 0x3;
	//congiguring PA5
	GPIOA->CRL &= clear20to23Bits;
	GPIOA->CRL |= (3 << 20);
	//congiguring PA6
	GPIOA->CRL &= clear24to27Bits;
	GPIOA->CRL |= (3 << 24);
	
	//Setting bit 5 for green LED on the STM32 to stay on
	GPIOA->ODR |= (1 << 5);
}
//-----------------------------------STARTTHEGAME FUNCTION-----------------------------------
unsigned int StartTheGame(void)
{
	//This function will start the game by a classic Cylon Eye Scanner generated by 4 LEDs
	uint32_t clearbitA0 = 0xFFFFFFFE;
	uint32_t clearbitA1 = 0xFFFFFFFD;
	uint32_t clearbitA4 = 0xFFFFFFEF;
	uint32_t clearbitB0 = 0xFFFFFFFE;
	//The count from this function will be used to generate the first random number
	unsigned int count = 0;
	//The will loop will keep the classic Cylon Eye Scanner running
	//until the player press the start button (the blue button on the STM32)
	while (1)
	{
		GPIOA->ODR |= (1 << 0);
		if ((GPIOC->IDR & (1 << 13)) == 0) break;
		delay(750);
		if ((GPIOC->IDR & (1 << 13)) == 0) break;
		GPIOA->ODR &= clearbitA0;
		if ((GPIOC->IDR & (1 << 13)) == 0) break;
		
		count = count + 1;
		
		GPIOA->ODR |= (1 << 1);
		if ((GPIOC->IDR & (1 << 13)) == 0) break;
		delay(750);
		if ((GPIOC->IDR & (1 << 13)) == 0) break;
		GPIOA->ODR &= clearbitA1;
		if ((GPIOC->IDR & (1 << 13)) == 0) break;
		
		count = count + 1;

		GPIOA->ODR |= (1 << 4);
		if ((GPIOC->IDR & (1 << 13)) == 0) break;
		delay(750);
		if ((GPIOC->IDR & (1 << 13)) == 0) break;
		GPIOA->ODR &= clearbitA4;
		if ((GPIOC->IDR & (1 << 13)) == 0) break;
		
		count = count + 1;

		GPIOB->ODR |= (1 << 0);
		if ((GPIOC->IDR & (1 << 13)) == 0) break;
		delay(750);
		if ((GPIOC->IDR & (1 << 13)) == 0) break;
		GPIOB->ODR &= clearbitB0;
		if ((GPIOC->IDR & (1 << 13)) == 0) break;
		
		count = count + 1;
		
		GPIOA->ODR |= (1 << 4);
		if ((GPIOC->IDR & (1 << 13)) == 0) break;
		delay(750);
		if ((GPIOC->IDR & (1 << 13)) == 0) break;
		GPIOA->ODR &= clearbitA4;
		if ((GPIOC->IDR & (1 << 13)) == 0) break;
		
		count = count + 1;
		
		GPIOA->ODR |= (1 << 1);
		if ((GPIOC->IDR & (1 << 13)) == 0) break;
		delay(750);
		if ((GPIOC->IDR & (1 << 13)) == 0) break;
		GPIOA->ODR &= clearbitA1;
		if ((GPIOC->IDR & (1 << 13)) == 0) break;
		
		count = count + 1;
	}
	//After the player press the start button
	//the 4 LEDs will turn on and off togather 3 times
	//telling the player: "Ready...Set...Go..."
	GPIOA->ODR &= clearbitA0;
	GPIOA->ODR &= clearbitA1;
	GPIOA->ODR &= clearbitA4;
	GPIOB->ODR &= clearbitB0;
	
	GPIOA->ODR |= (1 << 0);
	GPIOA->ODR |= (1 << 1);
	GPIOA->ODR |= (1 << 4);
	GPIOB->ODR |= (1 << 0);
	delay(1500);
	GPIOA->ODR &= clearbitA0;
	GPIOA->ODR &= clearbitA1;
	GPIOA->ODR &= clearbitA4;
	GPIOB->ODR &= clearbitB0;
	delay(1500);
	
	GPIOA->ODR |= (1 << 0);
	GPIOA->ODR |= (1 << 1);
	GPIOA->ODR |= (1 << 4);
	GPIOB->ODR |= (1 << 0);
	delay(1500);
	GPIOA->ODR &= clearbitA0;
	GPIOA->ODR &= clearbitA1;
	GPIOA->ODR &= clearbitA4;
	GPIOB->ODR &= clearbitB0;
	delay(1500);
	
	GPIOA->ODR |= (1 << 0);
	GPIOA->ODR |= (1 << 1);
	GPIOA->ODR |= (1 << 4);
	GPIOB->ODR |= (1 << 0);
	delay(1500);
	GPIOA->ODR &= clearbitA0;
	GPIOA->ODR &= clearbitA1;
	GPIOA->ODR &= clearbitA4;
	GPIOB->ODR &= clearbitB0;
	delay(1500);
	
	return count;
}
//-----------------------------------GENRAND FUNCTION-----------------------------------
unsigned int genRand(unsigned int rands)
{
	//This function will generate a random number
	//Since the MSB is more randomized than the LSB usually
	//And since the MSB is for the sign
	//AND we need 4 options for 4 LEDs
	//will take bit 30 and bit 29 and determain the LED
	unsigned int randomNumber = 0;
	unsigned int LIGHTMASK = 0x00000003;
	srand(rands);
	
	randomNumber = rand();
	randomNumber = randomNumber >> 29;
	randomNumber &= LIGHTMASK;
	
	return randomNumber;
}
//-----------------------------------TURNRANDS FUNCTION-----------------------------------
unsigned int turnRands(unsigned int rands)
{
	//This function will turn an LED on, then turn it off
	//The LED is already determained by the genRand function and passed here as rands
	uint32_t clearbitA0 = 0xFFFFFFFE;
	uint32_t clearbitA1 = 0xFFFFFFFD;
	uint32_t clearbitA4 = 0xFFFFFFEF;
	uint32_t clearbitB0 = 0xFFFFFFFE;
	
	switch (rands)
	{
		case 0:
			GPIOA->ODR |= (1 << 0);
			delay(1000);
			GPIOA->ODR &= clearbitA0;
			delay(1000);
			break;
		case 1:
			GPIOA->ODR |= (1 << 1);
			delay(1000);
			GPIOA->ODR &= clearbitA1;
			delay(1000);
			break;
		case 2:
			GPIOA->ODR |= (1 << 4);
			delay(1000);
			GPIOA->ODR &= clearbitA4;
			delay(1000);
			break;
		case 3:
			GPIOB->ODR |= (1 << 0);
			delay(1000);
			GPIOB->ODR &= clearbitB0;
			delay(1000);
			break;
	}
	return rands;
}
//-----------------------------------CHECKSELECTION FUNCTION-----------------------------------
unsigned int checkSelection(unsigned int selectCheck)
{
	//This function will check if the player pressed the right button within the limited time
	unsigned int start_time = 0;
	unsigned int current_time = 0;
	bool button_pressed = false;
	//The rands will be returned from this function and have two purposes:
	//if rands is 0, fails occurred
	//if rands is not 0, will pass it to genRand() function, to generate a random number and determine the next light 
	unsigned int rands = 0;
	
	start_time = current_time;
	while (current_time - start_time < 800000)
	{
		rands += 10;
		//Very short delay
		delay(12);
		//Manually incrementing the current time
		current_time += 10;
		if (((selectCheck == 0) && ((GPIOB->IDR & (1 << 4)) == 0)) || ((selectCheck == 1) && ((GPIOB->IDR & (1 << 6)) == 0))
			|| ((selectCheck == 2) && ((GPIOB->IDR & (1 << 8)) == 0)) || ((selectCheck == 3) && ((GPIOB->IDR & (1 << 9)) == 0)) )
		{
			button_pressed = true;
			break;
		}else if ((((selectCheck == 0) && ((GPIOB->IDR & (1 << 6)) == 0)) || ((selectCheck == 0) && ((GPIOB->IDR & (1 << 8)) == 0))
							|| ((selectCheck == 0) && ((GPIOB->IDR & (1 << 9)) == 0)))
							|| (((selectCheck == 1) && ((GPIOB->IDR & (1 << 4)) == 0)) || ((selectCheck == 1) && ((GPIOB->IDR & (1 << 8)) == 0))
							|| ((selectCheck == 1) && ((GPIOB->IDR & (1 << 9)) == 0)))
							|| (((selectCheck == 2) && ((GPIOB->IDR & (1 << 4)) == 0)) || ((selectCheck == 2) && ((GPIOB->IDR & (1 << 6)) == 0))
							|| ((selectCheck == 2) && ((GPIOB->IDR & (1 << 9)) == 0)))
							|| (((selectCheck == 3) && ((GPIOB->IDR & (1 << 6)) == 0)) || ((selectCheck == 3) && ((GPIOB->IDR & (1 << 8)) == 0))
							|| ((selectCheck == 3) && ((GPIOB->IDR & (1 << 4)) == 0))))
		{
			//If the player pressed the wrong button, break the while loop
			break;
		}	
	}
	if (!button_pressed) {
		return 0;
	}
	else
	{
		return rands;
	}
}
//-----------------------------------FAIL FUNCTION-----------------------------------
void fail(void)
{
	//If the player fails at any level, the seperated red LEDs will be blinking for 3 seconds
	uint32_t clearbitA6 = 0xFFFFFFBF;
	unsigned int start_time = 0;
	unsigned int current_time = 0;
	start_time = current_time;
	while (current_time - start_time < 150)
	{
		current_time += 10;
		GPIOA->ODR |= (1 << 6);
		delay(600);
		GPIOA->ODR &= clearbitA6;
		delay(600);
	}
}
//-----------------------------------PASSED FUNCTION-----------------------------------
void passed(void)
{
	//Note that the dpassed function will only be called if the player passed all 10 levels
	//The passed function will make the 4 LEDs keep blinking On and Off togather
	uint32_t clearbitA0 = 0xFFFFFFFE;
	uint32_t clearbitA1 = 0xFFFFFFFD;
	uint32_t clearbitA4 = 0xFFFFFFEF;
	uint32_t clearbitB0 = 0xFFFFFFFE;
	while(1)
	{
		GPIOA->ODR |= (1 << 0);
		GPIOA->ODR |= (1 << 1);
		GPIOA->ODR |= (1 << 4);
		GPIOB->ODR |= (1 << 0);
		delay(1000);
		GPIOA->ODR &= clearbitA0;
		GPIOA->ODR &= clearbitA1;
		GPIOA->ODR &= clearbitA4;
		GPIOB->ODR &= clearbitB0;
		delay(1000);
	}
}
//-----------------------------------RESULT FUNCTION-----------------------------------
void result(unsigned int results)
{
	//After either the fail or the pass function runs,
	//the result function will display the level in binary using 4 LEDs
	uint32_t clearbitA0 = 0xFFFFFFFE;
	uint32_t clearbitA1 = 0xFFFFFFFD;
	uint32_t clearbitA4 = 0xFFFFFFEF;
	uint32_t clearbitB0 = 0xFFFFFFFE;
	switch (results)
	{
		//All lights off for 0->0000
		case 0:
			break;
		//1->0001
		case 1:
			GPIOB->ODR |= (1 << 0);
			break;
		//2->0010
		case 2:
			GPIOA->ODR |= (1 << 4);
			break;
		//3->0011
		case 3:
			GPIOB->ODR |= (1 << 0);
			GPIOA->ODR |= (1 << 4);
			break;
		//4->0100
		case 4:
			GPIOA->ODR |= (1 << 1);
			break;
		//5->0101
		case 5:
			GPIOA->ODR |= (1 << 1);
			GPIOB->ODR |= (1 << 0);
			break;
		//6->0110
		case 6:
			GPIOA->ODR |= (1 << 1);
			GPIOA->ODR |= (1 << 4);
			break;
		//7->0111
		case 7:
			GPIOA->ODR |= (1 << 1);
			GPIOA->ODR |= (1 << 4);
			GPIOB->ODR |= (1 << 0);
			break;
		//8->1000
		case 8:
			GPIOA->ODR |= (1 << 0);
			break;
		//9->1001
		case 9:
			GPIOA->ODR |= (1 << 0);
			GPIOB->ODR |= (1 << 0);
			break;
		//10->1010
		case 10:
			GPIOA->ODR |= (1 << 0);
			GPIOA->ODR |= (1 << 4);
			break;
	}
}
//-----------------------------------DELAY FUNCTION-----------------------------------
void delay(unsigned int delayVal)
{
	unsigned int i = 0;
	unsigned int y = 0;
	unsigned int internalDelay = 0;
	
	internalDelay = delayVal;
	while(i < delayVal)
	{
		
		while(y < internalDelay)
		{
			++y;
		}
		y = 0;
		++i;
	}
}

