/*
 * main.cpp
 *
 *  Created on: Dec 5, 2018
 *      Author: zetrax
 */


#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include "SpravaLinkListu.h"
#include "SpravaCiest.h"
#include "Cesta.h"
#include "Subory.h"





bool overPrihlasenie(int typ){


	// akákoľvek funkcia na overenie uzivatela , porovnanie s databazou atd...

if(typ==1){
	printf("\n Ste prihlaseny ako spravca ciest");
}else{
	printf("\n Ste prihlaseny ako spravca miest");
}

	return true;
}


 // funkcia na prihlasenie , nieje povinna , skôr zabavka s vykreslovanim do konzoly
int prihlasenie(){

	char typ,buf;

	for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 69; j++) {
				if (i % 2 == 0 && j % 2 == 0) {
					printf("*");
				} else
					printf("§");
			}
			printf("\n");
		}
		printf("*§*                                                               *§*\n");
		printf("*§*                      Vitajte v aplikacii                      *§*\n");
		printf("*§*                                                               *§*\n");
		printf("*§*   Pre pihlasenie sa do aplikácie ako spravca ciest stlacte 1  *§*\n");
		printf("*§*   Pre pihlasenie sa do aplikácie ako spravca miest stlacte 2  *§*\n");
		printf("*§*              Pre ukončenie aplikácie stlačte 3                *§*\n");
		printf("*§*                                                               *§*\n");

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 69; j++) {
				if (i % 2 == 0 && j % 2 == 0) {
					printf("*");
				} else
					printf("§");
			}
			printf("\n");
		}

		while(1){

		scanf("%c",&typ); //nacitanie zadaneho
		scanf("%c",&buf); // osetrenie problemu na potvrdenie enterom

		if(typ=='1' || typ =='2'){
			if(overPrihlasenie(typ)){
				return typ;
			}

		}else{

			if(typ == '3'){
				return 0;
			}

			printf("nespravne vstup\n");
		}


		}


    return 0;
}


void menu(){
	printf("\n");
	for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 66; j++) {
					if (i % 2 == 0 && j % 2 == 0) {
						printf("*");
					} else
						printf("§");
				}
				printf("\n");
			}
			printf("*§*                                                            *§*\n");
			printf("*§*                         Hlavne Menu                        *§*\n");
			printf("*§*                                                            *§*\n");
			printf("*§*         Pridať mesto                             1         *§*\n");
			printf("*§*         Odstrániť mesto                          2         *§*\n");
			printf("*§*         Pridať cestu                             3         *§*\n");
			printf("*§*         Odstrániť cestu                          4         *§*\n");
			printf("*§*         Načítať sieť zo súboru                   5         *§*\n");
			printf("*§*         Zapísať sieť do súboru                   6         *§*\n");
			printf("*§*         Cesta z mesta A do mesta B               7         *§*\n");
			printf("*§*         Zoradený výpis všetkých miest            8         *§*\n");
			printf("*§*         Zoradený výpis všetkých ciest            9         *§*\n");
			printf("*§*         Pre ukoncenie programu                  10         *§*\n");
			printf("*§*                                                            *§*\n");

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 66; j++) {
					if (i % 2 == 0 && j % 2 == 0) {
						printf("*");
					} else
						printf("§");
				}
				printf("\n");
			}
			printf("\n");

}





int main(int argv, char *argc[]){


	//prihlásenie ako manžer ciest alebo manažer miest , majú rôzne povolené funkcie ...
	SpravaLinkListu *spravca_m = new SpravaLinkListu();
	SpravaCiest *spravca_c = new SpravaCiest();
	Subory *sub = new Subory(spravca_m,spravca_c);




	if(prihlasenie()==0){
		return 0;
	}



	int a=0;
	char *pom;

	while(1){

		menu();
		scanf("%d",&a);

		switch (a) {

		case 1: {
			//pridať mesto cez konzolu
			getchar();
			spravca_m->pridajMesto();

			break;
		}
		case 2: {

			pom=spravca_m->odstranitMesto();
			spravca_c->zmazVestkyyCesty(pom);

			break;
		}

		case 3: {
			getchar();
			spravca_c->spusti();

			break;
		}

		case 4: {
			getchar();
			spravca_c->spustiZmaz();

			break;
		}

		case 5: {
			getchar();
			spravca_m->vycistiM();
			spravca_c->vycistiC();

			sub->nacitajSiet();
			break;
		}

		case 6: {
			getchar();
			sub->zapisSiet();
			break;
		}

		case 7: {
			 printf("funkcia momentálne nieje k dispozícií \n");


		//	spravca_c->vytvorSiet(spravca_m->getPocet());

			break;
		}
		case 8: {
			spravca_m->zoradenyVypis();
			//spravca_c->vypis_ciest();
			break;
		}
		case 9: {
			spravca_c->zoradenyVypis();
			break;
		}
		case 10: {
			printf("\n program je ukoncený");
			return 0;
		}
		default :{
			printf("zle zadany vstup");

			break;
		}



		}






	}





	return 0;

}
