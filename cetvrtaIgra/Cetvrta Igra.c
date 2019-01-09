#include "FunkcijeZaIspis.h"
#include "Igrica4Komande.h"
#include "GameOfThrons.h"
#include "Cetvrta Igra.h"
#include "NekoIme.h"
#include "Portal.h"
#include "Mordor.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int Avantura(int* glavniXP, IGRANJE* rekord, int najveciRekordIgre){
	
	PuniEkran(1);
	system("title Pohod");
	int glavniXPA = *glavniXP;
	int osvojeniXP, uslovOtkazi = 0;
	
	Load("Pohod loading..", 33);
	UsporeniIspisTeksta(100, "Gospodar Igre: A odlicno nova zrtva je stigla. Dobro dosli u igru vaseg zivota.\n               Moje ime je Gospodar Igre, od ovog trenutka pa sve do kraja igre vasa sudbina je u mojim rukama.\n");
	VremenskaPauza(5);
	OcistiEkran();
	IspisSlike("Avantura.txt");
	VremenskaPauza(5);
	OcistiEkran();
	UsporeniIspisTeksta(100, "Gospodar Igre: Pravila igre su sledeca:\n\n	Birate jednu od cetiri ponudjene opcije, unosom broja koji se nalazi ispred opcije.\n	Nakon toga igrica pocinje. Pred vama ce biti postavljen niz odluka.\n	Na osnovu vase odluke igrica ce napredovati u razlicitim smjerovima.\n");
	UsporeniIspisTeksta(100, "	Vas cilj je da dodjete do kraja price.\n	Upamtite da u slucaju donosenja pogresnih odluka postoji sansa da izgubite sve bodove sa profila.\n	Ukoliko zelite da napustite igru, prije nego sto se igra zavrsila, umjesto odgovora unesite KRAJ.\n	Ukoliko zelite da otkazete igru, umjesto odgovora unesite OTKAZI.\n\n	Neka igra pocne!\n\n\n\n");
	printf("		1. Game Of Throns\n");
	printf("		2. Portal\n");
	printf("		3. Mordor\n");
	printf("		4. Neko Ime\n");

	int izbor, mim;
	do {
		izbor = UcitajOdgovor();
	} while (izbor != 1 && izbor != 2 && izbor != 3 && izbor != 4 && izbor != -2 && izbor != -3);

	if (izbor == 1) {
		Hahahaha();
		mim = GOTPohod(&glavniXPA, najveciRekordIgre, &osvojeniXP, 1);
		if (mim == -3) {
			uslovOtkazi = 1;
		}
		else {
			Slika(mim);
		}
	}
	else if (izbor == 2) {
		Hahahaha();
		mim = Portal(&glavniXPA, najveciRekordIgre, &osvojeniXP, 1);
		if (mim == -3) {
			uslovOtkazi = 1;
		}
		else {
			Slika(mim);
		}
	}
	else if (izbor == 3) {
		Mordor(&glavniXPA, najveciRekordIgre, &osvojeniXP);
	}
	else if (izbor == 4) {
		UsporeniIspisTeksta(100, "Gospodar Igre: Molim vas ne cinite ovo. Vi pravite veliku gresku. Vratite se nazad.\nDa li ce te nastaviti dalje?\n");
		DaNe("HORIZONTALNO");
		int odgovor = UcitajOdgovor();
		if (odgovor == 1) {
			UsporeniIspisTeksta(100, "Gospodar Igre: Zastooo! Zastoooo!\n");
			VremenskaPauza(3);
			NekoIme(&glavniXPA, najveciRekordIgre, &osvojeniXP);
		}
		else if (izbor == -2) {
			return 0;
		}
		else if (izbor == -3) {
			uslovOtkazi = 1;
		}
		else {
			UsporeniIspisTeksta(100, "Gospodar Igre: Napravili ste dobar izbor.\n");
		}
	}
	else if (izbor == -2) {
		return 0;
	}
	else if (izbor == -3) {
		uslovOtkazi = 1;
	}

	if (uslovOtkazi == 1) {
		ADIgru(0, rekord); // Deaktivacija igre
	}

	*glavniXP = glavniXPA;
	rekord->bodoviUIgri = osvojeniXP;
	
	return 0;
}
void Hahahaha(){
	OcistiEkran();
	UsporeniIspisTeksta(100, "Gospodar Igre: \n\n");
	VremenskaPauza(1);
	IspisSlike("You shall not pass.txt");
	VremenskaPauza(3);
}
void Slika(int mim){
	VremenskaPauza(10);
	OcistiEkran();
	if(mim == 1){
		printf("Gospodar Igre:\n");
		IspisSlike("Pikacu.txt");
	} else{
		IspisSlike("Ha Ha.txt");
		UsporeniIspisTeksta(100, "Gospodar Igre: Rekao sam vam.\n");
	}
	VremenskaPauza(10);
	OcistiEkran();
}
