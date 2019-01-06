#include "Kljuc.h"

int KreirajKljuc() {
	Sleep(1000);        //koristi se da bi se smanjila mogucnost kreiranja istog kljuca
	int i;
	KLJUC k;
	FILE* f = fopen("kljuc.csv", "a+");
	if (f == NULL) { printf("greska pri otvaranju datoteke!"); return 0; }
	srand(time(NULL));
	k.kljuc[19] = 0;
	for (i = 0; i < 19; i++)
		k.kljuc[i] = '0' + rand() % 10;
	k.kljuc[4] = k.kljuc[9] = k.kljuc[14] = '-';
	//printf("Kljuc je kreiran: %s\n", k.kljuc);
	if (!Provjeri(k.kljuc, f)) {
		k.redniBroj = Index(f);
		fprintf(f, "%d;%s;\n", k.redniBroj, k.kljuc);
	}
	else {
		fclose(f);
		KreirajKljuc();
	}
	fclose(f);
	return k.redniBroj;
}

int Provjeri(char* kljuc, FILE* file) {
	char niz[21];
	int rb;
	while (fscanf(file, "%d;%s", &rb, niz) != EOF) {
		niz[19] = 0;
		if (!strcmp(kljuc, niz))
			return 1;
	}
	return 0;
}

int Index(FILE* f) {
	int rb, i = 20;
	char c;
	if (ftell(f) == 0) return 1;		//ako nema kljuceva
	while ((c = fgetc(f)) != '\n') {
		fseek(f, -(i++), 2);
		if (ftell(f) == 0) break;		//ako postoji samo jedan kljuc
	}
	fscanf(f, "%d", &rb);
	fseek(f, 0, 2);
	return rb + 1;
}

void PisiKljuc(KORISNIK korisnik) {
	int i;
	KLJUC kljuc;
	for (i = 0; i < 4; i++) {
		kljuc = TraziKljuc(korisnik.indeksKljca[i]);
		printf("Kljuc za %d. igru: %s\n", i + 1, kljuc.kljuc);
	}
}

KLJUC TraziKljuc(int indeks) {
	int i;
	KLJUC kljuc = { 0,0 };
	char niz[21] = { 0 };
	FILE* f = fopen("kljuc.csv", "r");
	if (f == NULL) { printf("greska pri otvaranju datoteke!"); return kljuc; }
	for (i = 0; i < indeks; i++) {
		fscanf(f, "%d;%s", &kljuc.redniBroj, niz);
		niz[19] = 0;
		strcpy(kljuc.kljuc, niz);
	}
	fclose(f);
	return kljuc;
}

int Otkljucaj(KORISNIK korisnik, int a) {
	int i = 0;
	KLJUC kljuc;
	char niz[20] = { 0 }, c;
	printf("\nUnesi kljuc: ");
	while ((c = getchar()) != '\n')
		niz[i++] = c;
	if (i > 19) return 0;
	kljuc = TraziKljuc(korisnik.indeksKljca[a - 1]);
	return !strcmp(niz, kljuc.kljuc);
}