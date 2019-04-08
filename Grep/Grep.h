/*
 * Grep.h
 *
 *  Created on: Nov 21, 2018
 *      Author: zetrax
 */

#ifndef GREP_H_
#define GREP_H_
#include <iostream>



class Grep {
private:
//	FILE *dokument;
public:

	Grep();



	bool open_file(int index , char **subory,FILE **dokument);
	bool close_file(FILE *dokument);
	void citaj(FILE *dokument,char *vyraz,char*subor,int a,char *prepinac,int pri_a,int pocet);
	void list_dir(char *path);

	void hlavna(int tmp,char **subory,char *vyraz,char *prepinac,int pri_a,int pocet);



};


#endif /* GREP_H_ */
