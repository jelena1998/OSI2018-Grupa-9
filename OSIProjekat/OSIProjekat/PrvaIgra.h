#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "Igra.h"

#define BROJ_POKUSAJA 5

void IgrajPrvuIgru(IGRANJE*,int);
int PogodiBroj(int,IGRANJE*);
void Izgubi(IGRANJE*); 