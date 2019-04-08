/*
 * Cesta.h
 *
 *  Created on: Dec 8, 2018
 *      Author: zetrax
 */

#ifndef SRC_CESTA_H_
#define SRC_CESTA_H_

#include<string.h>

class Cesta {

private:
	int smer;
	char *mesto_A;
	char *mesto_B;
	int typ;
	int rychlost;
	char *meno_cesty;
	Cesta* dalsi;


public:

	Cesta(size_t s_meno ,size_t s_mesto_A,size_t s_mesto_B,int smer ,int rychlost , int typ,char* meno,char* mesto_A,char* mesto_B);
	int get_smer();
	int get_typ();
	int get_rychlost();
	char* get_mesto_A();
	char* get_mesto_B();
	char* get_meno_cesty();
	Cesta* get_dalsi();

	void set_smer();
	void set_typ();
	void set_rychlost();
	void set_meno_cesty();
	void set_mesto_A();
	void set_mesto_B();
	void set_dalsi(Cesta* nastav);


	void uvolni();
};

#endif /* SRC_CESTA_H_ */
