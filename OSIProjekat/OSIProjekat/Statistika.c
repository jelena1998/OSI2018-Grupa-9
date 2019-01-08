#include"Statistika.h"

#include"reglog.h" //zbog obrisiBafer()

void PrikazStatistike(KORISNIK* korisnik) {
	int izbor, i;
	int p = 0;

	do {
		system("cls");
		printf("Za koju igru zelite statistiku?\n Unesite brojeve (1-4) ili 5 za sve ");
		scanf("%d", &izbor);
	} while (!obrisiBafer() || izbor < 1 || izbor > 5);

	system("cls");
	if (izbor <= 4 && izbor >= 1) {
		PisiStatistiku(*korisnik, izbor);
		return;
	}
	if (izbor == 5) {
		for (i = 1; i < 5; i++)
			PisiStatistiku(*korisnik, i);
		return;
	}

	//printf("Pogresan unos. Bicete vraceni na glavni meni.\n");
	Sleep(1500);
	GlavniMeni(korisnik);
}

void PisiStatistiku(KORISNIK korisnik, int igra) {
	FILE* f;
	TABELA tabela;
	char odrediste[50] = "Korisnici\\", pom[10] = "0.csv", i=0;
	strcat(odrediste, korisnik.korisnickoIme);
	pom[0] += igra;
	strcat(odrediste, pom);
	f = fopen(odrediste, "r");
	if (f == NULL) { printf("greska pri otvaranju datoteke!"); return; }
	printf("\t\tStatistika za %d. igru\n", igra);
	printf("     %-8s %-11s %-12s %-s\n", "Ime", "Igra", "Datum", "bodovi");
	while (fscanf(f, "%d;%d.%d.%d.;%d\n", &tabela.igra, &tabela.dan, \
		&tabela.mjesec, &tabela.godina, &tabela.bodovi) != EOF) {
		i++;
		printf("%-4d %-10s %-7d %d. %d. %-4d. %-4s %-d\n", i,korisnik.korisnickoIme, \
			tabela.igra, tabela.dan, tabela.mjesec, tabela.godina,"",tabela.bodovi);
	}
	printf("\n");
	fclose(f);
}

void Snimi(IGRANJE* igranje) {
	int i = 0, n, izbor;
	char c, odrediste[50] = "Korisnici\\", pom[10] = "0.csv";
	FILE* f;
	TABELA niz[11] = { 0 };			//maksimalno ih je 10 u datoteci + 1 koji se upisuje
	printf("Zelite li snimiti rezultat?	DA[1] NE[0] ");
	do {
		scanf("%d", &izbor);
		while ((c = getchar()) != EOF && c != '\n');
	} while (izbor != 1 && izbor != 0);
	if (izbor == 0) return;
	strcat(odrediste, igranje->korisnickoIme);
	pom[0] += igranje->sifraIgre;
	strcat(odrediste, pom);
	f = fopen(odrediste, "r+");	//prvo ucitavamo sve podatke
	if (f == NULL) { printf("Greska pri otvaranju datoteke!"); return; }
	while (fscanf(f, "%d;%d.%d.%d.;%d\n", &niz[i].igra, &niz[i].dan, \
		&niz[i].mjesec, &niz[i].godina, &niz[i].bodovi) != EOF)
		i++;
	niz[i].igra = igranje->sifraIgre;
	niz[i].dan = igranje->datum->tm_mday;
	niz[i].mjesec = igranje->datum->tm_mon;
	niz[i].godina = igranje->datum->tm_year;
	niz[i].bodovi = igranje->bodoviUIgri;
	n = i + 1;
	qsort(niz, n, sizeof(TABELA), cmp);
	rewind(f);
	if (n == 11) n = 10;	//upisuje se 10 najboljih
	for (i = 0; i < n; i++)
		fprintf(f, "%d;%d.%d.%d.;%d\n", niz[i].igra, niz[i].dan, \
			niz[i].mjesec, niz[i].godina, niz[i].bodovi);
	fclose(f);
}

int cmp(const void * a, const void * b) {
	return ((TABELA*)b)->bodovi - ((TABELA*)a)->bodovi;
}
