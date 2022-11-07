# Projeto: LCD_LM35
## Integrantes da equipe:
* Gabriel Santana - Protótipo
* Gustavo Prado   - Firmware
* Richard Matheus - Projeto digital
* Murilo Duarte   - Documentação
* José Pereira    - Orientador  

# Introdução
Em processos industriais sensíveis há diversos parâmetros a se manter vigiliante, variações de tensão, corrente, umidade, temperatura etc. Por meio de um monitor de temperatura é possível controlar um desses aspectos, diminuindo a ocorrência de falhas imprevistas que possam atrapalhar a produção, sendo este o intuito de nosso projeto.
  
## Sensor de temperatura-LM35
Podendo ser utilizado para medir temperaturas em contextos variados e ser de fácil utilização, o LM35 oferece uma flexibilidade que o coloca a frente de outros sensores. Seu tamanho de encapsulamento (0.5 x 0,5 cm) possibilita uma implementação em lugares que podem ser inacessíveis para sensores industriais. 
Existem vários tipos de encapsulamento, mas de  mesmo funcionamento. Alguns outros modelos são: LM34A, LM35C, LM35CA e LM35D. Com alguns parâmetros que diferem do LM35, portanto é importante consultar o datasheet do modelo utilizado. Para garantir a segurança do componente é recomendado cobrir as conexões do pinos de conexão com epóxi, assim a troca de temperatura entre as conexões e o ambiente será minimizada. 

 ![image](https://user-images.githubusercontent.com/88776127/161051123-69a14a18-eb50-4477-9970-21256ae9c0d5.png)


## Amplificador operacional

O amplificador operacional (ou amp. op.) é um componente eletrônico que, como o nome sugere, amplifica a tensão e a corrente de entrada. Isto é, o sinal de saída (corrente ou tensão) é resultado do sinal de entrada multiplicado por um certo valor (muito elevado no caso da tensão). Sua utilização em nosso projeto foi para que a tensão de trabalho do sensor fosse de 0v a 5v, ao invés do padrão de -2,5V a 2,5V. Sendo a razão de tal mudança eliminar a necessidade de trabalhar com variáveis negativas no código, consequentemente obtendo um programa mais leve e fluído.

## Tabela de alocação de pinos 

|pino|PORT|Função| |pino|PORT|Função| |pino|PORT|Função|         |pino|PORT|Função|  	  		
|:--:|:--:|:--:|--|:---:|:--:|:--:|   --|:---:|:--:|:--:|        --|:---:|:--:|:--:|
| 1 | RE3 | ||  11| VDD |  |          | 21 | RD2 | D6 LCD |      |  31| VSS  |
| 2 | RA0 | Sensor-1 | | 12 | VSS |  || 22 | RD3 | D7 LCD |      | 32 | VDD |  |
| 3 | RA1 | Sensor-2 | | 13 | RA7 |  || 23 | RC4 |  |            |  33| RB0 |  |
| 4 | RA2 | Sensor-3 | | 14 | RA6 | | | 24 | RC5 | |             |  34| RB1 |  |
| 5 | RA3 | Sensor-4 | | 15 | RC0 | | | 25 | RC6 | |             |  35| RB2 |  |
| 6 | RA4 |  | | 16 | RC1 |  |        | 26 | RC7 | |             |  36| RB3 |  |
| 7 | RA5 |  | | 17 | RC2 |  |        | 27 | RD4 | RS LCD |      |  37| RB4 |  |
| 8 | RE0 |  | | 18 | RC3 |  |        | 28 | RD5 | EN LCD |      |  38| RB5 |  |
| 9 | RE1 |  | | 19 | RD0 | D5 LCD |  |  29| RD6 |  |            |  39| RB6 |  |
| 10 | RE2 | | | 20 | RD1 | D4 LCD |  |  30| RD7 |  |            |  40| RB7 |  |
