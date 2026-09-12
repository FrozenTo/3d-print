# Andmehõive — Labor 1 checklist

**Labor:** Andur ja kompressor, mis ise seisma jääb  
**Töömaht:** 32 tundi  
**Hindamine:** 20 punkti  
**Meeskond:** 3 tudengit  
**Tellimise kuupäev:** 22.09.2026  
**Esimene kaitsmine:** 06.10.2026  
**Repo tag:** `data-acquisition-lab1`

---

## 0. Projekti algseadistus

- [O] Loo repos kaust `data-acquisition/lab1/`
- [O] Kopeeri labori ülesanne faili `README.md`
- [O] Loo vajalik kaustastruktuur:
  - [ ] `src/`
  - [ ] `data/`
  - [ ] `notebooks/`
  - [ ] `docs/`
- [O] Kontrolli, et repo juurkaustas oleks `AGENTS.md`
- [O] Lisa arenduspäevik
- [O] Pane kirja meeskonnaliikmed
- [/] Pane kirja tegelikult kasutatavad vahendid ja tarkvara
- [ ] Lepi Nutikate Lahenduste L1 meeskonnaga kokku tähe saatmise kanal

### MG400 ühenduse test: 192.168.2.6 teise LAN-pordi kaudu ei töötanud. LAN1 kaudu töötas ühendus aadressiga 192.168.1.6, seega kasutame edaspidi seda.

---

# 1. Mida tellida

## 1.1 Labori vajaduste kaardistamine

- [ ] Vaata kogu labori ülesanne läbi ja märgi, mida iga osa vajab
- [ ] Kontrolli, millised komponendid on laboris juba olemas
- [ ] Koosta nimekiri puuduvatest komponentidest
- [ ] Kontrolli, kas voolikuid, T-liitmikke ja korke on piisavalt
- [ ] Otsusta, kas vaja on ühte või mitut uut rõhuandurit
- [ ] Mõtle, kas andurit tuleks tellida ka varuks

## 1.2 Rõhuanduri kandidaatide võrdlus

Võrdle vähemalt neid variante:

- [ ] MPX5700AP
- [ ] Absoluutandur vahemikuga umbes 30–210 kPa
- [ ] Kahe manomeetrilise anduri lahendus, kui see tundub mõistlik

Iga kandidaadi kohta leia:

- [ ] Mõõtevahemik
- [ ] Kas andur katab kogu pumba tööala `−70 ... +110 kPa`
- [ ] Tundlikkus `mV/kPa`
- [ ] Pa ühe ADC sammu kohta
- [ ] Kui suur osa anduri skaalast tegelikult kasutusse läheb (%)
- [ ] Minimaalne ja maksimaalne väljundpinge
- [ ] Kas väljund sobib AtomS3 3,3 V ADC sisendiga
- [ ] Kas vaja on pingejagurit või muud signaalitöötlust
- [ ] Hiljem: signaaliriba / müra suhe

## 1.3 Dokumentatsioon ja tellimus

- [ ] Koosta `docs/sensor_choice.md`
- [ ] Lisa sinna kandidaatide võrdlustabel
- [ ] Kirjuta valitud anduri põhjendus numbritega
- [ ] Koosta `docs/bom.md`
- [ ] Lisa Mouseri tootekoodid
- [ ] Iga tellitava osa juurde kirjuta, milline labori osa seda vajab
- [ ] Kontrolli BOM üle meeskonnaga
- [ ] Esita tellimus hiljemalt **22.09.2026**

---

# 2. Andur ja esimene signaal

## 2.1 MPX5700AP ühendamine

- [ ] Leia MPX5700AP õiged viigud andmelehelt
- [ ] Ühenda andur maketeerimisplaadile
- [ ] Ühenda 5 V
- [ ] Ühenda GND
- [ ] Ühenda `Vout` otse AtomS3 ADC viiku
- [ ] Ära lisa selles laboris pingejagurit
- [ ] Ära lisa op-ampi
- [ ] Ära lisa filtrit

## 2.2 Kontroll enne AtomS3 ühendamist

