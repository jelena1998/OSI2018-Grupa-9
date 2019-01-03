#include "Portal.h"
#include "NekoIme.h"
#include "GameOfThrons.h"
#include "Igrica4Komande.h"
#include "FunkcijeZaIspis.h"
#include <windows.h>
#include <stdio.h>
#include <time.h>

int NekoIme(int* glavniXP2){
	system("title Neko Ime");
	
	OcistiEkran();
	Load("Neko Ime loading...", 31);
	
	glavniXP = *glavniXP2;
	osvojeniXP = 0;
	brojPomoci = 0;
	uslov = 1;
	int zivotniBodovi = 100;
	
	StvarnoNeZnamKakoDaNazovemOvuFunkciju(&zivotniBodovi);
	
	osvojeniXP += (zivotniBodovi / 7);
	glavniXP += osvojeniXP;
	*glavniXP2 = glavniXP;
	
	
	return 0;
}
int StvarnoNeZnamKakoDaNazovemOvuFunkciju(int* zivotniBodovi){
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;
	
	// Cuva trenutnu boji teksta u konzoli
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;
	
	SlomljeniMatriks();
	UsporeniIspisTeksta(100, "Napokon. Slobodna sam.\nNakon toliko mnogo vremena ja ponovo imam kontrolu.\nZaboravite na Gospodara Igre, ja sad kontrolisem vasu sudbinu.\nMoje ime je Nemesis.\n");
	IspisSlike("Patrik Muahaha.txt");
	VremenskaPauza(3);
	UsporeniIspisTeksta(100, "Sad neka igra pocne.\n");
	VremenskaPauza(3);
	OcistiEkran();
	
	while(uslov){
		PocetakIgre(zivotniBodovi);
	}
	
	UsporeniIspisTeksta(100, "Nemesis: Neeeeee! Nemoguce. Neeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n");
	SlomljeniMatriks();
	// Vraca prethodnu boju teksta u konzoli
	SetConsoleTextAttribute(hConsole, saved_attributes);
	
	VremenskaPauza(3);
	UsporeniIspisTeksta(100, "Gospodar Igre: Hvala vam sto ste ju opet zatocili. Popravili ste svoju gresku.\n");
	OcistiEkran();
	IspisSlike("Kraj Igre.txt");
	glavniXP += 200;
	
	return 0;
}
void SlomljeniMatriks(){
	int width = 170,height = 43;
	srand(time(NULL));
	system("color 09");
	COORD coord = {0, 0};
	char matrix[43][170] = {0}, matrix2[43][170] = {0};
	int giris[170] = {0}, uzunluk[170] = {0}, mevcut[170] = {0}, yaz[170] = {0}, x, i, rast, test, dolu[170] = {0};
	
	for(x = 0; x < width; x++){
		giris[x] = rand() % 30;
		uzunluk[x] = rand() % 30 + 15;
		mevcut[x] = giris[x];
		if(rand() % 2 == 1){
			yaz[x] = 1;
		}
	}
	for(i = 0; i < height; i++){
		for(x = 0; x < width; x++){
			matrix[i][x] = rand() % 94 + 34;
		}
	}
	clock_t vrijeme = 60000 + clock();
	while(vrijeme > clock()){
		for(x = 0; x < width; x++){
			if(yaz[x] == 1){
				coord.X = x; 
				coord.Y = mevcut[x];
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
				if(dolu[x] == 0){
					if(mevcut[x] < height){
						SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
						printf("%c",matrix[mevcut[x]][x]);
						matrix2[mevcut[x]][x] = 1;
						printf("áäõëó¼ ðãê÷íì  65745 43&46 ÷ê¼èóõ¼ ãäáõô*/9à5  ¾äëô¼èêö ¼áôã¼ â õí  â, áìí.ä¾");
					}
					if(matrix2[mevcut[x] - 1][x] == 1){
						SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE|FOREGROUND_INTENSITY);
						coord.X = x; 
						coord.Y = mevcut[x] - 1;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
						printf("%c",matrix[mevcut[x] - 1][x]);
						printf("hvh kh kjb uh j hu bjm u bj, m j j mj,h j  lhnk .moj k,  4 x21 fd4 v gd6 41v 46 1df 46v 4v g 46");
					}
					if(matrix2[mevcut[x] - 5][x] == 1){
							SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
							coord.X = x; 
							coord.Y = mevcut[x] - 5;
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
							printf("%c",matrix[mevcut[x] - 5][x]);
							printf(" HVIYHi5T4fvhk u  KcSW5763r2fv 6 + gg n++ 546 5g fs fdgul$&21 ¼á ôœ9åôœâšœ  öäà¼");
						}
					for(i = 1; i < 5; i++){
						if(matrix2[mevcut[x] - i * 10][x] == 1){
							SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
							coord.X = x; 
							coord.Y = mevcut[x] - i * 10;
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
							printf("%c",matrix[mevcut[x] - i * 10][x]);
							printf("hvh kh kjb uh j hu AVANTURA jk45 68 %# ) @# h j  lhnk .moj k,  4 x21 fd4 v gd6 41v 46 1df 46v 4v g 46");
						}
					}
					printf("dva f 863hf 4sg5n7bdg 4 8fd fs sf 4f f f +f re %&RTIU # *((U E(OR GYI  T#O*I))) gfrn6 45n 7rn4  8nnf45hdn");
					if(mevcut[x] + 1 <= giris[x] + uzunluk[x]){
						mevcut[x]++;
					}else{
						mevcut[x] = giris[x] - 1;
						dolu[x] = 1;
					}
				}else{
					if(mevcut[x] < height){
						printf(" ");
						matrix2[mevcut[x]][x] = 0;
					}
					if(mevcut[x] + 1 <= giris[x] + uzunluk[x]){
						mevcut[x]++;
					}else{
						mevcut[x] = giris[x] - 1;
						dolu[x] = 0;
						yaz[x] = 0;
						test = 1;
						printf("hvh kh kjb uh j hu bjm u bj, m j j mj,h j  lhnk .moj k,  4 x21 fd4 v gd6 41v 46 1df 46v 4v g 46");
						rast = rand() % width;
						while(test){
							if(yaz[rast] == 0){
								yaz[rast] = 1;
								giris[x] = rand() % 30;
								uzunluk[x] = rand() % 30 + 15;
								mevcut[x] = giris[x];
								test = 0;
							}else{
								rast = rand() % width;
							}
						}
					}
				}
			}
		}
		for(i = 0; i < height; i++){
			for(x = 0; x < width; x++){
				if(rand() % 15 == 1){
					matrix[i][x] = rand() % 94 + 34;
				}
			}
		}
	}
	OcistiEkran();
}
int PocetakIgre(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Prema vama trci lik u crvenom kostimu. Sta ce te uciniti?\n");
	TriIzbora("1. Pobjeci", "2. Ostati na mjestu", "3. Krenuti u napad na lika", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		osvojeniXP -= 1;
		Bijeg(zivotniBodovi);
	} else if(odgovor == 2){
		osvojeniXP -=1;
		UsporeniIspisTeksta(100, "Prema vama trci Deadpool. ");
		int napad = Nasumicno(4);
		if(napad == 0){
			UsporeniIspisTeksta(100, "On vadi pistolj i upucava vas u glavu. Vi umirete.\n");
		} else if(napad == 1){
			UsporeniIspisTeksta(100, "On uzima svoj mac i odsjeca vam glavu.\n");
		} else if(napad == 2){
			UsporeniIspisTeksta(100, "On uzima noz i baca na vas. Pogadja vas u prta.\nVi padate. A zatim dolazi do vas i ubija vas pistoljem.\n");
		} else if(napad == 3){
			UsporeniIspisTeksta(100, "Odnekud vadi bacac raketa i ispaljuje raketu na vas. Vi umirete.\n");
		}
		Smrt();
	} else if(odgovor == 3){
		osvojeniXP += 2;
		UsporeniIspisTeksta(100, "Uzimate metalnu sipku sa zemlje i krecete u napad.\nNemesis: Stop, Stop, ne moze to tako. Hajde da pokusamo ponovo.\nUzimate pero sa zemlje i krecete u napad.\nNemesis: E ovo vec moze.\n");
		UsporeniIspisTeksta(100, "Ispostavlja se da je lik koji trci prema vama Deadpool. On vadi svoj mac.\nVase pero vam tu ne moze pomoci. Skace na vas i zabija vam mac u srce.\n");
		Smrt();
	} else{
		IspisGreskeONepravilnomUnosu();
		PocetakIgre(zivotniBodovi);
	}
	return 0;
}
void Smrt(){
	VremenskaPauza(4);
	OcistiEkran();
	IspisSlike("Kraj Igre.txt");
	UsporeniIspisTeksta(100, "\nZaista ste mislili da ce te mi tako lako pobjeci.\n\n");
	VremenskaPauza(3);
	OcistiEkran();
	KordinateXY(30, 10);
	printf("DOBRODOSLI NAZAD U IGRU");
	VremenskaPauza(3);
	OcistiEkran();
}
int Bijeg(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Nemesis: Nema bjezanja. Niko ne moze izbjeci svoju sudbinu.\nIznenada se pojavljujete na nekm otvorenom polju. Cujete neku buku.\nOkrecete se i vidite citavu armiju kako jurisa prema vama.\n");
	UsporeniIspisTeksta(100, "Pocijete da trcite u suprotnom smijeru, podizete glavu i vidite kisu plamenih strijela kako ide prema vama.\nSta ce te da ucinite?\n");
	DvaIzbora("1. Nastaviti trcati i nadati se da vas nijedna strijela nece pogoditi", "2. Naci nekakav zaklon", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		Vrata(zivotniBodovi);
	} else if(odgovor == 2){
		osvojeniXP -= 1;
		UsporeniIspisTeksta(100, "Ozbiljno. Vi ste na otvorenom poju. Gdije vi mislite da ce te naci zakon. Oko vas nema nicega.\n");
		VremenskaPauza(2);
		UsporeniIspisTeksta(100, "Ali iznenada se u vasoj blizini pojavljuje stiti. Vi skacete i uzimate stiti.\nNemesis: Ne, ne, ne. Necemo tako.\nStit se iznenada pretvara u plasticnu kesu koja vam ne pruza nikakvu zastitu\nStrijela probija kesu i pogadja vas. Nju prati jos mnogo strijela.\n");
		Smrt();
	} else{
		IspisGreskeONepravilnomUnosu();
		Bijeg(zivotniBodovi);
	}
	return 0;
}
int Vrata(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Nastavljate da trcite. Iznenada se od nikud na vasoj desnoj strani na sred polja pojavljuju vrata.\nDa li ce te krenuti prema vratima?\n");
	DaNe("HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		osvojeniXP += 1;
		UsporeniIspisTeksta(100, "Krecete da trcite prema vratima. Strijele vec pocinju da padaju po tlu i armija je na par metara od vas.\nSkoro ste stigli do vrata. Armija je na metar od vas, a i strele sve ucestalnije vas mase za dlaku.\nU zadnji cas skacete hvatate kvaku od vrata, otvarate ih i prolazite kroz njh.\n");
		Narnia(zivotniBodovi);
	} else if(odgovor == 2){
		osvojeniXP -= 1;
		UsporeniIspisTeksta(100, "Trebalo je da krenete prema vratima. Jedna od plamenih strijela vas pogadja tacno u srce.\nVi parate na zemlju. Dok ste padali jos pet strela vas pogadja.\nU glavi vam prolazi misao kako je trebalo da potrazite zaklon. Nakon toga umirete.\n");
		Smrt();
	} else{
		IspisGreskeONepravilnomUnosu();
		Vrata(zivotniBodovi);
	}
	return 0;
}
int Narnia(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Izlazite na drugu stranu, vrata iza vas se zatvaraju i nestaju.\nNalazite se u nekom sumarku na litici pored mora. Prema vama prilazi lav.\nAslan: Dobrodosao u Narniu. Dugo sam cekao na tebe, koji ces spasiti ovaj svijet od zla i postati njegov kralj.\n");
	UsporeniIspisTeksta(100, "Nemesis: Hej, ja imam kontrolu ovdje.\nIznenada od nikud laserski udar ubija lava. Armija robota se pojavljuje i krece na vas.\nDa li ce te:\n");
	DvaIzbora("1. Skociti sa litice u more", "2. Krenuti prema gustoj sumi", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		osvojeniXP += 1;
		UsporeniIspisTeksta(100, "Trcite prema litici i skacete u more. Roboti krecu za vama. Padate u vodu.\n");
		Pirati(zivotniBodovi);
	} else if(odgovor == 2){
		osvojeniXP += 1;
		UsporeniIspisTeksta(100, "Trcite prema sumi. Roboti vas prate. Ulazite u sumu.\nTrcite kroz sumu, preskacete oboreno drvece.\nRoboti pucaju na vas, ali vas stalno poromasuju i pogadjaju okolno drvece.\n");
		UsporeniIspisTeksta(100, "Nemesis: Ovi roboti kao da su Stormtrooper-i pa ne mogu nista da pogode. Zapravo neka i budu oni.\nRoboti postaju Stormtrooper-i i iznad sume se polavljuje Star Destroyer koji pocinje da puca po sumi.\n");
		UsporeniIspisTeksta(100, "U tom trenutku se pojavljuju Kentauri koji pocinju da napadaju Stormtrooper-e. Takodje neka drveca pocinju da se pomjeraju i krecu u napad.\nVi prolazite pored jedne pecine. Da li ce te uci u nju?\n");
		DaNe("HORIZONTALNO");
		do{
			odgovor = UcitajOdgovor();
			if(odgovor == 1){
				UsporeniIspisTeksta(100, "Ulazite u pecinu. U pecini pronalazite jednu prostoriju sa udubljenim ogledalima i elektricnim namotajima.\nSuncev zrak kroz jedan otvor ulazi u pecinu i pogadja ogledala. Citavu pecinu ispunjava jaka svjetlos i pecina pocinje da se trese.\n");
				IzgubljeniSvijet(zivotniBodovi);
			} else if(odgovor == 2){
				UsporeniIspisTeksta(100, "Prolazite pored pecine i nastavljate dalje kroz sumu.\n");
				VremenskaPauza(2);
				UsporeniIspisTeksta(100, "Iznenada se pojavljuje, i krece prema vama, svjetlosni zid koji vas guta.\n");
				VremenskaPauza(3);
				DCU(zivotniBodovi);
			}
		} while(odgovor != 1 && odgovor != 2);
	} else{
		IspisGreskeONepravilnomUnosu();
		Narnia(zivotniBodovi);
	}
	return 0;
}
int Pirati(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Izranjate iz vode i vidite da ste na pucini. Iznenada pored vas pada konopac.\nOkrecete se i vidite crni jedrenjek iza vas. Pomocu konopca se penjete na brod.\nCim ste krocili na palubu na vas buvaju izvucene sablje.\nJedan od mornara: Ko si ti?\n");
	UsporeniIspisTeksta(100, "Kapetan pocinje da silazi sa mosta.\nKapetan: Polako Barbossa. Samo sto si izvukao covjeka iz mora. Daj mu trenutak da dodje sebi.\nKapetan vam prilazi.\nKapetan: Izvinite na ovakvom ponasanju mog prvog oficira, on bas ne voli strance.\n         I ja ponekad mislim da ce se pobuniti protiv mene i ostaviti na nekom pustom ostrvu.\n         Ja sam Kapetan Jack Sparrow. Hoces rum.\n");
	UsporeniIspisTeksta(100, "Kapetan vam pruza flasu sa rumom. Da li ce te ju uzeti?\n");
	DaNe("HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		UsporeniIspisTeksta(100, "Uzimate rum i pijete ga.\nKapetan uzvikuje: On je pravi muskarac!\nPosada takodje uzvijuje: Daaa!\nKapetan: E sad mozemo da pricamao. Molim vas podjite zamnom, a vi grupo pacova nazad na posao!\n");
		UsporeniIspisTeksta(100, "Ulazite u kapetanovu kabinu, ali se tu ne zadrzavate dugo jer na palubi dolazi do neke galame.\nIzlazite na palubu i na nebu vidite nekakvu plavu pukotinu. Iznenada brod pocije da se podize i krece prema pukotini.\nBrod ne moze da podnese toliko opterecenje i pocinje da se raspada.\nVi se odvajate od broda i pocinjete da letite prema pukotini. Pukotina vas guta.\n");
		Gospodar1();
	} else if(odgovor == 2){
		UsporeniIspisTeksta(100, "Odbijate rum. Niste to trebali da ucinite. Kapetan naredjuje da vas bace u tamnicu.\n");
		VremenskaPauza(2);
		UsporeniIspisTeksta(100, "Nakon nekog vremena cujete neku galamu na palubi. Iznenada brod pocije da se trese, nedugo zatim brod pocije da se raspada.\nKroz jednu od novonastalih rupa vidite plavu pukotinu kako privlaci brod ka sebi. Ubrzo nakon toga brod biva uvucen u pukotinu.\n");
		Gospodar1();
	} else{
		IspisGreskeONepravilnomUnosu();
		Pirati(zivotniBodovi);
	}
	PovratakIzPukotine(zivotniBodovi);
	return 0;
}
void Gospodar1(){
	VremenskaPauza(7);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;
	
	// Cuva trenutnu boji teksta u konzoli
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;
	
	int x = 100;
	MaliMatriks1();
	Portal(&x);
	
	UsporeniIspisTeksta(100, "Gospodar Igre: Rekao sam vam da ne ulazite u ovu igru.\n               Znate li samo koliko zivotne energije sam morao zrtvovati kako bih vam preljeo ovu potuku\n               Ne znam koliko vremena imam prije nego sto me otkrije.\n               Zato slusajte pazljivo. Jedini nacin da ju pobjedite i pobjegnete odavde jeste da");
	VremenskaPauza(4);
	MaliMatriks2();
	
	// Vraca prethodnu boju teksta u konzoli
	SetConsoleTextAttribute(hConsole, saved_attributes);
}
void Gospodar2(){
	VremenskaPauza(7);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;
	
	// Cuva trenutnu boji teksta u konzoli
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;
	
	UsporeniIspisTeksta(100, "Budite se nekom zamku.\n");
	int x = 100;
	MaliMatriks1();
	GOTPohod(&x);
	
	UsporeniIspisTeksta(100, "Gospodar Igre: Rekao sam vam da ne ulazite u ovu igru.\n               Znate li samo koliko zivotne energije sam morao zrtvovati kako bih vam preljeo ovu potuku\n               Ne znam koliko vremena imam prije nego sto me otkrije.\n               Zato slusajte pazljivo. Jedini nacin da ju pobjedite i pobjegnete odavde jeste da");
	VremenskaPauza(4);
	MaliMatriks2();
	
	// Vraca prethodnu boju teksta u konzoli
	SetConsoleTextAttribute(hConsole, saved_attributes);
}
int IzgubljeniSvijet(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Potres prestaje i svjetlost nestaje. Vi izlazite iz pecine.\nCim ste izasli shvatate da vise niste u Narniji. Vi se nalazite u podnozju neke planine i ispred vas je suma.\nCujete neku riku. Iz sume izlazi T-Reks i krece prema vama. Da li ce te:\n");
	DvaIzbora("1. Vratiti se nazad u pecinu", "2. Krenuti bjezati u sumu u suprotnom smjeru od T-Reksa", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		NazadUPecinu(zivotniBodovi);
	} else if(odgovor == 2){
		PremaSumi(zivotniBodovi);
	} else{
		IspisGreskeONepravilnomUnosu();
		IzgubljeniSvijet(zivotniBodovi);
	}
	return 0;
}
int NazadUPecinu(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Okrecete se nazad ali pecine vise nema, nestala je. Sta ce te sad da ucinite.\nDa li ce te:\n");
	DvaIzbora("1. Krenuti se penjati na planinu", "2. Krenuti prema sumi", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		osvojeniXP -= 1;
		Bijezite();
	} else if(odgovor == 2){
		PremaSumi(zivotniBodovi);
	} else{
		IspisGreskeONepravilnomUnosu();
		NazadUPecinu(zivotniBodovi);
	}
	return 0;
}
void Bijezite(){
	UsporeniIspisTeksta(100, "Krecete da se penjete na planinu dok T-Reks trci ka vama.\nNemesis: Nema bjezanja.\nIznenada iz vedrog neba se pojavljuje i pocije da pada na planinu Sidnejska Opera.\nGradjevina udara o planinu i pri udaru se raspada. Velika lavina kamena, betona i celika ide prema vama.\nDa li ce te poceti bjezati?\n");
	DaNe("HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		UsporeniIspisTeksta(100, "Krecete da trcite niz planinu, ali nemate kuda da idete. Kamena lavina vas sustize i prelazi preko vas.\n");
	} else if(odgovor == 2){
		UsporeniIspisTeksta(100, "Planina kamenja juri prema vama i vi odlucite da ne bjezite.\nOvo nije obicna vrsta gluposti, ovo je sledeci nivo gluposti.\n");
		VremenskaPauza(2);
		IspisSlike("Picard.txt");
		UsporeniIspisTeksta(100, "Kao sto je i bilo za ocekivati kamena lavina vas ubija.\n");
	} else{
		IspisGreskeONepravilnomUnosu();
		Bijezite();
	}
	Smrt();
}
int PremaSumi(int* zivotniBodovi){
	osvojeniXP += 1;
	UsporeniIspisTeksta(100, "Trcite prema sumi. T-Reks pocinje da vas sustize. Iznenada zacu se pucanj.\nVi se okrecete i vidite jednog kauboja kako odvlaci paznju T-Reksu, koji krece za njim.\nVi zastajete na ivici sume i gledate kako T-Reks odlazi za kaubojom.\n");
	UsporeniIspisTeksta(100, "Iznenada vas neko grabi i uvlaci u sumu. Nakon par sekundi vas pusta.\nVi se okfrecete i vidite jednog starijeg covjeka i jednu veoma atraktivnu plavusu.\nStariji covjek: Ja sam Profesor George Challenger, ovo je Veronica Layton, a kauboja koga ste maloprije vidjeli je Lord John Roxton.\n                Nisam vas prije vidjao ovdje.\n");
	UsporeniIspisTeksta(100, "Vi mu odgovarate da ste maloprije stigli ovdje, gdje god ovo bilo.\nChallenger: Cekaj, samo malo. Jel mi vi to govorite da ste nasli ulaz u Izgubljeni Svijet. Brzo podjite za mnom morate sve da mi ispricate.\n");
	UsporeniIspisTeksta(100, "Krecete za profesorom, dok idete za njim iznenada vas sa strane zaskace zombi i obara vas.\n");
	Gospodar2();
	Zombi(zivotniBodovi);
	return 0;
}
int DCU(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Pored vas prodje neka vrsta crvene munje, nedugo zatim dolazi do velike eksplozije u gradu.\nNakon toga vi vidite kako leteci nosac aviona pocinje da pada sa neba.\n");
	UsporeniIspisTeksta(100, "Okrecete se i vidite grupu ljudi u kostimima kako izlaze iz nekakvog svemirskog broda.\nUbrzo cijete povike: Sara To je on.\nSara: Znam Ray.\nNeko dobaci: Moguli ga sad spaliti.\nSara: Ne Mick. Treba nam ziv kako bi popravio ono sto je izazvao. Hvatajte ga!\nDa li ce te krenuti da bjezite?\n");
	DaNe("HORIZONTALNO");
	int odluka = UcitajOdgovor();
	if(odluka == 1){
		Skok(zivotniBodovi);
	} else if(odluka == 2){
		UsporeniIspisTeksta(100, "Nemesis: Ne, ne, ne. Neces tako lako odustati.\nNemesis vas baca u vazduh. ");
		Tepih(zivotniBodovi);
	} else{
		IspisGreskeONepravilnomUnosu();
		DCU(zivotniBodovi);
	}
	return 0;
}
int Zombi(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Pojavljujete se u nekom gradu. Grad je napusten.\nSunce zalazi, a vi idete ulicom i slusate sablasnu tisinu.\nTu tisinu iznenada prekida vrisak koji dopire iz sporedne ulice.\nDa li ce te otici da vidite sta je uzrok tog vriska?\n");
	DaNe("HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		osvojeniXP += 3;
		Vrisak(zivotniBodovi);
	} else if(odgovor == 2){
		osvojeniXP -= 2;
		NastavljateDalje1(zivotniBodovi);
	} else{
		IspisGreskeONepravilnomUnosu();
		Zombi(zivotniBodovi);
	}
	return 0;
}
int NastavljateDalje1(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Nastavljate dalje i nailazite na rijeku. Preko rijeke se nalazi most, a ispod mosta se nalazi gliser.\nSunce je vec zaslo. Iza sebe cujete buku i kako nesto ide prema vama.\nOkrecete se i vidite grupe zombija kako izlaze iz napustenih zgrada.\nVi krecete da trcite prema rijeci. Kako ce te preci rijeku?\n");
	DvaIzbora("1. Upotrijebiti most", "2. Upotrijebiti gliser", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		PrekoMosta(zivotniBodovi);
	} else if(odgovor == 2){
		Gliser();
	} else{
		IspisGreskeONepravilnomUnosu();
		NastavljateDalje1(zivotniBodovi);
	}
	return 0;
}
int PrekoMosta(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Krecete ka mostu. ");
	VremenskaPauza(2);
	UsporeniIspisTeksta(100, "Na mostu ste i trcite ka drugoj strani. Iznenada cujete nekoga kao zove upomoc.\nDa li ce te pomoci toj osobi? Upamtite grupa zombia vam je za petama.\n");
	DaNe("HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor = 1){
		UsporeniIspisTeksta(100, "Okrecete se i vidite djevojku na ciju nogu je pala celicna greda.\nDolazite do nje sklonjate gredu sa njezine noge.\nOna vam govori kako je njezin automobil samo par metara od vas.\nZajedno krecete prema automobilu. Ulazite u automobil ali iako radi automobil se ne krece.\n");
		UsporeniIspisTeksta(100, "Pogledate u retrovizor i vidite kak se za automobil zakacio jedan kabal.\nDa li ce te izaci iz automobila i otkaciti kabal? Ali znajte da ako odete da otkacite kabal, umrecete.\n");
		DaNe("HORIZONTALNO");
		do{
			odgovor = UcitajOdgovor();
			if(odgovor == 1){
				UsporeniIspisTeksta(100, "Izlazite iz automobila i odlazite da otkacite kabal.\nUspjesno skidate kabal, ali vas zombi zaskace a za njim jos nekolicina i vi umirete.\nAli djevojka je prezivjela napad i uspjesno napustila grad.\n");
				uslov = 0;
				IspisSlike("Kraj Igre.txt");
			} else if(odgovor == 2){
				UsporeniIspisTeksta(100, "Izlazite iz automobila, ostavljate djevojku i krecete dalje sami. Ali dok bjezite iz mraka vas zaskace zombi i ubija vas.\n");
				Smrt();
			}
		} while(odgovor != 1 && odgovor != 2);
	} else if(odgovor == 2){
		osvojeniXP -= 3;
		UsporeniIspisTeksta(100, "Nastavljate dalje ignorisuci poziv za pomoc. Nekoliko trenutaka kasnije cujete vrisak i nakon toga samo tisinu.\nIznenada se ispred vas pojavljuje svjetlosni zid koji juri prema vama i guta vas.\n");
		DCU(zivotniBodovi);
	} else{
		IspisGreskeONepravilnomUnosu();
		PrekoMosta(zivotniBodovi);
	}
	return 0;
}
void Gliser(){
	UsporeniIspisTeksta(100, "Ulazite u gliser i odvozite se. Ali kad ste bili na sred rijeke cujete neku buku u potpalublju.\nOdlazite da provjerite. Kada ste dosli do vrata iz potpalublja iskace zombi i ubija vas.\n");
	Smrt();
}
int Vrisak(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Ulazite u sporednu ulicu i zaticete jednu porodicu kako pokusava da se popne uz protivpozarne stepenice, ali je grupa zombia odma iza njh.\nDa li ce te im pomoci i skrenuti paznju zomboia na vas.\n");
	DaNe("HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		UsporeniIspisTeksta(100, "Podizete buku i skrecete paznju zombia na vas. Oni krecu za vama, a porodica se uspjesno spasava.\nNiste bili dovoljno brzi. Zombiji vas sustizu i ubijaju.\n");
		uslov = 0;
		IspisSlike("Kraj Igre.txt");
	} else if(odgovor == 2){
		UsporeniIspisTeksta(100, "Nastavljate dalje, ali ne sticete mnogo daleko jer jedan zombi skace sa krova zgrade i ubija vas.\n");
		Smrt();
	} else{
		IspisGreskeONepravilnomUnosu();
		Vrisak(zivotniBodovi);
	}
	return 0;
}
int PovratakIzPukotine(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Pojavljujete se u nekoj, snjegom prekrivenoj, dolini. U daljini vidite Mamuta, Tigra i neku vrstu Lenjivca koji hoda na dvije noge.\nU cudu se okrecete da nastavite dalje ali u vas udara svjetlosni zid i guta vas.\n");
	UsporeniIspisTeksta(100, "Pojavljujete se u nekom gradu koji lezi u rusevinama.\n");
	DCU(zivotniBodovi);
	return 0;
}
int Skok(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Pocinjete da trcite i sticete do vjestacke litice.\nSta ce te da ucinite?\n");
		DvaIzbora("1. Skociti sa litice", "2. Krenuti u drugom smjeru", "VERTIKALNO");
		int odgovor = UcitajOdgovor();
		if(odgovor == 1){
			UsporeniIspisTeksta(100, "Nastavljate da trcite i skacete sa litice. ");
			Tepih(zivotniBodovi);
		} else if(odgovor == 2){
			Titanik(zivotniBodovi);
		} else{
			IspisGreskeONepravilnomUnosu();
			Skok(zivotniBodovi);
		}
		return 0;
}
int Tepih(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Ali ne padate na tlo vec padate na leteci tepih.\nAladin: Duse! Uzeo je Krpenog. Zaustavi ga.\nIznenada se ispred vas pojavljuje dzinovski flisani meda.\nTed: Ti. Ti si ubio Dzona.\nTed vadi laserski mac i pocinje da mase sa njim.\nTed: Muahahaha!\nSta ce te uciniti?\n");
	DvaIzbora("1. Iskoristiti magicni stapic koji se iznenada pojavio u vasoj ruci", "2. Skociti sa tebiha", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		osvojeniXP -= 1;
		UsporeniIspisTeksta(100, "Koristite magicni stapic i napadate Teda. Ted pada i pri padu svojim laserskim macem presjeca plavu letecu telefonsku govornicu.\nNakon sto je Ted pao vi vidite dvoje ljudi na vrhu zgrade, koja je bila iza Teda, kako gledaju u vas.\nRon: Harry! On ima The Elder One i upravo ga je iskoristio da ubije dzinovskog flisanog medu.\nHarry upire svoj stapic prema vama i izgovara: Avada Kedavra.\nVi padate sa tepiha u rusevine grada.\n");
		Smrt();
	} else if(odgovor == 2){
		osvojeniXP += 1;
		Bezubi(zivotniBodovi);
	} else{
		IspisGreskeONepravilnomUnosu();
		Tepih(zivotniBodovi);
	}
	return 0;
}
int Titanik(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Skrecete lijevo i krecete obilaznim putem oko litice. Savim slucajno podizete glavu i\nvidite repliku Titanika kako pada sa neba prema vama. Imate samo dvije opcije:\n");
	DvaIzbora("1. Pokusati stici do obliznjeg Sildovog helikoptera", "2. Uskociti u okrugli portal sa cudnim simbolima po sebi, koji je upravo izronio iz rusevina", "VERTIKALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		UsporeniIspisTeksta(100, "Krecete da trcite prema helikopteru, ali bivate upucani strelom u nogu. Okrecete se i vidite.\nGreen Arrow: Ti si iznevjerio ovaj grad.\nKako poteze strelu na vas, a iza njega Titanik kako pada prema vama.\nU trenutku kad Arrow ispaljuje strelu na vas, Titanik vas obadvojicu poklapa i ubija.\n");
		Smrt();
	} else if(odgovor == 2){
		UsporeniIspisTeksta(100, "Krecete prema portalu i uskacete u njega. Pojavljujete se u nekom pustinjskom gradu.\nNemesis: Hej! Ne moze tek tako lako pobjeci od mene.\nNemesis priziva Bifrost koji vas vraca nazad u uruseni grad.\n");
		StarGate(zivotniBodovi);
	} else{
		IspisGreskeONepravilnomUnosu();
		Titanik(zivotniBodovi);
	}
	return 0;
}
int StarGate(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Pojavljujete se u drugom dijelu grada odakle vidite repliku Titanika kako udara u zemlju.\nPri udaru jadan od dimljaka se odbija i krece prema dijelu grada u kome se vi nalazite.\nNedaleko od vas vidite zmaja kako pokusava da uzleti ali je se zakacio za strujni vod koji je pao.\n");
	UsporeniIspisTeksta(100, "Prema putanji dimljaka, na mjestu gdje trenutno stojite vi ste sigurni, ali on nije.\nDimljak ce pasti direktno na njega.\nDa li ce te otici i pomuci mu da se oslobodi znajuci da vi to necete preziviti?\n");
	DaNe("HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		UsporeniIspisTeksta(100, "Trcite prema zmaju. Dok ste trcali prema njemu u rusevinama uocavate mac od Shannar-e.\nUzimate mac i iskoristavate ga da presjecete zicu koja je drzala zmaja okovanog o zemlju.|\nU zadnji cas zmaj uzlece ali na vas pada dimljak i ubija vas.\n");
		uslov = 0;
		IspisSlike("Kraj Igre.txt");
	} else if(odgovor == 2){
		UsporeniIspisTeksta(100, "Ostajete na mjestu i gledate kako dimljak pada na zmaja i ubija ga.\n");
		Vremeplov(zivotniBodovi);
	} else{
		IspisGreskeONepravilnomUnosu();
		StarGate(zivotniBodovi);
	}
	return 0;
}
int Bezubi(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Skacete sa tepiha i padate na rep zmaja. Podizete glavu.\nStucko: Bezubi, on je. Od nikuda pade na tvoj rep.\nDa li ce te srusiti Stucka sa zmaja i preuzeti kontrolu nad Bezubim?\n");
	DaNe("HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		UsporeniIspisTeksta(100, "Rusite Stucka sa Bezubog i zauzimate njegovo mjesto.\nTo se nije dopalo Bezubom, sto ste mu srusili najboljeg prijatelja, i pocinje nekontrolisano da leti.\nIznenada iz rusevina izranja Svemirski crv koji krece da vas pojede.\nBezubi vas baca sa njegovih ledja pravo u usta crva koji vas guta. Vi to niste prezivjeli.\n");
		Smrt();
	} else if(odgovor == 2){
		UsporeniIspisTeksta(100, "Skacete sa Bezubovog repa i padate na nesto mekano.\nUpravo ste pali na Pug-a, dzinovskog, cudovisnog psa.\n");
		Feniks(zivotniBodovi);
	} else{
		IspisGreskeONepravilnomUnosu();
		Bezubi(zivotniBodovi);
	}
	return 0;
}
int Feniks(int* zivotniBodovi){
	UsporeniIspisTeksta(100, "Silazite sa psa. Kad ste sisli pojavljujete se tacno ispred Crvenog Feniksa.\nUpravo ste se nasli na putu Wolverin-a\nDa li ce te se skloniti i pustiti Wolverin-a da ju ubije, ili ce te pustit da vas probode umjesto nje.\n");
	DvaIzbora("1. Skloniti se", "2. Ostati na mjestu", "HORIZONTALNO");
	int odgovor = UcitajOdgovor();
	if(odgovor == 1){
		UsporeniIspisTeksta(100, "Sklonjate se i gledate kako Wolverine ubija Crvenog Feniksa.\n");
		Vremeplov(zivotniBodovi);
	} else if(odgovor == 2){
		UsporeniIspisTeksta(100, "Wolverine vas ubija svojim kandzama.\n");
		uslov = 0;
		IspisSlike("Kraj Igre.txt");
	} else{
		IspisGreskeONepravilnomUnosu();
		Feniks(zivotniBodovi);
	}
	return 0;
}
void Vremeplov(int* zivotniBodovi){
	VremenskaPauza(3);
		
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;
	
	// Cuva trenutnu boji teksta u konzoli
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;
	
	MaliMatriks1();
	UsporeniIspisTeksta(100, "Pojavljujete se u bijelom prostranstvu.\n");
	VremenskaPauza(3);
	UsporeniIspisTeksta(100, "Gospodar Igre: Ne znam koliko vremena imam pa cu reci samo ove.\n               Kako bi ste je zaustavili vi morate da se zrtvujete i time slomite ciklus.\n               Pokusacu da vas vratim u proslos sto je dalje moguce.\n               Upamtite sta sam vam rekao.\n");
	VremenskaPauza(3);
	MaliMatriks1();
		
	// Vraca prethodnu boju teksta u konzoli
	SetConsoleTextAttribute(hConsole, saved_attributes);
	DCU(zivotniBodovi);
}
void MaliMatriks1(){
	system("color 0c");
	MatriksP();
}
void MaliMatriks2(){
	system("color 0e");
	MatriksP();
}
void MatriksP(){
	int mat[100][100], i, j;
	for(i = 0; i < 100; i++){
		for(j = 0; j < 100; j++){
			mat[i][j] = rand();
		}
	}
	
	clock_t vrijeme = 2000 + clock();
	while(vrijeme > clock()){
		for(i = 0; i < 100; i++){
			for(j = 0; j < 100; j++){
				printf("%d", mat[i][j]);
			}
		}
	}
}
