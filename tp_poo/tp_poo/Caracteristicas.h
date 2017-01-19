#ifndef __CARACTERISTICAS_H__
#define __CARACTERISTICAS_H__

#include <string>
#include <string.h>
#include <iostream>

using namespace std;

class Caracteristicas {
	//string nome;
	int id;
	int custo;
	int forca;
	
public:
	Caracteristicas(int i, int c, int f);
	Caracteristicas(const Caracteristicas & ob) = delete; //construtor por copia
	Caracteristicas & operator=(const Caracteristicas &ob) = delete; //operador atribuicao

	int getID()const { return id; }
	int getCusto()const { return custo; }
	int getForca()const { return forca; }

	void setID(int i);
	void setCusto(int c);
	void setForca(int f);

	virtual bool trabalha()=0;
};

class Bandeira :public Caracteristicas {

public:
	Bandeira() :Caracteristicas(1,1,0){}

	bool trabalha() {
		//mudar o ser para outra colonia
	}
};

class Superior :public Caracteristicas {

public:
	Superior() :Caracteristicas(2, 1, 1) {}

	bool trabalha() {
		//aumenta a saude do ser

	}
};

/*
Bandeira
Superior
PeleDura
Armadura
Faca
Espada
Agresao	Ecologico
HeatSeeker
BuildSeeker
Walker
Remedio
SecondChance
*/


#endif