#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int provjeri();
int pogodiBroj(int);
void Izgubi();

int main() {
	printf("\t\t\t***IGRA POGADJANJA BROJA***\n\n");
	printf("\tPravila:\n1. Unesite broj (0-100).\n2.Imate pravo na 5. pokusaja\n3.Poeni se racunaju 100/broj_pokusaja.\n\n\n");

	srand((unsigned int)time(NULL));
	
	int broj = rand() % 101;
	int broj_pokusaja = 0, p = 1;
	int izgubi = 0; 
	/*dodati nacin racunanja bodova kada se sve spoji u jedno...*/

	if(!izgubi){

		while (broj_pokusaja < 5 && p) {

			printf("Pokusaj: %d", broj_pokusaja + 1);
			p=pogodiBroj(broj);

			broj_pokusaja++;
		}
		if (!p)
			printf("Kraj igre\nOsvojeni poeni su: %.3lf\n", 100 / (double)broj_pokusaja);
		else
			printf("Vise srece drugi put!\n");
	
		printf("Broj koji se trazio je: %d\n", broj);
	}else
		Izgubi();

	return 0;
}

int pogodiBroj(int broj) {
	int unos,p=0;
	do {
		printf("\nUnesite broj (0-100)->");
		scanf("%d", &unos);
		p = provjeri();
	} while (unos < 0 || unos > 100 || p);

	if (broj == unos) {
		printf("Pogodili ste broj cestitamo\n");
		return 0;
	}
	printf("Broj je %s od unijetog broja\n", (unos > broj) ? "manji" : "veci");
	return 1;
}

int provjeri() {
	char next;
	if ((next = getchar()) != EOF && next != '\n') {
		do
			next = getchar();
		while (next != EOF && next != '\n');
		return 1; //neispravan unos podataka
	}
	return 0; //ispravan unos podataka
}

//funkcija za gubiti...
void Izgubi() {
	int unos, i, min = 0, max = 100, maxp, minp;
	char c;
	for (i = 0; i < 5; i++) {
		do {
			printf("\nUnesite broj (0-100)->");
			scanf("%d", &unos);
			while ((c = getchar()) != EOF && c != '\n');		//za slucajan unos znaka ili stringa
		} while (unos < 0 || unos > 100);
		if (max - unos > unos - min) {
			minp = unos;
			if (minp > min) min = minp;
			printf("Broj je %s od unijetog broja\n", "veci");
		}
		else {
			maxp = unos;
			if (maxp < max) max = maxp;
			printf("Broj je %s od unijetog broja\n", "manji");
		}
		//     printf("min %d i max %d\n",min,max);
	}
	unos = rand() % (max - min - 1);
	printf("Vise srece drugi put!\nTrazeni broj je %d", min + unos + 1);
}