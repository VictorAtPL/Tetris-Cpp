/* 
 * File:   Bloczek.cpp
 * Author: Piotr
 * 
 * Created on 21 stycznia 2016, 16:40
 */

#include "Bloczek.h"

Bloczek::Bloczek(int szerokosc, int wysokosc) : ElementGry(0, 0), szerokosc(szerokosc), wysokosc(wysokosc), obrot(1) {
}

Bloczek::~Bloczek() {
}

void Bloczek::setX(short x) {
	this->x = x;
}

void Bloczek::setY(short y) {
	this->y = y;
}

int Bloczek::getSzerokosc() {
	return this->szerokosc;
}
int Bloczek::getWysokosc() {
	return this->wysokosc;
}

vector< vector< bool > > Bloczek::pobierzBloczek() {
	switch (this->obrot % 4) {
		case 0: 
			return this->obrot_1;
		case 1:
			return this->obrot_2;
		case 2:
			return this->obrot_3;
		case 3:
			return this->obrot_4;
	}
}

vector< vector< bool > > Bloczek::pobierzObroconyBloczek() {
	switch ((this->obrot + 1) % 4) {
		case 0: 
			return this->obrot_1;
		case 1:
			return this->obrot_2;
		case 2:
			return this->obrot_3;
		case 3:
			return this->obrot_4;
	}
}

short Bloczek::getX() {
	return this->x;
}

short Bloczek::getY() {
	return this->y;
}

void Bloczek::wyswietl(HANDLE handle) {};

void Bloczek::obroc() {
	this->obrot++;
}