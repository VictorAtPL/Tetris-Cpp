/* 
 * File:   Gra.h
 * Author: Piotr
 *
 * Created on 21 stycznia 2016, 14:31
 */

#ifndef GRA_H
#define	GRA_H
#include <vector>
#include "Napis.h"
#include <windows.h>
#include <iostream>
#include "Plansza.h"

using namespace std;

class Gra {
public:
	Gra(int szerokosc, int wysokosc, int poziom);
	Gra(const Gra& orig);
	virtual ~Gra();
	void odpal();
	void dodajNapis(Napis *napis);
private:
	void SetWindow(int Width, int Height);
	int szerokosc;
	int wysokosc;
	vector<Napis*> napisy;
	void wyswietlNapisy();
	Plansza *plansza;
	HANDLE handle;
	void dodajPunkty(int nowepunkty);
	int sprawdzLinii();
	int poziom;
};

#endif	/* GRA_H */

