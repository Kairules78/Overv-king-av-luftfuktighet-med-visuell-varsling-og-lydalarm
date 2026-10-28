# Overvåking av luftfuktighet med visuell varsling og lydalarm

Et enkelt system bygget med Arduino Mega 2560, DHT11,
lysdioder og buzzer.

Systemet måler relativ luftfuktighet og varsler med lys og lyd
når målingen er under en valgt grenseverdi.

## Funksjonalitet

- Leser luftfuktighet fra DHT11.
- Tenner rød LED og aktiverer lydalarm ved lav luftfuktighet.
- Tenner blå LED når luftfuktigheten er over grenseverdien.
- Viser målingene i Serial Monitor.

Grenseverdien er foreløpig satt til 45 % relativ luftfuktighet
som en del av utprøvingen.

## Formål

Prosjektet er laget for å få praktisk erfaring med
mikrokontrollere, sensoravlesning, elektronikk og programmering.

## Komponenter

- Arduino Mega 2560
- DHT11 temperatur- og luftfuktighetssensor
- Rød og blå LED
- Buzzer
- Motstander
- Breadboard og jumperledninger
