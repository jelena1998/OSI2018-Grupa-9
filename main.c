#include <stdio.h>
#include "PrvaIgra.h"
#include "DrugaIgra.h"
#include "TrecaIgra.h"

int main() {
	int izbor;
	char c;
	//registracija,logovanje
	do {
		printf("1 Igra pogadjanja\n2 Kviz\n3 Loto\n4 Pohod\n5 Izlaz\n");
		scanf("\n%d", &izbor);
		while ((c = getchar()) != EOF && c != '\n');
		switch(izbor) {
		case 1: IgrajPrvuIgru(); break;
		case 2: IgrajDruguIgru(); break;
		case 3: IgrajTrecuIgru(); break;
		case 4: break;
		default: printf("Pogresan unos!!"); break;
		}
	} while (izbor != 5);
	return 0;
}
