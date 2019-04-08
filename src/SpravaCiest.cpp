/*
 * SpravaCiest.cpp
 *
 *  Created on: Dec 8, 2018
 *      Author: zetrax
 */

#include "SpravaCiest.h"
#include "Cesta.h"
#include "SpravaLinkListu.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


SpravaCiest::SpravaCiest(){

	this->prva=NULL;
	this->posledna = NULL;
	this->pole=(siet*)malloc(sizeof(siet));
	this->size_pole =1;

}

Cesta* SpravaCiest::get_prva(){

	return this->prva;
}

void SpravaCiest::set_prva(Cesta* prva_n){
	this->prva=prva_n;
}






void SpravaCiest::mallocuj_tmp_premenne(char **tmp_mesto_A,char **tmp_mesto_B,char **tmp_meno_cesty){

	(*tmp_mesto_A) = (char*)malloc(sizeof(char)*100);
	(*tmp_mesto_B) = (char*)malloc(sizeof(char)*100);
	(*tmp_meno_cesty) = (char*)malloc(sizeof(char)*100);


}
void SpravaCiest::zmaz_tmp_premenne(char **tmp_mesto_A,char **tmp_mesto_B,char **tmp_meno_cesty){

	free(*tmp_meno_cesty);
	free(*tmp_mesto_A);
	free(*tmp_mesto_B);
}

void SpravaCiest::naskenujVstup(char **tmp_meno_cesty,int *tmp_smer,char **tmp_mesto_A, char **tmp_mesto_B,int *tmp_typ,int *tmp_rychlost){




	char c;
	int i =0;
//	getchar(); // naskenovanie posledneho enteru
	printf("\nzadaj názov/meno cesty , max 100 znakov , akceptovaný formát /cislo I/cislo, D/cislo :5 I12 ,D1 \n");

	fflush(stdin);


	while (c != '\n') {
		c = getchar();
		(*tmp_meno_cesty)[i] = c;
		i++;
	}
	(*tmp_meno_cesty)[i - 1] = '\0';


	if((*tmp_meno_cesty)[0]== 'I' ){

		(*tmp_typ) = 1;
	}
	if((*tmp_meno_cesty)[0]== 'D' ){

		(*tmp_typ) = 2;
	}
	if((*tmp_meno_cesty)[0] > '0' &&(*tmp_meno_cesty)[0] <= '9' ){

			(*tmp_typ) = 0;
	}

	// ďalšia funkcia pre overenie spravneho formátu , zatiaľ predpokladáme že užívateľ je gramotný a oboznámený z platným vstupom



	printf("Zadaj mesto A\n ");
	i = 0;
	c='a';//
	fflush(stdin);
	while (c != '\n') {
		c = getchar();
		(*tmp_mesto_A)[i] = c;
		i++;
	}
	(*tmp_mesto_A)[i - 1] = '\0';

	printf("Zadaj mesto B\n ");
	i = 0;
	c='a';
	fflush(stdin);
	while (c != '\n') {
		c = getchar();
		(*tmp_mesto_B)[i] = c;
		i++;
	}
	(*tmp_mesto_B)[i - 1] = '\0';

	printf("zadaj smer cesty : pre z A do B cislo 0;pre z B do A cislo 1; obojsmerne cislo 2 \n");

	scanf("%d",tmp_smer);

	printf("zadaj max povolenú rýchlost\n");


	scanf("%d",tmp_rychlost);




}


void SpravaCiest::pridajCestu(int tmp_smer ,char *tmp_mesto_A,char *tmp_mesto_B,int tmp_typ,int tmp_rychlost,char *tmp_meno_cesty ){

		Cesta *tmp = new Cesta(strlen(tmp_meno_cesty),strlen(tmp_mesto_A),strlen(tmp_mesto_B),tmp_smer,tmp_rychlost,tmp_typ,tmp_meno_cesty,tmp_mesto_A,tmp_mesto_B);

	if(this->prva == NULL){
		this->prva=tmp;
		this->posledna = this->prva;
	}else{

		this->posledna->set_dalsi(tmp);
		this->posledna = tmp;

	}



}




void SpravaCiest::nacitajMeno(char **tmp_meno_cesty){

	//getchar();
	char c;
	int i =0;

	printf("Zadaj meno cesty \n ");
		i = 0;
		c='a';//
		fflush(stdin);
		while (c != '\n') {
			c = getchar();
			(*tmp_meno_cesty)[i] = c;
			i++;
		}
		(*tmp_meno_cesty)[i - 1] = '\0';

}

