#include "Igra.h"

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
	}
	fprintf(f, "%s ;%d;%2d.%2d.%d.;%2d:%2d:%2d;%d\n", igranje->korisnickoIme, igranje->sifraIgre, \
		igranje->datum->tm_mday, igranje->datum->tm_mon + 1, igranje->datum->tm_year + 1900, \
		igranje->datum->tm_hour, igranje->datum->tm_min, igranje->datum->tm_sec, igranje->aktivna);
	printf("\nIgra je %s\n", bool ? "otkljucana" : "zakljucana");
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
	case 4: tm2.tm_year += 100;
	default: printf("Greska!"); break;
	}								//tm2 je datum i vrijeme isteka igre
	time_t t2 = mktime(&tm2);
	double sec = difftime(t1, t2);
	return sec > 0;
}

void GlavniMeni(KORISNIK* korisnik) {
	int izbor;
	char c;
	system("cls");
	printf("\t\t\tGlavni meni \n");
	printf("BODOVI: %d\n", korisnik->bodovi);
	do {
		printf("\n1 Igra pogadjanja\n2 Kviz\n3 Loto\n4 Pohod\n5 Prikaz kljuceva\n6 Statistika\n7 Izlaz\n");
		printf("Odaberite opciju: ");
		scanf("%d", &izbor);
		IGRANJE igranje;
		while ((c = getchar()) != EOF && c != '\n');
		//obrisiBafer(); // ocistimo bafer
		switch (izbor) {
		case 1:
			system("cls");
			TraziIgranje(korisnik->korisnickoIme, izbor, &igranje);
			if (PristupiIgri(&igranje, korisnik)) {
				IgrajPrvuIgru(&igranje);
				korisnik->bodovi += igranje.bodoviUIgri;
				Snimi(&igranje);
			}
			system("pause"); GlavniMeni(korisnik); break;
		case 2:
			system("cls");
			TraziIgranje(korisnik->korisnickoIme, izbor, &igranje);
			if (PristupiIgri(&igranje, korisnik)) {
				IgrajDruguIgru(&igranje);
				korisnik->bodovi += igranje.bodoviUIgri;
				Snimi(&igranje);
			}
		case 3:
			system("cls");
			TraziIgranje(korisnik->korisnickoIme, izbor, &igranje);
			if (PristupiIgri(&igranje, korisnik)) {
				IgrajTrecuIgru(&igranje);
				korisnik->bodovi += igranje.bodoviUIgri;
				Snimi(&igranje);
			}
		case 4:
			system("cls");
			TraziIgranje(korisnik->korisnickoIme, izbor, &igranje);
			if (PristupiIgri(&igranje, korisnik))
				//				Avantura(&bodovi, sifra);	//&korisnik.bodovi, sta je sifra?
			system("pause"); GlavniMeni(korisnik); break;
			
		case 5: 
			system("cls");
			PisiKljuc(*korisnik);
			system("pause"); GlavniMeni(korisnik); break;
		case 6: 
			system("cls");
			PrikazStatistike(korisnik);
			system("pause"); GlavniMeni(korisnik); break;
		default: 
			if (izbor == 7) exit(1);
			printf("Pogresan unos!!"); Sleep(1500);
			system("pause"); GlavniMeni(korisnik); break;
		}										
	} while (izbor != 7);
}

int PristupiIgri(IGRANJE* igranje, KORISNIK *korisnik) {
	while (igranje->aktivna == -1) {
		if (Otkljucaj(*korisnik, igranje->sifraIgre)) {
			ADIgru(1, igranje);
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
	else if ((igranje->aktivna == 1) && !Istekao(igranje))
		return 1;
	else
		printf("\nVas kljuc je istekao!\n");
	return 0;
}
