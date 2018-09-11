/* 
 * File:   J.h
 * Author: Piotr
 *
 * Created on 21 stycznia 2016, 23:37
 */

#ifndef J_H
#define	J_H
#include "Bloczek.h"
#include <vector>

using namespace std;

class J : public Bloczek {
public:
	J();
	J(const J& orig);
	virtual ~J();
private:

};

#endif	/* J_H */

