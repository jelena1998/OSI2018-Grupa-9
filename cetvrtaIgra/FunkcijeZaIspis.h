#ifndef FUNKCIJEZAISPIS_H_  // Ukljuci cuvara
#define FUNKCIJEZAISPIS_H_

void UsporeniIspisTeksta(int, char*); // Ispisuje karaktere stringa sa puzama
void IspisiPrazanRed(int); // Ispisuje zadati broj praznih redova
void IspisGreskeONepravilnomUnosu(); // Ispisuje poruku o unosu nepostojece komande
void SpecijalniIspis(char*); // Ispisuje <<<<<<<< tekst >>>>>>>>>>

void IspisSlike(char*); // Ispisuje tekstualnu datoteku red po red
void PisiZvijezde(); // Pomocna funkcija za ispis rezultata
void PisiStrele(); // Pomocna funkcija za ispis rezultata
void PisiRed(); // Pomocna funkcija za ispis rezultata
void PisiLiniju(); // Pomocna funkcija za ispis rezultata
void IspisRezultata(int, int); // Funkcija za formatirani ispis rezultata igre

void DaNe(char*); // Ispisuje DA i NE opcije HORIZONTALNO ili VERTIKALNO
void DvaIzbora(char*, char*, char*); // Ispisuje dve zadate opcije HORIZONTALNO ili VERTIKALNO
void TriIzbora(char*, char*, char*, char*); // Ispisuje tri zadate opcije HORIZONTALNO ili VERTIKALNO
void CetiriIzbora(char*, char*, char*, char*, char*); // Ispisuje cetiri zadate opcije HORIZONTALNO ili VERTIKALNO

#endif // FUNKCIJEZAISPIS_H_ 
