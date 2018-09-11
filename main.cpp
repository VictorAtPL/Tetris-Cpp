/* 
 * File:   main.cpp
 * Author: Piotr
 *
 * Created on 21 stycznia 2016, 14:21
 */

#include <iostream>
#include <windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include "Gra.h"
#include "Napis.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
	char wybor = 0;
	bool praca = true;
	
	Gra *gra = nullptr;
	Napis *liczbalinii = new Napis("Linii", 0, 0, 0);
	Napis *liczbapunktow = new Napis("Punkty", 0, 0, 1);
	Napis *copy1 = new Napis("> Piotr Podbielski", 0, 1, 3);
	Napis *copy2 = new Napis("> I4Z6S1", 0, 1, 4);
	Napis *copy3 = new Napis("> WAT Cyber @ 2016", 0, 1, 5);
	
	int poziom = 0;
	while (praca) {
		while (wybor != 27) {
			system("cls");
			cout<<"Menu:"<<endl<<\
					"1. Poziom 1"<<endl<<\
					"2. Poziom 2"<<endl<<\
					"3. Rabiak mode"<<endl<<\
					"ESC. Wyjscie"<<endl;

			wybor = getch();
			if (wybor == 27) {
				praca = false;
			}
			else if (wybor == '1') {
				poziom = 1;
			}
			else if (wybor == '2') {
				poziom = 2;
			}
			else if (wybor == '3') {
				poziom = 3;
			}
			
			if (wybor == '1' || wybor == '2' || wybor == '3') {
				gra = new Gra(80, 30, poziom);
				gra->dodajNapis(liczbalinii);
				gra->dodajNapis(liczbapunktow);
				gra->dodajNapis(copy1);
				gra->dodajNapis(copy2);
				gra->dodajNapis(copy3);
				liczbalinii->zeruj();
				liczbapunktow->zeruj();
				gra->odpal();
				delete gra;
				gra = nullptr;
			}
		}
	}
	
	delete liczbalinii;
	delete liczbapunktow;
	
	return 0;
}

