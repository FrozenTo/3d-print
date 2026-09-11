1. Checklist
A. Projekti algus ja repo
 Loo meeskonnale üks Git repo.
 Loo kaust 3d-print/lab1/.
 Kopeeri ülesande tekst sinna failina README.md.
 Veendu, et repo juurkaustas on AGENTS.md.
 Pane kirja 3 meeskonnaliiget.
 Lisa README-sse esimene arenduspäeviku sissekanne.
 Pane kirja, milliseid printereid, materjale ja tööriistu te tegelikult kasutate.
B. Kuup — printeri lõtku test
 Tee Fusion 360-s 50 × 50 × 50 mm kuup.
 Tee selle sisse silinder raadiusega 20 mm.
 Tee silindri ja ümbritseva osa vaheline lõtk parameetriks.
 Salvesta Fusioni lähtefail.
 Ekspordi STL.
 Tee PrusaSliceris .3mf.
 Prindi esimene variant.
 Kontrolli, kas silinder:
 on täiesti kinni;
 liigub suure jõuga;
 liigub normaalselt;
 pöörleb vabalt.
 Vajadusel tee järgmine lõtkuvariant ja prindi uuesti.
 Leia väikseim lõtk, millega silinder liigub.
 Leia lõtk, mille juures detail veel kokku sulab / kinni jääb.
 Mõõda tulemus nihikuga, kui vajalik.
 Pane kõik kasutatud lõtkude väärtused README-sse mm-des.
 Pane kirja printer, PLA ja olulised sliceri seaded.
 Salvesta iga prinditud variandi STL ja 3MF.
C. Paindlik tükk
 Mõtle välja lihtne painduv testdetail.
 Pane kirja selle mõõdud:
 pikkus;
 laius;
 paksus.
 Salvesta lähtefail.
 Ekspordi STL.
 Tee .3mf.
 Prindi detail PLA-st.
 Testi, kui palju saab seda painutada nii, et see tuleb tagasi.
 Pane kirja elastse painde piir.
 Painuta rohkem ja leia koht, kus detail jääb kõveraks.
 Pane kirja plastilise painde piir.
 Painuta kuni murdumiseni.
 Pane kirja, kus ja kuidas see murdus.
 Mõõda või dokumenteeri paine millimeetrites/kraadides.
 Tee vajadusel teine versioon.
 Salvesta kõik versioonid eraldi failidena.
 Kirjuta README-sse, mida igas versioonis muutsid ja miks.
D. Pastakahoidiku planeerimine
 Vaata üle MG400 kinnitus/flants.
 Ava antud MG400 mount Fusion 360 fail.
 Mõõda olemasolev kuulpastakas nihikuga.
 Mõõda:
 pastaka läbimõõt;
 kinnituseks vajalik pikkus;
 otsa asukoht;
 MG400 kinnituse mõõdud.
 Otsusta, kuidas pastakas hoidikusse kinnitub.
 Otsusta, millises suunas hoidik peab järele andma — peamiselt Z.
 Kasuta kuubi testist saadud lõtku.
 Kasuta painduva detaili testist saadud mõõte.
 Tee esimene CAD-versioon.
E. Pastakahoidiku prototüübid
 Salvesta esimene variant näiteks pen_holder_v01.
 Ekspordi STL.
 Tee .3mf.
 Prindi.
 Kontrolli, kas pastakas mahub sisse.
 Kontrolli, kas hoidik sobib MG400 külge.
 Kontrolli, kas vedrutav osa annab Z-suunas järele.
 Kontrolli, kas pastakas tuleb pärast vajutamist tagasi algasendisse.
 Testi umbes mõnemillimeetrist Z-viga.
 Pane kirja probleemid.
 Tee v02.
 Kirjuta juurde, mis muutus ja miks.
 Korda seni, kuni hoidik töötab.
 Säilita kõik versioonid, mitte ainult viimane.
F. Robotiga testimine
 Kinnita hoidik MG400 külge.
 Pane paber tööalale.
 Hoia hädastopp käeulatuses.
 Tee esimene robotijooks väikese kiirusega.
 Õpeta/kinnita kirjutamise Z-kõrgus.
 Kontrolli, et vedrustus kompenseeriks väikest Z-viga.
 Kontrolli, et pastakas ei saaks liiga suurt survet.
 Pane robot joonistama ühe lihtsa tähe.
 Ühenda see süsteemiga, kus ESP32 näitab tähte.
 Robot joonistab sama tähe, mida ESP32 näitab.
 Dokumenteeri töötav lõpptulemus.
G. Tellimus enne 22.09.2026
 Vaata, mis jäi laboris reaalselt puudu.
 Kontrolli, kas vaja on juurde:
 PLA;
 PETG;
 M5 polte;
 M5 mutreid;
 M3 kuumsisestusi;
 magneteid;
 midagi muud.
 Pane ainult reaalselt vajalikud asjad jagatud Google Sheeti.
 Tee see hiljemalt 22.09.2026.
H. Dokumentatsioon
 Iga töösessiooni kohta on arenduspäeviku sissekanne.
 Iga sissekanne sisaldab:
 kes kohal olid;
 mida tegite;
 mõõdetud numbreid;
 mida otsustasite;
 miks otsustasite;
 mis jäi järgmiseks korraks.
 README-s on kuubi tulemused.
 README-s on painduva detaili tulemused.
 README-s on pastakahoidiku versioonid.
 README-s on lõpliku hoidiku mõõdud ja kirjeldus.
 README-s on kasutatud vahendid.
 README-s on kasutatud allikad.
 README-s on lõpuosa „Mida teeksime teisiti”.
 README-s on info, mida järgmine labor peaks teadma.
I. Failid repos

3d-print/lab1/ kaustas peaks lõpuks olema vähemalt:

 README.md
 kuubi Fusion/CAD lähtefail
 kuubi STL-id
 kuubi .3mf-id
 painduva detaili lähtefail
 painduva detaili STL-id
 painduva detaili .3mf-id
 pen_holder_v01
 pen_holder_v02
 jne
 lõpliku hoidiku STL
 lõpliku hoidiku .3mf
 muud vajalikud skeemid/failid

Repo juures:

 AGENTS.md on uuendatud.
 Kõik muudatused on commititud.
 Loo tag 3d-print-lab1.
 Push repo + tag serverisse.
J. Kaitsmiseks
 Robot töötab.
 Pastakahoidik on roboti küljes.
 Hoidik annab Z-suunas järele.
 ESP32 näitab tähte.
 Robot joonistab selle tähe.
 Oskad öelda printeri sobiva lõtku.
 Oskad öelda painduva detaili elastse piiri.
 Oskad öelda plastilise painde piiri.
 Oskad kirjeldada murdumist.
 Oskad selgitada, miks lõplik pastakahoidik on sellise kujuga.
 Oskad näidata hoidiku varasemaid versioone.
 Oskad avada arenduspäeviku.
 Git tag 3d-print-lab1 on olemas.
