#include "Igrica4Komande.h"
#include "FunkcijeZaIspis.h"
#include <windows.h>
#include <stdio.h>
#include <time.h>

#include <stdlib.h>
#include <conio.h>
#include<time.h>
#include<ctype.h>
#include <process.h>

void UkloniIgracevXP(int* glavniXP){
		
	if (*glavniXP > 0) {
		*glavniXP = 0;
	}
}
void UkloniIgrice4XP(int* osvojeniXP){

	if (*osvojeniXP > 0) {
		*osvojeniXP = 0;
	}
}
int Dodaj_OduzmiXP(){
	int sansa =  Nasumicno(100);
	return (sansa < 40) ? 0 : 1;
}

void UgasiIgricu(int* glavniXP){
	UkloniIgracevXP(glavniXP);
	exit(1);
}
void IzadjiIzIgrice(int* glavniXP, int osvojeniXP){
	*glavniXP += osvojeniXP;
	// Napisati funkciju za povratak u glavni main tj. povratak u konzolu za biranje igrica
}
void NapustiIgricu(int* osvojeniXP){
	UkloniIgrice4XP(osvojeniXP);
	exit(1);
}

void OcistiEkran(){
	system("CLS");
}
void OcistiEkranPomjeranjem(){
	IspisiPrazanRed(50);
}
void PostaviVelicinuEkrana(int sirina, int visina){
	
	HWND hwnd = GetConsoleWindow();
	RECT rect = {0, 0, visina, sirina};
	MoveWindow(hwnd, rect.top, rect.left, rect.bottom-rect.top, rect.right-rect.left, TRUE);
}
void PuniEkran(int uslov){
	if(uslov == 1){
		system("mode con: cols=99 lines=44");
	}
	ShowWindow( GetConsoleWindow() , SW_MAXIMIZE);
}

void VremenskaPauza(int sekunde){
	unsigned int vrijeme = 1000 * sekunde;
	sleepM(vrijeme);
}

int Nasumicno(int max){
	return (rand() % max);
}
int UcitajOdgovor(){
	char odgovor[100];
	int prenos = -1;
	printf("Vas odgovor je: ");
	scanf("%s", odgovor);
	if(odgovor[0] == '0' || '1' || '2' || '3' || '4' || '5' || '6' || '7' || '8' || '9'){
		prenos = atoi(odgovor);
	} else{
		prenos = -1;
	}
	return prenos;
}
void ProvjeraOdgovora(int odgovor, int xp, int brOdgovora, int* osvojeniXP){
	if (odgovor > 0 && odgovor < brOdgovora + 1) {
		if (Dodaj_OduzmiXP()) {
			osvojeniXP += xp;
		} else {
			osvojeniXP -= xp;
		}
	}
}

int Pomoc(int* brojPomoci, char* tekst, int* glavniXP, int cijena){
	if(*brojPomoci < 2){
		printf("Da li zelite moju pomoc?\nAli budite oprezni imate pravo samo na dvije pomoci u igrici i svaka pomoc dolazi sa cijenom.\nRazmislite dobro prije nego sto potvrdite.\n");
		int dostupno = 2 - *brojPomoci;
		
		if(dostupno == 2){
			printf("Trenutno su vam dostupne 2 pomoci.\n\n");
		} else if(dostupno == 1){
			printf("Trenutno vam je dostupna 1 pomoc.\n\n");
		} else{
			printf("Nemate vise pravo na pomoc.");
		}
		
		DaNe("HORIZONTALNO");
		int odluka = UcitajOdgovor();
		
		if(odluka == 1){
			if((*glavniXP - cijena) >= 0){
				printf("%s", tekst);
				(*brojPomoci)++;
				*glavniXP -= cijena;
			} else{
				printf("Zao mi je, ali izgleda da nemate dovoljno bodova na svom profilu da bi ste mogli platiti pomoc.\n");
			}
		}
	}
}

void KordinateXY(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void sleepM(unsigned int milisekunde){
	clock_t vrijeme = milisekunde + clock();
	while (vrijeme > clock());
}
void Load(char* tekst, int x){
	int i, c;
	KordinateXY(x,14);
	printf("%s", tekst);
	KordinateXY(30,15);
	
	for(i = 1; i <= 20; i++){
		sleepM(200); // Usporava ispis karaktera
		printf("%c",177);
	}
	
	printf("\n\n\n                              Pritisni Enter.");
	
	char *ch;
	do{
		ch = fgetc(stdin);
	} while(ch != 0x0A);
	
	
	if(c == 0x0A){
		getch();
	}
	
	OcistiEkran();
}

