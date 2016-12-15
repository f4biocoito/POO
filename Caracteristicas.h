#ifndef __CARACTERISTICAS_H__
#define __CARACTERISTICAS_H__

#include <string>
#include <string.h>
#include <iostream>
#include "Defines.h"

using namespace std;

class Caracteristicas {
	string nome;
	int id;
	int custo;
	int forca;
	
private:
	Caracteristicas(string n);
	Caracteristicas(const Caracteristicas & ob) = delete; //construtor por copia
	Caracteristicas & operator=(const Caracteristicas &ob) = delete; //operador atribuicao
};

#endif