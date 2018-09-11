/* 
 * File:   Z.cpp
 * Author: Piotr
 * 
 * Created on 22 stycznia 2016, 01:56
 */

#include "../Z.h"

Z::Z() : Bloczek(3, 3) {
	this->obrot_1 = {
		{1,1,0},
		{0,1,1},
		{0,0,0}
	};
	
	this->obrot_2 = {
		{0,0,1},
		{0,1,1},
		{0,1,0}
	};
	
	this->obrot_3 = {
		{0,0,0},
		{1,1,0},
		{0,1,1}
	};
	
	this->obrot_4 = {
		{0,1,0},
		{1,1,0},
		{1,0,0}
	};
}

Z::~Z() {
}

