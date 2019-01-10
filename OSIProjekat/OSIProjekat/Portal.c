#include "Portal.h"
#include "FunkcijeZaIspis.h"
#include "Igrica4Komande.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>

const int bRzina = 0;


int Portal(int* glavniXP2, int najboljiR, int* oscojeniXP, int pisi){
	system("title Portal");
	
	OcistiEkran();
	Load("Portal loading...", 32);
	
	glavniXP = *glavniXP2;
	osvojeniXP = 0;
	int zivotniBodovi = 100;
	brojPomoci = 0;
	otkazi = 0;

	Pocetak(&zivotniBodovi);
	
	glavniXP += osvojeniXP;
	*glavniXP2 = glavniXP;
	*oscojeniXP = osvojeniXP;
	if (otkazi == 1) {
		return -3;
	}
	if(pisi == 1){
		IspisRezultata(najboljiR, osvojeniXP);
	}
	if(zivotniBodovi == 0){
		return 1;
	}
	
	return 0;
}

int Pocetak(int* zivotniBodovi){
	UsporeniIspisTeksta(bRzina, "Upravo se budite. Ustajete sa poda na kome ste lezali.\nPrimjecujete da se nalazite u nekakvom hodniku.\n");
	VremenskaPauza(2);
	UsporeniIspisTeksta(bRzina, "Kablovi vise sa plafona, svjetla trepere i varnice su ceste. Ne znate gdje se nalazite i kako ste uopste tu stigli.\nDa li ce te krenuti uz ili niz hodnik.\n");
	DvaIzbora("1. Uz hodnik", "2. Niz hodnik", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		osvojeniXP += 15;
		UzHodnik(zivotniBodovi);
	} else if(odgovor == 2){
		osvojeniXP += 15;
		NizHodnik(zivotniBodovi);
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		osvojeniXP = 0;
		return 0;
	} else{
		IspisGreskeONepravilnomUnosu();
		Pocetak(zivotniBodovi);
	}
	return 0;
}
int UzHodnik(int* zivotniBodovi){
	UsporeniIspisTeksta(bRzina, "Idete hodnikom.\nKako prolazite kroz hodni nailazite na grupu ljudi kako leze na podu u cudnim plavim i crvenim uniformama.\n");
	UsporeniIspisTeksta(bRzina, "Saginjete se da provjerite da li imaju puls. I sta osjecate. Nista.\nSvi su vec dugo mrtvi.\nNastavljate dalje i nailazite na vrata. Pokusavate da ih otvorite, ali vrata su zakljucana.\n");
	UsporeniIspisTeksta(bRzina, "Primjecujete na desnoj strani pored vrata panel za otvaranje. Prilazite panelu koji zahtjeva da unesete sifru kako bi ste otvorili vrata.\n");
	Kviz();
	int odgovor, izlaz = 1;
	char sifra[6] = "??????", ch[21];
	
	printf("1) Koja od navedenih planeta se najsporije rotira oko svoje ose?\n");
	CetiriIzbora("1. Mars", "2. Zemlja", "3. Venera", "4. Saturn", "HORIZONTALNO");
	odgovor = UcitajOdgovor();
	if(odgovor == 3){
		SpecijalniIspis("5");
		sifra[0] = '5';
		VremenskaPauza(3);
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		osvojeniXP = 0;
		return 0;
	}
	
	printf("2) Koja od navedenih cestica je najbrza?\n");
	CetiriIzbora("1. Tachyon", "2. Neutrino", "3. Higgs boson", "4. Quark", "HORIZONTALNO");
	odgovor = UcitajOdgovor();
	if(odgovor == 1){
		SpecijalniIspis("2");
		sifra[1] = '2';
		VremenskaPauza(3);
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		osvojeniXP = 0;
		return 0;
	}
	
	printf("3) Sta je Quasar?\n");
	CetiriIzbora("1. Zvijezda", "2. Veoma brzo rotirajuca Neutronska zvijezda", "3. Planeta", "4. Najsjajniji objekat u svemiru", "HORIZONTALNO");
	odgovor = UcitajOdgovor();
	if(odgovor == 4){
		SpecijalniIspis("8");
		sifra[2] = '8';
		VremenskaPauza(3);
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		osvojeniXP = 0;
		return 0;
	}
	
	printf("4) Koji od navedenih svemirskih brodova je najbrzi u galaksiji?\n");
	CetiriIzbora("1. U.S.S. Enterprise", "2. Millennium Falcon", "3. Battlestar Galactica", "4. BC507 Crateris", "HORIZONTALNO");
	odgovor = UcitajOdgovor();
	if(odgovor == 2){
		SpecijalniIspis("4");
		sifra[3] = '4';
		VremenskaPauza(3);
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		osvojeniXP = 0;
		return 0;
	}
	
	printf("5) Kada se kaze da je galaksija mrtva?\n");
	CetiriIzbora("1. Kada se sve zcijezde ugase", "2. Kada galaksija vise ne moze da proisvodi nove zvijezde", "3. Kada sav zivot u njoj nestane", "4. Galagsije ne mogu da umru", "VERTIKALNO");
	odgovor = UcitajOdgovor();
	if(odgovor == 2){
		SpecijalniIspis("0");
		sifra[4] = '0';
		VremenskaPauza(3);
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		osvojeniXP = 0;
		return 0;
	}
	
	printf("6) Izbaci uljeza?\n");
	CetiriIzbora("1. Vulkan", "2. Pandora", "3. Asgard", "4. Alfa", "HORIZONTALNO");
	odgovor = UcitajOdgovor();
	if(odgovor == 4){
		SpecijalniIspis("1");
		sifra[5] = '1';
		VremenskaPauza(3);
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		osvojeniXP = 0;
		return 0;
	}
	
	printf("\n? - nedostaje broj.\n");
	printf("Kod od vrata: %s\n", sifra);
	
	do{
		UsporeniIspisTeksta(bRzina, "Unesite kod: ");
		scanf_s("%s", ch, sizeof(ch));
		if(strcmp("528401", ch) == 0){
			izlaz = 0;
		} /*else if(strcmp("KRAJ", ch) == 0){ nije potrebno
			osvojeniXP = 0;
			return 0;
		} */else if(strcmp("OTKAZI", ch)){
			otkazi = 1;
			osvojeniXP = 0;
			return 0;
		} else{
			UsporeniIspisTeksta(bRzina, "Neispravan kod!\n");
			Pomoc(&brojPomoci,"Kod je 528401\n", &glavniXP, 30);
		}
	} while(izlaz == 1);
	
	UsporeniIspisTeksta(bRzina, "Vrata se otavraju i vi ulazite u prostoriju.\n");
	osvojeniXP += 15;
	Most(zivotniBodovi);
	return 0;
}
int NizHodnik(int* zivotniBodovi){
	UsporeniIspisTeksta(bRzina, "Idete hodnikom. Iznenada cujete eksploziju i citav hodnik se zatrese i vi padate na pod.\nUstajete sa poda i nastavljate dalje.\nKako idete hodnikom nailazite na nepremostivu prepreku.\n");
	UsporeniIspisTeksta(bRzina, "Hodnik se zavrsava sa provalijom. Dolazi do jos jedne eksplozije, koja zamalo da vas obori u provaliju.\nNadvijate se nad provalijom da vidite kolika je ali umjesto dna vidite plamen kako jurisa prema vama.\n");
	UsporeniIspisTeksta(bRzina, "Sta ce te da ucinite?\n");
	DvaIzbora("1. Odmaketi se od provalije i sacekati da plamen prodje", "2. Poceti trcati nazad", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		osvojeniXP -= 40;
		IspisSlike("Zastoo.txt");
		UsporeniIspisTeksta(bRzina, "Vas izbor je bio pogresan. Plamen je ispunio hodnik u kome ste se nalazili ubijajuci vas momentalno.\n");
		UkloniIgracevXP(&glavniXP);
		VremenskaPauza(5);
		OcistiEkran();
		IspisSlike("Kraj Igre.txt");
		*zivotniBodovi = 0;
		return 0;
	} else if(odgovor == 2){
		osvojeniXP += 15;
		Trci(zivotniBodovi);
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		osvojeniXP = 0;
		return 0;
	} else{
		IspisGreskeONepravilnomUnosu();
		NizHodnik(zivotniBodovi);
	}
	return 0;
}
void Kviz(){
	UsporeniIspisTeksta(bRzina, "Kako bi ste nastavili dalje morate da odgovorite na sledeca pitanja i zadatke.\nZa svaki tacan odgovor dobijate jedan podatak koji vam je potreban kako bi ste nastavili dalje.\n\n");
}
int Trci(int* zivotniBodovi){
	UsporeniIspisTeksta(bRzina, "Okrecete se i pocinjete da trcite od provalije. Okrecete glavu i vidite kako plamen izlazi iz provalije i ulazi u hodnik.\n");
	UsporeniIspisTeksta(bRzina, "Nastavljate da trcite i nailazite na raskrsnicu.\nDa li ce te skrenuti lijevo ili desno?\n");
	DvaIzbora("1. Lijevo", "2. Desno", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		osvojeniXP += 15;
		UsporeniIspisTeksta(bRzina, "Skrecete lijevo. Nastavljate da trcite i nailazite na poluotvorena klizna vrata.\nPomjerate malo vrata kako bi ste prosli, a onda ih brzo zatvarate.\n");
		UsporeniIspisTeksta(bRzina, "Na vratima se nalazi prozor kroz koji vidite kako plamen udara u vrata.\n");
		Most(zivotniBodovi);
	} else if(odgovor == 2){
		osvojeniXP -= 40;
		UsporeniIspisTeksta(bRzina, "Skrecete desno i nailazite na celicne grede koje su se srusile i blokirale hodnik.\nNema vremena da se vratite nazad. Plamen vas sustize i vi umirete.\n");
		UkloniIgrice4XP(&osvojeniXP);
		VremenskaPauza(5);
		OcistiEkran();
		IspisSlike("Kraj Igre.txt");
		*zivotniBodovi = 0;
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		osvojeniXP = 0;
		return 0;
	} else{
		IspisGreskeONepravilnomUnosu();
		Trci(zivotniBodovi);
	}
	return 0;
}
int Most(int* zivotniBodovi){
	UsporeniIspisTeksta(bRzina, "Na sredini prostorije se nalazi stolica u kojoj se nalazi neka osoba u zutoj uniformi.\nPrilazite joj i jedina stvara koju ste mogli jasno vidjeti na uniformi jeste da pise Kapetan Jam.\nTkodje u prostoriji ima jos ljudi koji leze po podu i preko konzola za kojim su sjedili.\n");
	UsporeniIspisTeksta(bRzina, "Okovas sve varnici, kablovi vire na sve strane, svuda se nalazi polomljena oprema i mnogobrojni alarmi se cuju.\nAli primjecujete da jedan od racunara idalje radi. prilazite racunaru.\n");
	UsporeniIspisTeksta(bRzina, "Na ekranu, na kome slika podrhtava, primjecujete u gornjem desnom uglu kako pise \"Stit za prozor: AKTIVAN\"\nNa konzoli ispod ekrana primjecujete crveno dugme kako trepce.\nDa li ce te pritisnuti dugme?\n");
	DaNe("HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		osvojeniXP += 15;
		UsporeniIspisTeksta(bRzina, "Na ekranu dolazi do promjene (Stit za prozor: ISKLJUCEN).\nJedan dio zida pocinje da se spusta i jaka svijetlost ulazi o prostoriju.\n");
		UsporeniIspisTeksta(bRzina, "Svijetlost obasija konzole i kapetanovo tijelo.\nDok se zid spusta vi primjecujete da na konzoli kod koje stojite nesto pise.\nRukom sklonjate krhotine i prasinu sa natpisa.\n");
		UsporeniIspisTeksta(bRzina, "Natpis je U.S.S. Enterprise.\nU tom trenutku kad ste procitali naziv zid je do kraja spusten i vi mozete da vidite sta se nalazi sa druge strane.\n");
		UsporeniIspisTeksta(bRzina, "Ispred vas se nalazi crvena nebula, ali tako primjecujete u samom cosku prozora nekakvu anomaliju.\nNeobicna crno-plava pukotina. Takodje primjecujete kako postaje sve veca i veca.\n");
		UsporeniIspisTeksta(bRzina, "Zakljucujete da ste uhvaceni u njezino gravitaciono polje i da vas vuce ka sebi.\nVidite da jedna od konzola izgjeda kao upravlacka konzola.\nDa li ce te iskoristiti konzoli?\n");
		DaNe("HORIZONTALNO");
		do{
			odgovor = UcitajOdgovor();
		} while(odgovor != 1 && odgovor != 2 && odgovor != -2 && odgovor != -3);
		if(odgovor == 1){
			osvojeniXP += 15;
			UsporeniIspisTeksta(bRzina, "Sklonjate mrtvu osobu koja je sjedila za konzolom i sjedate na njegovo mjesto.\nPocinjete da pomjerate rucice na konzoli i primjecujete da se brod okrece dalje od pukotine.\n");
			UsporeniIspisTeksta(bRzina, "Ali vase akcije postavljaju trup broda pod veliko opterecenje koje vec osteceni trup ne moze da podnese.\nBrod se pod opterecenjem raspada uz eksplozije i njegovi ostatci bivaju uvuceni u pukotinu.\n");
			VremenskaPauza(5);
			UsporeniIspisTeksta(bRzina, "Nekim cudom Most, a i vi sa njim, je prezivio raspad broda.\n");
			Pukotina(zivotniBodovi);
		} else if(odgovor == -2){
			osvojeniXP = 0;
			return 0;
		} else if(odgovor == -3){
			otkazi = 1;
			osvojeniXP = 0;
			return 0;
		} else{
			osvojeniXP -= 40;
			UsporeniIspisTeksta(bRzina, "Snazan gravitacioni talas udara brod i gura ga u pukotinu, dolazi do eksplozije brotskih motora koja poresa citav brod.\nVi padate na pod, a brod guta pukotina.\n");
			Pukotina(zivotniBodovi);
		}
	} else if(odgovor == 2){
		osvojeniXP -= 40;
		UsporeniIspisTeksta(bRzina, "Pomjerate se od koncole i primjecujete jedna otvorena vrata, prema kojim se upucujete.\nIznenada dolazi do snazne eksplozije koja vas obara na pod, a na vas pada jedna ploca sa natpisom U.S.S. Enterprise.\n");
		UsporeniIspisTeksta(bRzina, "Sklonjate plocu sa sebe i podizete se. Na jednom od monitora vidite nekakvu semu i upozorenje koje preko nje treperi (PREOPTERECENJE MOTORA).\nDolazi do jos jedne eksplozije koja otkida stit za prozor.\n");
		UsporeniIspisTeksta(bRzina, "Vi skrecete pogled prema prozoru i vidite crno-plavu pukotinu u svemiru koja privlaci brod.\nAlarmi se cuju na sve strane svuda trepere crvena svijetla i upozorenja, vi gjedate smrti u lice.\n");
		VremenskaPauza(3);
		UsporeniIspisTeksta(bRzina, "Pukotina guta brod.\n");
		VremenskaPauza(5);
		Pukotina(zivotniBodovi);
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		osvojeniXP = 0;
		return 0;
	} else{
		IspisGreskeONepravilnomUnosu();
		Most(zivotniBodovi);
	}
	return 0;
}
int Pukotina(int* zivotniBodovi){
	VremenskaPauza(5);
	UsporeniIspisTeksta(bRzina, "Nalazite se na podu, a preko vas je ispucali stakleni panel.\nIzvlacite se ispod panela. Prozora na mostu vise nema. Jaka svijetlost tuda ulazi.\nVi idete ka tom otvoru i izlazite na trup broda.\n");
	UsporeniIspisTeksta(bRzina, "Kad ste izasli van broda vidite da se nalazite u nekoj sumi.\nNiste vise u svemiru.\n");
	VremenskaPauza(4);
	IspisSlike("You dont say.txt");
	UsporeniIspisTeksta(bRzina, "\nDa li ce te ostati na brodu ili ce te napustiti brod i krenuti u nepoznatu sredinu?\n");
	DvaIzbora("1. Ostati na brodu", "2. Napustiti brod", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		osvojeniXP += 15;
		OstatiNaBrodu(zivotniBodovi);
	} else if(odgovor == 2){
		osvojeniXP += 15;
		NapustitiBrod(zivotniBodovi);
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		osvojeniXP = 0;
		return 0;
	} else{
		IspisGreskeONepravilnomUnosu();
		Pukotina(zivotniBodovi);
	}
	return 0;
}
int OstatiNaBrodu(int* zivotniBodovi){
	UsporeniIspisTeksta(bRzina, "Vracate se nazad na most broda. Provjeravate sta od opreme jos uvijek radi.\nNa vasu srecu Replikator hrane nije mnogo ostecen, tako da ce te imati dosta harne.\n");
	UsporeniIspisTeksta(bRzina, "Jos neki sporedni sistemi rade. Medjukojima je i komunikacioni sistem, ali moze samo da posanje poruku, ne moze da je primi.\nDa li ce te probati da posaljete signal za pomoc?\n");
	DaNe("HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		osvojeniXP += 15;
		UsporeniIspisTeksta(bRzina, "Prilazite komunikacionoj konzloji i saljete signal za pomoc.\n");
	} else if(odgovor == 2){
		osvojeniXP -= 40;
		UsporeniIspisTeksta(bRzina, "Ne saljete signal i gasite taj sistem kako bi ste ustedili energiju.\n");
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		osvojeniXP = 0;
		return 0;
	} else{
		IspisGreskeONepravilnomUnosu();
		OstatiNaBrodu(zivotniBodovi);
	}
	Cekanje(zivotniBodovi);
	return 0;
}
int Cekanje(int* zivotnoBodovi){
	Mjeseci();
	UsporeniIspisTeksta(bRzina, "Proslo je sest mjeseci od kad ste se srusili na ne poznatu planetu.\nIznenada cujete neku eksploziju koja dolazi sa polja. Iazlazite iz broda i u daljini vidite veliku eksploziju.\n");
	UsporeniIspisTeksta(bRzina, "Koristite primitivni elektronski uvecavajuci uredjaj, koji ste napravili od ostataka opreme sa mosta, da vidite sat se desava.\nVidite nekakve vrste letjelica kako granatiraju neko ogromno drvo u sred sume i kako ga obaraju.\n");
	UsporeniIspisTeksta(bRzina, "U tom trenutku Enterprise zahvata potres. Okrecete se prema smjeru odakle je potres dosao i primjecujete kako se suma pomjera.\n");
	UsporeniIspisTeksta(bRzina, "Iznenada se suma ispred vas spusta i vama se otvara siroki pogled.\nSta vidite jeste da suma, na koju se Enterprise srusila, se ne nalazi na povrsini planete.\n");
	UsporeniIspisTeksta(bRzina, "Nego se nalazi na lebdecim planinama i da je planina na kojoj ste vi pocela da puca na pola.\nDa li ce te sad napustiti brod?\n");
	DaNe("HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		osvojeniXP += 15;
		UsporeniIspisTeksta(bRzina, "Trcite prema satlu za spasavanje koji je prezivio pad i kojeg ste proteklih sest mjeseci popravljali.\nPokrecete satl u nadi da ce moci da leti. Napustate trup broda.\nKroz prozor vidite kako Enterprise propada izmedju dvije novoformirane lebdece planine.\n");
		UsporeniIspisTeksta(bRzina, "Letite iznad lebdecih planina i divitese cudesnoj prirodi koju je univerzum kreirao.\nSunce je pred zalaskom. Slesete na jednu od planina kako bi ste tu proveli noc.\n");
		VremenskaPauza(3);
		UsporeniIspisTeksta(bRzina, "Pred zoru vas budi neka cudna buka. Otvarate oci i vidite jednu od planina kako je na kursu da se sudari sa vama.\nBrzo pokrecete satl i za dlaku izbjegavate sigurnu smrt, posto je dolazeca planina zdrobila onu na kojo je se nalazio vas satl.\n");
		UsporeniIspisTeksta(bRzina, "Spustate se prema povrsini planete kako bi ste sletjeli, ali jaka sajzmicka aktivnost vam poremecuje plaove.\nTlo je pocela da puca, a iz pukotina izbija lava. Vulkanske eksplozije vas primoravaju da se podignete u vise slojeve atmosfere.\n");
		UsporeniIspisTeksta(bRzina, "Dok se uspinjete na horizontu primjecujete nakekvo plavo treptenje. Naleti plave plazme koji se pojavljuju i nestaju.\n");
		UsporeniIspisTeksta(bRzina, "Kako napustate atmosferu planete vidite da je preko cijele planete teku potoci lave i mnogobrojne vulkanske erupcije.\nU svom tom haosu uocavate poznati fenomen, pukotinu koja vas je progutala i dovela na ovu planetu se sad formira i nestaje uz planete i zahvaca jedan njezin dio.\n");
		UsporeniIspisTeksta(bRzina, "Udaljavate se od pukotine, ali njezina nestabilnost uzrokuje da se pojavi ispred vas i da vas ponovo proguta.\nGravitacioni uticaj pukotine na planetu, dovodi do njezinog pucanja na pola i na kraju eksplozije.\n");
		Pukotina2(zivotnoBodovi);
	} else if(odgovor == 2){
		osvojeniXP -= 40;
		UsporeniIspisTeksta(bRzina, "Zasto bi ste ponovo ostali na brodu.\n");
		VremenskaPauza(3);
		IspisSlike("Zastoo.txt");
		UsporeniIspisTeksta(bRzina, "Planina na kojoj se vi nalazite se prepolovila i Enterprise propada, a vi sa njom.\nPri padu vi zavrsavate ispod Enterprise i ona pada na vas.\nUpravo vas je Enterprise zdrobila. Mrtvi ste.\n");
		VremenskaPauza(7);
		OcistiEkran();
		UkloniIgracevXP(&glavniXP);
		IspisSlike("Kraj Igre.txt");
		*zivotnoBodovi = 0;
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		osvojeniXP = 0;
		return 0;
	} else{
		IspisGreskeONepravilnomUnosu();
		Cekanje(zivotnoBodovi);
	}
	return 0;
}
int NapustitiBrod(int* zivotniBodovi){
	UsporeniIspisTeksta(bRzina, "Spustate se niz trup broda i silazite na sumsko tlo. Krecete da se probijate kroz sumu.\nDolazite do ivice sume i vidite da vi niste ustvari na povrsini planete.\n");
	UsporeniIspisTeksta(bRzina, "Vi se nalazite na jednoj od mnogih lebdecih planina. Taj prizor vas zadivljuje.\nAli znate da ne mozete tu ostati, pa pocinjete da trazite nacin kako da se spustite na tlo.\n");
	UsporeniIspisTeksta(bRzina, "Idete uz ivicu planine u potrazi za nacinom da se spustite.\n");
	Odluke(zivotniBodovi);
	return 0;
}
int Odluke(int* zivotniBodovi){
	UsporeniIspisTeksta(bRzina, "Nailazite na grupu lijana koje se spustaju skroz do tla.\nDa li ce te iskoristiti lijane da se spustite?\n");
	DaNe("HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		Lijane(zivotniBodovi);
	} else if(odgovor == 2){
		UsporeniIspisTeksta(bRzina, "Prolazite pored lijana i nastavljate dalje svoju potragu.\nNakon nekog vremena nailazite na grupu bliskih lebdecih planina.\nUocavate da planine formiraju stepenice prema tlu.\nDa li ce te se tuda spustiti?\n");
		DaNe("HORIZONTALNO");
		odgovor = 0;
		do{
			odgovor = UcitajOdgovor();
			if(odgovor == 1){
				Stepenice(zivotniBodovi);
			} else if(odgovor == 2){
				UsporeniIspisTeksta(bRzina, "Nastavlate dalje.\n");
				Odluke(zivotniBodovi);
			} else if(odgovor == -2){
				osvojeniXP = 0;
				return 0;
			} else if(odgovor == -3){
				otkazi = 1;
				osvojeniXP = 0;
				return 0;
			}
		} while(odgovor != 1 && odgovor != 2 && odgovor != -2 && odgovor != -3);
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		osvojeniXP = 0;
		return 0;
	} else{
		IspisGreskeONepravilnomUnosu();
		NapustitiBrod(zivotniBodovi);
	}
	return 0;
}
int Lijane(int* zivotniBodovi){
	UsporeniIspisTeksta(bRzina, "Pomocu lijana se spustate do tla i nastavljate dalje.\n");
	osvojeniXP += 15;
	Tlo(zivotniBodovi);
	return 0;
}
int Stepenice(int* zivotniBodovi){
	UsporeniIspisTeksta(bRzina, "Pravite zalet i skacete na na planinu koja se nalazila ispod vas.\nSada ponovo skacete na narednu planinu i na narednu i tako dalje dok god se niste spustili do tla.\n");
	osvojeniXP += 15;
	Tlo(zivotniBodovi);
	return 0;
}
int Tlo(int* zivotniBodovi){
	UsporeniIspisTeksta(bRzina, "Ulazite u tamnu sumu ogromnih stabala, nakon nekoliko sati hoda pada noc. Vi trazite materijal za vatru, ali dok tragate za stvarima sto vam trebaju nesto cudesno se desava.\n");
	UsporeniIspisTeksta(bRzina, "Citava suma pocinje da svijetli. Prizor neopisive ljepote vas ocarava.\nSvaka bilka u sumi nevjerovatnu svjetlost razlicitih boja.\nOdlucujete tu da provedete noc i da ujutro nastavite dalje.\n");
	Mjeseci();
	UsporeniIspisTeksta(bRzina, "Proslo je sest mjeseci od kad ste se srusili na planetu.\nUpoznati ste sa dinamikom zivog svijeta u vasem okruzelju,\njos uvijek niste naisli na inteligentne oblike zivota.\n");
	UsporeniIspisTeksta(bRzina, "Ali ste zato upravo naisli na jedan od satlova sa Enterprise. Izgleda kao da je u dobrom stanju.\nDa li ce te pokusati da ga popravite, ili cete samo sa njga uzeti opremu sto vam treba i nastaviti dalje?\n");
	VremenskaPauza(4);
	IspisSlike("Nisam Siguran.txt");
	DvaIzbora("1. Pokusati popraviti satl", "2. Samo pokupiti neke zalihe", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		osvojeniXP += 15;
		UsporeniIspisTeksta(bRzina, "Ostajete kod satla i zapociljete opravke. Odma promjecujete da satl nije toliko mnogo ostecen\ni da vecina sistema radi i da ce te ga moci veoma brzo popraviti.\n");
		VremenskaPauza(2);
		UsporeniIspisTeksta(bRzina, "Dvije sedmice kasnije buka vas budi. Usatjete i izlazite iz satla.\nIznad vas prolecu nekakve vrse letjelica. Vracate se u satl i pocinjete da se spremate da idete za njima.\n");
		UsporeniIspisTeksta(bRzina, "Iznenada se zacuse snazne eksplozije. Par sekundi kasnije doslo je do velikog potresa.\nDa li ce te idalje krenuti za letjelicama?\n");
		DaNe("HORIZONTALNO");
		do{
			odgovor = UcitajOdgovor();
			if(odgovor == 1){
				osvojeniXP -= 40;
				Prati();
				*zivotniBodovi = 0;
			} else if(odgovor == 2){
				osvojeniXP += 15;
				UsporeniIspisTeksta(bRzina, "Vracate se u satl i pocinjete pripreme za test sistema.\n");
				VremenskaPauza(2);
				UsporeniIspisTeksta(bRzina, "Zapocijete test sistema. Za sad sve ide kako treba. Svi sistemi su ispravni.\nOdlucujete da sutra ujutro napustite ovu planetu.\n");
				VremenskaPauza(4);
				UsporeniIspisTeksta(bRzina, "Bude vas snazni potresi. Izlazite iz satla da vidite sta se desava.\nOkomas drvece pada, zemlja pocinje da se cepa. Odmah se vracate u satl i palite motore.\n");
				UsporeniIspisTeksta(bRzina, "Uzlecete. Probijate se kroz padajuce drvece i podizete se iznad sume.\nSpustate pogled prema tlu i vidite kako tlo puca i kako iz pukotina izbija lava.\nVulkanske eksplozije vas primoravaju da se podignete u vise slojeve atmosfere.\n");
				UsporeniIspisTeksta(bRzina, "Dok se uspinjete na horizontu primjecujete nakekvo plavo treptenje. Naleti plave plazme koji se pojavljuju i nestaju.\n");
				UsporeniIspisTeksta(bRzina, "Kako napustate atmosferu planete vidite da je preko cijele planete teku potoci lave i mnogobrojne vulkanske erupcije.\nU svom tom haosu uocavate poznati fenomen, pukotinu koja vas je progutala i dovela na ovu planetu se sad formira i nestaje uz planete i zahvaca jedan njezin dio.\n");
				UsporeniIspisTeksta(bRzina, "Udaljavate se od pukotine, ali njezina nestabilnost uzrokuje da se pojavi ispred vas i da vas ponovo proguta.\nGravitacioni uticaj pukotine na planetu, dovodi do njezinog pucanja na pola i na kraju eksplozije.\n");
				Pukotina2(zivotniBodovi);
			} else if(odgovor == -2){
				osvojeniXP = 0;
				return 0;
			} else if(odgovor == -3){
				otkazi = 1;
				osvojeniXP = 0;
				return 0;
			}
		} while(odgovor != 1 && odgovor != 2 && odgovor != -2 && odgovor != -3);
	} else if(odgovor == 2){
		osvojeniXP -= 40;
		UsporeniIspisTeksta(bRzina, "Ulazite u satl, uzimate par stvari iz njega za koje smatrate da ce vam biti od koristi i nastavljate dalje.\n");
		VremenskaPauza(2);
		UsporeniIspisTeksta(bRzina, "Dvije sedmice kasnije buka vas budi.\nIznad vas prolecu nekakve vrse letjelica. Ustajete i krecete za letjelicama.\n");
		UsporeniIspisTeksta(bRzina, "Iznenada se zacuse snazne eksplozije. Par sekundi kasnije doslo je do velikog potresa.\nDa li ce te idalje ici za letjelicama?\n");
		DaNe("HORIZONTALNO");
		do{
			odgovor = UcitajOdgovor();
			if(odgovor == 1){
				osvojeniXP -= 40;
				Prati();
				*zivotniBodovi = 0;
			} else if(odgovor == 2){
				osvojeniXP += 15;
				UsporeniIspisTeksta(bRzina, "Nastavljate dalje prvobitnim putem kojim ste isli.\n");
				VremenskaPauza(3);
				UsporeniIspisTeksta(bRzina, "Pada noc. Odlucujete da ce te ujutro nastaviti put.\n");
				Lava();
				*zivotniBodovi = 0;
			} else if(odgovor == -2){
				osvojeniXP = 0;
				return 0;
			} else if(odgovor == -3){
				otkazi = 1;
				osvojeniXP = 0;
				return 0;
			}
		} while(odgovor != 1 && odgovor != 2 && odgovor != -2 && odgovor != -3);
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		osvojeniXP = 0;
		return 0;
	} else{
		IspisGreskeONepravilnomUnosu();
		Tlo(zivotniBodovi);
	}
	return 0;
}
void Mjeseci(){
	printf("1\n");
	VremenskaPauza(3);
	printf("2\n");
	VremenskaPauza(3);
	printf("3\n");
	VremenskaPauza(3);
	printf("4\n");
	VremenskaPauza(3);
	printf("5\n");
	VremenskaPauza(3);
	printf("6\n");
	VremenskaPauza(3);
}
void Lava(){
	UsporeniIspisTeksta(bRzina, "Snazni potresi vas bude. Ustajete i vidite da drvece oko vas pada, zemlja puca, a iz pukotina izbija lava.\nUzimate stvari i pocinjete da bjezite.\nAli kuda bi ste vi to mogli pobjeci.\n");
	UsporeniIspisTeksta(bRzina, "Oko vas je svuda lava. Vi nemate kuda da idete. Trebali ste ostati uz satl.\nVeliko dvo krece da pada ka vama. Bjezite u stranu kako vas drvo nebi zdrobilo,\n ali tlo pod nogama vam bukvalno nestaje i vi upadate u lavu.\n");
	VremenskaPauza(7);
	OcistiEkran();
	UkloniIgrice4XP(&osvojeniXP);
	IspisSlike("Kraj Igre.txt");
}
void Prati(){
	UsporeniIspisTeksta(bRzina, "Nastavlate ka mjestu kuda su letjelice otisle.\n");
	VremenskaPauza(3);
	UsporeniIspisTeksta(bRzina, "Pada noc. Odlucujete da ce te ujutro nastaviti put.\n");
	Lava();
}
int Pukotina2(int* zivotniBodovi){
	VremenskaPauza(10);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    // Cuva trenutnu boji teksta u konzoli
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    
	MatriksEfekat();
	VremenskaPauza(3);
    Sletanje(zivotniBodovi);
    
    SetConsoleTextAttribute(hConsole, saved_attributes);
    return 0;
}
void MatriksEfekat(){
	
	OcistiEkran();
	int width = 170,height = 43;
	srand((unsigned int) time(NULL));
	system("color A");
	COORD coord = {0, 0};
	char matrix[43][170] = {0}, matrix2[43][170] = {0};
	int giris[170] = {0}, uzunluk[170] = {0}, mevcut[170] = {0}, yaz[170] = {0}, x, i, rast, test, dolu[170] = {0};
	
	for(x = 0; x < width; x++){
		giris[x] = rand() % 30;
		uzunluk[x] = rand() % 30 + 15;
		mevcut[x] = giris[x];
		if(rand() % 2 == 1){
			yaz[x] = 1;
		}
	}
	for(i = 0; i < height; i++){
		for(x = 0; x < width; x++){
			matrix[i][x] = rand() % 94 + 34;
		}
	}
	clock_t vrijeme = 60000 + clock();
	while(vrijeme > clock()){
		for(x = 0; x < width; x++){
			if(yaz[x] == 1){
				coord.X = x; 
				coord.Y = mevcut[x];
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
				if(dolu[x] == 0){
					if(mevcut[x] < height){
						SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
						printf("%c",matrix[mevcut[x]][x]);
						matrix2[mevcut[x]][x] = 1;
					}
					if(matrix2[mevcut[x] - 1][x] == 1){
						SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN|FOREGROUND_INTENSITY);
						coord.X = x; 
						coord.Y = mevcut[x] - 1;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
						printf("%c",matrix[mevcut[x] - 1][x]);
					}
					if(matrix2[mevcut[x] - 5][x] == 1){
							SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
							coord.X = x; 
							coord.Y = mevcut[x] - 5;
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
							printf("%c",matrix[mevcut[x] - 5][x]);
						}
					for(i = 1; i < 5; i++){
						if(matrix2[mevcut[x] - i * 10][x] == 1){
							SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
							coord.X = x; 
							coord.Y = mevcut[x] - i * 10;
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
							printf("%c",matrix[mevcut[x] - i * 10][x]);
						}
					}
					if(mevcut[x] + 1 <= giris[x] + uzunluk[x]){
						mevcut[x]++;
					}else{
						mevcut[x] = giris[x] - 1;
						dolu[x] = 1;
					}
				}else{
					if(mevcut[x] < height){
						printf(" ");
						matrix2[mevcut[x]][x] = 0;
					}
					if(mevcut[x] + 1 <= giris[x] + uzunluk[x]){
						mevcut[x]++;
					}else{
						mevcut[x] = giris[x] - 1;
						dolu[x] = 0;
						yaz[x] = 0;
						test = 1;
						rast = rand() % width;
						while(test){
							if(yaz[rast] == 0){
								yaz[rast] = 1;
								giris[x] = rand() % 30;
								uzunluk[x] = rand() % 30 + 15;
								mevcut[x] = giris[x];
								test = 0;
							}else{
								rast = rand() % width;
							}
						}
					}
				}
			}
		}
		for(i = 0; i < height; i++){
			for(x = 0; x < width; x++){
				if(rand() % 15 == 1){
					matrix[i][x] = rand() % 94 + 34;
				}
			}
		}
		Sleep(15);
	}
	OcistiEkran();
}
int Sletanje(int* zivotniBodovi){
	UsporeniIspisTeksta(bRzina, "Izlazite na drugu stranu pukotine. Svi sistemi vam otkazuju, gubite kontrolu nad satlom,\nuopste ne vidite kuda idete. Iznenada udarate u nesto i prestajete da se krecete.\n");
    UsporeniIspisTeksta(bRzina, "Izlazite iz satla oko vas vidite drvece, pomisljate da ste opet u sumi.\nOkrecete se i zakljucujete da niste u sumi, jer se iza vas nalaze zgrade.\nShvatate da se nalazite u nekakvom gradu i da tu sigurno postoji neko ko vam moze pomoci.\nTakodje zapazate da jedna od zgrada ima rupu u sebi, vi se prisjecate da ste pri sletanju udarili u nesto.\n");
    UsporeniIspisTeksta(bRzina, "Krecete prema zgradama. Prolazite kroz ulicu i susrecete razne prolaznike.\nDa li ce te pitati nekog za pomoc?\n");
    DaNe("HORIZONTALNO");
    int odgovor = UcitajOdgovor(), uslov;
    if(odgovor == 1){
    	PitatiProlaznika();
    	Dalje(zivotniBodovi);
	} else if(odgovor == 2){
		uslov = NastavljateDalje();
		if(uslov == 1){
			Dalje(zivotniBodovi);
		}
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		osvojeniXP = 0;
		return 0;
	} else{
		IspisGreskeONepravilnomUnosu();
		Sletanje(zivotniBodovi);
	}
	return 0;
}
void PitatiProlaznika(){
	osvojeniXP += 15;
	UsporeniIspisTeksta(bRzina, "Obracate se jednom od prolaznika za pomoc, ali vas ignorise.\nPitate narednog prolaznika za pomoc, ali vas i taj prolaznik ignorise.\nPocinjete da trcite ulicom i zauatavljate ljude, ali za njih vi kao i da ne postojite.\n");
	UsporeniIspisTeksta(bRzina, "Tako trceci izlazite na put kamion. Ali umjesto da vas ubije, kamion samo prolazi kroz vas.\nPocinjete da se pitate sta se to okovas desava i gdje se vi zaista nalazite.\n");
	UsporeniIspisTeksta(bRzina, "Primjecujete sa druge strane ulice neku osobu kako gleda u vas.\nKrecete prema toj osobi, ali ispred vas prolazi autobus i kad je autobus prosao ta osoba se vise tamo nije nalazila.\n");
}
int NastavljateDalje(){
	UsporeniIspisTeksta(bRzina, "Prolazite kraj jos par prolaznika. Da li ce te sad pitati nekoga za pomoc?\n");
	DaNe("HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		PitatiProlaznika();
		return 1;
	} else if(odgovor == 2){
		NastavljateDalje();
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		osvojeniXP = 0;
		return 0;
	} else{
		IspisGreskeONepravilnomUnosu();
		NastavljateDalje();
	}
	return 0;
}
int Dalje(int* zivotniBodovi){
	UsporeniIspisTeksta(bRzina, "Prelazite na drugu stranu ulice i pocinjete da trazite kuda je ta osoba mogla nestati.\nProlazite par ulica ali niste nikoga nasli.\nIznenada pored vas projuri par automobila koje prate drugi automobili.\n");
	UsporeniIspisTeksta(bRzina, "Pocinje pucnjava i jedan od automobila naglo skrece prema vama.\nDa li ce te se pomjeriti i izbjeci automobil koji juri prema vama?\n");
	DaNe("HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		osvojeniXP += 15;
		UsporeniIspisTeksta(bRzina, "Bacate se u stranu kako bi ste izbjegli automobil.\nAutomobil udara u izlog zgrade i eksplodira.\n");
		UsporeniIspisTeksta(bRzina, "Primjecujete da osoba koja stoji pored vas pocinje da pravi cudne pokrete glavom i kako postaje sasvim druga osoba.\nTa osoba nakratko baca pogled na vas i  sjeda u obliznji automobil i nastavlja potjeru.\n");
		UsporeniIspisTeksta(bRzina, "Vidite da se niz ulicu desavaju eksplozije. Odlucujete da odete u sporednu ulicu.\nPri izlasku iz sporedne ulice sudarate se sa osobom koju ste maloprije vidjeli kako se odvezla automobilom.\nPri sudaru primjecujete da mu na sakou pise Agent Smith.\n");
		AgentSmit(zivotniBodovi);
	} else if(odgovor == 2){
		osvojeniXP -= 40;
		UsporeniIspisTeksta(bRzina, "Ako ste mislili da ce automobil proci kroz vas kao kamion, bogme ste se dobro prevarili.\nAutomobil nije prosao kroz vas, nego vas je udario.\nOd siline udarca odmah umirete.\n");
		UkloniIgracevXP(&glavniXP);
		VremenskaPauza(5);
		OcistiEkran();
		IspisSlike("Kraj Igre.txt");
		*zivotniBodovi = 0;
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		osvojeniXP = 0;
		return 0;
	} else{
		IspisGreskeONepravilnomUnosu();
		Dalje(zivotniBodovi);
	}
	return 0;
}
int AgentSmit(int* zivotniBodovi){
	UsporeniIspisTeksta(bRzina, "Agent Smith: Vi nebiste smjeli biti ovdje. Ko ste vi?\n");
	UsporeniIspisTeksta(bRzina, "Vi mu odgovarate: Ko sam ja! Ko ste vi?\n");
	UsporeniIspisTeksta(bRzina, "Agent Smith: Moje ime je Agent Smith. Kako ste dospjeli ovdje? Vi biste trebali poci samnom.\n\nDa li ce te poci sa Agentom Smith-om?\n");
	DaNe("HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		osvojeniXP -= 40;
		UsporeniIspisTeksta(bRzina, "Niste trebali poci sa Agentom Smith-om. Agent Smith vas teleportuje negdje.\n");
		Zatvor();
		*zivotniBodovi = 0;
	} else if(odgovor == 2){
		osvojeniXP += 15;
		UsporeniIspisTeksta(bRzina, "Pocinjete da bjezite u suprotnom smjeru. Agent Smith trci za vama.\nPri trcanju saplicete se od ciglu i krecete da padate prema zidu,\nali ne udarate u zid vec prolazite kroz njega.\n");
		ZidProlaz(zivotniBodovi);
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		osvojeniXP = 0;
		return 0;
	} else{
		IspisGreskeONepravilnomUnosu();
		AgentSmit(zivotniBodovi);
	}
	return 0;
}
int ZidProlaz(int* zivotniBodovi){
	UsporeniIspisTeksta(bRzina, "Izlazite na drugu stranu. Nalazite se na pustoj ulici i pocije snazna kisa da pada.\nCujete neku buku niz ulicu. Pogledate i vidite armiju Agenata Smith kako trce prema vama.\n");
	UsporeniIspisTeksta(bRzina, "Da li ce te se skloniti sa ulice?\n");
	DaNe("HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		osvojeniXP += 15;
		UsporeniIspisTeksta(bRzina, "Bjezite u obliznju zgradu. Dok gledate Agente kako prolaze primjecujete\nda se iznad jedne zgrade pojavljuje i nestaje plava plazma.\nOdma shvatate da se to ponovo formira pukotina i da morate sto prije sitici tamao.\n");
		UsporeniIspisTeksta(bRzina, "Ali postoji jedan problem. Armija Agenata je otisla u tom smijeru.\nAli vi morate pod svaku cijenu stici do pukotine.\n");
		VremenskaPauza(2);
		IspisSlike("Challenge.txt");
		UsporeniIspisTeksta(bRzina, "Pa bez obzira sto se tamo uputila armija Agenata, vi krecete.\n ");
		VremenskaPauza(3);
		UsporeniIspisTeksta(bRzina, "Trcite prema pukotini koja postaje sve nestabilnija.\n");
		VremenskaPauza(2);
		UsporeniIspisTeksta(bRzina, "Nailazite na grupu agenata. Oni pocinju da jure za vama.\nVi krecete da bjezite u kontra smijeru, ali opet dolazi slucajnog teleportovanja,\nstim da su sad zajedno sa vama premjesteni i Agenti.\n");
		UsporeniIspisTeksta(bRzina, "Nalazite se u poslovnoj zgradi. Zgrada sa pukotinom se nalazi preko puta.\nKrecete da bjezite od agenata prema stepenicama i niz njh, kako bi ste izasli iz zgrade.\n");
		VremenskaPauza(3);
		UsporeniIspisTeksta(bRzina, "Iznenada dolazi do snaznog potresa i do pucanja svih prozora na zgradi.\nPotres vas izbacuje sa stepenista u kancelerije. Agenti vas sutizu.\n");
		SkokProzor(zivotniBodovi);
	} else if(odgovor == 2){
		osvojeniXP -= 40;
		IspisSlike("Grumpy Cat.txt");
		VremenskaPauza(3);
		UsporeniIspisTeksta(bRzina, "Vidio sam mnoge vrse gluposti, ali ovo, ovo je posebna vrsta gluposti.\nStampedo Agenata koji zele da vas ubiju trce prema vama i vi odlucite da ne bjezite.\n");
		UsporeniIspisTeksta(bRzina, "Prosto nemam rijeci. Ali sta ja tu mogu to je bio vas izbor.\nArmija Agenata Smith vas je bukvalno pregazila.\nCestitam upravo ste umrli.\n");
		VremenskaPauza(5);
		UkloniIgrice4XP(&osvojeniXP);
		MatriksEfekat();
		OcistiEkran();
		IspisSlike("Kraj Igre.txt");
		*zivotniBodovi = 0;
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		osvojeniXP = 0;
		return 0;
	} else{
		IspisGreskeONepravilnomUnosu();
		ZidProlaz(zivotniBodovi);
	}
	return 0;
}
void Zatvor(){
	UsporeniIspisTeksta(bRzina, "Zavrsili ste u nekakvoj bijeloj prostoriji bez vrata i prozora. Prosto nista se ne nalazi u njoj sem vas.\nPokusavate naci izlaz ali u kom god smjeru da krenete nikad ne stizete do zida.\n");
	UsporeniIspisTeksta(bRzina, "Pocinjete da trcite, ali se idalje nista ne mjenja, vi nestizete nikuda.\n");
	MaliMartiks(1000);
	OcistiEkran();
	UsporeniIspisTeksta(bRzina, "Samo malo nesto se desava.\n");
	VremenskaPauza(3);
	MaliMartiks(1000);
	OcistiEkran();
	UsporeniIspisTeksta(bRzina, "Jeste li primjetili to.\n");
	VremenskaPauza(3);
	MaliMartiks(2000);
	OcistiEkran();
	UsporeniIspisTeksta(bRzina, "Da to.\n");
	VremenskaPauza(3);
	MaliMartiks(3000);
	OcistiEkran();
	UsporeniIspisTeksta(bRzina, "Postaje sve ucestalnije.\n");
	VremenskaPauza(3);
	MaliMartiks(2500);
	OcistiEkran();
	UsporeniIspisTeksta(bRzina, "I ucestalnije.\n");
	VremenskaPauza(3);
	MaliMartiks(2000);
	OcistiEkran();
	UsporeniIspisTeksta(bRzina, "I ucestalnije.\n");
	VremenskaPauza(3);
	MaliMartiks(1500);
	OcistiEkran();
	UsporeniIspisTeksta(bRzina, "Nesto se desava.\n");
	VremenskaPauza(3);
	MaliMartiks(1000);
	OcistiEkran();
	VremenskaPauza(1);
	MaliMartiks(1000);
	OcistiEkran();
	VremenskaPauza(1);
	MaliMartiks(1000);
	OcistiEkran();
	VremenskaPauza(1);
	MaliMartiks(3000);
	OcistiEkran();
	UsporeniIspisTeksta(bRzina, "Izgleda kao da se ovaj svijet urusava.\n");
	VremenskaPauza(3);
	MaliMartiks(1000);
	OcistiEkran();
	VremenskaPauza(1);
	MaliMartiks(1000);
	OcistiEkran();
	VremenskaPauza(1);
	MaliMartiks(1000);
	OcistiEkran();
	UsporeniIspisTeksta(bRzina, "Bojim se da je ovo vas kraj.\n");
	VremenskaPauza(3);
	MaliMartiks(1000);
	OcistiEkran();
	VremenskaPauza(1);
	MaliMartiks(1000);
	OcistiEkran();
	VremenskaPauza(1);
	MaliMartiks(1000);
	OcistiEkran();
	VremenskaPauza(4);
	MatriksEfekat();
	OcistiEkran();
	UkloniIgrice4XP(&osvojeniXP);
	IspisSlike("Kraj Igre.txt");
}
void MaliMartiks(int milisekunde){
	
	int de;
	clock_t vrijeme = milisekunde + clock();
	
	while(vrijeme > clock()){
		/* Nasumicni izbor karaktera */
		char cb = 'a' + rand() % (('z'-'a') + 1);
		char c = 'a' + rand() % (('z'-'a') + 1);
		de = rand() % 26;
		printf("\t%c", de );
		printf("\t\t%c", cb );
		printf("\t\t\t%c", c);
		printf("\t\t\t\t%c", cb );
		printf("\t\t\t\t\t%c", c );
		printf("\t\t\t\t\t\t%c", cb );
		printf("\t\t\t\t\t\t\t%c", c );
	}
}
int SkokProzor(int* zivotniBodovi){
	UsporeniIspisTeksta(bRzina, "Da li ce te nastaviti da se spustate ili cete probati nesto drugo?\n");
	DaNe("HORIZONTALNO");
    int odgovor = UcitajOdgovor();
    if(odgovor == 1){
    	osvojeniXP += 15;
    	UsporeniIspisTeksta(bRzina, "Nastavljate dalje da se spustate niz stepenice.\nSisli ste do prizemla, krecete ka vratima, agenti su odma iza vas.\nAli taman kad ste stigli do vrata snazan udarni talas vas baca nazad.\nNakon toga zgrada iznad koje se nalazi pukotina pocije da se urusava.\n");
    	UsporeniIspisTeksta(bRzina, "Sklonjate se od ulaza i trazite zaklon.\n");
    	VremenskaPauza(3);
    	UsporeniIspisTeksta(bRzina, "Zgrada pada.\n");
    	VremenskaPauza(2);
    	UsporeniIspisTeksta(bRzina, "Svaka sansa o stizanju do pukotine je nestala.\nSklonjate se od rusevina i vracate se u mirniji dio grada.\nAli dok ste se vracali nazad prolazite kroz jedan park.\n");
    	UsporeniIspisTeksta(bRzina, "Podizete glavu i vidite u daljini zgradu sa rupom u sebi.\nOdmah se sjetite da ste vi udarili u tu zgradu, sto znaci da je satl tu negdje.\nPocinjete da ga trazite.\n");
    	VremenskaPauza(2);
    	UsporeniIspisTeksta(bRzina, "Pronalazite satl. Ulazite u njega.\nNekim cudom satl se uspjesno startuje i vi uzlecete.\nKrecete prema pukotini. U zadnji cas prolazite kroz pukotinu.\n");
    	VremenskaPauza(5);
    	OcistiEkran();
    	MatriksEfekat();
    	NePonovo();
	} else if(odgovor == 2){
		osvojeniXP -= 40;
		UsporeniIspisTeksta(bRzina, "Agenti ulaze u kncelarije. Sad vam je ostao samo jedan izlaz.\n");
		VremenskaPauza(3);
		UsporeniIspisTeksta(bRzina, "Okrecetese i pocinjete da trcite prema prozoru. Trcite i onda skacete kroz prozor.\nNekim cudom se hvatate za kran koji se tu nalazio.\nKoji vas tacno prebacuje do zgrade iznad koje se nalazi pukotina.\n");
		UsporeniIspisTeksta(bRzina, "Krecete da se penjete prema krovu zgrade.\nPredzadnjem spratu dolazi do snaznog potreza koji vas obara.\nPodizete se i nastavljate pu dok se zgrada nestabilno njise.\n");
		UsporeniIspisTeksta(bRzina, "Taman kad ste izasli na krov zgrade, zgrada pocinje da pad.\nKrecete da trcite prema pukotini dok se krov iza vas utusava.\nCitav krov pocinje da se spusta. Vi skacete.\nNa srecu gravitacija pukotine vas hvata i pocinje da vas privlaci.\n");
		UsporeniIspisTeksta(bRzina, "Kako prilazite pukotini gledate zgradu kako se urusava i nestaje u oblaku prasine.\nUlazite u pukotinu.\n");
		VremenskaPauza(7);
		OcistiEkran();
		MatriksEfekat();
		NePonovo();
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		osvojeniXP = 0;
		return 0;
	} else{
		IspisGreskeONepravilnomUnosu();
		SkokProzor(zivotniBodovi);
	}
	*zivotniBodovi = 0;
	return 0;
}
void NePonovo(){
	
	OcistiEkran();
	system("cls");
	system("COLOR F2");
	VremenskaPauza(7);
	system("cls");
	system("COLOR 07");
	UsporeniIspisTeksta(bRzina, "Budite se u fotelji. Ustajete i shvatate da ste se vartili svojoj kuci, zavrsilo se.\nPomisljate da je sve to bio samo jedan veoma cudan san i nastavljate dalje sa svojim zivotom.\n");
	VremenskaPauza(3);
	UsporeniIspisTeksta(bRzina, "Par dana kasnije cujete neku buku napolju. Dolazite do ulaznih vrata i otvarate ih.\nAli sa vidite ostavlja vas u soku.\n");
	VremenskaPauza(2);
	UsporeniIspisTeksta(bRzina, "Na nebu iznad vaseg komsiluka se formira pukotina.\n");
	IspisSlike("Ne ponovo.txt");
	VremenskaPauza(10);
	osvojeniXP += 100;
	OcistiEkran();
}
