#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>
#include<time.h>
#include "igra.h"

#define LOTO_BROJEVI  46		//izvlace se brojevi od 1 do 45
#define  TIKET_SIZE  7			
#define  BROJ_IZVLACENJA  20

int VecPostoji(int[], int n, int a);	//provjerava da li se broj a vec nalazi u nizu
void Tiket(int[],IGRANJE*);						//ispunjavanje tiketa
void Izvlacenje(int[],int[],int);					
void Kombinacija(int a, int[]);		//u niz treba da smjesti jednu slucajnu kombinaciju pogodaka za osvajanje a-bodova
void BrojPogodaka(int[], int[], int*);	
void PisiNiz(int[], int n,int pauza);    //ispisuju se elementi niza u razmaku pauza-sekundi
void IgrajTrecuIgru(IGRANJE*);