#include "Mordor.h"
#include "SkrivenaIgra.h"
#include "Igrica4Komande.h"
#include "FunkcijeZaIspis.h"
#include <stdio.h>
#include <string.h>

int Mordor(int* glavniXP2){
	system("title Mordor");
	OcistiEkran();
	Load("Mordor loading...", 32);
	glavniXP = *glavniXP2;
	osvojeniXP = 0;
	brojPomoci = 0;
	
	OnDasNot();
	
	glavniXP += osvojeniXP;
	*glavniXP2 = glavniXP;
	return 0;
}
void OnDasNot(){
	IspisSlike("Mordor.txt");
	VremenskaPauza(10);
	UsporeniIspisTeksta(100, "Unesite bilo sta kako bi ste izasli.\n");
	char hobit[6];
	scanf_s("%s", &hobit, sizeof(hobit));
	if(strcmp(hobit, "frodo") == 0){
		UMordor();
	} else if(strcmp(hobit, "FRODO") == 0){
		UMordor();
	} else if(strcmp(hobit, "Frodo") == 0){
		UMordor();
	}
}
void UMordor(){
	OcistiEkran();
	IspisSlike("Pikacu.txt");
	VremenskaPauza(3);
	Pokreni();
}
