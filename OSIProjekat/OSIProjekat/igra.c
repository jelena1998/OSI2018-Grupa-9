#include "Igra.h"

//zbog pozivanja funkcija iz ovih biblioteka
#include"PrvaIgra.h"
#include"DrugaIgra.h"
#include"TrecaIgra.h"
#include"CetvrtaIgra.h"
#include"Kljuc.h"
#include"Statistika.h"


int TraziIgranje(char korisnickoIme[], int igra, IGRANJE* igranje) {

	int adresa;
	time_t now = time(NULL);
	igranje->datum = localtime(&now);
	FILE* f = fopen("igranje.csv", "r");
	if (f == NULL) { printf("greska pri otvaranju datoteke!"); return -1; }
	do {
		adresa = ftell(f);
		fscanf(f, "%s ;%d;%d.%d.%d.;%d:%d:%d;%d\n", igranje->korisnickoIme, &igranje->sifraIgre, \
			&igranje->datum->tm_mday, &igranje->datum->tm_mon, &igranje->datum->tm_year, \
			&igranje->datum->tm_hour, &igranje->datum->tm_min, &igranje->datum->tm_sec, &igranje->aktivna);

	} while (strcmp(korisnickoIme, igranje->korisnickoIme) || (igra != igranje->sifraIgre));
	fclose(f);
	return adresa;
}

void ADIgru(int bool, IGRANJE* igranje) {
	char ime[20],sifra;
	strcpy(ime, igranje->korisnickoIme);
	sifra = igranje->sifraIgre;
	int adresa = TraziIgranje(ime, sifra, igranje);
	FILE* f = fopen("igranje.csv", "r+");
	if (f == NULL) { printf("greska pri otvaranju datoteke!"); return; }
	if (adresa < 0) return;
	fseek(f, adresa, 0);
	igranje->aktivna = bool;
	if (bool) {
		time_t now = time(NULL);
		igranje->datum = localtime(&now);
		igranje->datum->tm_year += 1900;
		igranje->datum->tm_mon += 1;
	}
	fprintf(f, "%s ;%d;%2d.%2d.%d.;%2d:%2d:%2d;%d\n", igranje->korisnickoIme, igranje->sifraIgre, \
		igranje->datum->tm_mday, igranje->datum->tm_mon, igranje->datum->tm_year, \
		igranje->datum->tm_hour, igranje->datum->tm_min, igranje->datum->tm_sec, igranje->aktivna);
	printf("\nIgra je %s\n", bool ? "otkljucana" : "zakljucana");
	Sleep(1500);
	system("cls");
	fclose(f);
}

int Istekao(IGRANJE* igranje) {
	time_t t1 = time(NULL);
	struct tm tm2 = *(igranje->datum);
	tm2.tm_year -= 1900;
	tm2.tm_mon--;
	switch (igranje->sifraIgre) {
	case 1: tm2.tm_hour++; break;
	case 2: tm2.tm_mday++; break;
	case 3: tm2.tm_mday += 7; break;
	case 4: tm2.tm_year += 100; break;
	default: printf("Greska!"); break;
	}								//tm2 je datum i vrijeme isteka igre
	time_t t2 = mktime(&tm2);
	double sec = difftime(t1, t2);
	return sec > 0;
}

void ucitajPodatke(KORISNIK korisnik, int bodovi, int pokusaj) {
	KORISNIK kopija;
	char odrediste[100] = "Korisnici\\";
	char eks[5] = ".dat";
	strcat(odrediste, korisnik.korisnickoIme);
	strcat(odrediste, eks);

	FILE* file = fopen(odrediste, "rb");
	if (file == NULL) {
		printf("Greska\n");
		//fclose(file);
		return;
	}

	//kopiranje podataka, trebalo bi izdvojiti u zasebnu funkciju
	fread(&kopija, sizeof(KORISNIK), 1, file);
	fclose(file);

	file = fopen(odrediste, "wb");
	if (file == NULL) {
		printf("Greska\n");
	//	fclose(file);
		return;
	}


	kopija.bodovi = bodovi;
	kopija.pokusaj = pokusaj;

	fwrite(&kopija, sizeof(KORISNIK), 1, file);
	fclose(file);
}


