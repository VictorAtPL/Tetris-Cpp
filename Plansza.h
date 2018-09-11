/* 
 * File:   Plansza.h
 * Author: Piotr
 *
 * Created on 21 stycznia 2016, 15:45
 */

#ifndef PLANSZA_H
#define	PLANSZA_H
#include <vector>
#include "ElementGry.h"
#include "Bloczek.h"
#include "O.h"
#include "J.h"
#include "I.h"
#include "L.h"
#include "T.h"
#include "Z.h"
#include "S.h"

using namespace std;
class Plansza : public ElementGry  {
public:
	Plansza(short x, short y, int szerokosc, int wysokosc);
	Plansza(const Plansza& orig);
	virtual ~Plansza();
	void wyswietl(HANDLE handle);
	bool czyJestBloczek();
	void losujBloczek();
	void aktualizuj(HANDLE handle);
	void usunBloczekZEkranu(HANDLE handle);
	void przesunBloczek(short x);
	void opuscBloczek();
	bool czyMoznaOpuscicBloczek();
	bool czyKoniecGry();
	bool czyMoznaPrzesunacBloczek(short x);
	void przeniesBloczekDoPlanszy();
	void wyczyscBloczek();
	int sprawdzPunkty();
	bool czyMoznaObrocicBloczek();
	void obrocBloczek();
private:
	int szerokosc;
	int wysokosc;
	vector<vector<bool>> stan;
	vector<vector<bool>> poprzedniStan;
	Bloczek *bloczek;
};

#endif	/* PLANSZA_H */