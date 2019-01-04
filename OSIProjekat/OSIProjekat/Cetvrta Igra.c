#include "FunkcijeZaIspis.h"
#include "Igrica4Komande.h"
#include "GameOfThrons.h"
#include "Cetvrta Igra.h"
#include "NekoIme.h"
#include "Portal.h"
#include "Mordor.h"
#include <string.h>
#include <stdio.h>

int Avantura(int* glavniXP, char* sifra){
	
	PuniEkran(1);
	system("title Avantura");
	int glavniXPA = *glavniXP;
	int dozvola = ProvjeraSifre(sifra);
	
	if(dozvola == 0){
		Load("Avantura loading..", 31);
		UsporeniIspisTeksta(100, "Gospodar Igre: A odlicno nova zrtva je stigla. Dobro dosli u igru vaseg zivota.\n               Moje ime je Gospodar Igre, od ovog trenutka pa sve do kraja igre vasa sudbina je u mojim rukama.\n");
		VremenskaPauza(5);
		OcistiEkran();
		IspisSlike("Avantura.txt");
		VremenskaPauza(5);
		OcistiEkran();
		UsporeniIspisTeksta(100, "Gospodar Igre: Pravila igre su sledeca:\n\n	Birate jednu od cetiri ponudjene opcije, unosom broja koji se nalazi ispred opcije.\n	Nakon toga igrica pocinje. Pred vama ce biti postavljen niz odluka.\n	Na osnovu vase odluke igrica ce napredovati u razlicitim smjerovima.\n");
		UsporeniIspisTeksta(100, "	Vas cilj je da dodjete do kraja price.\n	Upamtite da u slucaju donosenja pogresnih odluka postoji sansa da izgubbite sve bodove sa profila.\n\n	Neka igra pocne!\n\n\n\n");
		printf("		1. GameOfThrons\n");
		printf("		2. Portal\n");
		printf("		3. Mordor\n");
		printf("		4. NekoIme\n");
		
		int izbor, mim;
		do{
			izbor = UcitajOdgovor();
		} while(izbor != 1 && izbor != 2 && izbor != 3 && izbor != 4);
		
		if(izbor == 1){
			Hahahaha();
			mim = GOTPohod(&glavniXPA);
			Slika(mim);
		} else if(izbor == 2){
			Hahahaha();
			mim = Portal(&glavniXPA);
			Slika(mim);
		} else if(izbor == 3){
			mim = Mordor(&glavniXPA);
		} else if(izbor == 4){
			UsporeniIspisTeksta(100, "Gospodar Igre: Molim vas ne cinite ovo. Vi pravite veliku gresku. Vratite se nazad.\nDa li ce te nastaviti danje?\n");
			DaNe("HORIZONTALNO");
			int odgovor = UcitajOdgovor();
			if(odgovor == 1){
				UsporeniIspisTeksta(100, "Gospodar Igre: Zastooo! Zastoooo!\n");
				VremenskaPauza(3);
				NekoIme(&glavniXPA);
			} else{
				UsporeniIspisTeksta(100, "Gospodar Igre: Napravili ste dobar izbor.\n");
			}
		}
		
		*glavniXP = glavniXPA;
		
		return 1;
	}
	
	return 0;
}
int ProvjeraSifre(char* sifra){
	return strcmp("123456789", sifra);
}
void Hahahaha(){
	OcistiEkran();
	UsporeniIspisTeksta(100, "Gospodar Igre: Vi necete prezivjeti.\n");
	VremenskaPauza(3);
	IspisSlike("You shall not pass.txt");
	VremenskaPauza(3);
}
void Slika(int mim){
	VremenskaPauza(10);
	OcistiEkran();
	if(mim == 0){
		printf("Gospodar Igre:\n");
		IspisSlike("Pikacu.txt");
	} else{
		IspisSlike("Ha Ha.txt");
		UsporeniIspisTeksta(100, "Gospodar Igre: Rekao sam vam da ce te umrijeti.\n");
	}
	VremenskaPauza(10);
	OcistiEkran();
}