void GlavniMeni(KORISNIK* korisnik) {
	//char* sifra = "123456789"; //za potrebe 4 igre
	static int dobijeni;
	static int izgubljeni;
	int izbor,max;
	//char c;
	system("cls");
	//printf("%d %d", dobijeni, izgubljeni);
	printf("\t\t\tGlavni meni\n");
	printf("BODOVI: %d\n", korisnik->bodovi);

	//printf("Pokusaj %d\n", korisnik->pokusaj); //pokusaji za prvu igru

	//Vrsi ze upisivanje zbog bodova koji se mijenjaju (bag) - ispravljeno

	char c; int p = 0;
	do {

		//system("cls");
		printf("\n1 Igra pogadjanja\n2 Kviz\n3 Loto\n4 Pohod\n5 Prikaz kljuceva"
			"\n6 Statistika\n7 Snimanje igre\n8 Izlaz\n");
		printf("Odaberite opciju: ");
		scanf("%d", &izbor);
		//printf("Izbor: %d\n", izbor);
		//system("pause");
		while ((c = getchar()) != EOF && c != '\n');
		IGRANJE igranje;
		igranje.bodoviUIgri = 0;
		//while ((c = getchar()) != EOF && c != '\n');
		//obrisiBafer(); // ocistimo bafer

		switch (izbor) {
		case 1:
			system("cls");
			TraziIgranje(korisnik->korisnickoIme, izbor, &igranje);
			if (PristupiIgri(&igranje, korisnik,&izgubljeni)) {

				if ( (korisnik->pokusaj >= 1) && (korisnik->pokusaj <= 3)) {
					printf("BODOVI: %d", korisnik->bodovi);
					Pobijedi(&igranje);
					korisnik->pokusaj--;
					korisnik->bodovi += igranje.bodoviUIgri;
					dobijeni += igranje.bodoviUIgri;
					Snimi(&igranje);
				}
				else {
					int bool;
					bool = izgubljeni < (dobijeni + dobijeni * 0.4);
					if (korisnik->bodovi < 50) bool = 0;		//ako nema dovoljno bodova za ostale igre
					printf("BODOVI: %d", korisnik->bodovi);
					IgrajPrvuIgru(&igranje, bool);
					//korisnik->pokusaj--; // umanjujemo pokusaj
					korisnik->bodovi += igranje.bodoviUIgri;
					dobijeni += igranje.bodoviUIgri;
					Snimi(&igranje);
				}
			}
			Sleep(2000);
			/*system("pause");*/ GlavniMeni(korisnik); break;
		case 2:
			system("cls");
			TraziIgranje(korisnik->korisnickoIme, izbor, &igranje);
			if (PristupiIgri(&igranje, korisnik,&izgubljeni)) {
				IgrajDruguIgru(&igranje,&dobijeni,&izgubljeni,&korisnik->bodovi);
				//korisnik->bodovi += igranje.bodoviUIgri;
				Snimi(&igranje);
			}
			Sleep(2000);
			GlavniMeni(korisnik);
			break; //da ne propadne dalje
		case 3:
			system("cls");
			TraziIgranje(korisnik->korisnickoIme, izbor, &igranje);
			if (PristupiIgri(&igranje, korisnik,&izgubljeni)) {
				//int max = (int)(izgubljeni - izgubljeni * 0.4); //Mnozi se sa 0.4 max je int, samo sam castovo u int zbog warrninga, Ogi
				printf("BODOVI: %d\n", korisnik->bodovi);
				if (izgubljeni < (dobijeni + (dobijeni) * 0.4))
					max = 0;
				else
					max = izgubljeni - (int)(dobijeni + (dobijeni) * 0.4);
				IgrajTrecuIgru(&igranje,max,&dobijeni,&izgubljeni);
				korisnik->bodovi += igranje.bodoviUIgri;
				Snimi(&igranje);
			}
			Sleep(2000);
			GlavniMeni(korisnik);
			break; //isto tako
		case 4:
			system("cls");
			TraziIgranje(korisnik->korisnickoIme, izbor, &igranje);
			//printf("TraziIgru se izvrsilo\n"); system("pause");
			if (PristupiIgri(&igranje, korisnik,&izgubljeni)) {
			//	printf("PristupiIgri se izvrsilo kao i if u tijelu if smo\n"); system("pause");
				Avantura(&korisnik->bodovi, &igranje, 0);
				//Avantura(&korisnik->bodovi, sifra);	//&korisnik.bodovi, sta je sifra?
				//printf("pristupio si\n");
				Snimi(&igranje);
			}
			Sleep(2000);
			/*system("pause");*/
			GlavniMeni(korisnik);
			break;

		case 5:
			system("cls");
			PisiKljuc(*korisnik);
			system("pause"); GlavniMeni(korisnik); break;
		case 6:
			system("cls");
			PrikazStatistike(korisnik);
			system("pause"); GlavniMeni(korisnik); break;
		case 7: ucitajPodatke(*korisnik, korisnik->bodovi, korisnik->pokusaj); GlavniMeni(korisnik); break;
		default:
			if (izbor == 8) {
				ucitajPodatke(*korisnik, korisnik->bodovi, korisnik->pokusaj); //ucitavanje podataka
				exit(EXIT_SUCCESS);
			}
			printf("Pogresan unos!!"); Sleep(2000);
			/*system("pause");*/ GlavniMeni(korisnik); break;
		}
	} while (izbor != 8);


}

