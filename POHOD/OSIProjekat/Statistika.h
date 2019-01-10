#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<Windows.h>
#include<time.h>
#include"igra.h"
typedef struct tabela {
	int igra;
	int dan, mjesec, godina;
	int bodovi;
}TABELA;

void PrikazStatistike(KORISNIK*);
void PisiStatistiku(KORISNIK korisnik, int igra);
int cmp(const void * a, const void * b);