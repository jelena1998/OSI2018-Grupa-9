#pragma once
#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<time.h>

typedef struct pitanje
{
	char *pitanje;
	char *prviOdgovor, *drugiOdgovor, *treciOdgovor;
	int tacanOdgovor;
}PITANJE;

int TacanOdgovor(PITANJE *pitanje, int odgovor);
int UporediNiz(int niz1[5], int niz2[5], int j);
void NasumicniBrojevi(int* randomNovi, int max, int min);
void OdaberiPitanja(PITANJE* pitanja, FILE* file);
void IspisPitanja(PITANJE *pitanje, int rb);
void IspisPocetak();
void IspisKraj(int x);
void IgrajKviz(PITANJE *pitanja, int *korisnikBodovi);