void SpravaCiest::zmazCestu(char *tmp_meno_cesty){


	Cesta* tmp = this->prva;
	Cesta* pred = this->prva;


	while(tmp !=NULL){

		if(strcmp(tmp->get_meno_cesty(),tmp_meno_cesty)==0){

			if(tmp==this->prva){
				this->prva = tmp->get_dalsi();

			}else{
				pred->set_dalsi(tmp->get_dalsi());


			}
			tmp->uvolni();
			delete(tmp);
			printf("cesta bola odstranena zo zoznamu ");
			break;
		}
	}

	pred = tmp;
	tmp = tmp->get_dalsi();


}




void SpravaCiest::vypis_ciest(){

	Cesta *tmp = this->prva;

	while(tmp != NULL){
		printf("%s - %s, %s, %d km/h, %d typ ",tmp->get_mesto_A(),tmp->get_mesto_B(),tmp->get_meno_cesty(),tmp->get_rychlost(),tmp->get_typ());
		if (tmp->get_smer() == 0 || tmp->get_smer() == 1) {
			printf("jednosmerka");
		}

		if (tmp->get_smer() == 2) {
			printf("obojsmerka");
		}
		printf("\n");

		tmp= tmp->get_dalsi();
	}


}


void SpravaCiest::vypisCiestSubor(FILE *fw){

	Cesta *tmp = this->prva;

	while(tmp != NULL){
		fprintf(fw,"%s - %s, %s, %d km/h, ",tmp->get_mesto_A(),tmp->get_mesto_B(),tmp->get_meno_cesty(),tmp->get_rychlost());
		if (tmp->get_smer() == 0 || tmp->get_smer() == 1) {
			fprintf(fw,"jednosmerka");
		}

		if (tmp->get_smer() == 2) {
			fprintf(fw,"obojsmerka");
		}
		fprintf(fw,"\n");

		tmp= tmp->get_dalsi();
	}


}


void SpravaCiest::vycistiC(){


	if(this->prva == NULL){
			return;
		}

	Cesta *tmp = (this->prva)->get_dalsi();

	if (tmp == NULL) {
		free((this->prva)->get_mesto_A());
		free((this->prva)->get_mesto_B());
		free((this->prva)->get_meno_cesty());
		free(this->prva);
		this->prva = NULL;
		return;

	}


	if (tmp->get_dalsi() == NULL) {
		free(tmp->get_mesto_A());
		free(tmp->get_mesto_B());
		free(tmp->get_meno_cesty());
		free(tmp);
		free((this->prva)->get_mesto_A());
		free((this->prva)->get_mesto_B());
		free((this->prva)->get_meno_cesty());

		free(this->prva);
		this->prva = NULL;


		return;
	}

	while ((this->prva)->get_dalsi() != NULL) {

		tmp = (this->prva)->get_dalsi();
		while (tmp->get_dalsi() != NULL) {
			tmp = tmp->get_dalsi();
		}
		free(tmp->get_mesto_A());
		free(tmp->get_mesto_B());
		free(tmp->get_meno_cesty());
		free(tmp);

	}
	free(this->prva);
	this->prva =NULL;		// po free je NULL ale pre istotu


/*	for(int i=0;i<this->size_pole;i++){

		free(this->pole[i].nazov_mesto);
		for(int j=0;j<this->pole[i].pocet_spojeni;j++){
			free(this->pole[i].spojenia[j]);
		}
		free(this->pole[i].spojenia);
		free(this->pole[i].v);

	}*/


}
/*
void SpravaCiest::odstranCiestyDoMesta(char *nazov){



}
*/
void SpravaCiest::spustiZmaz(){
	char *tmp_meno= (char*)malloc(sizeof(char)*100);

	nacitajMeno(&tmp_meno);
	zmazCestu(tmp_meno);
	free(tmp_meno);

}



bool SpravaCiest::zistiVSieti(char *meno,int *iter, int size){

	for(int i=0;i<size;i++){
		if(strcmp(this->pole[i].nazov_mesto,meno)==0){
			(*iter) = i;
			return true;
		}

	}

	return false;
}


bool SpravaCiest::zistiVSietiCestu(int iter,char *meno){

	for(int i=0;i<(this->pole[iter].pocet_spojeni);i++){
		if(strcmp(this->pole[iter].spojenia[i],meno)==0){
			return true;
		}

	}

	return false;
}

