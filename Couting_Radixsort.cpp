/*
 * Couting_Radixsort.cpp
 *
 *  	Created on: Oct 23, 2018
 *      Author: Vladimír Večerek
 *      Description : radix sort and counting sort , using language c
 *      version : 1.1
 */

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

#define size_pole(a) (sizeof(a)/sizeof(a[0]))

void vypis_pola(int *pole, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << pole[i];
		std::cout << " ";
	}

}

int* countig(int *pole, int size) {

	int max = 0;
	for (int i = 0; i < size; i++) {
		if (max < pole[i]) {
			max = pole[i];
		}
	}
	int *tmp_pole = (int*) calloc((max + 1), (max + 1) * sizeof(int));
	int tmp = 0;
	int *nove_pole = (int*) malloc(size * sizeof(int));

	for (int i = 0; i < size; i++) {
		tmp_pole[pole[i]]++;
	}

	tmp = 0;
	for (int i = 0; i < max + 1; i++) {
		tmp_pole[i] = tmp + tmp_pole[i];
		tmp = tmp_pole[i];
	}

	for (int i = size - 1; i >= 0; i--) {
		tmp_pole[(pole)[i]]--;
		nove_pole[tmp_pole[(pole)[i]]] = (pole)[i];

		//std::cout << nove_pole[tmp_pole[(pole)[i]]];

	}

	return nove_pole;

}

int* radixs(int *pole, int size) {
	int tmp_pole[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	int max = 0, value = 0;
	int tmp = 10;
	int pom = 0;
	int *nove_pole = (int*) malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		if (max < pole[i]) {
			max = pole[i];
		}
	}
	while(value!=max){


		value = max % tmp;

		for (int i = 0; i < size; i++) {
			tmp_pole[(((pole[i]) % tmp) / (tmp / 10))]++;

		}

		for (int i = 0; i < 10; i++) {
			tmp_pole[i] = tmp_pole[i] + pom;
			pom = tmp_pole[i];
		}
		pom = 0;

		for (int i = size - 1; i >= 0; i--) {

			tmp_pole[(((pole[i]) % tmp) / (tmp / 10))]--;
			nove_pole[tmp_pole[(((pole[i]) % tmp) / (tmp / 10))]] = pole[i];

		}

		if (max == value) {
			return nove_pole;
		} else {
			for (int i = 0; i < size; i++) {
				pole[i] = nove_pole[i];
			}
			for (int i = 0; i < 10; i++) {
				tmp_pole[i] = 0;
			}
		}

		tmp = tmp * 10;

	}

	return nove_pole;

}

int main(int argc, char *argv[]) {

	int pole[] = { 24, 15, 46, 15, 44, 18, 29, 36, 34, 27, 38, 33 };
	int *nove;
	//nove = countig(pole, 12);
	nove = radixs(pole,12);
	vypis_pola(nove,12);
	//std::cout << 29/10;

	return 0;
}

