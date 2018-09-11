/* 
 * File:   Gra.cpp
 * Author: Piotr
 * 
 * Created on 21 stycznia 2016, 14:31
 */

#include "Gra.h"
#include <windows.h>
#include <conio.h>
#include "Plansza.h"

Gra::Gra(int szerokosc, int wysokosc, int poziom) : szerokosc(szerokosc), wysokosc(wysokosc), poziom(poziom) {
	this->plansza = new Plansza(20, 1, 10, 22);
}

Gra::Gra(const Gra& orig) {
}

Gra::~Gra() {
	delete this->plansza;
}

void Gra::odpal() {
	this->SetWindow(this->szerokosc, this->wysokosc);
	system("cls");
	
	this->wyswietlNapisy();
	this->plansza->wyswietl(this->handle);
	
	bool odpalona = true;
	int a = 0;
	while (odpalona) {
		if (!this->plansza->czyJestBloczek()) {
			this->plansza->losujBloczek();
		}
		
		if (kbhit()) {
			switch (getch()) {
				case 27:
					odpalona = false;
					break;
				case 'A':
				case 'a':
				case 75:
					if (this->plansza->czyMoznaPrzesunacBloczek(-1)) {
						this->plansza->usunBloczekZEkranu(this->handle);
						this->plansza->przesunBloczek(-1);
					}
					break;
				case 'D':
				case 'd':
				case 77:
					if (this->plansza->czyMoznaPrzesunacBloczek(1)) {
						this->plansza->usunBloczekZEkranu(this->handle);
						this->plansza->przesunBloczek(1);
					}
					break;
					break;
				case 's':
				case 'S':
				case 80:
					if (this->plansza->czyMoznaOpuscicBloczek()) {
						this->plansza->usunBloczekZEkranu(this->handle);
						this->plansza->opuscBloczek();
						a = 1;
					}
					break;
				case 'w':
				case 'W':
				case 72:
					if (this->plansza->czyMoznaObrocicBloczek()) {
						this->plansza->usunBloczekZEkranu(this->handle);
						this->plansza->obrocBloczek();
					}
					break;
				case 32:
					while (this->plansza->czyMoznaOpuscicBloczek()) {
						this->plansza->usunBloczekZEkranu(this->handle);
						this->plansza->opuscBloczek();
						a = 0;
					}
			}
		}
		
		this->plansza->aktualizuj(this->handle);
		
		if (a % 19 == 0) {
			if (this->plansza->czyMoznaOpuscicBloczek()) {
				this->plansza->usunBloczekZEkranu(this->handle);
				this->plansza->opuscBloczek();
			}
			else {
				if (this->plansza->czyKoniecGry()) {
					Napis *koniecgry = new Napis("Koniec gry!", 0, 0, 8);
					this->dodajNapis(koniecgry);
					this->wyswietlNapisy();
					delete koniecgry;
					while (getch() != 27) {}
					odpalona = false;
				}
				else {
					this->plansza->usunBloczekZEkranu(this->handle);
					this->plansza->przeniesBloczekDoPlanszy();
				}
				
				this->plansza->wyczyscBloczek();
			}
			
			this->dodajPunkty(this->plansza->sprawdzPunkty());
			a = 1;
		}
		a++;
		
		if (this->poziom == 1) {
			Sleep(25);
		}
		else if (this->poziom == 2) {
			Sleep(5);
		}
		else if (this->poziom == 3) {
			double zmniejsz_predkosc_o = this->sprawdzLinii() * 0.25;
			if (zmniejsz_predkosc_o > 24) {
				zmniejsz_predkosc_o = 24;
			}
			Sleep(25 - zmniejsz_predkosc_o);
		}
	}
}

/*
 * http://www.3dbuzz.com/forum/threads/102195-How-do-you-resize-a-console-window-in-C
 */
void Gra::SetWindow(int Width, int Height) { 
    _COORD coord; 
    coord.X = Width; 
    coord.Y = Height; 

    _SMALL_RECT Rect; 
    Rect.Top = 0; 
    Rect.Left = 0; 
    Rect.Bottom = Height - 1; 
    Rect.Right = Width - 1; 

    this->handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
    SetConsoleScreenBufferSize(this->handle, coord);            // Set Buffer Size 
    SetConsoleWindowInfo(this->handle, TRUE, &Rect);            // Set Window Size 
} 

void Gra::dodajNapis(Napis *napis) {
	this->napisy.push_back(napis);
}

void Gra::wyswietlNapisy() {
	for (auto const& value: this->napisy) {
		value->wyswietl(this->handle);
	}
}

void Gra::dodajPunkty(int nowepunkty) {
	if (nowepunkty > 0) {
		for (int i = 0; i < this->napisy.size(); i++) {
			if (this->napisy[i]->getCiag() == "Linii") {
				this->napisy[i]->addWartosc(nowepunkty);
			}
			if (this->napisy[i]->getCiag() == "Punkty") {
				this->napisy[i]->addWartosc(5 * nowepunkty);
			}
		}
		this->wyswietlNapisy();
	}
}

int Gra::sprawdzLinii() {
	for (int i = 0; i < this->napisy.size(); i++) {
		if (this->napisy[i]->getCiag() == "Linii") {
			return this->napisy[i]->getWartosc();
		}
	}
	
	return 0;
}