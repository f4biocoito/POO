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

	string getId const() { return id; }
	int getHP const() { return hp; }
	int getDano const() { return dano; }
	int getDefesa const() { return defesa; }
	int getVelocidade const() { return velocidade; };
	int getCordX const() { return cordX; }
	int getCordY const() { return cordY; }
	int getCordDestinoX const() { return cordDestinoX; }
	int getCordDestinoY const() { return cordDestinoY; }
	string getAlvo const() { return alvo; }
	int getCordAlvoX const() { return cordAlvoX; }
	int getCordAlvoY const() { return cordAlvoY; }
	bool getWandering const() { return wandering; }
	string getStatus const() { return status; }
	int getCargaMax const() { return capCarga; }

	//Set
	void setHP(int h) { hp = h; }
	void setWandering(bool deambula) { wandering = deambula; }
	void setStatus(string estado) { status = estado; }
	void setCordDestinoX(int x) { cordDestinoX = x; }
	void setCordDestinoY(int y) { cordDestinoY = y; }
	void setAtacar(int xAlvo, int yAlvo, string nome);

	void move();



}
#endif