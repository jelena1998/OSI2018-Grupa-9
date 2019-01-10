#include"DrugaIgra.h"

//void oslobodi(PITANJE*);


int TacanOdgovor(PITANJE *pitanje, int odgovor)
{
	return pitanje->tacanOdgovor == odgovor;
}


int VecPostojiBroj(int niz[], int n, int broj)
{
	int i;
	for (i = 0;i < n;i++)
	{
		if (niz[i] == broj)
			return 0;
	}
	return 1; //Ogi, ako se if ne izvrsi mora nesto vratiti
}

void OdaberiPitanja(PITANJE* pitanja, FILE* file)
{
	srand((unsigned)time(0));
	char *pom=NULL;
	int duzina;
	int znak, linija, i = 0, j, k, broj, ukupnoPitanja;
	int indexPitanja[BROJ_PITANJA] = { 0 };
	fscanf(file, "%d", &ukupnoPitanja);
	rewind(file);
	while (i < BROJ_PITANJA)
	{
		broj = rand() % ukupnoPitanja + 1;
		if (VecPostojiBroj(indexPitanja, 5, broj))
			indexPitanja[i++] = broj;
	}
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		int c = 10;
		pom = (char*)calloc(c, sizeof(char));
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
					pom = (char*)realloc(pom, (c *= 20) * sizeof(char));
				pom[duzina] = znak;
				duzina++;
			}
			pom[duzina] = 0;
			if (j == 0)
			{
				pitanja[i].pitanje = (char*)calloc(duzina+1, sizeof(char));
				strcpy(pitanja[i].pitanje, pom);
			}
			else
			{
				pitanja[i].odgovor[j - 1] = (char*)calloc(duzina+1, sizeof(char));
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
	printf("\tPravila:\n1. Odgovarate na 5 pitanja.\n2. Tacan odgovor nosi 20 poena\n"
		"3. Netacan odgovor vam oduzima 30 poena.\n4. Za otkazivanje igre unesite 'OTKAZI'\n\n\n");
	Sleep(5000);
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
	}
	printf("==========================================\n");
	printf("****************DOVIDJENJA****************\n");
	printf("==========================================\n\n");
	system("cls");
}

void IgrajKviz(PITANJE *pitanja, IGRANJE* igranje, int* dobijeni, int* izgubljeni,int* bodovi)
{
	int i, tacniOdg = 0;
	for (i = 0; i < 5; i++)
	{
		int odgovorKorisnik,pom;
		char c;
		printf("BODOVI: %d\n", *bodovi);
		printf("Za otkazivanje igre unesite \"OTKAZI\"\n");
		printf("%d. PITANJE:\n\n", i + 1);
		IspisPitanja(pitanja, i);
		printf("Unesi tacan odgovor (1,2,3) : ");
		do {
			pom = 0;
			if (scanf("%d", &odgovorKorisnik) != 1 || odgovorKorisnik <1 || odgovorKorisnik >3)
			{
				pom++;
				if (Otkazi(igranje)) return;
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
			igranje->bodoviUIgri += 20;
			*bodovi += 20;
			*dobijeni += 20;
			while ((c = getchar()) != EOF && c != '\n'); //ako se unese vise odgovora odjednom
			tacniOdg++;
			Sleep(2000);
		}
		else
		{
			printf("\nNetacan odgovor!\n\n");
			igranje->bodoviUIgri -= 30;
			*izgubljeni += 30;
			*bodovi -= 30;
			while ((c = getchar()) != EOF && c != '\n'); //ako se unese vise odgovora odjednom
			Sleep(2000);
		}
		if (tacniOdg == 5) {
			igranje->bodoviUIgri += 50;
			*dobijeni += 50;
		}
		system("cls");
	}
	IspisKraj(igranje->bodoviUIgri);
}

void IgrajDruguIgru(IGRANJE* igranje,int* dobijeni, int* izgubljeni,int* bodovi)
{
	int bool;
	bool = *izgubljeni < (*dobijeni + (*dobijeni) * 0.4);
	FILE *file;
	PITANJE pitanja[5];
	//pitanja->pitanje = NULL;
	//pitanja->odgovor[0] = NULL;
	int bodoviBrojac = 0;
	char pitanjaa[2][17] = { {"pitanjaLaka.txt"}, {"pitanjaTeska.txt"} };
	if ((file = fopen(pitanjaa[bool], "r")) != NULL)
	{
		OdaberiPitanja(pitanja, file);
		fclose(file);
	}
	else
		printf("Greska pri otvaranju datoteke\n");
	
	IspisPocetak();
	IgrajKviz(pitanja, igranje,dobijeni,izgubljeni,bodovi);
	//free(pitanja);
	//oslobodi(pitanja);
}
/*
void oslobodi(PITANJE* pitanja) {
	int i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 4; j++) {
			if (j == 0)
			{
				free(pitanja[i].pitanje);
				pitanja[i].pitanje = NULL;
				//strcpy(pitanja[i].pitanje, pom);
			}
			else
			{
				free(pitanja[i].odgovor[j - 1]);
				pitanja[i].odgovor[j - 1] = NULL;
				//strcpy(pitanja[i].odgovor[j - 1], pom);
			}
			//pitanja[i] = NULL;
		}
		//free(pitanja[i].pitanje);
	}
}
*/