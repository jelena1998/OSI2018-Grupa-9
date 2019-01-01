#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<Windows.h>
#include<time.h>
void pisiKljuc();
int provjeri(char*, FILE*);
int index(FILE* f);

int main()
{
	int a;
	do {
		scanf("%d", &a);
		pisiKljuc();
	} while (a != 0);
	system("pause");
	return 0;
}

void pisiKljuc() {
	Sleep(1000);        //koristi se da bi se smanjila mogucnost kreiranja istog kljuca
	int i;
	FILE* f = fopen("kljuc.csv", "a+");
	if (f == NULL) { printf("greska pri otvaranju datoteke!"); return; }
	char kljuc[21];
	srand(time(NULL));
	kljuc[19] = ';';
	kljuc[20] = '\0';
	for (i = 0; i < 19; i++)
		kljuc[i] = '0' + rand() % 10;
	kljuc[4] = kljuc[9] = kljuc[14] = '-';
	printf("Kljuc je kreiran: %s\n", kljuc);
	if (!provjeri(kljuc, f)) {
		int rb = index(f);
		fprintf(f, "%d;%s\n",rb, kljuc);
	}
	else {
		fclose(f);
		pisiKljuc();
	}
	fclose(f);
}

int provjeri(char* kljuc, FILE* file) {
	char niz[21];
	int rb;
	while (fscanf(file, "%d;%s", &rb,niz) != EOF) {
		if (!strcmp(kljuc, niz))
			return 1;
	}
	return 0;
}

int index(FILE* f) {
	int rb, i = 20;
	char c;
	if (ftell(f) == 0) return 1;		//ako nema kljuceva
	while ((c = fgetc(f)) != '\n') {
		fseek(f, -(i++), 2);
		if (ftell(f) == 0) break;		//ako postoji samo jedan kljuc
	}
	fscanf(f,"%d", &rb);
	fseek(f, 0, 2);
	return rb+1;
}










