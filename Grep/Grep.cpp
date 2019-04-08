/*
 * Grep.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: zetrax
 */

#include "Grep.h"
#include <iostream>
#include<string.h>
#include <dirent.h>
#include <sys/types.h>
#include <glob.h>

Grep::Grep() {

}

bool Grep::open_file(int index, char **subory, FILE **dokument) {

	(*dokument) = fopen(subory[index], "r");

	if ((*dokument) == NULL) {

		return false;
	}

	return true;
}

bool Grep::close_file(FILE *dokument) {

	if (fclose(dokument) == EOF) {
		std::cout << "\n subor sa nepodarilo zatvorit \n";
		return false;
	}

	return true;
}

void Grep::citaj(FILE *dokument, char *vyraz, char*subor, int a, char *prepinac,
		int pri_a, int pocet) {

	char * line = NULL, *tmp;
	size_t len = 0;
	ssize_t read;
	int iterator = 0;

	int zhoda = 0;

	for (int w = 0; w < pocet; w++) {
		if (prepinac[w] == 'l') {
			zhoda++;
		}
		if (prepinac[w] == 'v') {
			zhoda++;
		}

	}

	for (int q = 0; q < pocet; q++) {
		iterator = 0;

		switch (prepinac[q]) {

		case 'n': {

			while ((read = getline(&line, &len, dokument)) != -1) {
				iterator++;
				tmp = strstr(line, vyraz);

				if (tmp == NULL) {
					//std::cout << "neobsahuje";
				} else {

					printf("%s:%d %s", subor, iterator, line);
				}
			}
			rewind(dokument);

			break;
		}
		case 'l': {
			iterator = 0;
			if (zhoda != 2) {

				while ((read = getline(&line, &len, dokument)) != -1) {

					tmp = strstr(line, vyraz);

					if (tmp != NULL) {
						iterator++;
						//	std::cout << "neobsahuje";
					}

				}
				if (iterator > 0) {
					printf("%s\n", subor);
				}

				rewind(dokument);
			}
			break;

		}
		case 'v':
			iterator = 0;
			while ((read = getline(&line, &len, dokument)) != -1) {

				tmp = strstr(line, vyraz);

				if (tmp == NULL) {

					printf("%s", line);				//std::cout << "neobsahuje";
				} else {
					iterator++;
				}
			}
			printf("\n");
			if (zhoda == 2 && iterator == 0) {
				printf("%s\n", subor);
			}
			rewind(dokument);

			break;
		case 'a':{
			iterator = 0;
			int help=0;


			while ((read = getline(&line, &len, dokument)) != -1) {

				tmp = strstr(line, vyraz);

				if (tmp != NULL) {

					iterator = pri_a;
					printf("%s", line);
					//	std::cout << strlen(line)/sizeof(char);

					for (int asi = 0; asi < pri_a; asi++) {

						if ((read = getline(&line, &len, dokument)) != -1) {

							help = help + strlen(line);
							printf("%s", line);

						}
						//	std::cout << help;

					}
					fseek(dokument, (-help), SEEK_CUR);
					help = 0;
					//std::cout << "neobsahuje";
				}

			}



			rewind(dokument);
			break;
		}
		case 'p':
			while ((read = getline(&line, &len, dokument)) != -1) {
				// printf("%s", line);

				tmp = strstr(line, vyraz);

				if (tmp == NULL) {
					//std::cout << "neobsahuje";
				} else {
					if (a == 1) {
						printf("%s", line);
					} else {
						printf("%s:%s", subor, line);
					}
				}
			}
			rewind(dokument);
			break;
		}
		//	printf("\n");

	}
}

void Grep::hlavna(int tmp, char **subory, char *vyraz, char *prepinac,
		int pri_a, int pocet) {

	FILE *dokument;
	char **subory2;
	int iter = 0;

	for (int i = 0; i < tmp; i++) {
		if (subory[0][0] == '*') {
			//std::cout << "subory podla *" ;
			subory2 = (char**) malloc(100 * sizeof(char*));
			glob_t glob_result;
			glob("//home/zetrax/Program/workspace/testovanie/*", GLOB_TILDE,
			NULL, &glob_result);
			for (unsigned int i = 0; i < glob_result.gl_pathc; ++i) {

				if (glob_result.gl_pathv[i][(strlen(glob_result.gl_pathv[i]))
						- 1] == 't'
						&& glob_result.gl_pathv[i][(strlen(
								glob_result.gl_pathv[i])) - 2] == 'x'
						&& glob_result.gl_pathv[i][(strlen(
								glob_result.gl_pathv[i])) - 3] == 't') {

					// subory2 = (char**)realloc(subory,(sizeof(char*)*(iter+1)));

					int j = 1;

					while ((glob_result.gl_pathv[i][(strlen(
							glob_result.gl_pathv[i])) - j]) != '\/') {
						// std::cout<<(glob_result.gl_pathv[i][(strlen(glob_result.gl_pathv[i]))-j]);
						j++;
					}

					//	 std::cout << j;
					subory2[iter] = (char*) malloc(sizeof(char) * j);

					for (int k = 0; k < j; k++) {

						subory2[iter][k] = glob_result.gl_pathv[i][(strlen(
								glob_result.gl_pathv[i])) - j + k + 1];

					}

					iter++;

				}

			}

			for (int in = 0; in < iter; in++) {

				if (open_file(in, subory2, &dokument)) {

					//	std::cout << " \n subor je otvoreny \n" ;

					citaj(dokument, vyraz, subory2[in], iter, prepinac, pri_a,
							pocet);

					close_file(dokument);

				} else {

					//	std::cout<< " \n subor sa nepodarilo otvorit \n";
				}

			}

		} else {
			//	std::cout << i;
			if (open_file(i, subory, &dokument)) {

				//	std::cout << " \n subor je otvoreny \n" ;

				citaj(dokument, vyraz, subory[i], tmp, prepinac, pri_a, pocet);

				close_file(dokument);

			} else {

				//	std::cout<< " \n subor sa nepodarilo otvorit \n";
			}

		} //koniec podmieky pre *

	} //koniec for cyklu
}

