#ifndef __INTERACAO_H__
#define __INTERACAO_H__

#include <string>
#include <sstream>
#include <fstream>
#include <istream>
#include <iterator>
#include <iostream>
#include "Mapa.h"

static bool iniciar = false;

class Interacao {
	Mapa map;
	bool flag_moeda;
	Consola *c;
	bool jogoIniciado = false;
public:
	Interacao();

	bool getJogoIniciado() { return jogoIniciado; }
	void setJogoIniciado(bool b);


	void jogar();
	int menu();
	void corre();
	void inicio();
	bool VerificaComandoIniciais(string comando);

	bool Lerficheiro(string nome);
	string getComandos();
	string getCaracteristicas();
};


#endif