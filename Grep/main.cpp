/*
 * main.cpp
 *
 *  Created on: Nov 20, 2018
 *      Author: zetrax
 */

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include "Grep.h"

using namespace std;


char** analyzuj(char *pole[], int n,int *tmp) {

	char **subory;

	subory = (char**) malloc(sizeof(char*) * n);

	for (int i = n - 1; i > 0; i--) {


		if (strlen(pole[i]) > 3) {

			if (pole[i][(strlen(pole[i])) - 1] == 't'
					&& pole[i][(strlen(pole[i])) - 2] == 'x'
					&& pole[i][(strlen(pole[i])) - 3] == 't') {

				//subory = (char**)realloc(subory,sizeof(char*)*n);
				subory[*tmp] = (char*) malloc(strlen(pole[i]) * sizeof(char));
				for (int j = 0; j < (int) (strlen(pole[i])); j++) {
					subory[*tmp][j] = pole[i][j];
					//printf("%c",subory[tmp][j]);
				}
				(*tmp)++;

			}
		}

	}

	return subory;
}



char* prepinace(char *pole[],int *pom,int n,int *pri_a){

	char *prep= (char*)malloc(sizeof(char)*n);
	for(int i=1;i<n-1;i++){
		if(pole[i][0]=='-'){
			prep[(*pom)]=pole[i][1];
			if(pole[i][1]=='a'){

				int index = std::stoi(pole[i+1]);
			//	std::cout<< index;
				(*pri_a) =index;
			}
			(*pom)++;

		}
	}

	return prep;

}

int main(int argc, char *argv[]) {

	char **subory, *retazec;
	int tmp = 0,pom=0,pri_a=0;
	char *prepinac;

	Grep grep;

	subory = analyzuj(argv, argc, &tmp);


	if (tmp == argc - 1) {
		std::cout << "Zle zadané vstupné parametre";

		return 0;
	}
	prepinac=prepinace(argv,&pom,argc,&pri_a);
//	std::cout << pom;

	if(pri_a!=0){
		retazec=argv[pom+2];
	}else{
	retazec=argv[pom+1];
	}
	grep.hlavna(tmp,subory,retazec,prepinac,pri_a,pom);



	return 0;
}
































