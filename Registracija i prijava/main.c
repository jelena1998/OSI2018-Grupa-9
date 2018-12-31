#include "reglog.h"

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main() {
	/*Testni podaci za prijavu: korisnicko ime: ognjen lozinka testiramose*/
	printf("*** Registracija/Prijava ***\n");
	int izaberi;
	//za provjeru funkcija
	//do{
		//system("cls");
	//	printf("*** REG/LOGIN ***\n");
		printf("1.Registracija\n2.Prijava\n(1,2)->");
		scanf("%d", &izaberi);
		switch (izaberi) {
			case 1: 
				if (reg()) printf("Uspjesno ste se registrovali!\n"); else printf("Registracija nije uspjesno prosla\n");
				break;

			case 2:
				if (login()) printf("Dobrodosli na pocetnu\n"); else printf("Korisnicko ime/lozinka su vam netacni\n");
				break;
			//	default: printf("Greska\n");
		
		}

	//} while (izaberi != 1 || izaberi != 2);

	system("pause");
	return 0;
}