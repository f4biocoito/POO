#ifndef __EDIFICIOS_H__
#define __EDIFICIOS_H__

using namespace std;
#include <string>
#include <iostream>
#include "Consola.h"

class Edificio
{
protected:
	string id;
	int hp;
	int hpMax;
	int cordX, cordY;
public:
	Edificio(int x, int y, string sis) { id = sis;cordX = x;cordY = y; }

	//funушes get
	string getId() { return id; }
	int getHP() { return hp; }
	int getHPMax() { return hpMax; }
	int getCordX() { return cordX; }
	int getCordY() { return cordY; }

	//funушes
	void perdeHP(int dano) { hp = hp - dano; }
	void conserta(int recupera);
	virtual void desenha(int x, int y) {}
};


//-------------------Castelo-------------------------
class Castelo :public Edificio {

public:
	Castelo(int x, int y, string sis) :Edificio(x, y, sis) { hp = 200;hpMax = 200; }
	//Castelo (const Castelo & c){id=c.id; hp=c.hp; cordX=c.cordX; cordY=c.cordY;} construtor copia 
	void desenha(int x, int y)
	{
		Consola c;
		x = x * 3 + 1;
		y = y * 3 + 1;


		c.setTextColor(c.CINZENTO);

		c.gotoxy(x - 1, y - 1);
		cout << (char)0 << (char)124;
		c.setTextColor(c.VERMELHO);
		cout << (char)62 << endl;
		c.setTextColor(c.CINZENTO);
		c.gotoxy(x - 1, y);
		cout << (char)47 << (char)95 << (char)92 << endl;
		c.gotoxy(x - 1, y + 1);
		cout << (char)124 << (char)42 << (char)124 << endl;
		c.setTextColor(c.PRETO);
	}
};

//-------------Quinta--------------------------------
class Quinta :public Edificio {

public:
	Quinta(int x, int y, string sis) :Edificio(x, y, sis) { hp = 80;hpMax = 80; }

	void desenha(int x, int y)//Aumentar castelo
	{
		Consola c;
		x = x * 3 + 1;
		y = y * 3 + 1;

		c.setTextColor(c.CINZENTO);

		c.gotoxy(x - 1, y - 1);
		cout << (char)197 << (char)197 << (char)197;
		c.setTextColor(c.VERMELHO);
		c.gotoxy(x - 1, y);
		c.setTextColor(c.VERDE);
		cout << (char)42;
		c.setTextColor(c.VERMELHO);
		cout << (char)177;
		c.setTextColor(c.VERDE);
		cout << (char)42 << endl;
		c.setTextColor(c.VERMELHO);
		c.gotoxy(x - 1, y + 1);
		cout << (char)177 << (char)178 << (char)177 << endl;
		c.setTextColor(c.PRETO);
	}
};

#endif