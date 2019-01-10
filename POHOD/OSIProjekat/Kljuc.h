#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<Windows.h>
#include<time.h>
#include "igra.h"

int KreirajKljuc();
int Provjeri(char* kljuc, FILE* file);
int Index(FILE* f);
void PisiKljuc(KORISNIK k);
int Otkljucaj(KORISNIK, int a);	//a je redni broj igre
KLJUC TraziKljuc(int a);		