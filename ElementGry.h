/* 
 * File:   ElementGry.h
 * Author: Piotr
 *
 * Created on 21 stycznia 2016, 16:11
 */

#ifndef ELEMENTGRY_H
#define	ELEMENTGRY_H
#include <windows.h>

class ElementGry {
public:
	ElementGry(short x, short y);
	ElementGry(const ElementGry& orig);
	virtual ~ElementGry();
	virtual void wyswietl(HANDLE handle) = 0;
protected:
	int x;
	int y;
};

#endif	/* ELEMENTGRY_H */

