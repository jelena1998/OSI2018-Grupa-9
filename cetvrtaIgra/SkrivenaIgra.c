#include "SkrivenaIgra.h"
#include "Igrica4Komande.h"
#include "FunkcijeZaIspis.h"
#include <stdio.h>

int Pokreni(){
	osvojeniXP = 0;
	int brojac = 0, pitanja[17] = {0}, redniBroj, n;

	do{
		n = Nasumicno(100);
		if(n < 17){
			redniBroj = n;
			if(pitanja[redniBroj] == 0){
			pitanja[redniBroj] = 1;
			brojac++;
			Poziv(redniBroj);
			}
		}
		
	} while(brojac < 7);
	return 0;
}

void Pitanje1(){
	UsporeniIspisTeksta(100, "Ko je najbrzi?\n");
	CetiriIzbora("1. Flash", "2. Quicksilver", "3. Brzi gonzales", "4. Ptica trkacica", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 1, 4, &osvojeniXP);
}
void Pitanje2() {
	UsporeniIspisTeksta(100, "Ko je najveci zlikovac svih vremena?\n");
	CetiriIzbora("1. Joker", "2. Hannibal ", "3. Joffrey", "4. Anton Chigurh", "HORIZONTALNO");
	CetiriIzbora("5. Tha", "6. Carnage", "7. Thanos", "8. Witch-king of Angmar", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 1, 8, &osvojeniXP);
}
void Pitanje3() {
	UsporeniIspisTeksta(100, "Ko je najbolji strelac?\n");
	CetiriIzbora("1. Hawkeye", "2. Robin hood", "3. Merida", "4. Green arrow", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 1, 4, &osvojeniXP);
}
void Pitanje4() {
	UsporeniIspisTeksta(100, "Ko je spasio vise ljudi?\n");
	CetiriIzbora("1. Superman", "2. Thor", "3. Neo", "4. Optimus Prime", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 1, 4, &osvojeniXP);
}
void Pitanje5() {
	UsporeniIspisTeksta(100, "Koji od ovih...\n");
	UsporeniIspisTeksta(100, "Samo odaberite jedan.\n");
	CetiriIzbora("1. South Park", "2. The Simpsons", "3. Family Guy", "4. Rick and Morty", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 1, 4, &osvojeniXP);
}
void Pitanje6(){
	UsporeniIspisTeksta(100, "Koji od navedenih likova je najbogatiji?\n");
	CetiriIzbora("1. Richie Rich", "2. Bruce Wayne","3. Tony Stark", "4. Scrooge McDuck", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 4){
		osvojeniXP += 1;
	} else{
		osvojeniXP -= 1;
	}
}
void Pitanje7(){
	UsporeniIspisTeksta(100, "Ko je najprecizniji strelac?\n");
	CetiriIzbora("1. Han Solo", "2. John Wick", "3. Deadpool", "4. Stormtrooper", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 4){
		osvojeniXP -= 1;
	} else{
		osvojeniXP += 1;
	}
}
void Pitanje8(){
	UsporeniIspisTeksta(100, "Ko zna najvecu tajnu?\n");
	CetiriIzbora("1. Robin", "2. Podrick Payne", "3. Bran Stark", "4. Doktor Strange", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 1, 4, &osvojeniXP);
}
void Pitanje9(){
	UsporeniIspisTeksta(100, "Ko je najgori agent ikada?\n");
	CetiriIzbora("1. Johnny English", "2. Frank Drebin", "3. Gary Green", "4. Carter", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 1, 4, &osvojeniXP);
}
void Pitanje10(){
	UsporeniIspisTeksta(100, "Koji je najbolji nacin da unistis svoju veoma uspjesnu karijeru?\n");
	CetiriIzbora("1. Ubij nekoga", "2. Pocni da se drogiras", "3. Posvadjaj se sa svim producentima", "4. Ucestvuj u youtube rewind 2018", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 1, 4, &osvojeniXP);
}
void Pitanje11(){
	UsporeniIspisTeksta(100, "Ko je najmocniji?\n");
	CetiriIzbora("1. Superman", "2. Hulk", "3. Rainbow Dragon", "4. Sauron", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 1, 4, &osvojeniXP);
}
void Pitanje12(){
	UsporeniIspisTeksta(100, "Ko je najgori pirat svih vremena?\n");
	CetiriIzbora("1. Captain James Sparrow", "2. Captain Hook", "3. Captain Ahab", "4. Sinbad", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 1, 4, &osvojeniXP);
}
void Pitanje13(){
	UsporeniIspisTeksta(100, "Koja od navedenih igrica je najpoznatija?\n");
	CetiriIzbora("1. Pacman", "2. Super Mario", "3. Pokemon", "4. Sonic", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 1, 4, &osvojeniXP);
}
void Pitanje14(){
	UsporeniIspisTeksta(100, "Ko je najbolji gospodar zmajeva?\n");
	CetiriIzbora("1. Hiccup Horrendous Haddock III", "2. Floyd", "3. Daenerys Targaryen", "4. Merlin", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 1, 4, &osvojeniXP);
}
void Pitanje15(){
	UsporeniIspisTeksta(100, "Najsnazniji robot od svih je?\n");
	CetiriIzbora("1. Ultron ", "2. Voltron", "3. Optimus Prime", "4. Megazord", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 1, 4, &osvojeniXP);
}
void Pitanje16(){
	UsporeniIspisTeksta(100, "Ko je najefikasniji ubica?\n");
	CetiriIzbora("1. Predator", "2. Punisher", "3. Deadpool", "4. Tiranossauro Rex", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 1, 4, &osvojeniXP);
}
void Pitanje17(){
	UsporeniIspisTeksta(100, "Najbolji ucitelj svih vremena je: \n");
	CetiriIzbora("1. Yoda", "2. Master Shifu", "3. Sensei Wu", "4. Dumbledore", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 1, 4, &osvojeniXP);
}
/*
void Pitanje18(){
	UsporeniIspisTeksta(100, "");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
}
void Pitanje19(){
	UsporeniIspisTeksta(100, "");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
}
void Pitanje20(){
	UsporeniIspisTeksta(100, "");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
}
void Pitanje21(){
	UsporeniIspisTeksta(100, "");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
}
void Pitanje22(){
	UsporeniIspisTeksta(100, "");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
}
void Pitanje23(){
	UsporeniIspisTeksta(100, "");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
}
void Pitanje24(){
	UsporeniIspisTeksta(100, "");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
}
void Pitanje25(){
	UsporeniIspisTeksta(100, "");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
}
void Pitanje26(){
	UsporeniIspisTeksta(100, "");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
}
void Pitanje27(){
	UsporeniIspisTeksta(100, "");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
}
void Pitanje28(){
	UsporeniIspisTeksta(100, "");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
}
void Pitanje29(){
	UsporeniIspisTeksta(100, "");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
}
void Pitanje30(){
	UsporeniIspisTeksta(100, "");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
}
void Pitanje31(){
	UsporeniIspisTeksta(100, "");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
}
void Pitanje32(){
	UsporeniIspisTeksta(100, "");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
}
void Pitanje33(){
	UsporeniIspisTeksta(100, "");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
}
void Pitanje34(){
	UsporeniIspisTeksta(100, "");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
}
void Pitanje35(){
	UsporeniIspisTeksta(100, "");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
}
void Pitanje36(){
	UsporeniIspisTeksta(100, "");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
}
void Pitanje37(){
	UsporeniIspisTeksta(100, "");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
}
void Pitanje38(){
	UsporeniIspisTeksta(100, "");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
}
void Pitanje39(){
	UsporeniIspisTeksta(100, "");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
}
void Pitanje40(){
	UsporeniIspisTeksta(100, "");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
}*/
void Poziv(int n){
	if(n == 1){
		Pitanje1();
	} else if(n == 2){
		Pitanje2();
	} else if(n == 3){
		Pitanje3();
	} else if(n == 4){
		Pitanje4();
	} else if(n == 5){
		Pitanje5();
	} else if(n == 6){
		Pitanje6();
	} else if(n == 7){
		Pitanje7();
	} else if(n == 8){
		Pitanje8();
	} else if(n == 9){
		Pitanje9();
	} else if(n == 10){
		Pitanje10();
	} else if(n == 11){
		Pitanje11();
	} else if(n == 12){
		Pitanje12();
	} else if(n == 13){
		Pitanje13();
	} else if(n == 14){
		Pitanje14();
	} else if(n == 15){
		Pitanje15();
	} else if(n == 16){
		Pitanje16();
	} else if(n == 17){
		Pitanje17();
	} /*else if(n == 18){
		Pitanje18();
	} else if(n == 19){
		Pitanje19();
	} else if(n == 20){
		Pitanje20();
	} else if(n == 21){
		Pitanje21();
	} else if(n == 22){
		Pitanje22();
	} else if(n == 23){
		Pitanje23();
	} else if(n == 24){
		Pitanje24();
	} else if(n == 25){
		Pitanje25();
	} else if(n == 26){
		Pitanje26();
	} else if(n == 27){
		Pitanje27();
	} else if(n == 28){
		Pitanje28();
	} else if(n == 29){
		Pitanje29();
	} else if(n == 30){
		Pitanje30();
	} else if(n == 31){
		Pitanje31();
	} else if(n == 32){
		Pitanje32();
	} else if(n == 33){
		Pitanje33();
	} else if(n == 34){
		Pitanje34();
	} else if(n == 35){
		Pitanje35();
	} else if(n == 36){
		Pitanje36();
	} else if(n == 37){
		Pitanje37();
	} else if(n == 38){
		Pitanje38();
	} else if(n == 39){
		Pitanje39();
	} else if(n == 40){
		Pitanje40();
	} */
}