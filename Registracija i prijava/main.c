#include "reglog.h"

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main() {
	/*napravljeno radi potreba testiranja. Smije se mijenjati main.*/
	/*Testni podaci za prijavu: korisnicko ime: ognjen lozinka testiramose*/
	printf("*** Registracija/Prijava ***\n");
	int izaberi;

		printf("1.Registracija\n2.Prijava\n(1,2)->");
		scanf("%d", &izaberi);
		switch (izaberi) {
			case 1: 
				if (reg()) printf("Uspjesno ste se registrovali!\n"); else printf("Registracija nije uspjesno prosla\n");
				break;

			case 2:
				if (login()) printf("Dobrodosli na pocetnu\n"); else printf("Korisnicko ime/lozinka su vam netacni\n");
				break;
			default: printf("Pogresan unos.\n");
		
		}

	return 0;
}