- [ ] Mõõda multimeetriga anduri toide
- [ ] Kontrolli, et toide oleks umbes 5 V
- [ ] Mõõda `Vout` atmosfäärirõhul
- [ ] Kontrolli, et `Vout` oleks umbes 0,85 V
- [ ] Veendu, et ADC sisendile ei läheks üle 3,3 V

## 2.3 AtomS3 püsivara

Iga 10 ms järel:

- [ ] Loe ADC väärtus
- [ ] Teisenda ADC väärtus rõhuks
- [ ] Näita rõhku AtomS3 ekraanil
- [ ] Saada mõõterida UART-i kaudu arvutisse

- [ ] Kontrolli, et proovivõtusagedus oleks umbes 100 Hz
- [ ] Lisa vajadusel pumba olek UART andmetesse

## 2.4 Python logija

- [ ] Ühenda AtomS3 arvutiga USB kaudu
- [ ] Loe UART-i `pyserial` abil
- [ ] Salvesta CSV faili vähemalt väljad:
  - [ ] `t_ms`
  - [ ] `adc`
  - [ ] `p_kpa`
  - [ ] `pump`
- [ ] Tee 10 sekundi testlogi
- [ ] Kontrolli, et logis oleks `1000 ± 5` rida
- [ ] Võrdle ADC põhjal arvutatud pinget multimeetriga
- [ ] Kontrolli, et erinevus jääks 2% piiresse

## 2.5 ADC resolutsioon

- [ ] Arvuta MPX5700AP jaoks Pa ühe ADC sammu kohta
- [ ] Salvesta arvutus dokumentatsiooni
- [ ] Kontrolli arvutuse ühikuid

## 2.6 Müra mõõtmine

Mõõda vähemalt:

- [ ] Pump väljas
- [ ] Pump sees

Pane kirja:

- [ ] Müra suurus LSB-des
- [ ] Müra amplituud
- [ ] Peamised spektri tipud

Kontrolli võimalikke müraallikaid:

- [ ] Pumba mootor
- [ ] MG400 servod
- [ ] USB toide
- [ ] 50 Hz võrgumüra

- [ ] Kontrolli vähemalt kahte müraallikat füüsiliselt sisse/välja lülitades
- [ ] Salvesta vastavad CSV failid

## 2.7 FFT / spektri analüüs

- [ ] Loo analüüs `notebooks/` kausta
- [ ] Tee FFT või Welch PSD
- [ ] Märgi spektri tipud sagedustega
- [ ] Seosta tipud võimalike müraallikatega
- [ ] Salvesta graafikud

## 2.8 Falstad simulatsioon

- [ ] Tee Falstadis andur → ADC mudel
- [ ] Mudelda ADC sisend 0...3,3 V piiranguga
- [ ] Lisa mõõdetud mürale vastav müraallikas
- [ ] Vaata, millal signaal ADC piiril lõikub
- [ ] Võrdle simuleeritud müra reaalse mõõtmisega
- [ ] Salvesta Falstadi fail/link
- [ ] Lisa skeemi pilt `docs/` kausta

---

# 3. Tehase tark kast

## 3.1 Ühendamine

- [ ] Võta tehase tark pumbakast
- [ ] Ühenda T-liitmik väljundtorusse
- [ ] Ühenda rõhuandur
- [ ] Pane iminapp klaasile
- [ ] Käivita imemine MG400 baaspaketi CLI kaudu

## 3.2 Logimine

- [ ] Logi süsteemi umbes 5 minutit
- [ ] Salvesta CSV faili

Leia logi põhjal:

- [ ] Pumba väljalülitusrõhk
- [ ] Pumba sisselülitusrõhk
- [ ] Pumba keskmine tööaeg
- [ ] Pumba keskmine seisuaeg
- [ ] Käivituste arv minutis

- [ ] Lisa kõikidele väärtustele ühikud
- [ ] Salvesta tulemused dokumentatsiooni
- [ ] Kasuta neid väärtusi enda kasti sihtmärkidena

## 3.3 Süsteemi skeem

Tee draw.io skeem, kus on:

