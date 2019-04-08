/*
 * Subory.cpp
 *
 *  Created on: Dec 9, 2018
 *      Author: zetrax
 */

#include "Subory.h"
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include "SpravaLinkListu.h"
#include "SpravaCiest.h"



Subory::Subory(SpravaLinkListu *miest,SpravaCiest *ciest) {

	this->file=NULL;
	this->s_miest=miest;
	this->s_ciest=ciest;

}


bool Subory::otvorSubor(int ako,char *subor){


	if(ako==0){
		this->file=fopen(subor, "r");

	}
	if(ako==1){
		this->file=fopen(subor, "w");

	}

	if (this->file == NULL) {

			return false;
		}

	return true;


}
bool Subory::zatvorSubor(){

	if (fclose(this->file) == EOF) {
		std::cout << "\n subor sa nepodarilo zatvorit \n";
		return false;
	}

	return true;

}

char* Subory::nacitajNazov(){

	printf("Zadaj názov súboru\n");
	int i = 0;
	char c = 'a', *nazov;
	nazov = (char*)malloc(100 * sizeof(char));

	fflush(stdin);
	while (c != '\n') {
		c = getchar();
		nazov[i] = c;
		i++;
	}
	nazov[i - 1] = '\0';


return nazov;
}

void Subory::rozoberMesto(char* line){

	char meno[100],roz[100],poc[100];
	int pocet,i=0,j=0;
	float rozloha;


//	printf("%s",line);
	while(line[i]!=','){

		//printf("%c",line[i]);
		meno[i]=line[i];
		i++;

	}
	meno[i]='\0';

	i++;
	while(line[i]!=','){

			poc[j]=line[i];
			i++;
			j++;

	}
	poc[j]='\0';
//	printf("%s",poc);
	i++;
	j=0;
	while((line[i] != '/' )&&(line[i]!='\n')){

		roz[j]=line[i];
			i++;
			j++;

	}

	roz[j]='\0';
//	printf("%s",roz);

	rozloha =std::stof(roz);
	pocet = std::stoi(poc);


	(this->s_miest)->addMesto(meno,pocet,rozloha);

}

int Subory::identifikuj(char* line){

	char tmp[100];
	int i=0;
	while(line[i] != '/'){
		tmp[i]=line[i];
		i++;
	}
	line[i]='\0';

	int index = std::stoi(tmp);


//	std::cout<< index;
	printf("\n");
return index;

}

void Subory::rozoberCestu(char* line){
	//1,50,Abcd,Bcda,80// Typ - 0(jednosmerka),1(prvej triedy),2(dialnica), Meno, Meno mesta A, Meno mesta B, rýchlosť

	char meno[100],mesto_A[100],mesto_B[100],v[100];
	int rychlost,i=2,j=0,index=0,p=0;

	if(line[0]=='1'){
		meno[0]='I';
		p=1;
		index++;
	}
	if(line[0]=='2'){
		meno[0]='D';
		p=2;
		index++;
	}

	while(line[i]!=','){

		meno[index]=line[i];
		index++;
		i++;
	}
	meno[index]='\0';
	i++;
	j=0;

	while (line[i] != ',') {

		mesto_A[j] = line[i];
		j++;
		i++;
	}
	mesto_A[j] = '\0';
	i++;
	j=0;

	while (line[i] != ',') {

		mesto_B[j] = line[i];
		j++;
		i++;

	}
	mesto_B[j] = '\0';
	i++;


	j=0;
	while ((line[i] != '/' )&&(line[i]!='\n')) {

			v[j] = line[i];
			j++;
			i++;
		}
		v[j] = '\0';
		i++;


		rychlost =std::stoi(v);



		(this->s_ciest)->pridajCestu(2,mesto_A,mesto_B,p,rychlost,meno );
}


void Subory::nacitajSiet(){

	char *nazov;

	nazov =nacitajNazov();
	//printf("%s\n\n",nazov);

	char * line = NULL,tmp;
	size_t len = 0;
	ssize_t read;
	int ident = 0; //urcuje co sa prave nacitva : 0 pocet miest ,1 mesta ,2 pocet ciest ,3 cesty
	int index =0;

	if(!otvorSubor(0,nazov)){
		printf("\n subor sa nepodarilo otvoriť \n");
		return ;
	}

	while ((read = getline(&line, &len, this->file)) != -1) {

		//printf("%s\n\n",line);
		if ((line[0] == '/' && line[1] == '/') || line[0] == '\n') {
			//ignoruj riadok
		} else {

			if (ident == 3) {
				index--;
				 rozoberCestu(line);

				if (index == 0) {
					ident = 4;
				}

			}
			if (ident == 2) {
				index = identifikuj(line);
				ident = 3;
			}
			if (ident == 1) {
				index--;
				rozoberMesto(line);
				if (index == 0) {
					ident = 2;
				}
			}
			if (ident == 0) {
				index = identifikuj(line);
				ident = 1;
			}

		}

	}

	zatvorSubor();







}


void Subory::zapisSiet(){


	char *nazov;

	nazov = nacitajNazov();
	if (!otvorSubor(1, nazov)) {
		printf("\n subor sa nepodarilo otvoriť \n");
		return;
	}

	(this->s_miest)->vypisMiestSubor(this->file);
	(this->s_ciest)->vypisCiestSubor(this->file);



	zatvorSubor();

}



