void SpravaCiest::pridajSpojenie(Cesta *tmp, int iter, char *B) {

	this->pole[iter].spojenia = (char**) realloc(this->pole[iter].spojenia,sizeof(this->pole[iter].spojenia) + sizeof(char*));
	this->pole[iter].spojenia[this->pole[iter].pocet_spojeni] = (char*) malloc(
			sizeof(char) * 100);

	strcpy(this->pole[iter].spojenia[this->pole[iter].pocet_spojeni],
			tmp->get_meno_cesty());

	this->pole[iter].dos_mesta = (char**) realloc(this->pole[iter].dos_mesta,
			sizeof(this->pole[iter].dos_mesta) + sizeof(char*));
	this->pole[iter].spojenia[this->pole[iter].pocet_spojeni] = (char*) malloc(
			sizeof(char) * 100);

	strcpy(this->pole[iter].dos_mesta[this->pole[iter].pocet_spojeni],
			B);
	this->pole[iter].v[this->pole[iter].pocet_spojeni] = tmp->get_rychlost();
	this->pole[iter].pocet_spojeni++;

}

void SpravaCiest::vypisSiet(int iter){


	for(int i=0;i<iter;i++){

		printf("%s\n",this->pole[i].nazov_mesto);

	}
}


void SpravaCiest::zoradenyVypis(){

	// predpoklad zoradeného výpisu je že nenaruší pôvodný zoznam aby to bolo možné prípadne vypísať v pôvodnom poradí
	// casová zlozistost celkom velká  bez binary tree čo by bolo asi najlepšie

	Cesta *tmp = this->prva;
	int p1=0,p2=0,size,size2,i=0;


	while (tmp != NULL) {

		if (tmp->get_typ() == 0) {
			printf("%s - %s, %s, %d km/h, jednosmerka\n",tmp->get_mesto_A(),tmp->get_mesto_B(),tmp->get_meno_cesty(),tmp->get_rychlost());

		}
		if (tmp->get_typ() == 1) {
			p1++;
		}
		if (tmp->get_typ() == 2) {
			p2++;
		}

		tmp = tmp->get_dalsi();
	}

	Cesta **pole1 =(Cesta**)malloc(sizeof(Cesta*)*p1);
	Cesta **pole2 =(Cesta**)malloc(sizeof(Cesta*)*p1);


	size =p1;
	size2 =p2;
	p1=0;
	p2=0;
	tmp = this->prva;
	while (tmp != NULL) {
		if (tmp->get_typ() == 1) {
			pole1[p1]=tmp;
			p1++;
		}
		if (tmp->get_typ() == 2) {
			pole2[p2]=tmp;
			p2++;
		}

		tmp = tmp->get_dalsi();
	}


	//bouble sort

	//riešené abecedné usporiadanie teda napr I450 skor ako I50

	for(int i = 0; i < size -1 ; i++){
	       for(int j = 0; j < size - i-1 ; j++){
	           if(strcmp(pole1[j]->get_meno_cesty(),pole1[j+1]->get_meno_cesty()) > 0){


	               Cesta *vym = pole1[j+1];
	               pole1[j+1] = pole1[j];
	               pole1[j] = vym;


	           }
	       }
	   }



	for(int i = 0; i < size2 -1 ; i++){
		       for(int j = 0; j < size2 - i-1 ; j++){
		           if(strcmp(pole2[j]->get_meno_cesty(),pole2[j+1]->get_meno_cesty()) > 0){


		               Cesta *vym = pole2[j+1];
		               pole2[j+1] = pole2[j];
		               pole2[j] = vym;


		           }
		       }
		   }


	//vypis

//	printf("%d",size);




	for(int i = 0; i < size ; i++){
		printf("%s - %s, %s, %d km/h, obojsmerka\n",pole1[i]->get_mesto_A(),pole1[i]->get_mesto_B(),pole1[i]->get_meno_cesty(),pole1[i]->get_rychlost());

	 }

	for(int i = 0; i < size2 ; i++){
			printf("%s - %s, %s, %d km/h, obojsmerka\n",pole2[i]->get_mesto_A(),pole2[i]->get_mesto_B(),pole2[i]->get_meno_cesty(),pole2[i]->get_rychlost());

		 }

	free(pole1);
	free(pole2);





}




void SpravaCiest::spusti(){
	int tmp_smer;
	char *tmp_mesto_A =NULL;
	char *tmp_mesto_B = NULL;
	int tmp_typ;
	int tmp_rychlost;
	char *tmp_meno_cesty= NULL;






	mallocuj_tmp_premenne(&tmp_mesto_A,&tmp_mesto_B,&tmp_meno_cesty);
	naskenujVstup(&tmp_meno_cesty,&tmp_smer,&tmp_mesto_A,&tmp_mesto_B,&tmp_typ,&tmp_rychlost);
	pridajCestu(tmp_smer ,tmp_mesto_A,tmp_mesto_B,tmp_typ,tmp_rychlost,tmp_meno_cesty );
	zmaz_tmp_premenne(&tmp_mesto_A,&tmp_mesto_B,&tmp_meno_cesty);






}



