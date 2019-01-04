#ifndef FUNKCIJEZAISPIS_H_  // Ukljuci cuvara
#define FUNKCIJEZAISPIS_H_

void IspisTekstaSaPauzama(char*); // Ispisuje tekst sa pauzom tj. ispise dio teksta pa napravi pauzu
void UsporeniIspisTeksta(int, char*); // Ispisuje karaktere stringa sa puzama
void IspisiPrazanRed(int); // Ispisuje zadati broj praznih redova
void IspisiKarakterVisePuta(char, int, int); // Ispisuje zadati karakter zadati broj puta u redu u zadatom broju redova
void IspisGreskeONepravilnomUnosu(); // Ispisuje poruku o unosu nepostojece komande
void SpecijalniIspis(char*); // Ispisuje <<<<<<<< tekst >>>>>>>>>>

void IspisSlike(char*); // Ispisuje tekstualnu datoteku red po red
void IspisPasosa(char*); // Prvo ispise jedan pasos tekstualne datoteke pa napravi pauzu pa onda opet nastavi

void DaNe(char*); // Ispisuje DA i NE opcije HORIZONTALNO ili VERTIKALNO
void DvaIzbora(char*, char*, char*); // Ispisuje dve zadate opcije HORIZONTALNO ili VERTIKALNO
void TriIzbora(char*, char*, char*, char*); // Ispisuje tri zadate opcije HORIZONTALNO ili VERTIKALNO
void CetiriIzbora(char*, char*, char*, char*, char*); // Ispisuje cetiri zadate opcije HORIZONTALNO ili VERTIKALNO

#endif // FUNKCIJEZAISPIS_H_ 
