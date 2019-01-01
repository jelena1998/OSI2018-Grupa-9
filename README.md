# OSI2018-Grupa-9
Platforma za igre



Napraviti aplikaciju koja omogućava igranje jednostavnih konzolnih igara. Sve igre koje aplikacija podržava instaliraju se odjednom na klijentski računar, ali su podrazumijevano zaključane. Da bi korisnik mogao da igra određenu igru treba da unese odgovarajući ključ, koji je predstavljen nizom od 16 brojeva pri čemu su grupe po 4 broja odvojena znakom minus. Ključevi mogu imati ograničeno trajanje: 1 sat, 1 dan, 7 dana, a mogu imati i neograničeno trajanje. Svaka igra u svom instalacionom podešavanju definiše vrstu ključa. Korisnik može u bilo kom trenutku da otkaže igru, nakon čega se ona više ne može igrati. Nakon isteka ključa, korisnik više ne može aktivirati igru bez novog instaliranja aplikacije, pri čemu se dobija novi ključ.

Nakon prvog pokretanja igre, korisnik unosi svoje ime, a pri svakom sljedećem pokretanju aplikacija ispisuje poruku „Pozdrav IME“, nakon čega se prikazuju opcije za igranje i pregled statistike. Statistika predstavlja prikaz 10 rezultata sortiranih u opadajućem redoslijedu za svaku igru posebno. Prikazuju se datum igranja i broj bodova. Potrebno je napraviti opciju kojoj korisnik može sačuvati svoje rezultate u CSV fajl.

Aplikacija treba da ima najmanje 4 igre, od čega su tri igre iste u svim implementacijama, a njihovi ključevi imaju ograničeno trajanje. Četvrtu igru definiše svaki tim za sebe i ključ te igre ima neograničeno trajanje.

Prva igra je igra pogađanja zamišljenog broja u intervalu od 0 do 100. Aplikacija će prvo na slučajan način izabrati određeni broj, a korisnik ima 5 pokušaja da ga pogodi tako što unosi broj, a aplikacija mu prikazuje poruku „Broj koji tražite je [veći | manji] od unesenog broja”.  Ako korisnik pogodi traženi broj dobija 100/broj_pokušaja bodova za svoj profil.

Druga igra je kviz. Korisniku se prikazuje 5 slučajno odabranih pitanja iz liste koja ima najmanje 15 pitanja. Uz svako pitanje korisniku se prikazuju 3 moguća odgovora, nakon čega korisnik unosi broj odgovora za koji smatra da je tačan. Ako je odgovor tačan, korisnik će dobiti 20 bodova. Ako korisnik odgovori tačno na sva pitanja dobija još 50 bodova bonusa. Svaki pogrešan odgovor korisniku uzima 30 bodova.

Treća igra je loto. Korisnik unosi 7 različitih brojeva u opsegu od 1 do 45 nakon čega počinje proces izvlačenja dobitnih brojeva. Računar na slučajan način bira 20 brojeva. Za svaki pogođeni broj korisnik dobija (redni_broj_pogotka)*10 bodova (ako ima svih 7 pogodaka dobiće 10+20+30+40+50+60+70 bodova). Cijena igranja je 100 bodova.

Kada prvi put pokrene aplikaciju, korisnik treba da ima 10 početnih bodova. Samo prva igra nema negativne poene. Korisnik može imati negativan broj bodova na profilu. Aplikacija ne smije omogućiti korisniku da stalno pobjeđuje. Zbog toga što na početku ima dostupnu samo prvu igru, omogućiti da korisnik prva 3 put pobijedi. Nakon toga u prvoj i trećoj igri korisnik ne smije dobiti više bodova nego što je uložio. Aplikacija treba da radi tako da je minimalan broj izgubljenih bodova za 40% veći od dobijenih.
