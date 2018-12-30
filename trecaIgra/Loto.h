#pragma once

#define LOTO_BROJEVI  46		//izvlace se brojevi od 1 do 45
#define  TIKET_SIZE  7			
#define  BROJ_IZVLACENJA  20

int VecPostoji(int[], int n, int a);	//provjerava da li se broj a vec nalazi u nizu
void Izvlacenje(int[]);					
void Tiket(int[]);						//ispunjavanje tiketa
void BrojPogodaka(int[], int[], int*);	
void PisiNiz(int[], int n,int pauza);    //ispisuju se elementi niza u razmaku pauza-sekundi