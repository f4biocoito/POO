#ifndef __SERES_H__
#define __SERES_H__

#include <string>
#include <iostream>
#include "Consola.h"
using namespace std;

class Seres
{
protected:
	string id;
	int hp;
	int dano;
	int defesa;
	int velocidade;
	int capCarga;
	int cordX;
	int cordY;
	int cordDestinoX;
	int cordDestinoY;
	int cordAlvoX;
	int cordAlvoY;
	string alvo;

	bool wandering;
	string status; //estado da unidade - atacar, fugir, defender


public:
	// Unidade(int x, int y, string ident) { id = ident;cordDestinoX = x; cordDestinoY = y; cordX = x;cordY = y;cordAlvoX = -1;cordAlvoY = -1;alvo = ""; } 

	//Funcoes get

	string getId() { return id; }
	int getHP() { return hp; }
	int getDano() { return dano; }
	int getDefesa() { return defesa; }
	int getVelocidade() { return velocidade; };
	int getCordX() { return cordX; }
	int getCordY() { return cordY; }
	int getCordDestinoX() { return cordDestinoX; }
	int getCordDestinoY() { return cordDestinoY; }
	string getAlvo() { return alvo; }
	int getCordAlvoX() { return cordAlvoX; }
	int getCordAlvoY() { return cordAlvoY; }
	bool getWandering() { return wandering; }
	string getStatus() { return status; }
	int getCargaMax() { return capCarga; }

	//Set
	void setHP(int h) { hp = h; }
	void setWandering(bool deambula) { wandering = deambula; }
	void setStatus(string estado) { status = estado; }
	void setCordDestinoX(int x) { cordDestinoX = x; }
	void setCordDestinoY(int y) { cordDestinoY = y; }

	void move();
	



#endif