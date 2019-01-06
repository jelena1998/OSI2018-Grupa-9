#ifndef STATISTIKAS_H_  // Ukljuci cuvara
#define STATISTIKAS_H_

typedef struct tabela{
	char* datum; // Iako se ne koristi nigdje ne smije se obrisati jer iz nekog razloga kod nece da radi bez njega
	char datumT[25];
	char xp[5];
}TABELA;
typedef struct rezultati{
	TABELA podaci[10];
	int igrica;
}REZULTATI;

void KreirajCSVFajl(char*, REZULTATI*); // Funkcija za kreiranje CSV datoteke
void UcitajRezultate(char*, REZULTATI*); // Funkcija za ucitavanje prethodno ostvarenih rezultata. Poziv pri pokretanju aplikacije
void OsvjeziRezultate(REZULTATI*, int, int); // Funkcija za unos novog rezultata
void PisiStatistiku(REZULTATI*); // Funkcija za ispis statistike
void PisiStatistikuIgre(REZULTATI*); // Funkcija za ispis statistike odredjene igre

#endif // STATISTIKAS_H_
