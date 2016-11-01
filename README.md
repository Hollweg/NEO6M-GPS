# NEO6M-GPS

##The Purpose

Using the GPS receiver with **NEO6M ATMEGA328 AVR microcontroller.** </br>
To make the hardware integration it was used an Arduino UNO v3 board as well as an SD card module.

The proposed use of a single-frequency NEO6M GPS module is to **create a datalogger, capturing all data in NMEA format received by the chip and then make a post analysis of the data.** </br>
So it would be possivle to **analyze the GPGSV and other protocols of interest, even study the possibility of developing a positioning correction algorithm using INPE ionospheric simulation model.**

##Utility

The code was developed specifically for the Arduino platform **using C++ and a language based on Wiring.** </br>
However, with **some minor modifications in initilization and configuration of some registers, the design can be adapted to other microcontrollers from other manufacturers.** </br>
Or, basically, **making the necessary hardware settings modifications, you can change the compiler to MikroC or AtmelStudio**, as desired. </br>
I saw the need to create this algorithm without use of TinyGPS or TinyGPS++ library because they are in some ways a little bit confusing and complex, even for realization of simple tasks.

##How it works?

The project idea is to build a **datalogger of NMEA sentences received via single-frequency GPS using a SD module and an Arduino UNO.** </br>
Therefore, to facilitate the hardware connections, **I did cut an universal soldering board, added some headers, and did the welding pin to pin, creating a sort of additional shield, connected directly on the main board in order to reduce bad contact problems, distance between pins, and excess wires, becoming the system plug and play.**

The SD module uses SPI communication (Serial Peripheral Interface), since the single-frequency GPS communication module uses UART (User Assynchronous Receiver / Transmitter).

I/O digital microcontroller used in the project:

- 7: RX (GPS)
- 8: TX (GPS)
- 9: Pin to jump of SD card verification
- 10: CS (Chip Select)
- 11: MOSI (Master Output Slave Input)
- 12: MISO (Master Input Slave Output)
- 13: SCK (Standard Clock)

Remembering that **it is not necessary to develop the additional board for hardware integration**, since it is correct connections for SD card (MISO, MOSI, SCK and CS) and GPS (RX and TX).

The SD card is supplied with 3.3V, however, if you use it a module, it probably has a linear voltage regulator at the entrance, allowing the power in 5V.

The GPS module can be powered with either 3V3 as 5V. However, the NEO6M chip is **EXCLUSIVELY** fed with 3.3V. If you make your own hardware, be careful with this fact, or the GPS hardware will be **damaged**.

**It is very important that the GPS module antenna is in an horizontal position, ensuring a better signal reception.**

Below is a picture of the assembled hardware, with the developed plate and connected modules.

![Imgur](http://i.imgur.com/2gs1L0m.jpg)

The NMEALOG.txt file shows a data file acquired during the night of 21/09. </br>
To get some most difficult protocol to be captured, as GPGSV, I recommend data acquisition **during night because it is estimated that the ionosphere layer is less ionized.** </br>
Given that **its ionization is the main cause of single-frequency GPS error, the received data quality is higher during this period.**

To develop a protocol filtering, you should do a **scan in GPS UART communication channel only for those sentences of interest.** </br>
**Recalling that sentences in NMEA format begin with $ and have its last data marked by the character \*. **

Below it is a link with **NMEA-like sentences detailed description**.

http://www.gpsinformation.org/dale/nmea.htm

However, as the initial goal is just the receipt and storage of all protocols received by the module, has not yet been implemented nothing to make this disposal of unnecessary information.

##Data analysis and development of an ionosphere correction algorithm

It was thought in the **development of a system capable of correcting the error provided by the ionosphere algorithm using a more elaborate form of this layer.** </br>
**We know about Bent and Klobuchar ionosphere correction algorithms, but we planned to develop a more efficient one.**

**However, information received by NMEA protocol standard sentences were not sufficient to estimate the position of the emitting satellites, as well as we do not have access to raw data and satellite data propagation TIMESTAMP.**

The result of this research was submitted as a paper to the event CCIS 2016 - 4th Conference of Computational Interdisciplinary Sciences_, in São José dos Campos, SP. In the paper it is explained all process of acquisition data, and the try to develop an algorithm capable of correct ionospheric delay using NEO6M single-frequency GPS module. </br>

As soon as the paper is published I'll let the link to it here. :)


## Direitos

**The project can be reproduced without any problems.**
However, I only ask you to **keep author credits.** :)

Enjoy!

Hollweg

