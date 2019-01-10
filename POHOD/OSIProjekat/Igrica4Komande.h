#ifndef IGRICA4KOMANDE_H_  // Ukljuci cuvara
#define IGRICA4KOMANDE_H_ 

void UkloniIgracevXP(int*); // Brise sve XP bodove sa igracevog profila
void UkloniIgrice4XP(int*); // Brise sve XP bodove koje je igrac ostvario u igrici
int Dodaj_OduzmiXP(); // Funkcija za nasumicno odlucivanje da li bodove treba dodati ili oduzeti

void OcistiEkran(); // Cisti sav tekst sa ekrana
void OcistiEkranPomjeranjem(); // Ispisuje prazne linije tako da daje efekat da je ekran ociscen
void PuniEkran(int); // Postavlja konzolu preko cijelog ekrana i brise sve sto se do tad nalazilo na konzoli

void VremenskaPauza(int); // U funkciju se unosi koliko sekundi program treba da bude pauziran

int Nasumicno(int); // U funkciju se unosi vrijednost maksimalnog broja kojeg funkcija moze da vrati
int UcitajOdgovor(); // Funkcija za ucitavanje odgovora igraca
void ProvjeraOdgovora(int, int, int, int*); // Funkcija koja obezbjedjuje 40% sanse za gubitak bodova

int Pomoc(int*, char*, int*, int); // Funkcija koja nudi pomoc igracu, argumenti su broj do sad trazenih pomoci 
								   // i tekst za pomoc i i XP bodove sa igracevog profila, te cjenu pomoci
void sleepM(unsigned int); // U funkciju se unosi koliko milisekundi program treba da bude pauziran
void KordinateXY(int, int); // Postavlja odakle se tekst da se ispisuje na konzoli
void Load(char*, int); // Load animacija

#endif // IGRICA4KOMANDE_H_ 
