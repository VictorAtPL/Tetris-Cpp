/* 
 * File:   O.cpp
 * Author: Piotr
 * 
 * Created on 21 stycznia 2016, 16:41
 */

#include "../O.h"

O::O() : Bloczek(2, 2) {
	this->obrot_1 = this->obrot_2 = this->obrot_3 = this->obrot_4 = {
		{1,1},
		{1,1}		
	};
}

O::~O() {
}