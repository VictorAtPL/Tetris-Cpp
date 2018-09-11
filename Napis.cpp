/* 
 * File:   Napis.cpp
 * Author: Piotr
 * 
 * Created on 21 stycznia 2016, 15:04
 */

#include "Napis.h"
#include <windows.h>
#include <iostream>

Napis::Napis(string ciag, int wartosc, int x, int y) : ciag(ciag), wartosc(wartosc), ElementGry(x, y) {
}

Napis::~Napis() {
}

void Napis::wyswietl(HANDLE handle) {
	COORD coord = {this->x, this->y};

	SetConsoleCursorPosition(handle, coord);
	if (this->wartosc > 0) {
		cout<<this->ciag<<": "<<this->wartosc;
	}
	else {
		cout<<this->ciag;
	}
}

string Napis::getCiag() {
	return this->ciag;
}

int Napis::getWartosc() {
	return this->wartosc;
}

void Napis::addWartosc(int wartosc) {
	this->wartosc += wartosc;
}

void Napis::zeruj() {
	this->wartosc = 0;
}