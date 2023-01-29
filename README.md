# uebungsblatt

Eine Loesung zu dem [Uebungsblatt 5](https://github.com/gregorscholz/uebungsblatt/blob/main/U5_EidP_WS2223_Uebungsblatt.pdf).

## how-to (unter unix)
kompilieren:
`g++ -Wall Messungen.cpp MessReihe.cpp MessWert.cpp -o Messungen`

ausfuehren:
`./Messungen`

oder beides zusammen:
`g++ -Wall Messungen.cpp MessReihe.cpp MessWert.cpp -o Messungen && ./Messungen`

## output
```
Messreihe 1:
10 mA
20 mA
30 mA
40 mA
50 mA

Messreihe 2:
20 mA
40 mA
60 mA
80 mA
100 mA

Messreihe 4:
0.05 W
46 W
1.359e-07 W
0.00108 W
5e-10 W
Minimaler Wert: 5e-10 W
Maximaler Wert: 46 W
```
