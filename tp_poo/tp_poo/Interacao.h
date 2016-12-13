#ifndef __INTERACAO_H__
#define __INTERACAO_H__

#include <string>
#include <sstream>
#include <fstream>
#include <istream>
#include <iterator>
#include <iostream>
#include "Load.h"

class Interacao {
	
public:
	Interacao();
	int menu();
	void corre();
	void verCaracteristicas();
	void inicio();
	bool VerificaComando(string comando);
	string getComandos();
	bool Lerficheiro(string nome);
};

#endif