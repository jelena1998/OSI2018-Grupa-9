#include"reglog.h"

int login(KORISNIK *korisnik) {

	system("cls");
	printf("Login\n\n");

	FILE* file;

	char korisnickoIme[100], lozinka[100];
	char odrediste[100] = "Korisnici\\", eks[5] = ".dat";
	//provjeravamo i ovdje unos sa razmakom da ne dodje do punjena bafera...
	do {
		printf("Unesite korisnicko ime:\n->");
		scanf("%s", korisnickoIme);
	} while (!obrisiBafer());

	do {
		printf("Unesite lozinku:\n->");
		scanf("%s", lozinka);
	} while (!obrisiBafer());

	strcat(odrediste, korisnickoIme);
	strcat(odrediste, eks);

	//ukoliko se unese nepostojece ime
	file = fopen(odrediste, "rb");
	if (file == NULL) {
		printf("Korisnicko ime ne postoji u bazi podataka\nMolimo da se registrujete.\n");
		return 0;
	}

	fread(korisnik, sizeof(KORISNIK), 1, file); //citanje podataka

	//poslije pronalazenja korisnika i citanja podataka provjerava se identicnost unijetih podataka
	if (!strcmp(korisnik->korisnickoIme, korisnickoIme)) {
		if (!strcmp(korisnik->lozinka, lozinka)) {
			system("cls");
			printf("\t\tDobrodosli %s na platformu.\n\t\t    Vasi bodovi su: %d.\n", korisnik->korisnickoIme, korisnik->bodovi);
			Sleep(2000);
			return 1;
		}
	}
	return 0;
}

int reg() {

	system("cls");
	printf("Registracija\n");

	KORISNIK korisnik;
	FILE* file;
	char korisnickoIme[100], lozinka[100];
	char odrediste[100] = "Korisnici\\", eks[5] = ".dat";
	int duzina, i;
	int p=0;

	do {
		printf("Unesite korisnicko ime(MAX 20 karaktera):\n->");
		scanf("%s", korisnickoIme);
		duzina = strlen(korisnickoIme); 
		p = provjeriIme(korisnickoIme); //provjera za ime
		p = obrisiBafer(); //provjera da li je bafer ostao pun poslije unosa
	} while (duzina > 20 || !p); //max unos 20 karaktera
	p = 0;

	do {
		printf("Unesite password(MIN: 6 MAX: 10 karaktera):\n->");
		scanf("%s", lozinka);
		duzina = strlen(lozinka);
		p = provjeriLozinku(lozinka); //provjera za lozinku
		p = obrisiBafer(); //provjera da li je bafer ostao pun poslije unosa
	} while (duzina < 6 || duzina > 10 || !p); //lozinka moze da ima min 6 karaktera i max 10 karaktera
	
	strcat(odrediste, korisnickoIme);
	strcat(odrediste, eks);

	//provjera da li korisnicko ime postoji
	file = fopen(odrediste, "rb");
	if (file != NULL) {
		printf("Korisnicko ime postoji\n");
		fclose(file);
		return 0;
	}

	//snimanje podataka
	strcpy(korisnik.korisnickoIme, korisnickoIme);
	strcpy(korisnik.lozinka, lozinka);
	korisnik.bodovi = 10;
	for (i = 0; i < 4; i++)
		korisnik.indeksKljca[i] = KreirajKljuc();
	PisiKljuc(korisnik);
	//upisivanje podataka u datoteku
	file = fopen(odrediste, "wb");
	fwrite(&korisnik, sizeof(KORISNIK), 1, file);
	fclose(file);
	IGRANJE igranje;

	time_t now = time(NULL);
	file = fopen("igranje.csv", "a");
	if (file == NULL) { printf("Greska prilikom otvaranja datoteke 'igranje.txt'\n"); return 0; }
	strcpy(igranje.korisnickoIme, korisnik.korisnickoIme);
	igranje.aktivna = -1;
	igranje.datum = localtime(&now);
	for (i = 0; i < 4; i++) {
		igranje.sifraIgre = i + 1;
		fprintf(file, "%s ;%d;%2d.%2d.%d.;%2d:%2d:%2d;%d\n", igranje.korisnickoIme, igranje.sifraIgre, \
			igranje.datum->tm_mday, igranje.datum->tm_mon + 1, igranje.datum->tm_year + 1900, \
			igranje.datum->tm_hour, igranje.datum->tm_min, igranje.datum->tm_sec, igranje.aktivna);
	}
	fclose(file);

	char pom[10] = "0.csv";
	for (i = 0; i < 4; i++) {		//otvaranje datoteka za statistiku igara
		strcpy(odrediste, "Korisnici\\");
		strcat(odrediste, korisnik.korisnickoIme);
		pom[0]++;
		strcat(odrediste, pom);
		file = fopen(odrediste, "w");
		if (file == NULL) {
			printf("Greska prilikom otvaranja datoteke\n"); return 0;}
			fclose(file);
	}
	return 1;
}

int provjeriIme(char* korisnickoIme) { //provjera ispravnosti korisnickogImena
	
	int brojac = 0;
	int duzina = strlen(korisnickoIme);
	
	for (int i = 0; i < duzina; i++)
		if ((korisnickoIme[i] >= 65 && korisnickoIme[i] <= 90) || (korisnickoIme[i] >= 97 && korisnickoIme[i] <= 122) || (korisnickoIme[i] >= 48 && korisnickoIme[i] <= 57))
			brojac++;
	
	if (duzina == brojac)
		return 1;
	printf("\nKoristite samo engleski alfabet i cifre max 20 karaktera\n");
	return 0;
}
int provjeriLozinku(char* lozinka) { //provjera ispravnosti lozinke
	
	int brojacSlova = 0;
	int brojacBrojeva = 0;
	int duzina = strlen(lozinka);

	for (int i = 0; i < duzina; i++) {

		if ((lozinka[i] >= 65 && lozinka[i] <= 90) || (lozinka[i] >= 97 && lozinka[i] <= 122))
			brojacSlova++;

		if ((lozinka[i] >= 48 && lozinka[i] <= 57))
			brojacBrojeva++;
	}

	if (brojacBrojeva + brojacSlova == duzina)
		if (brojacSlova && brojacBrojeva)
			return 1;
		else
			printf("\nLozinka se mora sastojati min 6, max 10 karaktera iz engleskog alfabeta i cifri (kombinovano)\n");
	else
		printf("\nDozvoljeno je koristiti samo engleski alfabet i cifre\n");
	return 0;
}


int obrisiBafer(){
	char c;
	int brojac = -1;

	do {
		scanf("%c", &c);
		brojac++;
	} while (c != EOF && c != '\n');
	if (!brojac)
		return 1;
	
	printf("Ne smije se nalaziti razmak.\n");
	return 0;
}