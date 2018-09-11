/* 
 * File:   J.cpp
 * Author: Piotr
 * 
 * Created on 21 stycznia 2016, 23:37
 */

#include "../J.h"

J::J() : Bloczek(3, 3) {
	this->obrot_1 = {
		{1,0,0},
		{1,1,1},
		{0,0,0}
	};
	
	this->obrot_2 = {
		{0,1,1},
		{0,1,0},
		{0,1,0}
	};
	
	this->obrot_3 = {
		{0,0,0},
		{1,1,1},
		{0,0,1}
	};
	
	this->obrot_4 = {
		{0,1,0},
		{0,1,0},
		{1,1,0}
	};
}

J::~J() {
}

