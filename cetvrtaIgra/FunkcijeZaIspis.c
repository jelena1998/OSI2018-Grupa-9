#include "FunkcijeZaIspis.h"
#include "Igrica4Komande.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>

void IspisTekstaSaPauzama(char* tekst) {
	
	if (strcmp(tekst, "=+=+=+=+=+=+=+=+=+=") == 1) {
		VremenskaPauza(5);
		printf("\n");
	}
	else {
		printf("%s", tekst);
	}
}
void UsporeniIspisTeksta(int milisekunde, char* tekst){
	
	int brojKaraktera = strlen(tekst), i;
	for(i = 0; i < brojKaraktera; i++){
		printf("%c", tekst[i]);
		sleepM(milisekunde);
	}
}
void IspisiPrazanRed(int brojRedova){
	while(brojRedova--){
		printf("\n");
	}
}
void IspisiKarakterVisePuta(char karakter, int broj, int redovi){

	for (; redovi > 0; redovi--) {
		int i;
		for (i = broj; i > 0; i--) {
			printf("%c", karakter);
		}
		printf("\n");
	}
}
void IspisGreskeONepravilnomUnosu(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    // Cuva trenutnu boji teksta u konzoli
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("\nKOMANDA KOJU STE UNJELI NE POSTOJI. MOLIM VAS UNESITE ISPRAVNU KOMANDU!\n\n");

    // Vraca prethodnu boju teksta u konzoli
    SetConsoleTextAttribute(hConsole, saved_attributes);
}
void SpecijalniIspis(char* tekst){
	printf("\n<<<<<<<<<< %s >>>>>>>>>>\n\n", tekst);
}

void IspisSlike(char* url) {

	FILE* slika;
	errno_t err = fopen_s(&slika, url, "r");

	if (err == 0) {

		char red[171];
		while (fgets(red, 171, slika)) {
			printf("%s", red);
		}
	}
	else {
		printf("Greska pri otvaranju tekstualne datoteke [Slika]'.\n");
	}

	fclose(slika);
	printf("\n");
}
void IspisPasosa(char* url) {

	FILE* pasos;
	errno_t err = fopen_s(&pasos, url, "r");

	if (err == 0) {

		char red[171];
		while (fgets(red, 171, pasos)) {
			IspisTekstaSaPauzama(red);
		}
	}
	else {
		printf("Greska pri otvaranju tekstualne datoteke [Pasosi].\n");
	}

	fclose(pasos);
	printf("\n");
}

void DaNe(char* orjentacija) {

	if (strcmp(orjentacija, "HORIZONTALNO") == 0) {
		printf("       1. DA             2. NE\n\n");
	}
	else if (strcmp(orjentacija, "VERTIKALNO") == 0) {
		printf("       1. DA\n");
		printf("       2. NE\n");
	}
	else {
		printf("GRESKA KOMANDA NIJE DEFINISANA u 'DaNe'.\n\n");
	}

}
void DvaIzbora(char* izbor1, char* izbor2, char* orjentacija) {

	if (strcmp(orjentacija, "HORIZONTALNO") == 0) {
		printf("       %s       %s\n\n", izbor1, izbor2);
	}
	else if (strcmp(orjentacija, "VERTIKALNO") == 0) {
		printf("       %s\n", izbor1);
		printf("       %s\n\n", izbor2);
	}
	else {
		printf("GRESKA KOMANDA NIJE DEFINISANA u 'DvaIzbora'.\n\n");
	}

}
void TriIzbora(char* izbor1, char* izbor2, char* izbor3, char* orjentacija) {

	if (strcmp(orjentacija, "HORIZONTALNO") == 0) {
		printf("       %s       %s       %s\n\n", izbor1, izbor2, izbor3);
	}
	else if (strcmp(orjentacija, "VERTIKALNO") == 0) {
		printf("       %s\n", izbor1);
		printf("       %s\n", izbor2);
		printf("       %s\n\n", izbor3);
	}
	else {
		printf("GRESKA KOMANDA NIJE DEFINISANA u 'TriIzbora'.\n\n");
	}

}
void CetiriIzbora(char* izbor1, char* izbor2, char* izbor3, char* izbor4, char* orjentacija) {

	if (strcmp(orjentacija, "HORIZONTALNO") == 0 || strcmp(orjentacija, "VERTIKALNO") == 0) {
		DvaIzbora(izbor1, izbor2, orjentacija);
		DvaIzbora(izbor3, izbor4, orjentacija);
	}
	else {
		printf("GRESKA KOMANDA NIJE DEFINISANA u 'CetiriIzbora'.\n\n");
	}

}
