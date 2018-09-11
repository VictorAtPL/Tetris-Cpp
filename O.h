/* 
 * File:   O.h
 * Author: Piotr
 *
 * Created on 21 stycznia 2016, 16:41
 */

#ifndef O_H
#define	O_H
#include "Bloczek.h"
#include <vector>

using namespace std;

class O : public Bloczek {
public:
	O();
	O(const O& orig);
	virtual ~O();
private:
};

#endif	/* O_H */

