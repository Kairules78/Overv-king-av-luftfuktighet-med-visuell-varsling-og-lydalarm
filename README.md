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

## Tekniske valg og begrunnelser

### Arduino Mega 2560
Jeg brukte Mega fordi jeg allerede hadde kortet tilgjengelig.
Det har også nok pinner til sensoren, lysdiodene, buzzeren
og de planlagte displayene.

### DHT11
Jeg valgte DHT11 fordi jeg hadde sensoren tilgjengelig, og den
er tilstrekkelig for å teste avlesning og varsling i prototypen.
Begrenset nøyaktighet gjør at systemet ikke er ment for
presisjonsmålinger.

### Grenseverdi på 45 %
Jeg satte grensen til 45 % relativ luftfuktighet for å teste
varslingen. Dette er en valgt testgrense, ikke en generell
anbefaling for luftfuktighet.

### Lys- og lydvarsling
Lysdiodene viser systemets tilstand, mens lydalarmen gjør det
mulig å oppdage varslingen uten å se på oppsettet.


## Veien videre

Planlagte forbedringer:

- [ ] Vise luftfuktigheten på to 7-segmentdisplay.
- [ ] Legge til hysterese for å unngå hyppig bytting mellom
      alarm og normaltilstand når målingen ligger nær grenseverdien.
- [ ] Legge til en knapp som demper lydalarmen, mens lysvarslingen
      fortsatt viser tilstanden.
- [ ] Håndtere sensorfeil med en tydelig feilindikasjon.
- [ ] Erstatte delay() med tidsstyring via millis(), slik at
      systemet kan reagere på knappetrykk mellom målingene.
- [ ] Dokumentere koblingene og teste oppstart, grenseverdier
      og frakoblet sensor.
