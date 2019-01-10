#include "SkrivenaIgra.h"
#include "Igrica4Komande.h"
#include "FunkcijeZaIspis.h"
#include <stdio.h>

int Pokreni(){
	osvojeniXP = 0;
	otkaziA = 0;
	int brojac = 0, pitanja[20] = {0}, redniBroj;
	
	do{
		redniBroj = Nasumicno(20);
		if (pitanja[redniBroj] == 0) {
			pitanja[redniBroj] = 1;
			brojac++;
			Poziv(redniBroj);
		}
		
	} while(brojac < 7 && otkaziA == 0);
	
	if(otkaziA == -2){
		return -2;
	} else if(otkaziA == -3){
		return -3;
	}
	
	return osvojeniXP;
}

void Pitanje1(){
	UsporeniIspisTeksta(100, "Ko je najbrzi?\n");
	CetiriIzbora("1. Flash", "2. Quicksilver", "3. Brzi gonzales", "4. Ptica trkacica", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 30, 4, &osvojeniXP);
	Otkaziii(odgovor);
}
void Pitanje2() {
	UsporeniIspisTeksta(100, "Ko je najveci zlikovac svih vremena?\n");
	CetiriIzbora("1. Joker", "2. Hannibal ", "3. Joffrey", "4. Anton Chigurh", "HORIZONTALNO");
	CetiriIzbora("5. Tha", "6. Carnage", "7. Thanos", "8. Witch-king of Angmar", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 30, 8, &osvojeniXP);
	Otkaziii(odgovor);
}
void Pitanje3() {
	UsporeniIspisTeksta(100, "Ko je najbolji strelac?\n");
	CetiriIzbora("1. Hawkeye", "2. Robin hood", "3. Merida", "4. Green arrow", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 30, 4, &osvojeniXP);
	Otkaziii(odgovor);
}
void Pitanje4() {
	UsporeniIspisTeksta(100, "Ko je spasio vise ljudi?\n");
	CetiriIzbora("1. Superman", "2. Thor", "3. Neo", "4. Optimus Prime", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 30, 4, &osvojeniXP);
	Otkaziii(odgovor);
}
void Pitanje5() {
	UsporeniIspisTeksta(100, "Koji od ovih...\n");
	UsporeniIspisTeksta(100, "Samo odaberite jedan.\n");
	CetiriIzbora("1. South Park", "2. The Simpsons", "3. Family Guy", "4. Rick and Morty", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 30, 4, &osvojeniXP);
	Otkaziii(odgovor);
}
void Pitanje6(){
	UsporeniIspisTeksta(100, "Koji od navedenih likova je najbogatiji?\n");
	CetiriIzbora("1. Richie Rich", "2. Bruce Wayne","3. Tony Stark", "4. Scrooge McDuck", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 4){
		osvojeniXP += 25;
	} else{
		osvojeniXP -= 25;
	}
	Otkaziii(odgovor);
}
void Pitanje7(){
	UsporeniIspisTeksta(100, "Ko je najprecizniji strelac?\n");
	CetiriIzbora("1. Han Solo", "2. John Wick", "3. Deadpool", "4. Stormtrooper", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 4){
		osvojeniXP -= 25;
	} else{
		osvojeniXP += 25;
	}
	Otkaziii(odgovor);
}
void Pitanje8(){
	UsporeniIspisTeksta(100, "Ko zna najvecu tajnu?\n");
	CetiriIzbora("1. Robin", "2. Podrick Payne", "3. Bran Stark", "4. Doktor Strange", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 30, 4, &osvojeniXP);
	Otkaziii(odgovor);
}
void Pitanje9(){
	UsporeniIspisTeksta(100, "Ko je najgori agent ikada?\n");
	CetiriIzbora("1. Johnny English", "2. Frank Drebin", "3. Gary Green", "4. Carter", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 30, 4, &osvojeniXP);
	Otkaziii(odgovor);
}
void Pitanje10(){
	UsporeniIspisTeksta(100, "Koji je najbolji nacin da unistis svoju veoma uspjesnu karijeru?\n");
	CetiriIzbora("1. Ubij nekoga", "2. Pocni da se drogiras", "3. Posvadjaj se sa svim producentima", "4. Ucestvuj u youtube rewind 2018", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 30, 4, &osvojeniXP);
	Otkaziii(odgovor);
}
void Pitanje11(){
	UsporeniIspisTeksta(100, "Ko je najmocniji?\n");
	CetiriIzbora("1. Superman", "2. Hulk", "3. Rainbow Dragon", "4. Sauron", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 30, 4, &osvojeniXP);
	Otkaziii(odgovor);
}
void Pitanje12(){
	UsporeniIspisTeksta(100, "Ko je najgori pirat svih vremena?\n");
	CetiriIzbora("1. Captain James Sparrow", "2. Captain Hook", "3. Captain Ahab", "4. Sinbad", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 30, 4, &osvojeniXP);
	Otkaziii(odgovor);
}
void Pitanje13(){
	UsporeniIspisTeksta(100, "Koja od navedenih igrica je najpoznatija?\n");
	CetiriIzbora("1. Pacman", "2. Super Mario", "3. Pokemon", "4. Sonic", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 30, 4, &osvojeniXP);
	Otkaziii(odgovor);
}
void Pitanje14(){
	UsporeniIspisTeksta(100, "Ko je najbolji gospodar zmajeva?\n");
	CetiriIzbora("1. Hiccup Horrendous Haddock III", "2. Floyd", "3. Daenerys Targaryen", "4. Merlin", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 30, 4, &osvojeniXP);
	Otkaziii(odgovor);
}
void Pitanje15(){
	UsporeniIspisTeksta(100, "Najsnazniji robot od svih je?\n");
	CetiriIzbora("1. Ultron ", "2. Voltron", "3. Optimus Prime", "4. Megazord", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 30, 4, &osvojeniXP);
	Otkaziii(odgovor);
}
void Pitanje16(){
	UsporeniIspisTeksta(100, "Ko je najefikasniji ubica?\n");
	CetiriIzbora("1. Predator", "2. Punisher", "3. Deadpool", "4. Tiranossauro Rex", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 30, 4, &osvojeniXP);
	Otkaziii(odgovor);
}
void Pitanje17(){
	UsporeniIspisTeksta(100, "Najbolji ucitelj svih vremena je: \n");
	CetiriIzbora("1. Yoda", "2. Master Shifu", "3. Sensei Wu", "4. Dumbledore", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 30, 4, &osvojeniXP);
	Otkaziii(odgovor);
}

