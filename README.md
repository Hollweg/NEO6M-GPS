#NEO6M-GPS

##The Purpose

Using the GPS receiver with **NEO6M ATMEGA328 AVR microcontroller.** </br>
It was used an Arduino UNO v3 board as well as an SD card module together with NEO6M GPS for harware integration.

The proposed use of a single-frequency NEO6M GPS module is to **create a datalogger, capture all data in NMEA format received by the chip and then make a data post analysis.**

So, it would be possible to **analyze the GPGSV and other protocols of interest (NMEA like sentences), even study the possibility of developing a positioning correction algorithm using INPE ionospheric simulation model.**

##Utility

The code was developed specifically for Arduino platform **using C++ and a language based on Wiring.** </br>
However, with **some minor modifications in registers initialization and configuration, the design can be adapted to other microcontrollers fromdifferent manufacturers.** 

Or, basically, **making the necessary hardware settings modifications, you can change the compiler to MikroC or AtmelStudio (or other)**, as desired. </br>
I saw the importance to create this algorithm without use of TinyGPS or TinyGPS++ library because they are in some way a little bit confusing and complex, even for realization of simple tasks.

##How it works?

The project idea is to build a **datalogger of received NMEA sentences via single-frequency GPS using a SD module and an Arduino UNO.** </br>

Therefore, to facilitate the hardware connections, **I did cut an universal soldering board, added some headers and did the welding pin to pin, creating a sort of additional shield, connected directly on the main board in order to reduce bad contact problems, distance between pins, and wire problems, becoming the system plug and play. :)**

The SD module uses SPI communication (Serial Peripheral Interface), since the single-frequency GPS communication module uses UART (User Assynchronous Receiver / Transmitter).

I/O digital microcontroller used in project:

- 7: RX (GPS)
- 8: TX (GPS)
- 9: Pin to jump of SD card verification
- 10: CS (Chip Select)
- 11: MOSI (Master Output Slave Input)
- 12: MISO (Master Input Slave Output)
- 13: SCK (Standard Clock)

Remembering that **it is not necessary to develop the additional board for hardware integration**, since its correct connections for SD card (MISO, MOSI, SCK and CS) and GPS (RX and TX) would be right.

The SD card is supplied with 3.3V, however, if you use it a module, it probably has a linear voltage regulator at the entrance, allowing the power in 5V.

The GPS module can be powered with either 3V3 as 5V. However, the NEO6M chip is **EXCLUSIVELY** fed with 3.3V. If you make your own hardware, be careful with this fact, or the GPS hardware will be **damaged**.

**It is very important that the GPS module antenna is in an horizontal position, ensuring a better signal reception.**

Below is a picture of the assembled hardware, with the developed plate and connected modules.

![Imgur](http://i.imgur.com/2gs1L0m.jpg)

The NMEALOG.txt file shows a data file acquired during night of 21/09. </br>
To get some most difficult protocol to be captured, as GPGSV, I recommend data acquisition **during night (because it is estimated that the ionosphere layer is less ionized and the signal quality will be better)** </br>
Given that **its ionization is the main cause of single-frequency GPS error, the received data quality is higher during this period.**

To develop a protocol filtering you should do a **scan in GPS UART communication channel only for those sentences of interest.** </br>
**Recalling that sentences in NMEA format begin with $ and have its last data marked by the character \*.**

Below it is a link with **NMEA-like sentences detailed description**.

http://www.gpsinformation.org/dale/nmea.htm

However, as the initial goal is just the receipt and storage of all protocols received by the module, has not yet been implemented nothing to make this disposal of unnecessary information.

##Data analysis and development of an ionosphere correction algorithm

It was thought in the **development of an algorithm capable of correcting the error provided by the ionosphere layer using a more elaborate estimation of this layer.** </br>
**We know about Bent and Klobuchar ionosphere correction algorithms contributions, but our main ideia is to develop a more efficient one.**

**However, information received by NMEA protocol standard sentences were not sufficient to estimate the position of the emitting satellites, as well as we do not have access to sattelite raw data (and consequently we do not access the real TIMESTAMP) we cannot proceed with the project idea with this hardware. To contour this problem we plan to acquire a better single-frequency GPS hardware (superior NEO6M models) that allows raw data manipulation.**

This research was developed in CRS-INPE submitted as a paper to the event _CCIS 2016 - 4th Conference of Computational Interdisciplinary Sciences_, in São José dos Campos, SP. In the paper it is explained the acquisition data process and the try to develop an algorithm capable of correcting ionospheric delay using NEO6M single-frequency GPS module. </br>

As soon as the paper is published I'll let the link to it here.

##Acknowlegment

I would like to thanks my friends and research colleagues in INPE: Fernando E. Puntel, Telmo S. Klipp e Adriano Petry for the help provided during this work.

##Copyrights

**The project is open source and can be reproduced without any problems.**
However, I only ask you to **keep author credits.** :)


Enjoy!

Hollweg

