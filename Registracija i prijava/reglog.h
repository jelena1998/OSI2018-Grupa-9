#pragma once
#define MAX 21
typedef struct korisnik {
	char korisnickoIme[MAX];
	char lozinka[MAX];
	int bodovi;
}KORISNIK;

int reg();
int login();
int provjeriIme(char*);
int provjeriLozinku(char*);