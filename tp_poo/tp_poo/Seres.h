#ifndef __SERES_H__
#define __SERES_H__

#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include "Consola.h"
#include "Perfil.h"

using namespace std;

class Seres
{


protected:
	string id;
	int hp;
	int forca; // a caracteristica altera estes valores
	int dano;
	int defesa;
	int velocidade;
	int cordX;
	int cordY;
	int cordDestinoX;
	int cordDestinoY;
	int cordAlvoX;
	int cordAlvoY;
	string alvo;

	string status; //estado da unidade - atacar, fugir, defender

public:
	Seres(int cX, int cY, string id, int hp = 10,int forca = 10, int velocidade = 1, int dano = 1, int defesa = 1)
	{
		cordX = cX;
		cordY = cY;
		id = id;
	}

	//Funcoes get

	string getId () { return id; }
	int getHP () { return hp; }
	int getDano () { return dano; }
	int getDefesa () { return defesa; }
	int getVelocidade () { return velocidade; };
	int getCordX () { return cordX; }
	int getCordY () { return cordY; }
	int getCordDestinoX () { return cordDestinoX; }
	int getCordDestinoY () { return cordDestinoY; }
	string getAlvo () { return alvo; }
	int getCordAlvoX () { return cordAlvoX; }
	int getCordAlvoY () { return cordAlvoY; }


	string getStatus () { return status; }

	//Set
	void setHP(int h) { hp = h; }
	void setForca(int f) { forca = f; }
	void setStatus(string estado) { status = estado; }
	void setCordDestinoX(int x) { cordDestinoX = x; }
	void setCordDestinoY(int y) { cordDestinoY = y; }
	void setAtacar(int xAlvo, int yAlvo, string nome);

	void move();

	void desenha(int x, int y);
};


#endif