void SpravaCiest::zmazVestkyyCesty(char *meno){


	Cesta* tmp = this->prva, *tmp2;


   int ident =0;

	while(tmp!=NULL){

		if(strcmp(tmp->get_mesto_A(),meno)==0 || strcmp(tmp->get_mesto_B(),meno)==0 ){

			tmp2 = tmp->get_dalsi();
			ident =1;
			zmazCestu(tmp->get_meno_cesty());



		}



		if(ident == 1){
			tmp = tmp2;
		}else{
			tmp=tmp->get_dalsi();
		}

		ident =0;
	}




}



/*

void SpravaCiest::vytvorPoleSiet(){

	int iter=0,size=0;
	this->pole = (siet*)malloc(sizeof(siet));
	this->pole[0].pocet_spojeni =0;
	this->pole[0].vzdialenost =0;
	this->pole[0].od =0;
	this->pole[0].v=(int*)malloc(sizeof(int));
	this->pole[0].spojenia = (char**)malloc(sizeof(char*));
	this->pole[0].spojenia[0]=(char*)malloc(sizeof(char)*100);

	Cesta* tmp = this->prva;




//	while(tmp!=NULL){

		// je mestoA v sieti
		if (tmp->get_smer() == 0 || tmp->get_smer() == 2) {

			if (zistiVSieti(tmp->get_mesto_A(), &iter, size)) {

				if (zistiVSietiCestu(iter, tmp->get_meno_cesty())) {

				} else {

//ak existuje mesto A ale nemá tuto cestu

					pridajSpojenie(tmp, iter,tmp->get_mesto_B());
				}

			} else {

//ak neexistuje mesto A

				this->pole = (siet*) realloc(this->pole,(++iter) * sizeof(siet));
				this->pole[iter].od = 0;
				this->pole[iter].pocet_spojeni = 0;
				this->pole[iter].spojenia = NULL;
				this->pole[iter].dos_mesta =NULL;

				pridajSpojenie(tmp, iter,tmp->get_mesto_B());

			}
		}
		if (tmp->get_smer() == 1  || tmp->get_smer() == 2){



			if (zistiVSieti(tmp->get_mesto_B(), &iter, size)) {

				if (zistiVSietiCestu(iter, tmp->get_meno_cesty())) {

				} else {

//ak existuje mesto B ale nemá tuto cestu

					pridajSpojenie(tmp, iter,tmp->get_mesto_A());
				}

			} else {

//ak neexistuje mesto B

			this->pole = (siet*) realloc(pole,( (++iter) * sizeof(siet)));
			this->pole[iter].od = 0;
			this->pole[iter].pocet_spojeni = 0;
			this->pole[iter].spojenia = NULL;
			this->pole[iter].dos_mesta = NULL;

			//	pridajSpojenie(tmp, iter,tmp->get_mesto_A());

			}





		}
		printf("%d",iter);
	//	vypisSiet(iter);







	//	tmp= tmp->get_dalsi();

//	}





}
*/


/*

void SpravaCiest::vytvorSiet(int poc , mesto prve){


	this->pole = (siet*)malloc(sizeof(siet)*poc);
	for(int i=0;i<poc;i++){

	}


	Cesta* tmp = this->prva;



	int iter = 0;

	while (tmp != NULL) {

		if(zistiVSieti(tmp->get_mesto_A(),&iter,poc)){
		if (tmp->get_smer() == 0 || tmp->get_smer() == 2) {

			if (zistiVSietiCestu(iter, tmp->get_meno_cesty())) {

			} else {

				//ak existuje mesto A ale nemá tuto cestu

				pridajSpojenie(tmp, iter, tmp->get_mesto_B());
			}

		}
		if (tmp->get_smer() == 1 || tmp->get_smer() == 2) {

			if (zistiVSietiCestu(iter, tmp->get_meno_cesty())) {

			} else {
			zistiVSieti(tmp->get_mesto_B(),&iter,poc);


				//ak existuje mesto A ale nemá tuto cestu

				pridajSpojenie(tmp, iter, tmp->get_mesto_A());
			}

		}
		}

		tmp = tmp->get_dalsi();
	}




}
*/
