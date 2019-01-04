#include "GameOfThrons.h"
#include "FunkcijeZaIspis.h"
#include "Igrica4Komande.h"
#include <stdio.h>

int GOTPohod(int* glavniXP2){
	system("title Game Of Throns");
	
	OcistiEkran();
	Load("GOT loading...", 34);
	
	glavniXP = *glavniXP2;
	int zivotniBodovi = 100;
	Gavran(&zivotniBodovi);
	osvojeniXP += (zivotniBodovi / 7);
	if(glavniXP > 0){
		glavniXP += osvojeniXP;
	}
	*glavniXP2 = glavniXP;
	if(zivotniBodovi == 0){
		return 1;
	}
	
	return 0;
}

int Gavran(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Stigao je gavran sa porukom. Da li zelite da ju procitate.\n");
	DaNe("VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if (odgovor == 1) {
		Poruka(zivotniBodovi);
	} else if (odgovor == 2) {
		*zivotniBodovi = 0;
		IspisSlike("Kraj Igre.txt");
	} else{
		IspisGreskeONepravilnomUnosu();
		Gavran(zivotniBodovi);
	}
	return 0;
}
int Poruka(int* zivotniBodovi) {
	UsporeniIspisTeksta(100, "\nTvoj kralj Robert Baratheon, ti naredjuje da smjesta\nnapustis Winterfell i krenes prema Kings Landing.\nOdbijanje kraljevog poziva moze imati strasne posljedice.\n\n");
	UsporeniIspisTeksta(100, "Da li ce te prihvatiti kraljev poziv i krenuti prema Kings Landing-u (DA),\n");
	UsporeniIspisTeksta(100, "ili ce te odbaciti kraljev poziv (NE) i ostati u Winterfell-u?\n");
	DaNe("VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if (odgovor == 1) {
		KraljevPut(zivotniBodovi);
	}
	else if (odgovor == 2) {
		LanasterNapad(zivotniBodovi);
	}
	else {
		IspisGreskeONepravilnomUnosu();
		Poruka(zivotniBodovi);
	}
	return 0;
}
int LanasterNapad(int* zivotniBodovi) {
	UsporeniIspisTeksta(100, "Lannister-ske trupe marsiraju prema Winterfell-u. Da li ce te se:\n");
	DvaIzbora("1. Pripremiti za napad.", "2. Prihvatiti kraljev poziv.", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if (odgovor == 1) {
		PripremaZaNapad(zivotniBodovi);
	}
	else if (odgovor == 2) {
		KraljevPut(zivotniBodovi);
	}
	else {
		IspisGreskeONepravilnomUnosu();
		LanasterNapad(zivotniBodovi);
	}
	return 0;
}
int KraljevPut(int* zivotniBodovi) {
	UsporeniIspisTeksta(100, "Na putu ste za Kings Landing. Prema vama ide postar na konju sa porukom iz Kings Landing-a.\n");
	UsporeniIspisTeksta(100, "Poruka:\n");
	UsporeniIspisTeksta(100, "Kralj Robert Baratheon je mrtav.\n");
	UsporeniIspisTeksta(100, "Da li ce te nastaviti put prema Kings Landing-u.\n");
	DaNe("VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if (odgovor == 1) {
		osvojeniXP -= 3;
		KingsLanding(zivotniBodovi);
	}
	else if (odgovor == 2) {
		osvojeniXP += 2;
		UsporeniIspisTeksta(100, "Nekoliko mjeseci kasnije.");
		DzonovaPoruka(zivotniBodovi);
	}
	else {
		IspisGreskeONepravilnomUnosu();
		KraljevPut(zivotniBodovi);
	}
	return 0;
}
int KingsLanding(int* zivotniBodovi) {
	UsporeniIspisTeksta(100, "Ulazite u Kings Landing. Kraljeva straza vas privodi.\n");
	UsporeniIspisTeksta(100, "Sta ce te uciniti?\n");
	DvaIzbora("1. Mirno se predati kraljevoj strazi.", "2. Ne predavati se bez borbe.", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if (odgovor == 1) {
		SjecaGlave(zivotniBodovi);
	}
	else if (odgovor == 2) {
		osvojeniXP += 3;
		KraljevaStraza(zivotniBodovi);
	}
	else {
		IspisGreskeONepravilnomUnosu();
		KingsLanding(zivotniBodovi);
	}
	return 0;
}
int SjecaGlave(int* zivotniBodovi) {
	UsporeniIspisTeksta(100, "Glupane. Zasto se niste borili.\n");
	UsporeniIspisTeksta(100, "Novi kralj Joffrey vas je proglasio za izdajnika krune\n");
	UsporeniIspisTeksta(100, "i naredio je da vam odsjeku glavu.\n");
	UsporeniIspisTeksta(100, "Cestitam. Vase lose odluke su vas dovele do smrti.\n");
	IspisSlike("Kraj Igre.txt");
	UkloniIgracevXP(&glavniXP);
	*zivotniBodovi = 0;
	return 0;
}
int KraljevaStraza(int* zivotniBodovi) {
	UsporeniIspisTeksta(100, "Da li zelite da napadnete kraljevu strazu\n");
	DvaIzbora("1. Pesnicama", "2. Sa macem", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if (odgovor == 1) {
		osvojeniXP -=3;
		NapadPesnicama(zivotniBodovi);
	}
	else if (odgovor == 2) {
		osvojeniXP += 3;
		NapadMacem(zivotniBodovi);
	}
	else {
		IspisGreskeONepravilnomUnosu();
		KraljevaStraza(zivotniBodovi);
	}
	return 0;
}
int NapadPesnicama(int* zivotniBodovi) {
	UsporeniIspisTeksta(100, "Da li ste sigurni da zelite krenuti na pet, dobro naoruzanih, kraljevih cuvara goloruki?\n");
	DaNe("VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if (odgovor == 1) {
		NapadPesnicama1(zivotniBodovi);
	}
	else if (odgovor == 2) {
		KraljevaStraza(zivotniBodovi);
	}
	else {
		IspisGreskeONepravilnomUnosu();
		NapadPesnicama(zivotniBodovi);
	}
	return 0;
}
int NapadPesnicama1(int* zivotniBodovi) {
	UsporeniIspisTeksta(100, "Unesite:\n");
	CetiriIzbora("1 - za udarac lijevom sakom", "2 - za udrac desnom sakom", "3 - za udarac lijevom nogom", "4 - za udarac desnom nogom", "VERTIKALNO");
	DvaIzbora("5 - za udarac glavom", "6 - za udarac koljenom", "VERTIKALNO");
	int sef = 150;
	do{
		int potez = UcitajOdgovor(), strazar = Nasumicno(100);
		if(potez == 1){
			UsporeniIspisTeksta(100, "To je dobar udarac.\n");
			sef -= 15;
		} else if(potez == 2){
			UsporeniIspisTeksta(100, "Vas udarac je bio snazan.\n");
			sef -= 20;
		} else if(potez == 3){
			UsporeniIspisTeksta(100, "Vaaauuu kakav potez. Srusili ste jednog strazara.\n");
			sef -= 10;
		} else if(potez == 4){
			UsporeniIspisTeksta(100, "Kakav sut! Kakav sut!\n");
			sef -= 27;
		} else if(potez == 5){
			UsporeniIspisTeksta(100, "Zanimljiv potez.\n");
			sef -= 13;
		} else if(potez == 6){
			UsporeniIspisTeksta(100, "Uuh to je boljelo. Bas mi je dargo da ja nisam taj strazar.\n");
			sef -= 32;
		}
		if(strazar < 40){
			zivotniBodovi -= 3;
		}
	} while(zivotniBodovi > 0 && sef > 0);
	
	if(zivotniBodovi < 0){
		UsporeniIspisTeksta(100, "Strazar vam zadaje smrtonosti udarac.\nUpravo ste umrli.\n");
		VremenskaPauza(3);
		IspisSlike("Kraj Igre.txt");
		UkloniIgrice4XP(&osvojeniXP);
		*zivotniBodovi = 0;
	} else{
		osvojeniXP += 5;
		SmrtNeda(zivotniBodovi);
	}
	return 0;
}
int NapadMacem(int* zivotniBodovi) {
	UsporeniIspisTeksta(100, "Izvlacite mac i jurisate na kraljevu starzu.\n");
	UsporeniIspisTeksta(100, "Kraljeva straza se postavlja u borbeni polozaj.\n");
	VremenskaPauza(2);
	int strazar = 0, i;
	for (i = 0; strazar != 5 || zivotniBodovi > 0; i++) {
		if(zivotniBodovi <= 0){
			UsporeniIspisTeksta(100, "Strazar vam zadaje smrtonosti udarac.\nUpravo ste umrli.\n");
			IspisSlike("Kraj Igre.txt");
			UkloniIgrice4XP(&osvojeniXP);
			*zivotniBodovi = 0;
			return 0;
		}
		int potez = Nasumicno(2);
		if (potez) {
			int udarac = Nasumicno(2);
			if(udarac){
				UsporeniIspisTeksta(100, "Jedan strazar je ubijen.\n");
				VremenskaPauza(2);
				strazar++;
			} else{
				UsporeniIspisTeksta(100, "Jedan strazar je ranjen.\n");
				VremenskaPauza(2);
			}
		} else {
			UsporeniIspisTeksta(100, "Strazar vas raljava.\n");
			VremenskaPauza(2);
			zivotniBodovi -= Nasumicno(11);
		}
	}
	
	SmrtNeda(zivotniBodovi);
	
	return 0;
}
int SmrtNeda(int* zivotniBodovi){
	VremenskaPauza(3);
	UsporeniIspisTeksta(100, "Nakon napada Kraljeve straze shvatate da nesto nije uredu i da morate sto prije napustiti Kings Landing.\nDok ste prolazili kroz uske ulice Kings Landing-a, prema kapiji sa ledja vas zaskace Hound.\n");
	UsporeniIspisTeksta(100, "Hvata vas i odvodi pred novog kralja Joffrey.\nJoffrey vas proglasava za izdajnika i naredjuje vase pogubljenje.\nUmrli set.\n");
	UkloniIgrice4XP(&osvojeniXP);
	VremenskaPauza(20);
	OcistiEkran();
	KordinateXY(40, 14);
	IspisSlike("Kraj Igre.txt");
	*zivotniBodovi = 0;
	return 0;
}
int PripremaZaNapad(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Winterfell je u stanju pripravnosti.\nVi predvodite trupe na bojno polje da se suocite sa Lannister-ima.\n");
	UsporeniIspisTeksta(100, "Doslo je vrijeme da odaberete strategiju napada. Da li ce te:\n");
	TriIzbora("1. Napasti u formaciji Trougao", "2. Napasti u Liniskoj formaciji", "3. Napasti u formaciji Rimske kornjace sa tri strane", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	printf("Bitka je pocela!\n");
	VremenskaPauza(5);
	if(odgovor == 1){
		int odluka = Nasumicno(2) ? Nasumicno(2) : Nasumicno(2);
		if(odluka){
			osvojeniXP += 4;
			Pobjeda(zivotniBodovi);
		} else{
			Poraz(zivotniBodovi);
		}
	} else if(odgovor == 2){
		UsporeniIspisTeksta(100, "Zao mi je ali vasa strategija je bila pogresna. Vase trupe su masakrirane i Winterfell je pao.\nVi krvarite na bojnom polju. Smrt je neizbjezna.\n");
		VremenskaPauza(3);
		printf("Umrli ste.");
		IspisSlike("Kraj Igre.txt");
		UkloniIgrice4XP(&osvojeniXP);
		*zivotniBodovi = 0;
	} else if(odgovor == 3){
		Pobjeda(zivotniBodovi);
	} else{
		IspisGreskeONepravilnomUnosu();
		PripremaZaNapad(zivotniBodovi);
	}
	
	return 0;
}
int Pobjeda(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Cestitam upravo ste pobjedili vaznu bitku. Winterfell je siguran.\n");
	osvojeniXP += 2;
	TajmerMjeseci(zivotniBodovi);
	return 0;
}
int Poraz(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Vas izbor strategije nije bio dovoljno efikasan. Izgubili ste bitku za Winterfell.\n");
	UsporeniIspisTeksta(100, "Vracate se u Winterfell, ali vise nemate moc koju ste nekada imali.\nLannister-i sad imaju kontrolu nad jednim dijelom Sjevera.\n");
	TajmerMjeseci(zivotniBodovi);
	return 0;
}
void PorukaSaZida(){
	VremenskaPauza(3);
	UsporeniIspisTeksta(100, "Vama stize gavran sa porukom od Lorda Komandanta Nocne Straze Jon Snow-a.\n\n");
	UsporeniIspisTeksta(100, "    Dragi brate. Postoji velika pretnja s druge strane zida.\nPrice o White Walker-ima nisu samo price. Oni su stvarni.\nSavjetujem te da se pripremis za najvecu bitku u poslednjih hiljadu godina.\n");
	UsporeniIspisTeksta(100, "Lorda Komandanta Nocne Straze i tvoj dragi brat, Jon Snow\n\n");
	VremenskaPauza(3);
}
int Daneres(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Prava nasljednica Celicnog trona, Daenerys Targaryen, je presla Narrow more sa svoja tri zmaja i Dothraki armijom.\n");
	UsporeniIspisTeksta(100, "Sedam kraljevstva se raspadaju krvavim ratom.\nSad moras donijeti vaznu odluku. Da li ces:\n");
	DvaIzbora("1. Pomoci Daenerys da vrati Celicni tron u ruke Targaryen-a", "2. Pomoci Lannister-ima da odbrane Celicni tron", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		PomociDaneres(zivotniBodovi);
	} else if(odgovor == 2){
		PadKraljevstava(zivotniBodovi);
	} else{
		IspisGreskeONepravilnomUnosu();
		Daneres(zivotniBodovi);
	}
	return 0;
}
int PadKraljevstava(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Trebali ste odabrati prvu opciju.\nKings Landing je pao. Zmajevi su srusili Red Keep, a vi ste izgubili Winterfell.\n");
	UsporeniIspisTeksta(100, "Za vas je Igra prestola gotova.\n");
	UkloniIgrice4XP(&osvojeniXP);
	UsporeniIspisTeksta(100, "Dok ste se vi igrali Igre prestola, Zid je pao i White Walker-i su presli zid.\nSmrt, a sa njom mrtvi i vjecita zima su stigli u Westeros.\n");
	UsporeniIspisTeksta(100, "Trebali ste poslusati Jon-ovo upozorenje.\n");
	IspisSlike("Kraj Igre.txt");
	*zivotniBodovi = 0;
	return 0;
}
int PadZida(int* zivotniBodovi){
	Zid();
	VremenskaPauza(5);
	UsporeniIspisTeksta(100, "U IGRI PRESTOLA, ILI POBJRDIS, ILI UMRES.\n\n");
	VremenskaPauza(4);
	UsporeniIspisTeksta(100, "Tvoja sudbina kao i sudbina citavog Westeros-a je sad u rukama Sedam bogova\n i George R. R. Martin-a.\n");
	VremenskaPauza(7);
	IspisSlike("Kraj Igre.txt");
	glavniXP += 200;
	return 0;
}
void Zid(){
	VremenskaPauza(3);
	UsporeniIspisTeksta(100, "\nU medjuvremenu na Zidu.\n\nNight King sa armijom mrtvih napada zid.\nNocna straza pokusava da odbrani zid i ne dozvoli White Walker-ima da predju u Westeros.\n");
	UsporeniIspisTeksta(100, "Napori Nocne straze su uzaludni. Lord Komadant Nocne Straze Jon Snow je mrtav.\nMagija koja je drzala zid i sprecavala mrtve da ga predju je nestala.\n");
	UsporeniIspisTeksta(100, "Zid pada, Nocna straza je porazena. 1000 godina nakon njegovog podiza mrtvi ulaze u Westeros.\n\n");
}
int DzonovaPoruka(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Sedam kraljevstava su na ivici rata.\n");
	PorukaSaZida();
	UsporeniIspisTeksta(100, "Da li ce te poslusati bratova upozorenja i poceti se pripremati za bitku.\n");
	DaNe("VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		Daneres(zivotniBodovi);
		PadZida(zivotniBodovi);
	} else if(odgovor == 2){
		Daneres(zivotniBodovi);
		Zid();
		UkloniIgracevXP(&glavniXP);
	} else{
		IspisGreskeONepravilnomUnosu();
		DzonovaPoruka(zivotniBodovi);
	}
	return 0;
}
void TajmerMjeseci(int* zivotniBodovi){
	VremenskaPauza(2);
	printf("  1\n");
	VremenskaPauza(2);
	printf("  2\n");
	VremenskaPauza(2);
	printf("  3\n");
	VremenskaPauza(2);
	printf("  4\n");
	VremenskaPauza(2);
	UsporeniIspisTeksta(100, "  5\nProslo je pet mjeseci od bitke za Winterfell.\nU Kings Landing-u doslo je do smjene tri kralja na Celicnom tronu.\n");
	DzonovaPoruka(zivotniBodovi);
}
int PomociDaneres(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Vidim da ste odlucili pomoci Daenerys Targaryen.\nSvaostala kraljevstva su takodje odlucili da pomognu Daenerys u borbi protiv Lannister-a.\n");
	UsporeniIspisTeksta(100, "Napad na Kings Landing je poceo.");
	int n = 0, potez;
	for(; n < 8;){
		potez = Nasumicno(10);
		if(potez == 1){
			UsporeniIspisTeksta(100, "Zmaj napada Red Keap.\n");
			n++;
			VremenskaPauza(2);
		} else if(potez == 2){
			UsporeniIspisTeksta(100, "Tyrell se probijaju kroz jos jednu ulicu.\n");
			VremenskaPauza(2);
		} else if(potez == 3){
			UsporeniIspisTeksta(100, "Lannister-ske trupe zadaju snazan udarac.\n");
			n--;
			VremenskaPauza(2);
		} else if(potez == 4){
			UsporeniIspisTeksta(100, "Greyjoy flota napada vase trupe.\n");
			n--;
			VremenskaPauza(2);
		} else if(potez == 5){
			UsporeniIspisTeksta(100, "Martell armija zadaje udarac Lannister-skim trupama.\n");
			n++;
			VremenskaPauza(2);
		} else if(potez == 6){
			UsporeniIspisTeksta(100, "Wildfire eksplozija.\nVase trupe su ranjene.\n");
			n--;
			VremenskaPauza(2);
		} else if(potez == 7){
			UsporeniIspisTeksta(100, "Nova trupa stize do Red Keap-a.\n");
			n++;
			VremenskaPauza(2);
		} else if(potez == 8){
			UsporeniIspisTeksta(100, "Vase trupe se probijaju prema Red Keap-u.\n");
			n++;
			VremenskaPauza(2);
		} else if(potez == 9){
			UsporeniIspisTeksta(100, "Dothraki jurisaju kroz Kings Landing.\n");
			VremenskaPauza(2);
		} 
	}
	VremenskaPauza(3);
	UsporeniIspisTeksta(100, "\nBitka je dobijena Lannister-i su porazeni.\nWesteros ima novu kraljicu od kuce Targaryen.\nDoba novog mira izmedju sedam kraljevstava je pocelo.\n");
	return 0;
}
