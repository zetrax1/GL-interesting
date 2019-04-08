/*
 * Cesta.cpp
 *
 *  Created on: Dec 8, 2018
 *      Author: zetrax
 */

#include "Cesta.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

Cesta::Cesta(size_t s_meno ,size_t s_mesto_A,size_t s_mesto_B,int smer ,int rychlost , int typ,char* meno,char* mesto_A,char* mesto_B) {

this->meno_cesty = (char*)malloc(sizeof(char)*s_meno+1);
this->mesto_A=(char*)malloc(sizeof(char)*s_mesto_A+1);
this->mesto_B=(char*)malloc(sizeof(char)*s_mesto_B+1);
this->smer=smer;
this->rychlost=rychlost;
this->typ=typ;

this->dalsi=NULL;


strcpy(this->meno_cesty,meno);
strcpy(this->mesto_A,mesto_A);
strcpy(this->mesto_B,mesto_B);



}

void Cesta::uvolni(){

	free(this->meno_cesty);
	free(this->mesto_A);
	free(this->mesto_B);
}

int Cesta::get_smer(){

	return this->smer;
}

char* Cesta::get_mesto_A(){

	return this->mesto_A;
}


char* Cesta::get_mesto_B(){
	return this->mesto_B;
}

int Cesta::get_rychlost(){

	return this->rychlost;
}
int Cesta::get_typ(){

	return this->typ;
}

char* Cesta::get_meno_cesty(){

	return this->meno_cesty;
}

Cesta* Cesta::get_dalsi(){

	return this->dalsi;
}

void Cesta::set_dalsi(Cesta* nastav){

	this->dalsi = nastav;
	return ;
}
