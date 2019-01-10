#include "GameOfThrons.h"
#include "FunkcijeZaIspis.h"
#include "Igrica4Komande.h"
#include <stdlib.h>
#include <stdio.h>

//za potrebe ispisa
const int brzinaa = 0;


int GOTPohod(int* glavniXP2, int najboljiR, int* osvojeniXP2, int pisi){
	
	system("title Game Of Throns");
	
	OcistiEkran();
	Load("GOT loading...", 34);
	
	glavniXP = *glavniXP2;
	int zivotniBodovi = 100;
	otkazi = 0;
	Gavran(&zivotniBodovi);
	if(glavniXP > 0){
		glavniXP += osvojeniXP;
	}
	*glavniXP2 = glavniXP;
	*osvojeniXP2 = osvojeniXP;
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

int Gavran(int* zivotniBodovi){

	UsporeniIspisTeksta(brzinaa, "Stigao je gavran sa porukom. Da li zelite da ju procitate.\n");
	DaNe("VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if (odgovor == 1) {
		osvojeniXP += 15;
		Poruka(zivotniBodovi);
	} else if (odgovor == 2) {
		*zivotniBodovi = 0;
		OcistiEkran();
		IspisSlike("Kraj Igre.txt");
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		return 0;
	} else{
		IspisGreskeONepravilnomUnosu();
		Gavran(zivotniBodovi);
	}
	return 0;
}
int Poruka(int* zivotniBodovi) {

	

	UsporeniIspisTeksta(brzinaa, "\nTvoj kralj Robert Baratheon, ti naredjuje da smjesta\nnapustis Winterfell i krenes prema Kings Landing.\nOdbijanje kraljevog poziva moze imati strasne posljedice.\n\n");
	UsporeniIspisTeksta(brzinaa, "Da li ce te prihvatiti kraljev poziv i krenuti prema Kings Landing-u (DA),\n");
	UsporeniIspisTeksta(brzinaa, "ili ce te odbaciti kraljev poziv (NE) i ostati u Winterfell-u?\n");
	DaNe("VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if (odgovor == 1) {
		osvojeniXP -= 40;
		KraljevPut(zivotniBodovi);
	}
	else if (odgovor == 2) {
		osvojeniXP -= 40;
		LanasterNapad(zivotniBodovi);
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		return 0;
	}
	else {
		IspisGreskeONepravilnomUnosu();
		Poruka(zivotniBodovi);
	}
	return 0;
}
int LanasterNapad(int* zivotniBodovi) {


	UsporeniIspisTeksta(brzinaa, "Lannister-ske trupe marsiraju prema Winterfell-u. Da li ce te se:\n");
	DvaIzbora("1. Pripremiti za napad.", "2. Prihvatiti kraljev poziv.", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if (odgovor == 1) {
		osvojeniXP += 15;
		PripremaZaNapad(zivotniBodovi);
	}
	else if (odgovor == 2) {
		osvojeniXP += 15;
		KraljevPut(zivotniBodovi);
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		return 0;
	}
	else {
		IspisGreskeONepravilnomUnosu();
		LanasterNapad(zivotniBodovi);
	}
	return 0;
}
int KraljevPut(int* zivotniBodovi) {
	UsporeniIspisTeksta(brzinaa, "Na putu ste za Kings Landing. Prema vama ide postar na konju sa porukom iz Kings Landing-a.\n");
	UsporeniIspisTeksta(brzinaa, "Poruka:\n");
	UsporeniIspisTeksta(brzinaa, "Kralj Robert Baratheon je mrtav.\n");
	UsporeniIspisTeksta(brzinaa, "Da li ce te nastaviti put prema Kings Landing-u.\n");
	DaNe("VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if (odgovor == 1) {
		osvojeniXP -= 40;
		KingsLanding(zivotniBodovi);
	}
	else if (odgovor == 2) {
		osvojeniXP += 15;
		UsporeniIspisTeksta(brzinaa, "Nekoliko mjeseci kasnije.");
		DzonovaPoruka(zivotniBodovi);
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		return 0;
	}
	else {
		IspisGreskeONepravilnomUnosu();
		KraljevPut(zivotniBodovi);
	}
	return 0;
}
int KingsLanding(int* zivotniBodovi) {
	UsporeniIspisTeksta(brzinaa, "Ulazite u Kings Landing. Kraljeva straza vas privodi.\n");
	UsporeniIspisTeksta(brzinaa, "Sta ce te uciniti?\n");
	DvaIzbora("1. Mirno se predati kraljevoj strazi.", "2. Ne predavati se bez borbe.", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if (odgovor == 1) {
		osvojeniXP -= 40;
		SjecaGlave(zivotniBodovi);
	}
	else if (odgovor == 2) {
		osvojeniXP += 15;
		KraljevaStraza(zivotniBodovi);
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		return 0;
	}
	else {
		IspisGreskeONepravilnomUnosu();
		KingsLanding(zivotniBodovi);
	}
	return 0;
}
int SjecaGlave(int* zivotniBodovi) {
	UsporeniIspisTeksta(brzinaa, "Glupane. Zasto se niste borili.\n");
	UsporeniIspisTeksta(brzinaa, "Novi kralj Joffrey vas je proglasio za izdajnika krune\n");
	UsporeniIspisTeksta(brzinaa, "i naredio je da vam odsjeku glavu.\n");
	UsporeniIspisTeksta(brzinaa, "Cestitam. Vase lose odluke su vas dovele do smrti.\n");
	VremenskaPauza(5);
	OcistiEkran();
	IspisSlike("Kraj Igre.txt");
	UkloniIgracevXP(&glavniXP);
	*zivotniBodovi = 0;
	return 0;
}
int KraljevaStraza(int* zivotniBodovi) {
	UsporeniIspisTeksta(brzinaa, "Da li zelite da napadnete kraljevu strazu\n");
	DvaIzbora("1. Pesnicama", "2. Sa macem", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if (odgovor == 1) {
		osvojeniXP -= 40;
		NapadPesnicama(zivotniBodovi);
	}
	else if (odgovor == 2) {
		osvojeniXP += 15;
		NapadMacem(zivotniBodovi);
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		return 0;
	}
	else {
		IspisGreskeONepravilnomUnosu();
		KraljevaStraza(zivotniBodovi);
	}
	return 0;
}
int NapadPesnicama(int* zivotniBodovi) {
	UsporeniIspisTeksta(brzinaa, "Da li ste sigurni da zelite krenuti na pet, dobro naoruzanih, kraljevih cuvara goloruki?\n");
	DaNe("VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if (odgovor == 1) {
		NapadPesnicama1(zivotniBodovi);
	}
	else if (odgovor == 2) {
		KraljevaStraza(zivotniBodovi);
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		return 0;
	}
	else {
		IspisGreskeONepravilnomUnosu();
		NapadPesnicama(zivotniBodovi);
	}
	return 0;
}
int NapadPesnicama1(int* zivotniBodovi) {
	UsporeniIspisTeksta(brzinaa, "Unesite:\n");
	CetiriIzbora("1 - za udarac lijevom sakom", "2 - za udrac desnom sakom", "3 - za udarac lijevom nogom", "4 - za udarac desnom nogom", "VERTIKALNO");
	DvaIzbora("5 - za udarac glavom", "6 - za udarac koljenom", "VERTIKALNO");
	int sef = 150;
	do{
		int potez = UcitajOdgovor(), strazar = Nasumicno(100);
		if(potez == 1){
			UsporeniIspisTeksta(brzinaa, "To je dobar udarac.\n");
			sef -= 15;
		} else if(potez == 2){
			UsporeniIspisTeksta(brzinaa, "Vas udarac je bio snazan.\n");
			sef -= 20;
		} else if(potez == 3){
			UsporeniIspisTeksta(brzinaa, "Vaaauuu kakav potez. Srusili ste jednog strazara.\n");
			sef -= 10;
		} else if(potez == 4){
			UsporeniIspisTeksta(brzinaa, "Kakav sut! Kakav sut!\n");
			sef -= 27;
		} else if(potez == 5){
			UsporeniIspisTeksta(brzinaa, "Zanimljiv potez.\n");
			sef -= 13;
		} else if(potez == 6){
			UsporeniIspisTeksta(brzinaa, "Uuh to je boljelo. Bas mi je dargo da ja nisam taj strazar.\n");
			sef -= 32;
		} else if(potez == -2){
			osvojeniXP = 0;
			return 0;
		} else if(potez == -3){
			otkazi = 1;
			return 0;
		}
		if(strazar < 40){
			zivotniBodovi -= 3;
		}
	} while(zivotniBodovi > 0 && sef > 0);
	
	if(zivotniBodovi < 0){
		UsporeniIspisTeksta(brzinaa, "Strazar vam zadaje smrtonosti udarac.\nUpravo ste umrli.\n");
		VremenskaPauza(3);
		OcistiEkran();
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
	UsporeniIspisTeksta(brzinaa, "Izvlacite mac i jurisate na kraljevu starzu.\n");
	UsporeniIspisTeksta(brzinaa, "Kraljeva straza se postavlja u borbeni polozaj.\n");
	VremenskaPauza(2);
	int strazar = 0, i, ranjen = 0;
	for (i = 0; strazar < 5 && zivotniBodovi > 0; i++) {
		if(zivotniBodovi <= 0){
			UsporeniIspisTeksta(brzinaa, "Strazar vam zadaje smrtonosti udarac.\nUpravo ste umrli.\n");
			VremenskaPauza(3);
			OcistiEkran();
			IspisSlike("Kraj Igre.txt");
			UkloniIgrice4XP(&osvojeniXP);
			*zivotniBodovi = 0;
			return 0;
		}
		int potez = Nasumicno(2);
		if (potez) {
			int udarac = Nasumicno(2);
			if(udarac){
				UsporeniIspisTeksta(brzinaa, "Jedan strazar je ubijen.\n");
				VremenskaPauza(2);
				strazar++;
			} else{
				UsporeniIspisTeksta(brzinaa, "Jedan strazar je ranjen.\n");
				VremenskaPauza(2);
				ranjen++;
				if (ranjen == 3) {
					ranjen = 0;
					strazar++;
					UsporeniIspisTeksta(brzinaa, "Jedan strazar je ubijen.\n");
				}
			}
		} else {
			UsporeniIspisTeksta(brzinaa, "Strazar vas raljava.\n");
			VremenskaPauza(2);
			zivotniBodovi -= Nasumicno(21);
		}
	}
	
	SmrtNeda(zivotniBodovi);
	
	return 0;
}
int SmrtNeda(int* zivotniBodovi){
	VremenskaPauza(3);
	UsporeniIspisTeksta(brzinaa, "Nakon napada Kraljeve straze shvatate da nesto nije uredu i da morate sto prije napustiti Kings Landing.\nDok ste prolazili kroz uske ulice Kings Landing-a, prema kapiji sa ledja vas zaskace Hound.\n");
	UsporeniIspisTeksta(brzinaa, "Hvata vas i odvodi pred novog kralja Joffrey.\nJoffrey vas proglasava za izdajnika i naredjuje vase pogubljenje.\nUmrli set.\n");
	UkloniIgrice4XP(&osvojeniXP);
	VremenskaPauza(10);
	OcistiEkran();
	KordinateXY(40, 14);
	IspisSlike("Kraj Igre.txt");
	*zivotniBodovi = 0;
	return 0;
}
int PripremaZaNapad(int* zivotniBodovi){
	UsporeniIspisTeksta(brzinaa, "Winterfell je u stanju pripravnosti.\nVi predvodite trupe na bojno polje da se suocite sa Lannister-ima.\n");
	UsporeniIspisTeksta(brzinaa, "Doslo je vrijeme da odaberete strategiju napada. Da li ce te:\n");
	TriIzbora("1. Napasti u formaciji Trougao", "2. Napasti u Liniskoj formaciji", "3. Napasti u formaciji Rimske kornjace sa tri strane", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	printf("Bitka je pocela!\n");
	VremenskaPauza(5);
	if(odgovor == 1){
		osvojeniXP -= 40;
		int odluka = Nasumicno(2) ? Nasumicno(2) : Nasumicno(2);
		if(odluka){
			osvojeniXP += 4;
			Pobjeda(zivotniBodovi);
		} else{
			Poraz(zivotniBodovi);
		}
	} else if(odgovor == 2){
		osvojeniXP -= 40;
		UsporeniIspisTeksta(brzinaa, "Zao mi je ali vasa strategija je bila pogresna. Vase trupe su masakrirane i Winterfell je pao.\nVi krvarite na bojnom polju. Smrt je neizbjezna.\n");
		VremenskaPauza(3);
		printf("Umrli ste.");
		VremenskaPauza(3);
		OcistiEkran();
		IspisSlike("Kraj Igre.txt");
		UkloniIgrice4XP(&osvojeniXP);
		*zivotniBodovi = 0;
	} else if(odgovor == 3){
		Pobjeda(zivotniBodovi);
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		return 0;
	} else{
		IspisGreskeONepravilnomUnosu();
		PripremaZaNapad(zivotniBodovi);
	}
	
	return 0;
}
int Pobjeda(int* zivotniBodovi){
	UsporeniIspisTeksta(brzinaa, "Cestitam upravo ste pobjedili vaznu bitku. Winterfell je siguran.\n");
	osvojeniXP += 15;
	TajmerMjeseci(zivotniBodovi);
	return 0;
}
int Poraz(int* zivotniBodovi){
	UsporeniIspisTeksta(brzinaa, "Vas izbor strategije nije bio dovoljno efikasan. Izgubili ste bitku za Winterfell.\n");
	UsporeniIspisTeksta(brzinaa, "Vracate se u Winterfell, ali vise nemate moc koju ste nekada imali.\nLannister-i sad imaju kontrolu nad jednim dijelom Sjevera.\n");
	TajmerMjeseci(zivotniBodovi);
	return 0;
}
void PorukaSaZida(){
	VremenskaPauza(3);
	UsporeniIspisTeksta(brzinaa, "Vama stize gavran sa porukom od Lorda Komandanta Nocne Straze Jon Snow-a.\n\n");
	UsporeniIspisTeksta(brzinaa, "    Dragi brate. Postoji velika pretnja s druge strane zida.\nPrice o White Walker-ima nisu samo price. Oni su stvarni.\nSavjetujem te da se pripremis za najvecu bitku u poslednjih hiljadu godina.\n");
	UsporeniIspisTeksta(brzinaa, "Lorda Komandanta Nocne Straze i tvoj dragi brat, Jon Snow\n\n");
	VremenskaPauza(3);
}
int Daneres(int* zivotniBodovi){
	UsporeniIspisTeksta(brzinaa, "Prava nasljednica Celicnog trona, Daenerys Targaryen, je presla Narrow more sa svoja tri zmaja i Dothraki armijom.\n");
	UsporeniIspisTeksta(brzinaa, "Sedam kraljevstva se raspadaju krvavim ratom.\nSad moras donijeti vaznu odluku. Da li ces:\n");
	DvaIzbora("1. Pomoci Daenerys da vrati Celicni tron u ruke Targaryen-a", "2. Pomoci Lannister-ima da odbrane Celicni tron", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		osvojeniXP += 15;
		PomociDaneres(zivotniBodovi);
	} else if(odgovor == 2){
		osvojeniXP -= 40;
		PadKraljevstava(zivotniBodovi);
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		return 0;
	} else{
		IspisGreskeONepravilnomUnosu();
		Daneres(zivotniBodovi);
	}
	return 0;
}
int PadKraljevstava(int* zivotniBodovi){
	UsporeniIspisTeksta(brzinaa, "Trebali ste odabrati prvu opciju.\nKings Landing je pao. Zmajevi su srusili Red Keep, a vi ste izgubili Winterfell.\n");
	UsporeniIspisTeksta(brzinaa, "Za vas je Igra prestola gotova.\n");
	UkloniIgrice4XP(&osvojeniXP);
	UsporeniIspisTeksta(brzinaa, "Dok ste se vi igrali Igre prestola, Zid je pao i White Walker-i su presli zid.\nSmrt, a sa njom mrtvi i vjecita zima su stigli u Westeros.\n");
	UsporeniIspisTeksta(brzinaa, "Trebali ste poslusati Jon-ovo upozorenje.\n");
	VremenskaPauza(7);
	OcistiEkran();
	IspisSlike("Kraj Igre.txt");
	*zivotniBodovi = 0;
	return 0;
}
int PadZida(int* zivotniBodovi){
	Zid();
	VremenskaPauza(5);
	UsporeniIspisTeksta(brzinaa, "U IGRI PRESTOLA, ILI POBJRDIS, ILI UMRES.\n\n");
	VremenskaPauza(4);
	UsporeniIspisTeksta(brzinaa, "Tvoja sudbina kao i sudbina citavog Westeros-a je sad u rukama Sedam bogova\n i George R. R. Martin-a.\n");
	VremenskaPauza(7);
	OcistiEkran();
	IspisSlike("Kraj Igre.txt");
	glavniXP += 75;
	return 0;
}
void Zid(){
	VremenskaPauza(3);
	UsporeniIspisTeksta(brzinaa, "\nU medjuvremenu na Zidu.\n\nNight King sa armijom mrtvih napada zid.\nNocna straza pokusava da odbrani zid i ne dozvoli White Walker-ima da predju u Westeros.\n");
	UsporeniIspisTeksta(brzinaa, "Napori Nocne straze su uzaludni. Lord Komadant Nocne Straze Jon Snow je mrtav.\nMagija koja je drzala zid i sprecavala mrtve da ga predju je nestala.\n");
	UsporeniIspisTeksta(brzinaa, "Zid pada, Nocna straza je porazena. 1000 godina nakon njegovog podiza mrtvi ulaze u Westeros.\n\n");
}
int DzonovaPoruka(int* zivotniBodovi){
	UsporeniIspisTeksta(brzinaa, "Sedam kraljevstava su na ivici rata.\n");
	PorukaSaZida();
	UsporeniIspisTeksta(brzinaa, "Da li ce te poslusati bratova upozorenja i poceti se pripremati za bitku.\n");
	DaNe("VERTIKALNO");
	int odgovor = UcitajOdgovor(), uslov;
	if(odgovor == 1){
		osvojeniXP += 15;
		uslov = Daneres(zivotniBodovi);
		if(odgovor == -2){
			osvojeniXP = 0;
			return 0;
		} else if(odgovor == -3){
			otkazi = 1;
			return 0;
		}
		PadZida(zivotniBodovi);
	} else if(odgovor == 2){
		osvojeniXP -= 40;
		uslov = Daneres(zivotniBodovi);
		if(odgovor == -2){
			osvojeniXP = 0;
			return 0;
		} else if(odgovor == -3){
			otkazi = 1;
			return 0;
		}
		Zid();
		UkloniIgracevXP(&glavniXP);
	} else if(odgovor == -2){
		osvojeniXP = 0;
		return 0;
	} else if(odgovor == -3){
		otkazi = 1;
		return 0;
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
	UsporeniIspisTeksta(brzinaa, "  5\nProslo je pet mjeseci od bitke za Winterfell.\nU Kings Landing-u doslo je do smjene tri kralja na Celicnom tronu.\n");
	DzonovaPoruka(zivotniBodovi);
}
int PomociDaneres(int* zivotniBodovi){
	UsporeniIspisTeksta(brzinaa, "Vidim da ste odlucili pomoci Daenerys Targaryen.\nSva ostala kraljevstva su takodje odlucili da pomognu Daenerys u borbi protiv Lannister-a.\n");
	UsporeniIspisTeksta(brzinaa, "Napad na Kings Landing je poceo.");
	int n = 0, potez;
	for(; n < 6;){
		potez = Nasumicno(10);
		if(potez == 1){
			UsporeniIspisTeksta(brzinaa, "Zmaj napada Red Keap.\n");
			n++;
			VremenskaPauza(2);
		} else if(potez == 2){
			UsporeniIspisTeksta(brzinaa, "Tyrell se probijaju kroz jos jednu ulicu.\n");
			n++;
			VremenskaPauza(2);
		} else if(potez == 3){
			UsporeniIspisTeksta(brzinaa, "Lannister-ske trupe zadaju snazan udarac.\n");
			n--;
			VremenskaPauza(2);
		} else if(potez == 4){
			UsporeniIspisTeksta(brzinaa, "Greyjoy flota napada vase trupe.\n");
			n--;
			VremenskaPauza(2);
		} else if(potez == 5){
			UsporeniIspisTeksta(brzinaa, "Martell armija zadaje udarac Lannister-skim trupama.\n");
			n++;
			VremenskaPauza(2);
		} else if(potez == 6){
			UsporeniIspisTeksta(brzinaa, "Wildfire eksplozija.\nVase trupe su ranjene.\n");
			n--;
			VremenskaPauza(2);
		} else if(potez == 7){
			UsporeniIspisTeksta(brzinaa, "Nova trupa stize do Red Keap-a.\n");
			n++;
			VremenskaPauza(2);
		} else if(potez == 8){
			UsporeniIspisTeksta(brzinaa, "Vase trupe se probijaju prema Red Keap-u.\n");
			n++;
			VremenskaPauza(2);
		} else if(potez == 9){
			UsporeniIspisTeksta(brzinaa, "Dothraki jurisaju kroz Kings Landing.\n");
			n++;
			VremenskaPauza(2);
		}
	}
	VremenskaPauza(3);
	UsporeniIspisTeksta(brzinaa, "\nBitka je dobijena Lannister-i su porazeni.\nWesteros ima novu kraljicu od kuce Targaryen.\nDoba novog mira izmedju sedam kraljevstava je pocelo.\n");
	return 0;
}
