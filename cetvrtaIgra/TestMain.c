/*=============================================================================*/
/* OVAJ MAIN JEDINO SLUZI ZA ZAMOSTALNO POKRETANJE 4 IGRE */
/* CIM 4 IGRA BUDE IMPLEMENTIRANA U GLAVNI MAIN TJ. PLATFORMU ZA IGRE */
/* OVAJ FAJL SE TREBA OBRISATI */
/*=============================================================================*/

#include "Cetvrta Igra.h"

int main(){

	int glavniXP = 100;
	char c[10] = "123456789";
	IGRANJE rekord;
	Avantura(&glavniXP, &rekord, 50, c); // 50 - trenitni najbolji rekord ostvaren u igri
	
	return 0;
}
