#ifndef __PERFIL_H__
#define __PERFIL_H__

#include <iostream>
#include <string>

using namespace std;

class Perfil {
	char nome;
	string * carac;
	int quantas;
public:
	Perfil();
	char getNome()const { return nome; }
	string getCarac(int i)const { return carac[i]; }

	void setNome(char n);
	void addCarac(string car);
	void subCarac(string car);
};


#endif