/* 
 * File:   Plansza.cpp
 * Author: Piotr
 * 
 * Created on 21 stycznia 2016, 15:45
 */

#include "Plansza.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

Plansza::Plansza(short x, short y, int szerokosc, int wysokosc) : ElementGry(x, y), szerokosc(szerokosc), wysokosc(wysokosc), bloczek(nullptr) {
	this->stan.resize(this->wysokosc, vector<bool>(this->szerokosc, 0));
	
	this->poprzedniStan = this->stan;
}

Plansza::~Plansza() {
}

void Plansza::wyswietl(HANDLE handle) {
	for (int i = 0; i < this->stan.size(); i++) {
		COORD coord = {this->x - 1, this->y + i};
		SetConsoleCursorPosition(handle, coord);
		cout<<(char)177;

		COORD coord_2 = {this->x + this->szerokosc, this->y + i};
		SetConsoleCursorPosition(handle, coord_2);
		cout<<(char)177;
	}
	
	COORD coord_3 = {this->x - 1, this->y + this->wysokosc};
	SetConsoleCursorPosition(handle, coord_3);
	for (int i = 0; i < this->szerokosc + 2; i++) {
		cout<<(char)177;
	}
}

bool Plansza::czyJestBloczek() {
	if (this->bloczek != nullptr) {
		return true;
	}
	return false;
}

void Plansza::losujBloczek() {
	srand( time( NULL ) );
	
	switch (( rand() % 7 ) + 0) {
		case 0:
			this->bloczek = new O();
			break;
		case 1:
			this->bloczek = new J();
			break;
		case 2:
			this->bloczek = new I();
			break;
		case 3:
			this->bloczek = new L();
			break;
		case 4:
			this->bloczek = new T();
			break;
		case 5:
			this->bloczek = new S();
			break;
		case 6:
			this->bloczek = new Z();
			break;
	}
	
	int new_x = this->szerokosc / 2 - this->bloczek->getSzerokosc() / 2;
	this->bloczek->setX(new_x);
}

void Plansza::aktualizuj(HANDLE handle) {
	if (this->poprzedniStan != this->stan) {
		for (int i = 0; i < this->stan.size(); i++) {
			for (int j = 0; j < this->stan[i].size(); j++) {
				COORD coord = {this->x + j, this->y + i};

				if (this->stan[i][j] != this->poprzedniStan[i][j]) {
					SetConsoleCursorPosition(handle, coord);
					if (this->stan[i][j] == 1) {
						cout<<(char)219;
					}
					else {
						cout<<(char)' ';
					}
				}
			}
		}
	}
	
	auto bloczek = this->bloczek->pobierzBloczek();
	for (int i = 0; i < bloczek.size(); i++) {
		for (int j = 0; j < bloczek[i].size(); j++) {
			COORD coord = {this->x + this->bloczek->getX() + j, this->y + this->bloczek->getY() + i};

			SetConsoleCursorPosition(handle, coord);
			if (bloczek[i][j] == 1) {
				cout<<(char)219;
			}
		}
	}
	
	this->poprzedniStan = this->stan;	
}

void Plansza::usunBloczekZEkranu(HANDLE handle) {
	auto bloczek = this->bloczek->pobierzBloczek();
	for (int i = 0; i < bloczek.size(); i++) {
		for (int j = 0; j < bloczek[i].size(); j++) {
			COORD coord = {this->x + this->bloczek->getX() + j, this->y + this->bloczek->getY() + i};

			SetConsoleCursorPosition(handle, coord);
			if (bloczek[i][j] == 1) {
				cout<<(char)' ';
			}
		}
	}
}

