<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/ferasaljoudi/AssetsRepository/main/SVGsHeader/simonGame.svg" alt="Simon Game" style="width: 100%"></a>
</div>
<br>

A simple Simon game designed with 10 levels using C code in Keil uVision, utilizing an STM32F103 Nucleo Board.

<br>
<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/ferasaljoudi/AssetsRepository/main/BrownSVGs/overview.svg" alt="Overview" style="width: 100%"></a>
</div>
<br>

This project involves creating a Simon game that challenges the player to replicate sequences of lights generated by the system. The game is designed to run on an STM32F103 Nucleo Board and involves the use of LEDs and push buttons for user interaction. The game progresses through 10 levels of increasing complexity, providing feedback through LEDs for both successful and failed attempts.

<br>
<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/ferasaljoudi/AssetsRepository/main/BrownSVGs/technologiesUsed.svg" alt="Technologies Used" style="width: 100%"></a>
</div>
<br>

<div align="center">

[![C](https://img.shields.io/badge/-C-00599C?style=for-the-badge&logo=c&logoColor=00FF00)](https://www.w3schools.com/c/)
[![STM32](https://img.shields.io/badge/-STM_32-150458?style=for-the-badge)](https://www.st.com/en/microcontrollers-microprocessors/stm32f1-series.html)
[![Keil uVision](https://img.shields.io/badge/-Keil_uVision-0090D0?style=for-the-badge&logoColor=white)](https://www.keil.com/)

</div>

<br>
<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/ferasaljoudi/AssetsRepository/main/BrownSVGs/connectionDetails.svg" alt="Connection details" style="width: 100%"></a>
</div>
<br>

<div align="center">

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


</div>

<br>
<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/ferasaljoudi/AssetsRepository/main/BrownSVGs/description.svg" alt="Description" style="width: 100%"></a>
</div>
<br>

- When the code runs, the 4 LEDs will keep running as a classic Cylon Eye Scanner
- When the player pushes the blue button in the STM32, the classic Cylon Eye Scanner stops and the game starts by generating the first random light (the first round starts)
- The player has to mimic the light by pressing the appropriate button
- The player has a limited time to press the button
- If the player succeeds, then the game moves to round two and adds an LED to the sequence. This will continue for 10 rounds
- If the player fails to mimic the pattern in the time allotted, pressed the wrong button, or did not press the buttons in the correct sequence the failure sequence will occur
- In the failure sequence, the separated red LED will be blinking quickly for 3 seconds. Then the player will see the level he reached represented in binary by the 4 LEDs 
- If the player completes 10 rounds successfully, then the 4 LEDs will be blinking on and off together

<br>
<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/ferasaljoudi/AssetsRepository/main/BrownSVGs/resources.svg" alt="Resources" style="width: 100%"></a>
</div>
<br>

<b>Here is a link to a YouTube video demonstrating the game:</b>

- _[Click Here](https://www.youtube.com/watch?v=UqE-Zc_CKJw "Watch a demonstration of the Simon game")_

