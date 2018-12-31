#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>
#include"Loto.h"

int main() {
	//za testiranje funkcija
	int loto[20] = { 0 };
	int korisnik[7] = { 0 };
	int poeni,max,izgubljeniPoeni;
	printf("Unesi broj izgubljenih poena: ");
	scanf("%d", &izgubljeniPoeni);
	max = izgubljeniPoeni - izgubljeniPoeni * 0.4;	
	printf("Maksimalan broj poena koji je moguce osvojiti u igri je %d\n", max);
	Tiket(korisnik);								//korisnik unosi 7 brojeva
	Izvlacenje(loto,korisnik,max);					//sistem generise 20 brojeva za loto
	//system("cls");
	PisiNiz(korisnik, TIKET_SIZE, 0);
	PisiNiz(loto, BROJ_IZVLACENJA, 1);
	BrojPogodaka(loto, korisnik, &poeni);
	printf("Osvojili ste ukupno %d bodova u ovoj igri\n", poeni);
	system("pause");
	return 0;
}











