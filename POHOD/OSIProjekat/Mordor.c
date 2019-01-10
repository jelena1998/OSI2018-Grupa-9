#include "Mordor.h"
#include "SkrivenaIgra.h"
#include "Igrica4Komande.h"
#include "FunkcijeZaIspis.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int brzinA = 50;

int Mordor(int* glavniXP2, int najboljiR, int* osvojeniXP2){
	system("title Mordor");
	OcistiEkran();
	Load("Mordor loading...", 32);
	glavniXP = *glavniXP2;
	osvojeniXP = 0;
	brojPomoci = 0;
	otkazi = 0;

	OnDasNot();
	
	if(otkazi == 1){
		return -3;
	}
	
	glavniXP += osvojeniXP;
	*glavniXP2 = glavniXP;
	*osvojeniXP2 = osvojeniXP;
	OcistiEkran();
	IspisSlike("Kraj Igre.txt");
	IspisRezultata(najboljiR, osvojeniXP);
	VremenskaPauza(10);
	return 0;
}
void OnDasNot(){
	IspisSlike("Mordor.txt");
	VremenskaPauza(10);
	UsporeniIspisTeksta(brzinA, "Unesite bilo sta kako bi ste izasli.\n");
	char hobit[21];
	scanf_s("%s", &hobit, sizeof(hobit));
	if(strcmp(hobit, "frodo") == 0){
		UMordor();
	} else if(strcmp(hobit, "FRODO") == 0){
		UMordor();
	} else if(strcmp(hobit, "Frodo") == 0){
		UMordor();
	} else if (strcmp(hobit, "OTKAZI") == 0) {
		otkazi = 1;
	}
}
void UMordor(){
	OcistiEkran();
	IspisSlike("Pikacu.txt");
	VremenskaPauza(3);
	OcistiEkran();
	osvojeniXP = Pokreni();
	if(osvojeniXP == -2){
		osvojeniXP = 0;
	} else if(osvojeniXP == -3){
		otkazi = 1;
	} else{
		osvojeniXP += 50;
	}
	OcistiEkran();
}
