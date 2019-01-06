#include "StatistikaS.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* getfield(char* line, int num){
    char* tok;
    for (tok = strtok(line, ";"); tok && *tok; tok = strtok(NULL, ";\n")){
    	if (!--num)
        	return tok;
    }
    return NULL;
}
void KreirajCSVFajl(char* ime, REZULTATI* rez){
	
	FILE* stat;
	int i, j, k;
	char imeDat[] = "Statistika_", ime2[sizeof(ime)]; // KADA SE SPOJI SA PROJEKTOM ISPRED [Statistika_] DODATI PUTANJU DO FOLDERA Korisnici
	
	strcpy(ime2, ime);
	strcat(imeDat, ime2);
	strcat(imeDat, ".csv");
	printf("\nKreiranje datoteke %s\n", imeDat);
	
	stat = fopen(imeDat, "w+");
	
	if(stat != NULL){
		fprintf(stat, "Igra, Datum, Bodovi");
		for(k = 0; k < 4; k++){
			for(i = 0; i < 10; i++){
				
				fprintf(stat, "\n%d", rez[k].igrica);
				fprintf(stat,",%s", rez[k].podaci[i].datumT);
				fprintf(stat,",%s", rez[k].podaci[i].xp);
	    	}
		}
		printf("Datoteka uspjesno kreirana.\n");
	} else{
		printf("Datoteka nije kreirana.\n");
	}
	fclose(stat);
}
void UcitajRezultate(char* ime, REZULTATI* rez){
	FILE* stat;
	int i, j, k = 0;
	char imeDat[] = "Statistika_", ime2[21]; // KADA SE SPOJI SA PROJEKTOM ISPRED [Statistika_] DODATI PUTANJU DO FOLDERA Korisnici
	
	for(i = 0; i < 4; i++){
		rez[i].igrica = i + 1;
	}
	
	strcpy(ime2, ime);
	strcat(imeDat, ime2);
	strcat(imeDat, ".csv");
	
	stat = fopen(imeDat, "r");
	if(stat != NULL){
		i = 0;
		char line[1024];
		fgets(line, 1024, stat);
	    while (fgets(line, 1024, stat)){
			
        	char* tmp = strdup(line);
        	char* data;
        	data = getfield(tmp, 1);
        	
        	int igra;
			char datum[25], xp[5], n;
			n = data[0];
			
			datum[0] = data[2];
			datum[1] = data[3];
			datum[2] = data[4];
			datum[3] = data[5];
			datum[4] = data[6];
			datum[5] = data[7];
			datum[6] = data[8];
			datum[7] = data[9];
			datum[8] = data[10];
			datum[9] = data[11];
			datum[10] = data[12];
			datum[11] = data[13];
			datum[12] = data[14];
			datum[13] = data[15];
			datum[14] = data[16];
			datum[15] = data[17];
			datum[16] = data[18];
			datum[17] = data[19];
			datum[18] = data[20];
			datum[19] = data[21];
			datum[20] = data[22];
			datum[21] = data[23];
			datum[22] = data[24];
			datum[23] = data[25];
			datum[24] = '\0';
			
			xp[0] = data[27];
			xp[1] = data[28];
			xp[2] = data[29];
			xp[3] = data[30];
			xp[4] = '\0';
			
			rez[i].igrica = atoi(&n) / 10000;
			rez[i].podaci[j].datum = 0; // Postavlja pokazivac na datum na 0 pokazivac se ne smije ukloniti iako se ne koristi, ali bez njega program iz nekog razloga pada
			int d, g;
			for(g = 0; g < 25; g++){
				rez[i].podaci[j].datumT[g] = datum[g];
			}
			for(d = 0; d < 5; d++){
				rez[i].podaci[j].xp[d] = xp[d];
			}
			
			j++;
			if(j == 10){
				i++;
				j = 0;
			}
        	
        	free(tmp);
   		}
	}
	fclose(stat);
}
void OsvjeziRezultate(REZULTATI* rez, int igraA, int osvojeniXP){
	
	int i, indeks = -1, igra = igraA - 1;
	char xp[5];
	itoa(osvojeniXP, xp, 10);
	
	for(i = 0; i < 10; i++){
		if(strcmp(rez[igra].podaci[i].xp, xp) == -1){
			indeks = i;
			break;
		}
	}
	if(indeks > -1){
		
		REZULTATI kopija[4];
		int q, w, e;
		for(q = 0; q < 4; q++){
			kopija[q].igrica = rez[q].igrica;
			for(w = 0; w < 10; w++){
				for(e = 0; e < 25; e++){
					kopija[q].podaci[w].datumT[e] = rez[q].podaci[w].datumT[e];
				}
				for(e = 0; e < 5; e++){
					kopija[q].podaci[w].xp[e] = rez[q].podaci[w].xp[e];
				}
			}
		}
		
		for(i = 10; i > indeks; i--){
			
			int d, g;
			TABELA pom;
			for(g = 0; g < 25; g++){
				pom.datumT[g] = rez[igra].podaci[i].datumT[g];
			}
			for(d = 0; d < 5; d++){
				pom.xp[d] = rez[igra].podaci[i].xp[d];
			}
			for(g = 0; g < 25; g++){
				rez[igra].podaci[i].datumT[g] = rez[igra].podaci[i - 1].datumT[g];
			}
			for(d = 0; d < 5; d++){
				rez[igra].podaci[i].xp[d] = rez[igra].podaci[i - 1].xp[d];
			}
			rez[igra].podaci[i].datum = 0;
			rez[igra].igrica = igraA;
		}
		
		time_t vrijeme;
		struct tm * vrijemePodaci;
		time(&vrijeme);
		vrijemePodaci = localtime(&vrijeme);
		
		char datum[25];
		strcpy(datum, asctime(vrijemePodaci));
		datum[24] = '\0';
		
		int d, g;
		for(g = 0; g < 25; g++){
			rez[igra].podaci[i].datumT[g] = datum[g];
		}
		for(d = 0; d < 5; d++){
			rez[igra].podaci[i].xp[d] = xp[d];
		}
		
		for(q = igra + 1; q < 4; q++){
			rez[q].igrica = kopija[q].igrica;
			for(w = 0; w < 10; w++){
				for(e = 0; e < 25; e++){
					rez[q].podaci[w].datumT[e] = kopija[q].podaci[w].datumT[e];
				}
				for(e = 0; e < 5; e++){
					rez[q].podaci[w].xp[e] = kopija[q].podaci[w].xp[e];
				}
			}
		}
	}
}
void PisiZvijezde(){
	printf("                      *************************************************************\n");
}
void PisiStrele(){
	printf("                      * /////===============================================\\\\\\\\\\ *\n");
	printf("                      *	\\\\\\\\\\===============================================///// *\n");
}
void PisiRed(){
	printf("                      *	|||||						    ||||| *\n");
}
void PisiLiniju(){
	printf("                      *	|||||	==========================================  ||||| *\n");
}
void PisiStatistiku(REZULTATI* rez){
	PisiZvijezde();
	PisiStrele();
	PisiRed();
	printf("                      *	|||||	1. Igra pogadjanja	             	    ||||| *\n");
	PisiLiniju();
	printf("                      * |||||   2. Kviz		                       	    ||||| *\n");
	PisiLiniju();
	printf("                      *	|||||	3. Loto	                         	    ||||| *\n");
	PisiLiniju();
	printf("                      *	|||||	4. Avantura	                     	    ||||| *\n");
	PisiRed();
	PisiStrele();
	PisiZvijezde();
	
	char odgovor[100];
	int igra;
	printf("\n");
	do{
		printf("\nPrikazi statistiku za: ");
		scanf("%s", odgovor);
	} while(odgovor[0] != '1' && odgovor[0] != '2' && odgovor[0] != '3' && odgovor[0] != '4');
	
	igra = atoi(&odgovor[0]);
	
	system("CLS");
	
	switch(igra) {
		case 1: PisiStatistikuIgre(&rez[0]); break;
		case 2: PisiStatistikuIgre(&rez[1]); break;
		case 3: PisiStatistikuIgre(&rez[2]); break;
		case 4: PisiStatistikuIgre(&rez[3]); break;
		default: printf("Greska pri ispisu statistike!"); break;
	}
}
void PisiStatistikuIgre(REZULTATI* rez){
	PisiZvijezde();
	PisiStrele();
	PisiRed();
	int i;
	printf("                      *	|||||       Datum igranja         Ostvareni bodovi  ||||| *\n");
	PisiLiniju();
	for(i = 0; i < 10; i++){
		printf("                      *	|||||   %s	 %s       ||||| *\n", rez->podaci[i].datumT, rez->podaci[i].xp);
	}
	PisiRed();
	PisiStrele();
	PisiZvijezde();
}

