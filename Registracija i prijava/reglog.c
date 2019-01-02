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
	int duzina;
	int p=0;

	do {
		printf("Unesite korisnicko ime(MAX 20 karaktera):\n->");
		scanf("%s", korisnickoIme);
		duzina = strlen(korisnickoIme); 
		p = provjeri(korisnickoIme); //provjera za ime
	} while (duzina > 20 || !p); //max unos 20 karaktera
	p = 0;
	do {
		printf("Unesite password(MIN: 6 MAX: 10 karaktera):\n->");
		scanf("%s", lozinka);
		duzina = strlen(lozinka);
		p = provjeri(lozinka); //provjera za lozinku
	} while (duzina < 6 || duzina > 10 || !p); //lozinka moze da ima min 6 karaktera i max 10 karaktera
	
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

int provjeri(char* korisnickoIme) {
	int brojac = 0, duzina = strlen(korisnickoIme);
	
	for (int i = 0; i < duzina; i++)
		if ((korisnickoIme[i] >= 65 && korisnickoIme[i] <= 90) || (korisnickoIme[i] >= 97 && korisnickoIme[i] <= 122) || (korisnickoIme[i] >= 48 && korisnickoIme[i] <= 57))
			brojac++;
	
	if (duzina == brojac)
		return 1;
	return 0;
}
