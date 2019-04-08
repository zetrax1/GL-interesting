/*
 * Subory.h
 *
 *  Created on: Dec 9, 2018
 *      Author: zetrax
 */

#ifndef SRC_SUBORY_H_
#define SRC_SUBORY_H_
#include<stdio.h>
#include<stdio.h>

#include "SpravaLinkListu.h"
#include "SpravaCiest.h"


class Subory {

private:

	FILE *file;
	SpravaLinkListu *s_miest;
	SpravaCiest *s_ciest;


public:
	Subory(SpravaLinkListu *s_miest,SpravaCiest *s_ciest);
	bool otvorSubor(int ako,char *subor);
	bool zatvorSubor();
	char* nacitajNazov();
	void nacitajSiet();
	int identifikuj(char* line);
	void rozoberMesto(char* line);
	void rozoberCestu(char* line);
	void zapisSiet();

};

#endif /* SRC_SUBORY_H_ */
