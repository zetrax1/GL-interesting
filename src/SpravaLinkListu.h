/*
 * SpravaLinkListu.h
 *
 *  Created on: Dec 7, 2018
 *      Author: zetrax
 */

#ifndef SRC_SPRAVALINKLISTU_H_
#define SRC_SPRAVALINKLISTU_H_

#include<stdio.h>


class SpravaLinkListu {

private:
	struct mesto{
		char *nazov;
		int obyvatelia;
		float rozloha;
		struct mesto *dalsi;

	};
	typedef struct mesto mesto;

	mesto *prvy;
	mesto *posledny;



public:

	SpravaLinkListu();
	int getPocet();
	void vypisMiestSubor(FILE *file);
	void addMesto(char *nazov,int obcania,float plocha);
	void pridajMesto();
	void vypisMiest();
	char* odstranitMesto();
	void vycistiM();
	void zoradenyVypis();

	void spusti();
};



#endif /* SRC_SPRAVALINKLISTU_H_ */
