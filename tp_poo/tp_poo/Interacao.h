#ifndef __INTERACAO_H__
#define __INTERACAO_H__

#include <string>
#include <sstream>
#include <fstream>
#include <istream>
#include <iterator>
#include <iostream>
#include "Mapa.h"


class Interacao {
	int flag;
	Mapa map;
	bool flag_moeda;
public:
	int menu();
	void corre();
	string verCaracteristicas();
	void inicio();
	bool VerificaComando(string comando);
	string getComandos();
	bool Lerficheiro(string nome);
};

#endif