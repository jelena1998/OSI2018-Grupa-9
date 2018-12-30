#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//int pogodiBroj(int, int);
int pogodiBroj(int);
int main() {
	printf("\t\t\t***IGRA POGADJANJA BROJA***\n\n");
	printf("\tPravila:\n1. Unesite broj (0-100).\n2.Imate pravo na 5. pokusaja\n3.Poeni se racunaju 100/broj_pokusaja.\n\n\n");

	srand((unsigned int)time(NULL));
	
	int broj = rand() % 101;
	int broj_pokusaja = 0, p = 1;
	
	while (broj_pokusaja < 5 && p) {

		//printf("*%d\nPokusaj: %d\n", broj, broj_pokusaja+1);
		printf("Pokusaj: %d", broj_pokusaja + 1);
		p=pogodiBroj(broj);

		broj_pokusaja++;
	}
	if (!p)
		printf("Kraj igre\nOsvojeni poeni su: %.3lf\n", 100 / (double)broj_pokusaja);
	else
		printf("Vise srece drugi put!\n");
	return 0;
}

int pogodiBroj(int broj) {
	int unos;
	do {
		printf("\nUnesite broj (0-100)->");
		scanf("%d", &unos);
	} while (unos < 0 || unos > 100);

	if (broj == unos) {
		printf("Pogodili ste broj cestitamo\n");
		return 0;
	}

	printf("Broj je %s od unijetog broja\n", (unos < broj) ? "manji" : "veci");
	
	return 1;
}