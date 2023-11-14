# SimonGame
This is a lab project for ENSE352 class. The requirment of the project is to design a simple Simon game with 10 levels designed with C code using Keil uVision.

Other tools were used for this project:
- STM32F103 Nucleo Board
- Breadboard
- 4 LEDs with common Cathode to GND and the Anodes going through Isolated Resistor 270ohm to the output of the STM32
- 4 push buttons. For each one: one side is connected to GND and the other side is going through 10Kohm Bussed Resistor to the input in the STM32
- An extra red LED, this will blink for 3 seconds if a fail occurred, to tell the player that a fail occurred

Description of the game:
-
- When the code runs, the 4 LEDs will keep running as a classic Cylon Eye Scanner
- When the player pushes the blue button in the STM32, the classic Cylon Eye Scanner stops and the game starts by generating the first random light (the first round starts)
- The player has to mimic the light by pressing the appropriate button
- The player has a limited time to press the button
- If the player succeeds, then the game moves to round two and adds an LED to the sequence. This will continue for 10 rounds
- If the player fails to mimic the pattern in the time allotted, pressed the wrong button, or did not press the buttons in the correct sequence the failure sequence will occur
- In the failure sequence, the separated red LED will be blinking quickly for 3 seconds. Then the player will see the level he reached represented in binary by the 4 LEDs 
- If the player completes 10 rounds successfully, then the 4 LEDs will be blinking on and off together

Have fun and see how far you reach😍

