#include "TrecaIgra.h"

int VecPostoji(int niz[], int n, int broj) {
	int i;
	for (i = 0; i < n; i++) {
		if (niz[i] == broj)
			return 0;
	}
	return 1;
}

void Tiket(int korisnik[],IGRANJE* igranje) { //korisnik unosi svoje brojeve

	int i, broj;
//	char c;
	printf("Za otkazivanje igre unesite \"OTKAZI\"\n");
	printf("Unesite 7 brojeva da popunite vas tiket\n");
	printf("Vasi brojevi moraju biti u rasponu od 1 do 45\n");
	for (i = 0; i < TIKET_SIZE; i++)
	{
		printf("Unesite broj-> ");
		scanf("%d", &broj);
		if (Otkazi(igranje)) return;
		int a = VecPostoji(korisnik, TIKET_SIZE, broj);
		while (broj < 1 || broj>45 || !a)
		{
			printf("Greska! Broj nije u zadanom opsegu ili je vec ranije unesen\n");
			printf("Unesite broj-> ");
			scanf("%d", &broj);
			if (Otkazi(igranje)) return;
			a = VecPostoji(korisnik, TIKET_SIZE, broj);
		}
		korisnik[i] = broj;
	}
}

void Izvlacenje(int loto[], int korisnik[], int max) {		//max je maksimalan broj bodova koji se moze osvojiti
	srand((unsigned int)time(0)); //Ogi dodao unsigned int
	if (max > 208) max = 280;							//jer je maksimalan broj poena u igri 280
	max /= 10;
	int i = 0, broj, komb[7], poz[TIKET_SIZE] = {-1,-1,-1,-1,-1,-1,-1};		//u nizu poz smjestaju se pozicije pogodaka u loto nizu
	int osvojeni = rand() % (max + 1);						//broj poena koji ce se osvojiti u igri (mora biti <=max)
	//printf("Broj poena koji ce se osvojiti: %d\n", osvojeni*10);//nece pokuazivati tacno jer su dodani negativni poeni
	Kombinacija(osvojeni, komb);
	while (i < BROJ_IZVLACENJA) {
		broj = rand() % LOTO_BROJEVI;
		if (VecPostoji(loto, BROJ_IZVLACENJA, broj) && VecPostoji(korisnik,TIKET_SIZE,broj)) {
			loto[i] = broj;
			i++;
		}
	}
	i = 0;
	while (i < TIKET_SIZE) {
		broj = rand() % BROJ_IZVLACENJA;
		if (VecPostoji(poz, TIKET_SIZE, broj)) {
			poz[i] = broj;
			i++;
		}
	}
	for (int i=0; i < TIKET_SIZE; i++)
		if (komb[i] != 0 && VecPostoji(loto,BROJ_IZVLACENJA,korisnik[komb[i]-1]) )
			loto[poz[i]] = korisnik[komb[i] - 1];
}

//funkcija kreira niz svih mogucih kombinacija za ostvarivanje a*10 poena
//iz niza kombinacija slucajnim odabirom uzima se jedna i smijesta u niz[]
void Kombinacija(int a, int niz[]) {
	int mat[8][7] = { 0 }, red = -1;
	for (int i = 1; i <= 7; i++) {
		if (i == a) { mat[++red][0] = i; }
		for (int j = i + 1; j <= 7 && i != a; j++) {
			if ((i + j) == a) { mat[++red][0] = i, mat[red][1] = j; }
			for (int k = j + 1; k <= 7 && (i + j) != a; k++) {
				if ((i + j + k) == a) { mat[++red][0] = i, mat[red][1] = j, mat[red][2] = k; }
				for (int l = k + 1; l <= 7 && (i + j + k) != a; l++) {
					if ((i + j + k + l) == a) { mat[++red][0] = i, mat[red][1] = j, mat[red][2] = k; mat[red][3] = l; }
					for (int m = l + 1; m <= 7 && (i + j + k + l) != a; m++) {
						if ((i + j + k + l + m) == a) { mat[++red][0] = i, mat[red][1] = j, mat[red][2] = k; mat[red][3] = l; mat[red][4] = m; }
						for (int n = m + 1; n <= 7 && (i + j + k + l + m) != a; n++) {
							if ((i + j + k + l + m + n) == a) { mat[++red][0] = i, mat[red][1] = j, mat[red][2] = k; mat[red][3] = l; mat[red][4] = m; mat[red][5] = n; }
							for (int o = n + 1; o <= 7 && (i + j + k + l + m + n) != a; o++) {
								if ((i + j + k + l + m + n + o) == a) { mat[++red][0] = i, mat[red][1] = j, mat[red][2] = k, mat[red][3] = l, mat[red][4] = m, mat[red][5] = n, mat[red][6] = o; }

							}
						}
					}
				}

			}
		}
	}
//	for (int i = 0; i < 8; i++)
//		PisiNiz(mat[i], 7, 0);
	int s = 0;
	if(red+1)						//zbog dijeljenja sa nulom
		s = rand() % (++red);		//s je broj nasumicne kombinacije za dobijanje a-poena
	//printf("%d\n", s);
	for (int i = 0; i < 7; i++)
		niz[i] = mat[s][i];
}

void BrojPogodaka(int loto[], int korisnik[], int* poeni,int* dobijeni,int* izgubljeni) { //broji koliko pogodaka ima
	int pogodak = 0, i, j,*pogoci;
	pogoci = (int*)calloc(TIKET_SIZE,sizeof(int));
	*poeni = 0;
	for (i = 0; i < BROJ_IZVLACENJA; i++) {
		for (j = 0; j < TIKET_SIZE; j++) {
			if (loto[i] == korisnik[j]) {
				pogoci[pogodak++] = loto[i];
				int t = j;
				*poeni += (t + 1) * 10;
				*dobijeni = *poeni;
			}
		}
	}
	*izgubljeni += (TIKET_SIZE - pogodak) * 5;
	*poeni -= (TIKET_SIZE - pogodak) * 5;						//dodano, moraju se gubiti poeni u igri
	printf("Broj pogodaka je: %d\n", pogodak);
	if (pogodak)
		printf("Pogodili ste brojeve: ");
	PisiNiz(pogoci, pogodak, 0);		//pogodjeni brojevi
	free(pogoci);
}


void PisiNiz(int niz[], int n, int pauza) {
	int i;
	for (i = 0; i < n; i++) {
		Sleep(pauza*1000);
		printf("%d ", niz[i]);
	}
	Sleep(pauza * 1000);
	printf("\n");
}

void IgrajTrecuIgru(IGRANJE* igranje,int max,int* dobijeni, int* izgubljeni) {
	int loto[20] = { 0 };
	int korisnikUnos[7] = { 0 };
	int poeni;
	if(max > 100) max = 100;     //manji od ulozenih poena
	Tiket(korisnikUnos,igranje);								//korisnik unosi 7 brojeva
	Izvlacenje(loto, korisnikUnos, max);					//sistem generise 20 brojeva za loto
	//system("cls");
	PisiNiz(korisnikUnos, TIKET_SIZE, 0);
	PisiNiz(loto, BROJ_IZVLACENJA, 1);
	BrojPogodaka(loto, korisnikUnos, &poeni,dobijeni,izgubljeni);
	printf("Osvojili ste ukupno %d bodova u ovoj igri\n", poeni);
	igranje->bodoviUIgri = poeni;
	//system("pause");
}
