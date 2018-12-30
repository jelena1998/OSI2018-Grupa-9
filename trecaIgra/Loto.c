#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>
#include "Loto.h"

int VecPostoji(int niz[], int n, int broj) { 
	int i;
	for (i = 0; i < n; i++) {
		if (niz[i] == broj)   
			return 0;
	}
	return 1;
}

void Izvlacenje(int loto[]) {
	srand(time(0));
	int i = 0, broj;
	while (i < BROJ_IZVLACENJA) {
		broj = rand() % LOTO_BROJEVI;
		if (VecPostoji(loto, BROJ_IZVLACENJA, broj)) {
			loto[i] = broj;
			i++;
		}
	}
}

void Tiket(int korisnik[]) { //korisnik unosi svoje brojeve

	int i,broj;
	printf("Unesite 7 brojeva da popunite vas tiket\n");
	printf("Vasi brojevi moraju biti u rasponu od 1 do 45\n");
	for (i = 0; i < TIKET_SIZE; i++)
	{
		printf("Unesite broj-> ");
		scanf("%d", &broj);
		int a = VecPostoji(korisnik,TIKET_SIZE, broj);
		while (broj < 1 || broj>45 || !a)
		{
			printf("Greska! Broj nije u zadanom opsegu ili je vec ranije unesen\n");
			printf("Unesite broj-> ");
			scanf("%d", &broj);
			a = VecPostoji(korisnik,TIKET_SIZE, broj);
		}
		korisnik[i] = broj;
	}
}

void BrojPogodaka(int loto[], int korisnik[], int* poeni) { //broji koliko pogodaka ima
	int pogodak = 0, i, j,*pogodci;
	pogodci = (int*)calloc(TIKET_SIZE,sizeof(int));
	*poeni = 0;
	for (i = 0; i < BROJ_IZVLACENJA; i++) {
		for (j = 0; j < TIKET_SIZE; j++) {
			if (loto[i] == korisnik[j]) {
				pogodci[pogodak++] = loto[i];
				int t = j;
				*poeni += (t + 1) * 10;
			}
		}
	}
	printf("Broj pogodaka je: %d\n", pogodak);
	PisiNiz(pogodci, pogodak, 0);		//pogodjeni brojevi
	free(pogodci);
}


void PisiNiz(int niz[], int n, int pauza) {
	int i;
	for (i = 0; i < n; i++) {
		Sleep(pauza*1000);
		printf("%d ", niz[i]);
	}
	Sleep(pauza * 1000);
	printf("\n");
}