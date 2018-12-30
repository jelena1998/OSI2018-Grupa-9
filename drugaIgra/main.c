#include"kviz.h"

int main()
{
	FILE *file;
	PITANJE pitanja[5];
	int i;
	int korisnikBodovi = 0, bodoviBrojac = 0;
	if ((file = fopen("pitanja.txt", "r")) != NULL)
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