- [ ] Arvuti
- [ ] MG400
- [ ] Pumbakast
- [ ] Rõhuandur
- [ ] AtomS3
- [ ] Haarats / iminapp

- [ ] Lisa skeemi pilt dokumentatsiooni
- [ ] Lisa link muudetavale draw.io failile

---

# 4. Meie tark pumbakast

## 4.1 Põhisüsteem

- [ ] Ühenda T-liitmik oma meeskonna tavalise pumbakastiga
- [ ] Ühenda rõhuandur
- [ ] AtomS3 mõõdab rõhku
- [ ] AtomS3 saab arvutist töörežiimi
- [ ] AtomS3 saab arvutist lülitusrõhud / riba
- [ ] AtomS3 teeb ise pumba ON/OFF otsuse
- [ ] AtomS3 näitab ekraanil:
  - [ ] rõhku
  - [ ] režiimi
  - [ ] pumba otsust / olekut
  - [ ] vea põhjust, kui süsteem läheb ohutusse olekusse

## 4.2 UART protokoll

Atom → arvuti:

- [ ] `t`
- [ ] `adc`
- [ ] `p`
- [ ] `mode`
- [ ] `pump`

Arvuti → Atom:

- [ ] `mode`
- [ ] `band`
- [ ] `stop`

- [ ] Testi, et käsud jõuavad õigesti kohale
- [ ] Testi vigase käsu käsitlemist

## 4.3 Imemise juhtloogika

- [ ] Määra sisselülitusrõhk
- [ ] Määra väljalülitusrõhk
- [ ] Rakenda hüsterees / rõhuriba
- [ ] Lisa minimaalne seisuaeg enne uut käivitust
- [ ] Lisa käivituste arvu piir minutis
- [ ] Kui rõhk on skaalast väljas → pump OFF
- [ ] Kui režiim on OFF → pump OFF

## 4.4 Puhumise juhtloogika

- [ ] Tee sama juhtimine positiivse rõhu jaoks
- [ ] Määra puhumise sisselülitusrõhk
- [ ] Määra puhumise väljalülitusrõhk
- [ ] Kontrolli hüstereesi toimimist
- [ ] Kontrolli käivituste piirangut

## 4.5 Fail-safe

- [ ] Kui 500 ms jooksul Atomilt uut rida ei tule → DO OFF
- [ ] Kui USB ühendus katkeb → pump OFF
- [ ] Kui programm jookseb kokku → pump OFF
- [ ] Kui Atom saadab vigase väärtuse → pump OFF
- [ ] Testi USB kaabli eemaldamist töötava süsteemi ajal
- [ ] Dokumenteeri testi tulemus

---

# 5. Hoidmise katsed

Tee katsed kolmes olukorras:

## 5.1 Iminapp klaasil

- [ ] Tõmba rõhk väljalülitusrõhuni
- [ ] Lülita pump välja
- [ ] Logi rõhu muutumist kuni sisselülitusrõhuni
- [ ] Mõõda pump ON/OFF tsükleid
- [ ] Leia käivituste arv minutis

## 5.2 Iminapp õhus

- [ ] Tee sama katse
- [ ] Mõõda rõhk
- [ ] Mõõda käivituste arv minutis
- [ ] Kontrolli, et pump ei läheks lühitsüklisse

## 5.3 Voolik korgiga

- [ ] Tee sama katse
- [ ] Mõõda rõhulangus
- [ ] Mõõda käivituste arv minutis

## 5.4 Juhtparameetrite valik

Katsete põhjal määra:

- [ ] Rõhuriba laius
- [ ] Minimaalne seisuaeg
- [ ] Maksimaalne käivituste arv minutis
- [ ] Imemise sisselülitusrõhk
- [ ] Imemise väljalülitusrõhk
- [ ] Puhumise sisselülitusrõhk
- [ ] Puhumise väljalülitusrõhk

Pane kirja:

- [ ] Rõhk iminapp klaasil
- [ ] Rõhk iminapp õhus
- [ ] Kõigi kolme olukorra käivitused minutis

---

# 6. MG400 klaasi võtmise test

Robot peab tegema järjestuse:

