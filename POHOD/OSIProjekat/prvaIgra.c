#include "PrvaIgra.h"

void Pobijedi(IGRANJE* igranje) {
	int unos, i, min = 0, max = 100, maxp, minp, pokusaj;
//	char c;
	printf("\t\t\t***IGRA POGADJANJA BROJA***\n\n");
	printf("\tPravila:\n1. Unesite broj (0-100).\n2. Imate pravo na 5 pokusaja\n"
	"3. Poeni se racunaju 100/broj_pokusaja.\n4. Za otkazivanje igre unesite 'OTKAZI'\n\n\n");

	srand((unsigned int)time(NULL));
	pokusaj = rand() % 5 + 1;		//u kojem pokusaju ce korisnik pobijediti
	for (i = 0; i < 5; i++) {
		do {
			printf("Pokusaj: %d", i + 1);
			printf("\nUnesite broj (0-100)->");
			scanf("%d", &unos);
			if (Otkazi(igranje)) return;
		} while (unos < 0 || unos > 100);
		if (max - unos > unos - min) {
			minp = unos;
			if (minp > min) min = minp;
			if (!((i + 1 >= pokusaj) && (unos >= min) && (unos <= max)))
			printf("Broj je %s od unijetog broja\n", "veci");
		}
		else {
			maxp = unos;
			if (maxp < max) max = maxp;
			if (!((i + 1 >= pokusaj) && (unos >= min) && (unos <= max)))
			printf("Broj je %s od unijetog broja\n", "manji");
		}
		//     printf("min %d i max %d\n",min,max);
		if ((i+1 >= pokusaj) && (unos >= min) && (unos <= max)) { 
			igranje->bodoviUIgri = 100 / pokusaj;
			printf("Kraj igre\nOsvojeni poeni su: %d\n", 100/pokusaj);
			printf("Trazeni broj je: %d\n", unos);
			return;
		}
	}
	unos = rand() % (max - min - 1);
	printf("Kraj igre\nOsvojeni poeni su: 0\n");
	printf("Vise srece drugi put!\nTrazeni broj je %d\n", min + unos + 1);
}



void IgrajPrvuIgru(IGRANJE* igranje,int izgubi) {
	printf("\t\t\t***IGRA POGADJANJA BROJA***\n\n");
	printf("\tPravila:\n1. Unesite broj (0-100).\n2. Imate pravo na 5 pokusaja\n"
		"3. Poeni se racunaju 100/broj_pokusaja.\n4. Za otkazivanje igre unesite 'OTKAZI'\n\n\n");

	srand((unsigned int)time(NULL));

	int broj = rand() % 101;
	int pokusaj = 0, p = 1, poeni = 0;
	/*dodati nacin racunanja bodova kada se sve spoji u jedno...*/

	if (!izgubi) {

		while (pokusaj < BROJ_POKUSAJA && p) {

			printf("Pokusaj: %d", pokusaj + 1);
			p = PogodiBroj(broj,igranje);
			pokusaj++;
		}
		if (p == -1) return;
		if (!p) {
			poeni = 100 / pokusaj;
			printf("Kraj igre\nOsvojeni poeni su: %d\n", poeni);
		}
		else {
			printf("Kraj igre\nOsvojeni poeni su: 0\n");
			printf("Vise srece drugi put!\n");
		}
		printf("Trazeni broj je: %d\n", broj);
	}
	else 
		Izgubi(igranje);
	igranje->bodoviUIgri = poeni;
}

int PogodiBroj(int broj,IGRANJE* igranje) {
	int unos, p = 0;
//	char c;
	do {
		printf("\nUnesite broj (0-100)->");
		scanf("%d", &unos);
		if (Otkazi(igranje)) return -1;
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

void Izgubi(IGRANJE* igranje) {
	int unos, i, min = 0, max = 100, maxp, minp,pokusaj = 0;
//	char c;
	for (i = 0; i < 5; i++) {
		do {
			printf("Pokusaj: %d", pokusaj + 1);
			printf("\nUnesite broj (0-100)->");
			scanf("%d", &unos);
			if (Otkazi(igranje)) return;
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
	printf("Vise srece drugi put!\nTrazeni broj je %d\n", min + unos + 1);
}