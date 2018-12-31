#include"reglog.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int login() {
	system("cls");
	printf("Login\n\n");
	KORISNIK korisnik;
	FILE* file;
	char korisnickoIme[100], lozinka[100];
	char odrediste[100] = "Korisnici\\", eks[5] = ".dat";

	printf("Unesite korisnicko ime:\n->");
	scanf("%s", korisnickoIme);
	printf("Unesite lozinku:\n->");
	scanf("%s", lozinka);

	strcat(odrediste, korisnickoIme);
	strcat(odrediste, eks);

	file = fopen(odrediste, "rb");
	if (file == NULL) {
		printf("Korisnicko ime ne postoji u bazi podataka\nMolimo da se registrujete.\n");
		return 0;
	}
	
	fread(&korisnik, sizeof(KORISNIK), 1, file);
	
	//poslije pronalazenja korisnika i citanja podataka provjerava se identicnost unijetih podataka
	if (!strcmp(korisnik.korisnickoIme, korisnickoIme)) { 
		if (!strcmp(korisnik.lozinka, lozinka)) {

				printf("Dobrodosli %s na platformu.\nVasi bodovi su: %d.\n", korisnik.korisnickoIme, korisnik.bodovi);
			return 1;
		}
	}

	return 0;
}

int reg() {
	system("cls");
	printf("Registracija\n");

	KORISNIK korisnik;
	FILE* file;
	char korisnickoIme[100], lozinka[100];
	char odrediste[100] = "Korisnici\\", eks[5] = ".dat";

	do {
		printf("Unesite korisnicko ime(MIN: 3,MAX 10 karaktera):\n->");
		scanf("%s", korisnickoIme);
	} while (strlen(korisnickoIme) > 10 || strlen(korisnickoIme) < 3);
	do {
		printf("Unesite password(MIN: 6 MAX: 15 karaktera):\n->");
		scanf("%s", lozinka);
	} while (strlen(lozinka) > 15 || strlen(lozinka) < 5);
	strcat(odrediste, korisnickoIme);
	strcat(odrediste, eks);

	file = fopen(odrediste, "rb");
	if (file != NULL) {
		printf("Korisnicko ime postoji\n");
		fclose(file);
		return 0;
	}

	strcpy(korisnik.korisnickoIme, korisnickoIme);
	strcpy(korisnik.lozinka, lozinka);
	korisnik.bodovi = 10; //svi novi korisnici dobijaju po 10 bodova

	file = fopen(odrediste, "wb");
	fwrite(&korisnik, sizeof(KORISNIK), 1, file); //upisivanje podataka
	fclose(file);
	return 1;
}