- [ ] Viib iminapi klaasile
- [ ] Lülitab imemise sisse
- [ ] Ootab piisava vaakumi tekkimist
- [ ] Tõstab klaasi
- [ ] Viib klaasi sihtkohta
- [ ] Lülitab puhumise sisse
- [ ] Vabastab klaasi

Test:

- [ ] Tee vähemalt 10 järjestikust võtmist
- [ ] Märgi iga katse õnnestumine / ebaõnnestumine
- [ ] Logi rõhk ja pumba olek
- [ ] Arvuta pumba töötsükkel 10 võtmise jooksul
- [ ] Paranda vead ja dokumenteeri muudatused

---

# 7. `docs/pump_control.md`

Fail peab sisaldama:

- [ ] Imemise ON rõhk
- [ ] Imemise OFF rõhk
- [ ] Puhumise ON rõhk
- [ ] Puhumise OFF rõhk
- [ ] Rõhuriba / hüsterees
- [ ] Minimaalne pumba seisuaeg
- [ ] Maksimaalne käivituste arv minutis
- [ ] Käivitused minutis: iminapp klaasil
- [ ] Käivitused minutis: iminapp õhus
- [ ] Käivitused minutis: voolik korgiga
- [ ] Rõhk iminapp klaasil
- [ ] Rõhk iminapp õhus
- [ ] 10 võtmise pumba töötsükkel
- [ ] Juhtloogika kirjeldus
- [ ] Fail-safe loogika
- [ ] Selgitus, miks just need parameetrid valiti

---

# 8. Tähe saatmine

## 8.1 AtomS3 kasutajaliides

- [ ] Lühike nupuvajutus liigub tähestikus edasi
- [ ] AtomS3 ekraan näitab valitud tähte
- [ ] Pikk vajutus saadab valitud tähe

Näide:

```json
{"letter":"A"}
```

## 8.2 Integratsioon

- [ ] Saada täht Nutikate Lahendustega kokkulepitud kanalisse
- [ ] Kontrolli, et jaam saab tähe kätte
- [ ] Kontrolli, et robot saab käsu joonistamiseks
- [ ] Dokumenteeri kasutatav protokoll / kanal

---

# 9. Arenduspäevik

Lisa üks sissekanne iga töösessiooni kohta.

## Mall

```md
## PP.KK.AA — kohal: Nimi, Nimi, Nimi

### Tegime
-

### Juhtus
- Mõõdetud väärtused:
-

### Otsustasime, ja miks
-

### Lahti järgmiseks korraks
-
```

Kontroll:

- [ ] Iga töösessioon on kirjas
- [ ] Kohal olnud inimesed on märgitud
- [ ] Reaalsed failinimed on kirjas
- [ ] Mõõdetud numbrid ja ühikud on kirjas
- [ ] Otsused on põhjendatud
- [ ] Vanad valed tulemused ei ole kustutatud
- [ ] Parandused on lisatud uue kuupäevaga

---

# 10. Repo kontroll

Repo `data-acquisition/lab1/` peab sisaldama:

## `src/`

- [ ] AtomS3 püsivara
- [ ] Python UART logija
- [ ] Python MG400 / DO pumba juhtimine

## `data/`

- [ ] Esimesed 100 Hz CSV logid
- [ ] Pump OFF müra logi
- [ ] Pump ON müra logi
- [ ] Tehase targa kasti logi
- [ ] Oma kasti testlogid
- [ ] Klaasi võtmise testlogid

## `notebooks/`

- [ ] FFT / Welch analüüs
- [ ] Spektrigraafikud
- [ ] Hoidmiskõverate analüüs

## `docs/`

- [ ] `sensor_choice.md`
- [ ] `bom.md`
- [ ] `pump_control.md`
- [ ] draw.io skeemi pilt
- [ ] Link draw.io algfailile
- [ ] Falstadi skeemi pilt
- [ ] Link / eksport Falstadi failist
- [ ] Ostsilloskoobi pildid
- [ ] Vajalikud fotod prototüübist

## Muud

- [ ] `README.md` täidetud
- [ ] `AGENTS.md` uuendatud
- [ ] Arenduspäevik täidetud

