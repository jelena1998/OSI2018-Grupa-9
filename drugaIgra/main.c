#include"kviz.h"

int main()
{
	FILE *file;
	PITANJE pitanja[5];
	int korisnikBodovi = 0, bodoviBrojac = 0;
	char pitanjaa[16]; printf("Unesi pitanjaLaka.txt ili pitanjaTeska.txt:   "); scanf("%s", pitanjaa); //dok se ne napravi manipulacija ishoda
	if ((file = fopen(pitanjaa, "r")) != NULL)
	{
		OdaberiPitanja(pitanja, file);
		fclose(file);
	}
	else
		printf("Greska pri otvaranju datoteke\n");
	IspisPocetak();
	IgrajKviz(&pitanja, &korisnikBodovi);
	return 0;
}