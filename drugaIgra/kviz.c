#include"kviz.h"

int TacanOdgovor(PITANJE *pitanje, int odgovor)
{
	return pitanje->tacanOdgovor == odgovor;
}


int VecPostoji(int niz[], int n, int broj)
{
	int i;
	for (i = 0;i < n;i++)
	{
		if (niz[i] == broj)
			return 0;
	}
}

void OdaberiPitanja(PITANJE* pitanja, FILE* file)
{
	srand(time(0));
	char *pom;
	int duzina;
	int znak, linija, i = 0, j, k, broj, ukupnoPitanja;
	int indexPitanja[BROJ_PITANJA] = { 0 };
	fscanf(file, "%d", &ukupnoPitanja);
	rewind(file);
	while (i < BROJ_PITANJA)
	{
		broj = rand() % ukupnoPitanja + 1;
		if (VecPostoji(indexPitanja, 5, broj))
			indexPitanja[i++] = broj;
	}
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		int c = 10;
		pom = (char*)malloc(c * sizeof(char));
		duzina = 0;
		broj = indexPitanja[i];
		for (linija = 2, k = 0; k < broj - 1; linija += 5, k++); //trazi pocetak linije pitanja
		for (j = 1; j < linija; j++) //preskace sve linije prije linije sa pitanjem
			while ((znak = fgetc(file)) != '\n');
		for (j = 0; j < 4; j++) //obradjuje 5 linija; pitanje, 3 odgovora
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
			else
			{
				pitanja[i].odgovor[j - 1] = (char*)malloc(duzina * sizeof(char));
				strcpy(pitanja[i].odgovor[j - 1], pom);
			}
			duzina = 0;
		}
		fscanf(file, "%d", &pitanja[i].tacanOdgovor);
		rewind(file);
	}
}

void IspisPitanja(PITANJE *pitanje, int rb)
{
	int i;
	printf("%s\n\n", pitanje[rb].pitanje);
	for (i = 0;i < BROJ_ODGOVORA;i++)
		printf("\t%d. %s\n", i + 1, pitanje[rb].odgovor[i]);
	printf("\n");
}

void IspisPocetak()
{
	printf("==========================================\n");
	printf("************DOBRODOSLI NA KVIZ************\n");
	printf("==========================================\n\n");
	Sleep(2000);
	system("cls");
}

void IspisKraj(int x)
{
	if (x == 150)
	{
		for (int i = 0; i < 46; i++)
		{
			printf("*");
			Sleep(35);
		}
		printf("\n");
		printf("Cestitamo! Osvojili ste sve poene igrice KVIZ\nDobijate bonus 50 bodova!\nUkupan broj osvojenih bodova: %d\n", x);
		for (int i = 0; i < 46; i++)
		{
			printf("*");
			Sleep(35);
		}
		printf("\n");
		Sleep(3000);
		system("cls");
	}
	else
	{
		printf("\n********************************************\n");
		printf("Ukupan broj osvojenih bodova: %d\n", x);
		printf("********************************************\n\n");
		Sleep(3000);
		system("cls");
	}
	printf("==========================================\n");
	printf("****************DIVIDJENJA****************\n");
	printf("==========================================\n\n");
}

void IgrajKviz(PITANJE *pitanja, int *korisnikBodovi)
{
	int i, tacniOdg = 0;
	for (i = 0; i < 5; i++)
	{
		int odgovorKorisnik,pom;
		printf("%d. PITANJE:\n\n", i + 1);
		IspisPitanja(pitanja, i);
		printf("Unesi tacan odgovor (1,2,3) : ");
		do {
			pom = 0;
			if (scanf("%d", &odgovorKorisnik) != 1 || odgovorKorisnik <1 || odgovorKorisnik >3)
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
			tacniOdg++;
			Sleep(2000);
		}
		else
		{
			printf("\nNetacan odgovor!\n\n");
			*korisnikBodovi -= 30;
			Sleep(2000);
		}
		if (tacniOdg == 5)
			*korisnikBodovi += 50;
		system("cls");
	}
	IspisKraj(*korisnikBodovi);
}