void Pitanje18(){
	UsporeniIspisTeksta(100, "Ko bi pobjedio u borbi jedan na jedan: \n");
	CetiriIzbora("1. ", "2. ", "3. ", "4. ", "HORIZONTALNO");
	DvaIzbora("1. Superman", "2. Hulk", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 30, 2, &osvojeniXP);
	Otkaziii(odgovor);
}
void Pitanje19(){
	UsporeniIspisTeksta(100, "Ko najbolje barata sa macem: \n");
	CetiriIzbora("1. The Bride", "2. Zoro", "3. Darth Maul", "4. Maximus", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 30, 2, &osvojeniXP);
	Otkaziii(odgovor);
}
void Pitanje20(){
	UsporeniIspisTeksta(100, "Ko je najmocniji carabnjak: \n");
	CetiriIzbora("1. Gandalf", "2. Albus Dumbledore", "3. White Witch", "4. Merlin", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	ProvjeraOdgovora(odgovor, 30, 2, &osvojeniXP);
	Otkaziii(odgovor);
}
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
	} else if(n == 18){
		Pitanje18();
	} else if(n == 19){
		Pitanje19();
	} else if(n == 20){
		Pitanje20();
	}
}
void Otkaziii(int odgovor){
	if(odgovor == -2){
		otkaziA = -2;
	} else if(odgovor == -3){
		otkaziA = -3;
	}
}
