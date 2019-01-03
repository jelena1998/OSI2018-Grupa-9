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

	//ukoliko se unese nepostojece ime
	file = fopen(odrediste, "rb");
	if (file == NULL) {
		printf("Korisnicko ime ne postoji u bazi podataka\nMolimo da se registrujete.\n");
		return 0;
	}
	
	fread(&korisnik, sizeof(KORISNIK), 1, file); //citanje podataka
	
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
		p = provjeriIme(korisnickoIme); //provjera za ime
	} while (duzina > 20 || !p); //max unos 20 karaktera
	p = 0;

	do {
		printf("Unesite password(MIN: 6 MAX: 10 karaktera):\n->");
		scanf("%s", lozinka);
		duzina = strlen(lozinka);
		p = provjeriLozinku(lozinka); //provjera za lozinku
	} while (duzina < 6 || duzina > 10 || !p); //lozinka moze da ima min 6 karaktera i max 10 karaktera
	
	strcat(odrediste, korisnickoIme);
	strcat(odrediste, eks);

	//provjera da li korisnicko ime postoji
	file = fopen(odrediste, "rb");
	if (file != NULL) {
		printf("Korisnicko ime postoji\n");
		fclose(file);
		return 0;
	}

	//snimanje podataka
	strcpy(korisnik.korisnickoIme, korisnickoIme);
	strcpy(korisnik.lozinka, lozinka);
	korisnik.bodovi = 10;

	//upisivanje podataka u datoteku
	file = fopen(odrediste, "wb");
	fwrite(&korisnik, sizeof(KORISNIK), 1, file);
	fclose(file);

	return 1;
}

int provjeriIme(char* korisnickoIme) { //provjera ispravnosti korisnickogImena
	
	int brojac = 0;
	int duzina = strlen(korisnickoIme);
	
	for (int i = 0; i < duzina; i++)
		if ((korisnickoIme[i] >= 65 && korisnickoIme[i] <= 90) || (korisnickoIme[i] >= 97 && korisnickoIme[i] <= 122) || (korisnickoIme[i] >= 48 && korisnickoIme[i] <= 57))
			brojac++;
	
	if (duzina == brojac)
		return 1;
	printf("\nKoristite samo engleski alfabet i cifre max 20 karaktera\n");
	return 0;
}
int provjeriLozinku(char* lozinka) { //provjera ispravnosti lozinke
	
	int brojacSlova = 0;
	int brojacBrojeva = 0;
	int duzina = strlen(lozinka);

	for (int i = 0; i < duzina; i++) {

		if ((lozinka[i] >= 65 && lozinka[i] <= 90) || (lozinka[i] >= 97 && lozinka[i] <= 122))
			brojacSlova++;

		if ((lozinka[i] >= 48 && lozinka[i] <= 57))
			brojacBrojeva++;
	}

	if (brojacBrojeva + brojacSlova == duzina)
		if (brojacSlova && brojacBrojeva)
			return 1;
		else
			printf("\nLozinka se mora sastojati min 6, max 10 karaktera iz engleskog alfabeta i cifri (kombinovano)\n");
	else
		printf("\nDozvoljeno je koristiti samo engleski alfabet i cifre\n");
	return 0;
}