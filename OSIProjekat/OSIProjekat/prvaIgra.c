#include "PrvaIgra.h"

void IgrajPrvuIgru(KORISNIK* korisnik) {
	printf("\t\t\t***IGRA POGADJANJA BROJA***\n\n");
	printf("\tPravila:\n1. Unesite broj (0-100).\n2.Imate pravo na 5. pokusaja\n3.Poeni se racunaju 100/broj_pokusaja.\n\n\n");

	srand((unsigned int)time(NULL));

	int broj = rand() % 101;
	int pokusaj = 0, p = 1;
	int izgubi = 1;
	/*dodati nacin racunanja bodova kada se sve spoji u jedno...*/

	if (!izgubi) {

		while (pokusaj < BROJ_POKUSAJA && p) {

			printf("Pokusaj: %d", pokusaj + 1);
			p = PogodiBroj(broj);
			pokusaj++;
		}
		if (!p)
			printf("Kraj igre\nOsvojeni poeni su: %.3lf\n", 100 / (double)pokusaj);
		else
			printf("Vise srece drugi put!\n");

		printf("Trazeni broj je: %d\n", broj);
	}
	else
		Izgubi();
}

int PogodiBroj(int broj) {
	int unos, p = 0;
	char c;
	do {
		printf("\nUnesite broj (0-100)->");
		scanf("%d", &unos);
		while ((c = getchar()) != EOF && c != '\n');
	} while (unos < 0 || unos > 100 || p);

	if (broj == unos) {
		printf("Pogodili ste broj cestitamo\n");
		return 0;
	}
	printf("Broj je %s od unijetog broja\n", (unos > broj) ? "manji" : "veci");
	return 1;
}


//funkcija uvijek bira siri opseg izmedju (min,unos) i (unos,max), azurira min i max po potrebi
//i na kraju u posljednjem opsegu (min,max) bira nasumican broj

void Izgubi() {
	int unos, i, min = 0, max = 100, maxp, minp,pokusaj = 0;
	char c;
	for (i = 0; i < 5; i++) {
		do {
			printf("Pokusaj: %d", pokusaj + 1);
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
		pokusaj++;
	}
	unos = rand() % (max - min - 1);
	printf("Kraj igre\nOsvojeni poeni su: 0\n");
	printf("Vise srece drugi put!\nTrazeni broj je %d", min + unos + 1);
}