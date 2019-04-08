/*
 * SpravaLinkListu.cpp
 *
 *  Created on: Dec 7, 2018
 *      Author: zetrax
 */

#include "SpravaLinkListu.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



SpravaLinkListu::SpravaLinkListu() {
	this->prvy=NULL;
	this->posledny =NULL;
}



int SpravaLinkListu::getPocet(){
	int i=0;
	mesto *tmp=this->prvy;
	while(tmp!=NULL){
			i++;
			tmp=tmp->dalsi;
		}

	return i;
}

void SpravaLinkListu::pridajMesto() {

	char c= 'a';
	int i = 0;
	mesto *nove;
	nove = (mesto*) malloc(sizeof(struct mesto));

	// konzolove nacitanie
	printf("zadaj názov mesta, max 100 znakov\n");
	nove->nazov = (char*) malloc(sizeof(char)*100);



	if ((this->prvy)==NULL) {
		(this->prvy) = nove;
		(this->posledny)=nove;


	}else{


	(this->posledny)->dalsi = nove;

	}

	fflush(stdin);

	while (c != '\n') {
		c = getchar();
		nove->nazov[i] = c;
		i++;
	}
	nove->nazov[i - 1] = '\0';

	printf("zadaj pocet obyvatelov\n");
	scanf("%d", &nove->obyvatelia);
	printf("zadaj rozlohu\n");
	scanf("%f", &nove->rozloha);

	nove->dalsi = NULL;

	// tu treba overenie o správnosti údajov , zatial predpokladám že bolo správne zadané

	(this->posledny) = nove;

	// poprepájanie zoznamu , s ošetrenim na prvy blok zoznamu ...


	return ;
}


void SpravaLinkListu::addMesto( char *nazov,int obcania,float plocha){
	mesto *nove;
	nove = (mesto*) malloc(sizeof(struct mesto));



	if ((this->prvy)==NULL) {
		(this->prvy) = nove;
		(this->posledny)=nove;

	}else{

	(this->posledny)->dalsi = nove;

	}
	nove->nazov = (char*) malloc(sizeof(char)*100);
	strcpy(nove->nazov,nazov);
	nove->obyvatelia = obcania;
	nove->rozloha = plocha;
	nove->dalsi = NULL;



	(this->posledny) = nove;

}

void SpravaLinkListu::vypisMiest(){

	mesto *tmp=this->prvy;

	while(tmp!=NULL){
		printf("\n%s, %d, %2.f",tmp->nazov,tmp->obyvatelia,tmp->rozloha);
		tmp=tmp->dalsi;
	}
 printf("\n");



}
void SpravaLinkListu::vypisMiestSubor( FILE *file){

	mesto *tmp=this->prvy;


	while(tmp!=NULL){
		fprintf(file,"%s, %d, %2.f\n",tmp->nazov,tmp->obyvatelia,tmp->rozloha);
		tmp=tmp->dalsi;
	}
 printf("\n");



}

void SpravaLinkListu::vycistiM(){
	if(this->prvy == NULL){
		return;
	}

	mesto *tmp = (this->prvy)->dalsi;

	if(tmp == NULL){
		free((this->prvy)->nazov);
		free(this->prvy);
		this->prvy = NULL;
		return;

	}

	if(tmp->dalsi == NULL){
		free(tmp->nazov);
		free(tmp);
		free((this->prvy)->nazov);
		free(this->prvy);
		this->prvy = NULL;
		return;
	}

	while (((this->prvy)->dalsi)!= NULL) {

		tmp = (this->prvy)->dalsi;


		while (tmp->dalsi != NULL) {
			tmp = tmp->dalsi;
		}

		free(tmp->nazov);
		free(tmp);

	}

	free(this->prvy);
	this->prvy = NULL;


}


char* SpravaLinkListu::odstranitMesto(){


	printf("\nzadajte názov mesta pre odsranenie\n");
	fflush(stdin);
	char c='a',*n_nazov=(char*) malloc(sizeof(char)*100);
	int i=0;
	getchar();


	while (c != '\n') {
			c = getchar();
			n_nazov[i] = c;
			i++;
		}
	n_nazov[i - 1] = '\0';

	//printf("\n\n%s",n_nazov);

	mesto *tmp = (this->prvy), *pred = (this->prvy);





	while (tmp != NULL) {

		if (strcmp(tmp->nazov, n_nazov) == 0) {

			if (tmp == (this->prvy)) {

				(this->prvy) = tmp->dalsi;

			} else {

				pred->dalsi = tmp->dalsi;

			}
			free(tmp->nazov);
			free(tmp);
// teraz záleži či akceptujeme možnosť duplikátov , viacerých miest s rovnakým názvom
			// ak áno bude tu miesto break; toto :
			// tmp= pred->dalsi  + ošetrenie vyžšie ak je to prvý a zároveň posledný blok
			printf("\n záznam mesta bol odstraneny\n");
			return n_nazov;
		}

		pred = tmp;
		tmp = tmp->dalsi;

	}






	return n_nazov;
}


void SpravaLinkListu::zoradenyVypis(){

	if(this->prvy == NULL){
		return;
	}
	///velká casová zlozistost O(n2) , z nedostatku casu ktory som si na to vyčlenil
	mesto *tmp=this->prvy,*tmp2=this->prvy;
	mesto *akt;
	char *rov = (char*)malloc(sizeof(char)*100);
	char *naposledy=(char*)malloc(sizeof(char)*100),aktual[100];
	int a=0;

	if(this->prvy->dalsi == NULL){
		printf("%s, %d, %.2f\n",this->prvy->nazov,this->prvy->obyvatelia,this->prvy->rozloha);
			return;
		}


	strcpy(rov,tmp->nazov);

	while(tmp2!=NULL){
		while(tmp!=NULL){

			if(a==0){


				if(strcmp(rov,tmp->nazov) < 0){
					strcpy(rov,tmp->nazov);
					akt =tmp;
				}

			}
			else{

				if(strcmp(naposledy,tmp->nazov) > 0 && strcmp(aktual,tmp->nazov) < 0){

					strcpy(aktual,tmp->nazov);
					akt =tmp;

				}

			}



			tmp=tmp->dalsi;
		}
		tmp=this->prvy;

		a=1;

		strcpy(naposledy,akt->nazov);
		printf("%s, %d, %.2f\n",akt->nazov,akt->obyvatelia,akt->rozloha);

		tmp2=tmp2->dalsi;
	}

	free(rov);
	free(naposledy);


}



void SpravaLinkListu::spusti(){



}
