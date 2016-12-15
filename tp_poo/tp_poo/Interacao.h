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
public:
	int menu();
	void corre();
	void inicio();
	bool VerificaComando(string comando);
	bool Lerficheiro(string nome);
	string getComandos();
	string getCaracteristicas();
};

#endif