---

# 11. Ohutuse kontroll

Enne juhtmete muutmist:

- [ ] USB välja
- [ ] 5 V välja
- [ ] Kontrolli viike andmelehelt

ADC:

- [ ] AtomS3 ADC-le ei lähe üle 3,3 V

Pumbakast:

- [ ] 24 V toide välja enne DO ühenduste muutmist
- [ ] Robot keelatud enne DO ühenduste muutmist

Pump:

- [ ] Väldi sekundilise intervalliga lühitsüklit
- [ ] Kasuta minimaalset seisuaega
- [ ] Kui kast läheb liiga kuumaks, suurenda rõhuriba

Rõhk:

- [ ] +110 kPa lahtine voolik ei ole suunatud inimese poole
- [ ] −70 kPa iminappi ei panda naha vastu

Robot:

- [ ] Käed ei ole roboti tööalas
- [ ] Esimene test tehakse aeglaselt
- [ ] Hädastopp on käeulatuses

- [ ] Laboris ei joodeta

---

# 12. Enne kaitsmist

## Funktsionaalne demo

- [ ] AtomS3 näitab reaalajas rõhku
- [ ] CSV logimine töötab 100 Hz juures
- [ ] Pump jääb imemisel ise seisma
- [ ] Pump käivitub uuesti, kui rõhk muutub
- [ ] Pump jääb puhumisel ise seisma
- [ ] USB eemaldamisel jääb pump seisma
- [ ] Robot suudab klaasi võtta ja vabastada
- [ ] Täht jõuab jaama

## Analüüs

- [ ] Pa / ADC samm arvutatud
- [ ] Müra mõõdetud
- [ ] Spektrid olemas
- [ ] Müraallikad nimetatud
- [ ] Vähemalt kaks müraallikat eksperimentaalselt kontrollitud
- [ ] Tehase targa kasti 5 põhinumbrit olemas
- [ ] Hoidmiskõverad olemas
- [ ] Anduri valik põhjendatud numbritega

## Dokumentatsioon

- [ ] `README.md`
- [ ] Arenduspäevik
- [ ] `sensor_choice.md`
- [ ] `bom.md`
- [ ] `pump_control.md`
- [ ] `AGENTS.md`
- [ ] Skeemid
- [ ] Mõõtmised
- [ ] CSV failid
- [ ] Notebookid

## Git

- [ ] Commiti kõik vajalikud failid
- [ ] Kontrolli, et repo avaneb puhtalt teisest arvutist
- [ ] Kontrolli, et failides pole absoluutseid kohalikke path'e
- [ ] Lisa Git tag `data-acquisition-lab1`
- [ ] Push repo ja tag remote'i
- [ ] Valmista kaitsmiseks repo link

---

# 13. Kaitsmise ajal

Ole valmis näitama:

- [ ] Pumba automaatset seiskumist
- [ ] Pumba automaatset taaskäivitumist, kui iminappi kergitada
- [ ] AtomS3 ekraani
- [ ] Reaalajas rõhuandmeid
- [ ] CSV logi
- [ ] Arenduspäevikut
- [ ] Sensorivaliku arvutusi
- [ ] Spektrit / müramõõtmisi
- [ ] `pump_control.md`
- [ ] Klaasi võtmise demo
- [ ] Tähe saatmist

Ole valmis seletama:

- [ ] Miks valisite selle rõhuanduri
- [ ] Kuidas ADC väärtusest saab kPa
- [ ] Miks valisite just sellise hüstereesi
- [ ] Kuidas väldite pumba lühitsüklit
- [ ] Mis juhtub USB / UART vea korral
- [ ] Kuidas määrasite pumba ON/OFF rõhud

---

# 14. Lõpus README-sse lisada

- [ ] Git repo ja tag
- [ ] Laborist saadud peamised numbrid koos ühikutega
- [ ] Mida teeksime järgmine kord teisiti
- [ ] Mida Andmehõive Labor 2 peaks enne alustamist teadma
- [ ] Uuendatud tegelik eesmärk, kui see töö käigus muutus