bool Plansza::czyMoznaPrzesunacBloczek(short x) {
	auto bloczek = this->bloczek->pobierzBloczek();
	
	for (int i = 0; i < bloczek.size(); i++) {
		for (int j = 0; j < bloczek[i].size(); j++) {
			if (bloczek[i][j] == 1) {
				if (x == -1) {
					if (this->bloczek->getX() + j - 1 < 0) {
						return false;
					}
					if (this->stan[this->bloczek->getY()+i][this->bloczek->getX()+j-1] == 1) {
						return false;
					}
				}
				else if (x == 1) {
					if (this->bloczek->getX() + j + 1 >= this->szerokosc) {
						return false;
					}
					if (this->stan[this->bloczek->getY()+i][this->bloczek->getX()+j+1] == 1) {
						return false;
					}
				}
			}
		}
	}
	return true;
}

void Plansza::przesunBloczek(short x) {
	if (x == -1) {
		this->bloczek->setX(this->bloczek->getX() - 1);
	}
	else if (x == 1) {
		this->bloczek->setX(this->bloczek->getX() + 1);
	}
}

bool Plansza::czyMoznaOpuscicBloczek() {
	auto bloczek = this->bloczek->pobierzBloczek();
	
	for (int i = 0; i < bloczek.size(); i++) {
		for (int j = 0; j < bloczek[i].size(); j++) {
			if (bloczek[i][j] == 1) {
				if (this->bloczek->getY() + i + 1 >= this->wysokosc) {
					return false;
				}
				if (this->stan[this->bloczek->getY() + i + 1][this->bloczek->getX() + j] == true) {
					return false;
				}
			}
		}
	}
	return true;
}

void Plansza::opuscBloczek() {
	this->bloczek->setY(this->bloczek->getY() + 1);
}

void Plansza::przeniesBloczekDoPlanszy() {
	auto bloczek = this->bloczek->pobierzBloczek();
	
	for (int i = 0; i < bloczek.size(); i++) {
		for (int j = 0; j < bloczek[i].size(); j++) {
			if (bloczek[i][j] == 1) {
				this->stan[i + this->bloczek->getY()][j + this->bloczek->getX()] = bloczek[i][j];
			}
		}
	}
}

void Plansza::wyczyscBloczek() {
	delete this->bloczek;
	this->bloczek = nullptr;
}

bool Plansza::czyKoniecGry() {
	if (this->bloczek->getY() == 0) {
		return true;
	}
	return false;
}

int Plansza::sprawdzPunkty() {
	int linie = 0;
	bool flaga = 1;
	
	vector<bool> punktowane(this->szerokosc, 1);
	
	for (int i = 0; i < this->stan.size(); i++) {
		if (this->stan[i] == punktowane) {
			linie++;

			for (int j = i; j > 0; j--) {
				this->stan[j] = this->stan[j-1];
			}

			fill(this->stan[0].begin(), this->stan[0].end(), 0);
		}
	}
	
	return linie;
}

bool Plansza::czyMoznaObrocicBloczek() {
	auto bloczek = this->bloczek->pobierzObroconyBloczek();

	int temp_x = this->bloczek->getX();
	if (this->bloczek->getX() < 0) {
		temp_x = 0;
	}
	
	//getx = 18
	//getszerokosc = 3
	// o jeden w lewo
	else if (this->bloczek->getX() + this->bloczek->getSzerokosc() >= this->szerokosc) {
		temp_x -= this->szerokosc - (this->bloczek->getX() + this->bloczek->getSzerokosc());
	}
	
	
	for (int i = 0; i < bloczek.size(); i++) {
		for (int j = 0; j < bloczek[i].size(); j++) {
			if (bloczek[i][j] == 1) {
				if (this->stan[i + this->bloczek->getY()][j + temp_x] == 1) {
					return false;
				}
			}
		}
	}
	
	return true;
}

void Plansza::obrocBloczek() {	
	if (this->bloczek->getX() < 0) {
		this->bloczek->setX(0);
	}
	
	if (this->bloczek->getX() + this->bloczek->getSzerokosc() > this->szerokosc) {
		int ile_w_lewo = this->bloczek->getSzerokosc() + this->bloczek->getX() - this->szerokosc;
		this->bloczek->setX(this->bloczek->getX() - ile_w_lewo);
	}
	this->bloczek->obroc();
}