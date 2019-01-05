#include <stdio.h>
#include "PrvaIgra.h"
#include "DrugaIgra.h"
#include "TrecaIgra.h"
#include "Cetvrta Igra.h"
#include "reglog.h"


void pocetnaStranica();


int main() {
	/*Podaci za test: korisnicko ime: ognjen  lozinka: ognjen123*/
	
	pocetnaStranica(); //pozivanje pocetne strane
	
	//za potrebe Avantura()
	int bodovi = 0;
	char sifra[10] = { "123456789" };

	int izbor;
	int p = 0;
	char c;
	printf("Ukolliko nemate nalog molimo da se registrujete\nUkoliko ste vec registrovani prijavite se na sistem\n\n");
	do {
		printf("1.Registracija\n2.Prijava\n->");
		scanf("%d", &izbor);
		obrisiBafer(); //ocistimo bafer 

		switch (izbor) {
		case 1:
			reg(); 
			break;
		case 2: 
			if (login())
				p = 1;
			else {
				printf("Neuspjesna prijava\n");
				p = 0;
			}
			break;
		default: printf("Pogresan unos.\n");
		}

	} while (izbor < 1 || izbor > 2 || !p);

	//if (!p) return; //u slucaju da proba nastaviti ako nije prijavljen

	izbor = 0;

	do {
		printf("\n1 Igra pogadjanja\n2 Kviz\n3 Loto\n4 Pohod\n5 Izlaz\n");
		scanf("%d", &izbor);
		while ((c = getchar()) != EOF && c != '\n');
		//obrisiBafer(); // ocistimo bafer
		switch(izbor) {
		case 1: IgrajPrvuIgru(); break;
		case 2: IgrajDruguIgru(); break;
		case 3: IgrajTrecuIgru(); break;
		case 4: Avantura(&bodovi, sifra); break;
		default: printf("Pogresan unos!!"); break;
		}
	} while (izbor != 5);
	return 0;
}


void pocetnaStranica() {
	system("title Platforma za igre - POHOD");
	printf("\n\n\n\n\n\n\n\n\n\t\t\tDOBRODOSLI NA PLATFORMU ZA IGRE\n\t\t\t\t  \"POHOD\"\n\n");
	printf("\t\t\t\tUcitavanje igre\n\n\t\t\t");
	for (int i = 0; i < 16; i++) {
		Sleep(500);
		printf("%c ", 177);
	}
	Sleep(3000);
	system("cls");
}
