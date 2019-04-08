/*
 * SpravaCiest.h
 *
 *  Created on: Dec 8, 2018
 *      Author: zetrax
 */
#include "Cesta.h"
#include<stdio.h>
#ifndef SRC_SPRAVACIEST_H_
#define SRC_SPRAVACIEST_H_

class SpravaCiest {

private:

	struct siet{
		char *nazov_mesto =NULL;
		char **spojenia=NULL;
		char **dos_mesta=NULL;
		int *v=NULL;
		int pocet_spojeni=0;
		int vzdialenost=0;
		int od=0;



	};
	typedef struct siet siet;


	int size_pole;
	siet *pole;

	Cesta *prva;
	Cesta *posledna;
	void mallocuj_tmp_premenne(char **tmp_mesto_A,char **tmp_mesto_B,char **tmp_meno_cesty);
	void zmaz_tmp_premenne(char **tmp_mesto_A,char **tmp_mesto_B,char **tmp_meno_cesty);

public:
	SpravaCiest();
	void pridajSpojenie(Cesta *tmp,int iter, char*B);
	bool zistiVSieti(char *meno,int *iter, int size);
	bool zistiVSietiCestu(int iter,char *meno);
	void vypisSiet(int iter);
	void vytvorSiet(int poc);
	void vypis_ciest();
	void vytvorPoleSiet();
	void spusti();
	Cesta* get_prva();
	void zmazCestu(char *tmp_meno_cesty);
	void zmazVestkyyCesty(char *meno);
	void set_prva(Cesta* prva_n);
	void vytvorListCiest();
	void vypisCiestSubor(FILE *fw);
	void pridajCestu(int tmp_smer ,char *tmp_mesto_A,char *tmp_mesto_B,int tmp_typ,int tmp_rychlost,char *tmp_meno_cesty );
	void nacitajMeno(char **tmp_meno_cesty);
	void vycistiC();
	void spustiZmaz();
	void zoradenyVypis();
	void naskenujVstup(char **tmp_meno_cesty,int *tmp_smer,char **tmp_mesto_A, char **tmp_mesto_B,int *tmp_typ,int *tmp_rychlost);
};

#endif /* SRC_SPRAVACIEST_H_ */
