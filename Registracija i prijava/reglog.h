#pragma once
#define MAX 21
typedef struct korisnik {
	char korisnickoIme[MAX];
	char lozinka[21];
	int bodovi;
}KORISNIK;

int reg();
int login();
int provjeri(char*);