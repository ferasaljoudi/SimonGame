# SimonGame
This is a lab project for ENSE352 class. The requirment of the project is to design a simple Simon game with 10 levels with C code using Keil uVision.

Other tools were used for this project:
- STM32F103 Nucleo Board
- Breadboard
- 4 LEDs with common Cathode to GND and the Anodes going through 270ohm Isolated Resistor to the output of the STM32
- 4 push buttons: 
    - For each push button: one side is connected to GND and the other side is going through 10Kohm Bussed Resistor to the input in the STM32
- An extra red LED (LED4), this will blink for 3 seconds if a fail occurred, to tell the player that a fail occurred

### Connection details:
Here is a table of the connection:

|      Equipment      |   To Breadboard   |   To STM32   |
|:-------------------:|:-----------------:|:------------:|
| 1st pin in btn0     |        GND        |      -       |
| 1st pin in btn1     |        GND        |      -       |
| 1st pin in btn2     |        GND        |      -       |
| 1st pin in btn3     |        GND        |      -       |
| 2nd pin in btn0     | 10Kohm Bussed Resistor |    PB4     |
| 2nd pin in btn1     | 10Kohm Bussed Resistor |    PB6     |
| 2nd pin in btn2     | 10Kohm Bussed Resistor |    PB8     |
| 2nd pin in btn3     | 10Kohm Bussed Resistor |    PB9     |
| Cathode LED0        |        GND        |      -       |
| Cathode LED1        |        GND        |      -       |
| Cathode LED2        |        GND        |      -       |
| Cathode LED3        |        GND        |      -       |
| Cathode LED4        |        GND        |      -       |
| Anode LED0          | 270ohm Isolated Resistor |   PA0    |
| Anode LED1          | 270ohm Isolated Resistor |   PA1    |
| Anode LED2          | 270ohm Isolated Resistor |   PA4    |
| Anode LED3          | 270ohm Isolated Resistor |   PB0    |
| Anode LED4          | 270ohm Isolated Resistor |   PA6    |





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

**Here is a link to a YouTube video demonstrating the game:**
- _[Click Here](https://www.youtube.com/watch?v=4QuzgClFiL4&t=0s "Watch a demonstration of the Simon game")_



Have fun and see how far you reach😍

