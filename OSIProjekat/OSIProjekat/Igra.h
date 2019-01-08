#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<Windows.h>
#include<time.h>



#define MAX 21

typedef struct tm* DATUM;

typedef struct korisnik {
	char korisnickoIme[MAX];
	char lozinka[MAX];
	int bodovi;
	int indeksKljca[4];
}KORISNIK;

typedef struct kljuc {
	int redniBroj;
	char kljuc[20];
}KLJUC;

typedef struct igranje {
	int sifraIgre;
	char korisnickoIme[MAX];	//ono je jedinstveno
	DATUM datum;					//datum otkljucavanja
	int aktivna;				// -1 ako igra nikada nije bila otkljucana  1/0 (aktivna/deaktivirana)
	int bodoviUIgri;
}IGRANJE;

int TraziIgranje(char[], int, IGRANJE*); //vraca adresu pocetka trazene linije
void ADIgru(int bool, IGRANJE*); //aktivira ili deaktivira igru
int Istekao(IGRANJE* igranje);		//provjerava da li je kljuc istekao#pragma once

int PristupiIgri(IGRANJE*, KORISNIK*);
void GlavniMeni(KORISNIK*);
void Snimi(IGRANJE*);
int cmp(const void * a, const void * b);

void ucitajPodatke(KORISNIK,int);