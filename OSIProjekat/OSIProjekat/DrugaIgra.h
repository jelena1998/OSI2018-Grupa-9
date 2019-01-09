#pragma once
#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
#include "igra.h"

#define BROJ_PITANJA 5
#define BROJ_ODGOVORA 3

typedef struct pitanje
{
	char *pitanje;
	char *odgovor[BROJ_ODGOVORA];
	int tacanOdgovor;
}PITANJE;

int TacanOdgovor(PITANJE *pitanje, int odgovor);
int VecPostojiBroj(int niz[], int n, int broj);
void OdaberiPitanja(PITANJE* pitanja, FILE* file);
void IspisPitanja(PITANJE *pitanje, int rb);
void IspisPocetak();
void IspisKraj(int x);
void IgrajKviz(PITANJE *pitanja, IGRANJE*, int*, int*);
void IgrajDruguIgru(IGRANJE*,int*,int*); 