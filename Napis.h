/* 
 * File:   Napis.h
 * Author: Piotr
 *
 * Created on 21 stycznia 2016, 15:04
 */

#ifndef NAPIS_H
#define	NAPIS_H
#include <string>
#include "ElementGry.h"

using namespace std;

class Napis : public ElementGry {
	friend class Gra;
public:
	Napis(string ciag, int wartosc, int x, int y);
	Napis(const Napis& orig);
	virtual ~Napis();
	void wyswietl(HANDLE handle);
	string getCiag();
	void addWartosc(int wartosc);
	void zeruj();
	int getWartosc();
private:
	string ciag;
	int wartosc;
};

#endif	/* NAPIS_H */

