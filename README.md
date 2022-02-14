1)POPIS ZAPOJENÍ: 
a)k Stm8 je zapojen LCD displayi, který je napájen 5V 
b)b)použití ncoderu(pomocí rotace nastavení času) 
c)c)buzzer
d)d)potenciometr(trimr), který nastavuje jas

2)POPIS FUNKCE: 
Cílem je naprogramovat minutky, které nastavuji pomocí ncoderu. Pomocí ncoderu nastavím požadovaný čas(tzn. jak dlouho chci danou činnost vykonávat, např.:20ms) a postupně se bude odečítat 1 sekunda až se na displayi objeví 0. Program simuluje klasické kuchyňské minutky
a)Při stisknutí ncoderu=časování
b)Minutky budou měřit v sekundách 
c)Stav se zobrazuje na displayi LCD
d)Trimr nastavuje jas na displeji

Podrobnější popis funkce:
-Na displeji nastavíme pomocí ncoderu počáteční stav, který se zobrazí na horní straně displeje(hodnota se .
-Na dolní straně displeje se ukazuje cas do konce, kde se odečítá nastavený čas
-Při stisku ncoderu se postupně bude odečítat čas
-Čas se vždy odečte po 1sek(1000ms) 
-Jakmile dojede čas do konce tak buzzer zapípá

SOUČÁSTKY:
1.LCD displej
-VSTUPY: LOAD/CS, CLK(clock), DIN(data input) 
-16-bitový posuvný registr-zápis příkazů
-Začneme zleva hledat vzestupnou hranu na vstupu CLK. 
-Jakmile ji nalezneme podíváme se na stav vstupu DIN v okamžiku této vzestupné hrany. 
-Je-li tam úroveň Low, zapíšeme si "0", je-li tam úroveň High, zapíšeme si "1". 
Pak hledáme další vzestupnou hranu na vstupu CLK. To děláme tak dlouho než narazíme na vzestupnou hranu na vstupu LOAD/CS. V tom okamžiku zapisování ukončíme a podíváme se na celé číslo.


2.LCD displej
-Jas displeje je regulovaný pomocí potenciometru 5kΩ - připojen na nepájivém poli
-Displej ukzauje:
-Pocatecni cas a cas dokonce
Rotační n-coder
-nastavuje pocatecní čas pomocí otáčení
-Pomocí kliknutí nasatví čas do konce

6)ZÁVĚR:
Projekt simuluje kuchyňské minutky. Používá periferie - LCD displej, n-coder, potenciometr, buzzer
Nevýhody:
-Ncoder funguje pouze na pravou stranu, pokud točím na začátku na levou stranu tak přeteče a přestane fungovat
Výhody:
-Můžeme využívat v praxi(kuchyň)

Co jsem se naučil:
-Programovat displej
-Programovat n-coder

Kód má průměrnou délku a na moje poměry hodně složitý. Doteď nechápu, některé složitější části v mém kódu, ale celkově jsem se naučil spoustu věcí, které v budoucnu nejspíše nevyužiji.

Jak to vidím dál:
V budoucnu už se nechci věnovat programování