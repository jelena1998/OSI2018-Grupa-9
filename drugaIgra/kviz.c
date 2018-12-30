#include"kviz.h"

int TacanOdgovor(PITANJE *pitanje, int odgovor)
{
	return pitanje->tacanOdgovor == odgovor;
}


int UporediNiz(int niz1[5], int niz2[5], int j) //pomocna: NasumicniBrojevi
{
	int i;
	for (i = 0; i < 5; i++) {
		if (niz1[j] == niz2[i])
			return 1;
		else if (niz1[j] == 0 || niz1[i] == 0)
			break;
	}
	return 0;
}

void NasumicniBrojevi(int* randomNovi, int max, int min) //nekad nece da radi
{
	//time_t t;
	int i, randomStari[5] = { 0 };
	//srand((unsigned)time(&t));
	srand(time(0));
	for (i = 0; i < 5; i++)
	{
		randomNovi[i] = rand() % (max + 1 - min) + min;
		while (UporediNiz(randomNovi, randomStari, i))
			randomNovi[i] = rand() % (max + 1 - min) + min;
		//printf("%d ", randomNovi[i]); //ispisuje brojeve
		randomStari[i] = randomNovi[i];
	}
}

void OdaberiPitanja(PITANJE* pitanja, FILE* file)
{
	char *pom, b[2];
	int duzina;
	int znak, linija, i = 0, j, k, broj, brojPitanja;
	int nizBrojeva[5] = { 0 };
	while ((brojPitanja = fgetc(file)) != '\n')
	{
		b[i] = brojPitanja;
		i++;
	}
	brojPitanja = atoi(b); //ukupan broj pitanja
	rewind(file);
	NasumicniBrojevi(nizBrojeva, brojPitanja, 1);
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		int c = 10;
		pom = (char*)malloc(c * sizeof(char));
		duzina = 0;
		broj = nizBrojeva[i];
		for (linija = 2, k = 0; k < broj - 1; linija += 5, k++); //trazi pocetak linije pitanja
		for (j = 1; j < linija; j++) //preskace sve linije prije linije sa pitanjem
			while ((znak = fgetc(file)) != '\n');
		for (j = 0; j < 5; j++) //obradjuje 5 linija; pitanje, 3 odgovora i tacan odgovor
		{
			while ((znak = fgetc(file)) != '\n')
			{
				if (duzina == c)
					pom = (char*)realloc(pom, (c *= 2) * sizeof(char));
				pom[duzina] = znak;
				duzina++;
			}
			pom[duzina] = 0;
			if (j == 0)
			{
				pitanja[i].pitanje = (char*)malloc(duzina * sizeof(char));
				strcpy(pitanja[i].pitanje, pom);
			}
			else if (j == 1)
			{
				pitanja[i].prviOdgovor = (char*)malloc(duzina * sizeof(char));
				strcpy(pitanja[i].prviOdgovor, pom);
			}
			else if (j == 2)
			{
				pitanja[i].drugiOdgovor = (char*)malloc(duzina * sizeof(char));
				strcpy(pitanja[i].drugiOdgovor, pom);
			}
			else if (j == 3)
			{
				pitanja[i].treciOdgovor = (char*)malloc(duzina * sizeof(char));
				strcpy(pitanja[i].treciOdgovor, pom);
			}
			else if (j == 4)
			{
				pitanja[i].tacanOdgovor = atoi(pom);
			}
			duzina = 0;
		}
		rewind(file);
		//free(pom);
	}
}

void IspisPitanja(PITANJE *pitanje, int rb)
{
	printf("%s\n", pitanje[rb].pitanje);
	printf("\n\t1. %s\n", pitanje[rb].prviOdgovor);
	printf("\t2. %s\n", pitanje[rb].drugiOdgovor);
	printf("\t3. %s\n\n", pitanje[rb].treciOdgovor);
}

void IspisPocetak()
{
	printf("==========================================\n");
	printf("************DOBRODOSLI NA KVIZ************\n");
	printf("==========================================\n\n");
	Sleep(3000);
	system("cls");
}

void IspisKraj(int x)
{
	if (x == 150)
	{
		for (int i = 0; i < 60; i++)
		{
			printf("*");
			Sleep(50);
		}
		printf("\n");
		printf("Cestitamo! Osvojili ste sve poene igrice KVIZ, dobijate bonus 50 bodova!\nUkupan broj osvojenih bodova: %d\n", x);
		for (int i = 0; i < 60; i++)
		{
			printf("*");
			Sleep(50);
		}
		printf("\n");
		Sleep(3000);
		system("cls");
	}
	else
	{
		printf("\n********************************************\n");
		printf("Ukupan broj osvojenih bodova: %d\n", x);
		printf("**********************************************\n\n");
		Sleep(3000);
		system("cls");
	}
	printf("==========================================\n");
	printf("****************DIVIDJENJA****************\n");
	printf("==========================================\n\n");
}

void IgrajKviz(PITANJE *pitanja, int *korisnikBodovi)
{
	int i, bodoviBrojac = 0;
	for (i = 0; i < 5; i++)
	{
		int odgovorKorisnik,pom;
		printf("%d. PITANJE:\n\n", i + 1);
		IspisPitanja(pitanja, i);
		printf("Unesi tacan odgovor (1,2,3) : ");
		do {
			pom = 0;
			if (scanf("%d", &odgovorKorisnik) != 1)
			{
				int c;
				pom++;
				while ((c = getchar()) != EOF && c != '\n');
				printf("Pogresan unos! Korisnik mora da unese brojeve 1,2,3.\nPokusaj ponovo: ");
			}
			else
			{
				if (odgovorKorisnik < 1 || odgovorKorisnik > 3)
					printf("Pogresan unos! Korisnik mora da unese brojeve 1,2,3.\nPokusaj ponovo: ");
			}
		} while (pom != 0 || odgovorKorisnik < 1 || odgovorKorisnik > 3);
		if (TacanOdgovor((pitanja + i), odgovorKorisnik))
		{
			printf("\nOdgovor je tacan!\n\n");
			*korisnikBodovi += 20;
			bodoviBrojac++;
			Sleep(2000);
		}
		else
		{
			printf("\nNetacan odgovor!\n\n");
			*korisnikBodovi -= 30;
			Sleep(2000);
		}
		if (bodoviBrojac == 5)
			*korisnikBodovi += 50;
		system("cls");
	}
	IspisKraj(*korisnikBodovi);
}