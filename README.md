# NEO6M-GPS

## A proposta

Utilização do receptor GPS **NEO6M com microcontrolador AVR ATMEGA328**. </br>
Para fazer a integração de hardware foi utilizado uma placa Arduino UNO v3, bem como um módulo cartão SD. 

A proposta de utilização do módulo GPS NEO6M de única-frequência é a de **criar um datalogger, captando todos os dados em formato NMEA recebidos pelo chip, e então 
fazer uma pós análise dos dados, de forma que seja possível analisar os protocolos GPGSV, e então, estudar a possibilidade do desenvolvimento de um algoritmo de
correção de posicionamento utilizando dados de simulação ionosférica do INPE.**

## Utilidade

O código foi desenvolvido especificamente para a plataforma Arduino, **utilizando C++ e uma linguagem baseada em Wiring**. </br>
Entretanto, **sendo feitas algumas pequenas modificações de inicalização e configuração de alguns registradores, o projeto pode ser adaptado para outros microcontroladores**, de outras fabricantes. </br>

Ou então, basicamente, **fazendo-se as devidas inicializações de hardware, pode-se trocar o compilador para MikroC ou AtmelStudio, conforme desejado**. Vi a necessidade da criação desse código, e da não utilização da biblioteca TinyGPS ou TinyGPS++, pois a mesma em alguns aspectos é um tanto confusa e muito complexa para tarefas simples. </br>

## Como funciona?

A ideia do projeto é fazer um **datalogger das sentenças NMEA recebidas via GPS, utilizando um módulo SD e um Arduino UNO**. </br>
Portanto, para facilitar as conexões de hardware, cortei uma placa universal, adicionei uns headers, e fiz a soldagem pino a pino, criando uma espécie de **shield adicional, conectado diretamente em cima da placa principal, de modo a reduzir problemas de mau contato, distância entre pinos, e fios excedentes, tornando o sistema plug and play.**

O módulo SD utiliza comunicação SPI (Serial Peripheral Interface), já o módulo GPS comunicação UART (User Assynchronous Receiver/Transmitter). </br>
I/O digitais do microcontrolador utilizados no projeto:

- 7: RX (GPS)
- 8: TX (GPS)
- 9: Pino para pular a verificação de cartão SD
- 10: CS (Chip Select)
- 11: MOSI (Master Output Slave Input)
- 12: MISO (Master Input Slave Output)
- 13: SCK (Standard Clock)

Lembrando que não é necessário desenvolver a placa adicional para integração de hardware, desde que sejam feitas as conexões corretas quanto ao cartão SD (MISO, MOSI, SCK e CS) e ao GPS (RX e TX). 

O cartão SD é alimentado com _3.3V_, entretanto, caso utilize-se um módulo, provavelmente ele tenha um regulador de tensão linear na entrada, permitindo a alimentação em _5V_. 

O módulo GPS pode ser alimentado tanto com _3V3 quanto 5V_. Entretanto, o chip NEO6M é **EXCLUSIVAMENTE** alimentado com 3.3V. 
Caso faça seu próprio hardware, atente-se a esse fato, ou o hardware GPS será **danificado**. 

**É muito importante que a antena do módulo GPS fique em posição horizontal, garantindo uma melhor recepção do sinal.**

Abaixo, fica uma imagem do hardware montado, com a placa desenvolvida, e os módulos conectados.

![Imgur](http://i.imgur.com/2gs1L0m.jpg)

O arquivo _NMEALOG.txt_ mostra um arquivo de dados adquiridos durante a madrugada de 21/09. </br>
Para adquirir alguns protocolos mais difícies de serem capturados, como _GPGSV_, indica-se a aquisição de dados **durante a noite, pois estima-se que a ionosfera esteja menos ionizada.**

Tendo em vista que a sua ionização é a principal causa do **erro dos sinais de GPS**, a qualidade de dados recebida é maior durante esse período. </br>

Para utilização e filtragem de protocolos, deve-se fazer uma varredura no canal de comunicação UART do GPS apenas por aquelas sentenças de interesse. Lembrando que sentenças no formato NMEA começam com $ e tem seu último dado marcado pelo caractere \*.

Abaixo, deixo um link sobre a descrição das sentenças **NMEA-like**.

http://www.gpsinformation.org/dale/nmea.htm

Entretanto, como o objetivo inicial é apenas o recebimento e armazenagem de todos os protocolos recebidos pelo módulo, ainda não foi implementado nada que faça esse descarte de informações desnecessárias. 

## Análise de Dados e criação de um algoritmo para correção do erro ionosférico

Foi pensado no desenvolvimento de um algoritmo capaz de **corrigir o erro proporcionado pela ionosfera** utilizando um modelo mais elaborado dessa camada. 

**Entretanto, as informações recebidas pelas sentenças padrões do protocolo NMEA não foram
suficientes para estimação da posição dos satélites emissores, bem como acesso ao TIMESTAMP de propagação de dados dos satélites.**

Foi submetido para o _evento CCIS 2016 - 4th Conference of Computational Interdisciplinary Sciences_, em São José dos Campos, SP, um _paper_ explicando todo o processo de aquisição de dados, e tentativa de criação de um algoritmo capaz de corrigir a precisão de GPSs de única frequência. 

Logo que o artigo for publicado, deixarei abaixo o link com o paper completo.


## Direitos

**O projeto pode ser reproduzido sem problema algum.** </br>
Entretanto, caso isso seja feito, apenas peço para manterem/referenciarem **créditos ao autor**.

Enjoy!

Hollweg

