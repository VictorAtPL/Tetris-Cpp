/* 
 * File:   L.cpp
 * Author: Piotr
 * 
 * Created on 22 stycznia 2016, 01:52
 */

#include "../L.h"

L::L() : Bloczek(3, 3) {
	this->obrot_1 = {
		{0,0,1},
		{1,1,1},
		{0,0,0}
	};
	
	this->obrot_2 = {
		{0,1,0},
		{0,1,0},
		{0,1,1}
	};
	
	this->obrot_3 = {
		{0,0,0},
		{1,1,1},
		{1,0,0}
	};
	
	this->obrot_4 = {
		{1,1,0},
		{0,1,0},
		{0,1,0}
	};
}

L::~L() {
}

