/* 
 * File:   T.cpp
 * Author: Piotr
 * 
 * Created on 22 stycznia 2016, 01:58
 */

#include "../T.h"

T::T() : Bloczek(3, 3) {
	this->obrot_1 = {
		{0,1,0},
		{1,1,1},
		{0,0,0}
	};
	
	this->obrot_2 = {
		{0,1,0},
		{0,1,1},
		{0,1,0}
	};
	
	this->obrot_3 = {
		{0,0,0},
		{1,1,1},
		{0,1,0}
	};
	
	this->obrot_4 = {
		{0,1,0},
		{1,1,0},
		{0,1,0}
	};
}

T::~T() {
}

