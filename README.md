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

1. <b>Initialization:</b>
    - When the code runs, the 4 LEDs perform a classic Cylon Eye Scanner sequence.

2. <b>Starting the Game:</b>
    - The game begins when the player presses the blue button on the STM32.
    - The Cylon Eye Scanner stops, and the first round starts by generating a random light sequence.

3. <b>Player Interaction:</b>
    - The player must mimic the light sequence by pressing the corresponding buttons within a limited time.
    - If the player successfully replicates the sequence, a new light is added to the sequence for the next round.
    - The game continues this way for up to 10 rounds.

4. <b>Failure Condition:</b>
    - If the player fails to mimic the pattern correctly, presses the wrong button, or runs out of time, a failure sequence is triggered.
    - The separated red LED blinks quickly for 3 seconds to indicate failure.
    - The level reached by the player is then displayed in binary using the 4 LEDs.

5. <b>Winning Condition:</b>
    - If the player successfully completes all 10 rounds, the 4 LEDs blink on and off together in celebration.

<br>
<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/ferasaljoudi/AssetsRepository/main/BrownSVGs/resources.svg" alt="Resources" style="width: 100%"></a>
</div>
<br>

<b>Here is a link to a YouTube video demonstrating the game:</b>

- _[Click Here](https://www.youtube.com/watch?v=UqE-Zc_CKJw "Watch a demonstration of the Simon game")_

