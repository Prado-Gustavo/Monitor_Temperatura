# Projeto: LCD_LM35
## Integrantes da equipe:
* Gabriel Santana - Protótipo
* Gustavo Prado   - Firmware
* Richard Matheus - Projeto digital
* Murilo Duarte   - Documentação
* José Pereira    - Orientador  

# Introdução
No mundo atual, há vários componentes ou aparelhos no nosso dia a dia que servem para nos deixar informados sobre as coisas que acontecem no cotidiano, e este projeto falará sobre a importância da temperatura e sobre o controlador de temperatura lido pelo sensor LM-35. A temperatura é muito importante, pois tem muitas máquinas e lugares críticos que precisam ser avisados sobre o calor do ambiente para prevenção de algum equipamento ou para o conforto da temperatura para os seres vivos. O controlador de temperatura tem uma tela LCD onde mostra a temperatura média como °C (grau celsius) ou °F (fahrenheit) portanto assim sendo funcional e para diversas situações. 


## O que é sensor 
 Os sensores são componentes que conseguem nos informar sobre determinadas coisas do dia a dia, existem na indústria, comercial e residencial. São utilizados para nos auxiliar e identificar todas as tarefas que estão sendo executadas, eles conseguem reagir a mudanças de temperatura, distância, cor, som, velocidade, posicionamento, vibrações e etc. Isso varia muito para cada utilização, pois cada execução os resultados são diferentes, portanto, têm que se saber lidar e escolher sensores de específico funcionamento para que a execução seja perfeita e funcional. Os sensores acabam gerando um sinal elétrico que pode ser analógico ou digital, sendo uma saída ou entrada, isso depende muito da forma de ligação para o processo, portanto o sinal o qual é enviado para um microcontrolador é interpretado pelo sistema que faz o que foi programado. Os tipos de sensores são: Fotoelétricos, acústicos, magnéticos, elétricos, térmicos, capacitivos e pressão.
 
 | Figura 1: Sensores diversos |
 |:--:|
 |![sensores diversos](https://user-images.githubusercontent.com/88776127/161050897-636e7124-d012-4e44-ab9f-8773d3e0c6e8.png)|
 | Fonte: Multicomercial |
    

## Sensor de temperatura-LM35

O sensor serve para medir a temperatura ambiente, sendo um objeto ou um liquido que possui temperatura, sendo assim a função dele e medir ou informar uma temperatura. O sensor LM35 é bem simples e bem funcional que pode ajudar em variadas coisas. O sensor LM35, ele pode ter diferentes encapsulamento, que é o tipo material feito para o componente, portanto o mais utilizado para encapsulamento é o TO-92  que é feito de material plástico ou epóxi, o material muito utilizado por diversos componente. O encapsulamento serve para aguentar uma determinada temperatura e para proteger o componente. O tamanho do encapsulamento é de (0.5 x 0,5 cm). Existem vários tipos de encapsulamento que as empresas fabricam, mas o funcionamento são os mesmos. Os sensores tem varias versões, sendo elas: LM34A, LM35C, LM35CA e LM35D. Os sensores tem parâmetros diferentes do LM35, portando e importante consultar o datasheet. Para garantir a segurança do componente e necessário cobrir as conexões do pinos de conexão com epóxi. Portanto a troca de temperatura entre as conexões e o ambiente será minimizada, pois a temperatura podem ser influenciada na temperatura medida. Este sensor e indicado para medir corpos que seja no máximo 0.01°C, diferente da superfície a qual ele esta fixado. O que poderia influenciar a temperatura do componente e a corrente, mas não entra no caso pois o componente trabalha com uma corrente de 60μA, adequado ao uso.

 ![image](https://user-images.githubusercontent.com/88776127/161051123-69a14a18-eb50-4477-9970-21256ae9c0d5.png)

                                               
## Como utilizar

A ligação de alimentação é através dos pinos externos, e o entendimento e super simples, mas tem que tomar cuidado para inverter os pinos da alimentação do LM – 35. Para entendimento melhor, é importante saber como que o sensor ira reagir, pois cada dispositivos reagi de uma forma, eles tem umas funções especifica, portando tem que dimensionar um sensor adequada. Uma breve explicação sobre; “Um sensor é um dispositivo que responde a um estímulo físico/químico de maneira específica e mensurável analogicamente”. O sensor LM-35, não necessita de uma certa calibração externar para mostras os resultados com precisão, os valores de temperatura com variações de 0,25ºC ou até mesmo 0,75ºC dentro da faixa de temperatura de –55ºC à 150ºC, mostrando-se muito prático e eficiente.

1° terminal: alimentação que suporta de 4 a 20 v

2° terminal: tensão de saída, a proporcional a temperatura medida.

3° terminal: GND (terra)

Antes de executar a instalação ou utilização do componente é importante verificar o datasheet, sendo assim vê se todas as ligações estão corretas. É importante exaltar que existem vários tipos de formas de ligar o LM35, para o acesso de formas de ligações, apenas acessar as paginas 16,17 e 18 do datasheet do componente. 

![image](https://user-images.githubusercontent.com/88776127/161051374-116ae812-b708-4e56-9eee-2e6f48d32ee6.png)

## LCD

O termo LCD é a sigla que traduzido é ‘’liquid Crystal display’’. Uma tela cristal liquido. Ele e utilizado para mostra letras, números e imagens, vídeo , diversas coisas para monitoramento e ele é muito utilizado em dispositivos eletrônicos, e muitas das vezes ele aparece no nosso dia a dia, podendo auxiliar ou mostrar um emoji ou fotos, etc. O LCD pode ter diversos tamanhos, podendo ser pequeno e ate grande, O LCD é a parte frontal que gera as cores e forma a imagem da tela, o que muda é o padrão da luz de fundo. As telas LCDs funcionam com cores projetadas em uma transparência, ou seja, não brilham. Desse modo, a tela precisa de uma fonte de luz localizada na parte de trás, o backlight, para mostrar a image

## Resistor 

Os resistores são componente na eletrônica e também na elétrica muito usado, e são importante para todas as partes elétrica como proteção de algum componente e etc. 	A função do resistor e limitar o fluxo de corrente passando no condutor, por meio da conversão da energia elétrica em energia térmica, os resistores são geralmente feitos a partir de materiais dielétricos, de grande resistência elétrica. A grande resistência elétrica dos resistores torna esses componentes capazes de reduzir a passagem da corrente elétrica.Dentre as várias utilidades de um resistor, podemos citar a conversão da energia elétrica em energia térmica (através da dissipação de calor), é a Lei de Joule e o controle da voltagem em qualquer parte do circuito, pois oferece uma resistência à passagem da corrente elétrica, ‘dificultando’ a passagem das cargas elétricas.Essa resistência às cargas ocasiona, na direção da corrente elétrica, uma queda de potencial nos terminais do resistor. Tal característica é muito útil quando queremos obter uma voltagem diferente da disponível, bastando usar uma determinada configuração de resistores, como no caso do circuito divisor de tensão, um dos circuitos mais estudados em faculdades e cursos técnicos.Como a corrente elétrica é o movimento ordenado desses elétrons, eles se moverão mais, e mais aleatoriamente, se tiverem mais energia (maior temperatura), o que reduziria o valor da corrente elétrica, pois como vimos anteriormente, a corrente é um fluxo ordenado de cargas.Portanto, à medida que a temperatura aumenta, a resistividade (que é a característica do material) aumenta, pois é mais difícil que os elétrons se movam de maneira uniforme para gerar a corrente elétrica. Os tipos de resistores depende da funcionalidade que esta optando, São exemplos potenciômetros, LDR (light depend resistor), PTC (coeficiente de temperatura positivo), NTC (coeficiente de temperatura negativo), Magnetorresistores, reostato, dentre outros.

## Amplificador operacional

O amplificador operacional (ou amp. op.) é um componente eletrônico que, como o nome sugere, amplifica a tensão e a corrente de entrada. Isto é, o sinal de saída (corrente ou tensão) é resultado do sinal de entrada multiplicado por um certo valor (muito elevado no caso da tensão).Acontece que, o amplificador operacional é um componente não intuitivo e que possui “regras” que o definem. Portanto, os pontos que serão apresentados adiante não possuem uma lógica clara, já que mostrarei o amp. op. de forma direta. Embora, em um tópico mais a frente, mostrarei, resumidamente, o circuito por trás dele.Enfim, considere a imagem abaixo que mostra a simbologia do amplificador operacional com algumas nomenclaturas usuais. Duas entradas do amp. op. servem para alimentar o circuito interno do amplificador, que são o Vcc e o Vee. Estas entradas também definem os limites de tensão da saída. Isto é, a tensão de saída só poderá variar entre Vee e Vcc. Sendo Vee o limite inferior e Vcc o limite superior. Por conta disto, Vcc é uma tensão positiva e Vee é uma tensão negativa.É importante lembrar que deve existir um referencial (terra), assim como em qualquer circuito. E as tensões (entradas e saída) são relativas à ele.Basicamente, o amplificador operacional é uma unidade eletrônica que se comporta como uma fonte de tensão controlada por tensão. Ele é projetado para executar algumas operações matemáticas quando componentes externos, como resistores e capacitores estão conectados aos seus terminais.

## Detalhes tecnicos 


                                          Mapeamento dos pino 


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

































                                                


                                           










