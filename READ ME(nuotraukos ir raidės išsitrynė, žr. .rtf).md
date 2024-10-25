Prad?kim nuo v0.1

1.	Pradioje reik?jo parašyti program? kuri nuskaityt? duomenis.
Taip pat buvo si?loma naudoti struk?r?.
 
 Taigi, susik?riau tok? strukt?r?.

U failo nuskaitym? atsakinga funkcija sekan?i?me paveiksl?lyje.

Nuskiatymo funkcija
 
?ia "temp" sukuriamas tik tam, kad su "getline" pagalba atsikraty?iau failo antrašt?s.

Atsidarau fail? pavadinimu, kuris buvo nustatytas kvie?iant funkcij?.

Po to, pasinaudodamas ciklu "for" perskaitau vard? ir pavard?, po vien? raides kurias veliau priskyriu i laikin? strukt?r? "current", kad tvarkingai gal??iau visk? kartu perrašyti ? pagrindin? strukt?r? "mokinys".

Toliau skaitau paymius iš tos pa?ios eilut?s nested cikle "for", tiek kart? kiek iš anksto nusakoma funkcijai. Nuskaitytus paymius, po vien?, priskiriu strukt?ros vektoriui "Pazymys" naudodamas push_back funkcij?.

Ciklui pasibaigus nuskaitau paskutin? ?rašyt? vert? likusi? eilut?je - Egzamino bal?.

Cia suskai?iuojamas galutinis(*) balas kuris sudarytas iš 0.4*ND vidurkio(*) + 0.6 * Egz.
Ši vert? ska?iuojama keli? kit? funkcij? apie kurias bus aiškinama v?liau.

Galiausiai baigiu skaityt fail?, savo laikinos strukt?ros "current" reikšmes priskiriu iš anksto paskirtai strukt?rai ir udarau fail?.


Galutinio balo funkcija(*)
 
Galutinis balas skai?iuojamas štai taip, funkcijoje, kuri yra kitame .cpp faile.



Vidurkio funkcija(*)
 
?ia pradioje tikrinam ar iš vis turime paymi? iš kuri? gal?tum?m skai?iuot vidurk?. Jei toki? n?ra, tai tiesiog grainam 0.

Pasinaudojam std::accumulate funkcija, kad sud?tum?m visas vertes nuo "mok.Pazymys" pradios iki pabaigos ir grainam ši? sum? padalint? iš paymi? kiekio.




2-3.	Toliau tur?jau parašyt program? kuri skai?iuot? ir išvest? vidurk?, bei median?.



Medianos funkcija
 
?ia v?l tikrinam ar turim paymi? kaip ir vidurkio funcijoj.

Pasinaudoju "sort" funkcija kad sur?šiuot? man duomenis medianos skai?iavimui.

Jei paymi? skai?ius yra lyginis, tai surandu dvi vidurines vertes ir išvedu j? vidurk?. Jei ne, tai išvedu vidurin? paym?.

Išvedimo funkcija
 
?ia pradioj ?vedu nesibaigiant? cikl? kuris veikia iki kol naudotojas ?veda tinkamo tipo reikšm?.
Jei ?vestas netinkamas duomen? tipas, pradioj atlaisvinu "cin" funkcija, tada praleidiu klaid? ir bandau v?l.
?ia naudotojo prašau ?vesti kiek mokini? man reik?s išvesti.

Tada duodu naudotojui pasirinkim? tarp vidurkio ir medianos rodymo.

Sukuriu vektoriu kuriame laikysiu naudotojo ?vestus mokini? numerius, kad gal??iau v?liau juos panaudot.

Abu vidurkio ir medianos išvedimo ciklai veilia taip pat:
	pradedu cikl? nuo 0, nes taip indeksuojami konteineriai,
	kintamajam "idx" priskiriu ankš?iau naudotojo duotus mokini? numerius, bet iš j? atimu vienet?, kad gau?iau teising? mokinio indeks?.
	Išvedu Vard?, Pavard? ir vidurk? arba median?.
	Naudoju mano funkcij? "spacing"(*) kad išves?iau reikiam? tarp? kiek?.


Spacing funkcija(*)
 
Šiai funkcijai prašau "string" tipo ir viso ilgio kur? tur?s uimti odis kartu su tarpais.

At?m?s vien? iš kito, gaunu skai?i? kiek tarp? prireiks.

grainu tekst? kuriame yra pradinis tekstas sud?tas su rekiamu tarp? kiekiu.

Ši funkcija yra kitam faile "dalykas.cpp".


4-5  
Toliau uduotis prašo, jog programa veikt? net jei ND paymi? kiekis n?ra iš anksto inomas.


Eilut? 231
 
?ia v?l naudoju t? pat? metod? gauti reikiam? duomen? tip?.

gav?s reikiam? skaitin? "ND_kiekis" vert? paleidiu "nuskaitymas" funkcij?, kuri nuskaityt? tik reikiam? kiek? ND paymi?.


Toliau v0.2

1-2	Uduotis prašo sugeneruot 5 failus: 1000, 10000, 100000, 1000000, 10000000 dydio.


eilut? 223
 
Pradioj duodu naudotojui pasirinkim? ar jie nori sukurt failus.

