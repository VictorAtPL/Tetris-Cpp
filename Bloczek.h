/* 
 * File:   Bloczek.h
 * Author: Piotr
 *
 * Created on 21 stycznia 2016, 16:40
 */

#ifndef BLOCZEK_H
#define	BLOCZEK_H
#include "ElementGry.h"
#include <vector>

using namespace std;

class Bloczek : public ElementGry {
public:
	Bloczek(int szerokosc, int wysokosc);
	Bloczek(const Bloczek& orig);
	virtual ~Bloczek();
	void setX(short x);
	void setY(short y);
	short getX();
	short getY();
	int getSzerokosc();
	int getWysokosc();
	vector< vector< bool > > pobierzBloczek();
	vector< vector< bool > > pobierzObroconyBloczek();
	void wyswietl(HANDLE handle);
	void obroc();
private:
	int szerokosc;
	int wysokosc;
	int obrot;
protected:
	vector< vector< bool > > obrot_1, obrot_2, obrot_3, obrot_4;
};

#endif	/* BLOCZEK_H */

