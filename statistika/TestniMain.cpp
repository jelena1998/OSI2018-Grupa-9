/*=================================================================*/
//
//	OVAJ FAJL SLUZI SAMO ZA TESTIRANJE FUNKCIJA IZ FAJLA STATISTIKA
//
/*=================================================================*/

#include "StatistikaS.h"
#include <string.h>
#include <stdio.h>
#include <time.h>

int main(){
	
	char ime[21] = "Test"; // Ime igraca. Koristi se pri kreiranju imena CSV datoteke
	REZULTATI rez[4];
	UcitajRezultate(ime, rez);
	int i, j, k;
	
	/* AKO CSV FAJL SA DATIM IMENOM POSTOJI OVA FOR PETLJA MORA BITI KOMENTARISANA POSTO */
	/* ONA SLUZI ZA POPUNJAVANJE REZULTATA KADA NEMA FAJLA IZ KOGA BI SE UCITALI REZULTATI */
/*	
	for(i = 0; i < 4; i++){
		for(j = 0; j < 10; j++){
			
			time_t vrijeme;
			struct tm * vrijemePodaci;
			time(&vrijeme);
			vrijemePodaci = localtime(&vrijeme);
			
			int k;
			char xp[5];
			
			xp[0] = '1' + i;
			xp[1] = '0' + (9 - j);
			xp[2] = '0';
			xp[3] = '0';
			xp[4] = '\0';
			
			char datum[25];
			strcpy(datum, asctime(vrijemePodaci));
			datum[24] = '\0';
			
			rez[i].podaci[j].datum = 0; // Postavlja pokazivac na datum na 0 pokazivac se ne smije ukloniti iako se ne koristi, ali bez njega program iz nekog razloga pada
			int d, g;
			for(g = 0; g < 25; g++){
				rez[i].podaci[j].datumT[g] = datum[g];
			}
			for(d = 0; d < 5; d++){
				rez[i].podaci[j].xp[d] = xp[d];
			}
			
			printf("%d ======== %s     %s\n", i, rez[i].podaci[j].xp, rez[i].podaci[j].datumT);
		}
	}
*/	
	
	PisiStatistiku(rez);
	OsvjeziRezultate(rez, 1, 9999);
	OsvjeziRezultate(rez, 3, 9999);
	OsvjeziRezultate(rez, 2, 9999);
	PisiStatistiku(rez);
	
	KreirajCSVFajl(ime, rez);
	return 0;
}
