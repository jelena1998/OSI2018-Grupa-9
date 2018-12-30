#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>
#include"Loto.h"
void Kombinacije(int m);
int main() {
	//za testiranje funkcija
	int loto[20] = { 0 };
	int korisnik[7] = { 0 };
	int poeni,ulozeno = 100;
	Izvlacenje(loto); //sistem generise 20 brojeva za loto
	Tiket(korisnik); //korisnik unosi 7 brojeva
	system("cls");
	PisiNiz(korisnik, TIKET_SIZE, 0);
	PisiNiz(loto, BROJ_IZVLACENJA, 1);
	BrojPogodaka(loto, korisnik, &poeni);
	printf("Osvojili ste ukupno %d bodova u ovoj igri\n", poeni);
	system("pause");
	return 0;
}