void Plati(IGRANJE* igranje, KORISNIK* korisnik,int* izgubljeni) {
	int plati,izbor;
	char c;
	if (igranje->sifraIgre != 1) {
		switch (igranje->sifraIgre) {
		case 2: plati = 50; break;
		case 3: plati = 100; break;
		case 4: plati = 125;
		}
		printf("\nKako bi pristupili %d. igri morate platiti %d bodova\n", \
			igranje->sifraIgre, plati);
		printf("Da li zelite nastaviti: DA [1]  NE[0]  ");
		scanf("%d", &izbor);
		while ((c = getchar()) != EOF && c != '\n');
		if (izbor == 0) {
			Sleep(1500);
			GlavniMeni(korisnik);
			return;
		}
		if (izbor != 1) { printf("Pogresan unos!"); return; }
		if (korisnik->bodovi >= plati) {
			korisnik->bodovi -= plati;
			*izgubljeni += plati;
		}
		else {
			printf("Nemate dovoljno bodova za igru");
			Sleep(1500);
			GlavniMeni(korisnik);
		}
		Sleep(1500);
		system("cls");
	}
}

int PristupiIgri(IGRANJE* igranje, KORISNIK *korisnik, int* izgubljeni) {
//	char c;
	while (igranje->aktivna == -1) {
		if (Otkljucaj(*korisnik, igranje->sifraIgre)) {
			ADIgru(1, igranje);
			Plati(igranje, korisnik,izgubljeni);
			return 1;
		}
		else {
			printf("\nGreska! Niste unijeli ispravan kljuc.\n");
			Sleep(1500);
			GlavniMeni(korisnik);
		}
	}
	if (igranje->aktivna == 0) {
		printf("\nIgra je zakljucana\n");
		return 0;
	}
	else if ((igranje->aktivna == 1) && !Istekao(igranje)) {
		Plati(igranje, korisnik,izgubljeni);
		return 1;
	}
	else
		printf("\nVas kljuc je istekao!\n");
	return 0;
}

int Otkazi(IGRANJE* igranje) {
	char *niz, c;
	int n=10,i=0;
	niz = (char*)calloc(n, sizeof(char)); if(!niz) {printf("Greska kod alokacije memorije"); return 1;}
		while ((c = getchar()) != EOF && c != '\n') {
			niz[i++] = c;
			if (i >= n) {
				n += 10;
				niz = (char*)realloc(niz, n);
			}
		}
	if (!strcmp(niz, "OTKAZI")) {
		ADIgru(0, igranje);
		free(niz);
		return 1;
	}
	free(niz);
	return 0;
}
