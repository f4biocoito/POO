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
	Seres(string id, int hp = 10,int forca = 10, int velocidade = 1, int dano = 1, int defesa = 1, int cordX=0, int cordY=0)
	{
			
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
	void setStatus(string estado) { status = estado; }
	void setCordDestinoX(int x) { cordDestinoX = x; }
	void setCordDestinoY(int y) { cordDestinoY = y; }
	void setAtacar(int xAlvo, int yAlvo, string nome);

	void move();

	void desenha(int x, int y) {}


};


class Perfil1 : Seres {

	
public:	
	Perfil1(string id , int hp , int forca , int velocidade , int dano , int defesa , int cordX , int cord) :Seres(id="", hp = 10,  forca = 10, velocidade = 1, dano = 1, defesa = 1, cordX=0, cord=0) {}
	void desenha(int x, int y)
	{
		x = x * 3 + 1;
		y = y * 3 + 1;


		Consola::setTextColor(Consola::CINZENTO);

		Consola::gotoxy(x - 1, y - 1);
		cout << (char)0 << (char)124;
		Consola::setTextColor(Consola::VERMELHO);
		cout << (char)62 << endl;
		Consola::setTextColor(Consola::CINZENTO);
		Consola::gotoxy(x - 1, y);
		cout << (char)47 << (char)95 << (char)92 << endl;
		Consola::gotoxy(x - 1, y + 1);
		cout << (char)124 << (char)42 << (char)124 << endl;
		Consola::setTextColor(Consola::PRETO);
	}
};


#endif