Jei naudotojas atsako - taip, tai klausiu kiek failu prireiks, kiek eilu?i? ir ND paymi? kiekvienam failui reik?s.

Kaip matot ?ia yra dar viena mano funkcija "pav_gen"(*)kuri atsakinga u fail? pavadinim? k?rim?.

Gav?s mokini?, ND kiekius ir pavadinim?, galiu sugeneruot failus cikle kuris veikia kol sukurtas ankš?iau ?rašytas fail? kiekis.

Taip pat ?ia ir suskirstau mokinius.

Eilut?je 198 prasideda skirstymas.

Pradioj naudotojo atsiklausiu.

Tuomet atsiklausiu, kur? fail? suskirstyt cikle kuris prii?ri, kad pavadinimas b?t? ?rašytas teisingai.

tuomet su funkcija "nuskaitymas" - nuskaitau fail?, "gal_isvedimas" - ? konsol? išveda duomenis panašiai kaip funkcija "isvedimas", bet ?ia taip pat išveda galutin? paymi su dviem skaitmenim po kablelio ir paskiria mokin?, šaunuoliu arba beg?diu.


pav_gen funkcija(*)
 
Labai trumpa funkcija, kurioje priskiriamas šabloninis pavadinimas "pavadinimas" prie jo pridedamas skai?ius pagal iš anksto nustatyt? kiek? kvie?iant pa?i? funkcij? ir galiausiai pabaigoj pridedamas ".txt".

Tuomet gauti pavadinimai idedami ? "string" tipo vektori?, kad gal??iau naudot v?liau.




gal_isvedimas funkcija
 
Kaip matot funkcija yra beveik identiška funkcijai "isvedimas",
tiktais ?ia taip pat išvedama galutinis balas, bei priskirta kategorija.

Taip pat ?ia turim kelias, ankš?iau nematytas funkcijas:
"space_remove"(*) ir "vadinam"(*)


space_remove funkcija (*)
 
Funkcija labai paprasta - paima Vard? ir Pavard? ir jeigu per?jus j? nuo pradios iki pabaigos randa tarp?, j? panaikina.



vadiman funkcija(*)
 
Ši funkcija irgi labai trumpa.
Jei galutinis paymys nemaesnis u 5, grainam "šaunuoliai", kitu atv?ju - "beg?diai".


3	Toliau prašoma suskirstyt mokinius atskirame faile.



isskirstymas funkcija
 
Sukuriami ir atidaromi 2 failai, vienas šaunuoliams, o kitas beg?diams.

Abiem failam sukuriamos antrašt?s.

Tuo pa?iu išvedimo principu, tie patys duomenys išvedami ? atskir? fail?.

Abu failai udaromi.



4	Prašoma pamatuoti fail? k?rimo, fail? nuskaitym?, student? r?šiavimo ir r?šiavimo išvedimo laik?.



69 eilut?
 
 
Atsiklausiam naudotojo ar jie nori atlikt analiz?.

Tada failas "analize.txt" atidaroma ir udaroma kad ?sitikint jog jis tikrai tuš?ias.

Prašom naudotojo ?vest mokini? ir nd paymi? kiek?, kad gal??iau sukurt naudotojui sukurt fail? su norimais parametrais.

Laikui matuot naudoju "chrono" bibliotek?.

Laiko skai?iavimo algoritmas veikia taip:
	prieš pat pradedant matuot, gaunu tiksl? laik?,
 	gaunu tiksl? laik? po programos,
	atimu vien? iš kito, kad gau?iau pra?jus? laik? ir nurodau, jog jis mus ?rašytas milisekundi? tikslumu.
	galiausiai š? laik? išvedu.

Uduo?iai atlikt šaukiu keturias funkcijas "generavimas", "nuskaitymas", "vadinam" ir "isskirstymas"

Skai?iuoju ne tik ši? funkcij? laikus atskirai, bet ir j? vis? kartu.

Visus laikus išvedus programa usidaro.




Galiausiai v0.3
Uduotis - išmatuot fail? k?rimo, fail? nuskaitym?, student? r?šiavimo ir r?šiavimo spart? naudojant "std::list"

Jog tai gal??iau padaryt man reik?jo visas reikiamas funkcijas("generavimas", "nuskaitymas", "vadinam" ir "isskirstymas") perrašyt naudojant "std::list".

Suk?riau nauj? strukt?r?, kurioje vietoj vektoriaus, paymiai laikomi list'e.

Kadangi generavimas nenaudoja vektori?, šios funkcijos galiu nekeisti.

l_nuskaitymas funkcija
 
Šioj funkcijoj beveik nieko nereik?jo keisti, tiktais kelis pavadinimus.


Vadinam funkcija taip pat nenaudojo vektori?, tai galima j? naudot kaip ir prieš tai.

l_vidurkis funkcija
 
Pakytimu taip pat beveik nebuvo.



l_isskirstymas funkcija
 
Vienintelis pokytis ?ia buvo ciklas išvedimui.



126 eilut?
 
 
Laiko analizavimas vyko lygiai taip pat kaip ir su vektoriais, tik keliose vietose teko pakeist pavadinimus.


























