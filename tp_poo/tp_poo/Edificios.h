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
	Edificio(int x, int y, string sis) { id = sis; cordX = x; cordY = y; }

	//funcoes get
	string getId () const { return id; }
	int getHP () const { return hp; }
	int getHPMax () const { return hpMax; }
	int getCordX () const { return cordX; }
	int getCordY () const { return cordY; }

	//funcoes set
	void perdeHP(int dano);
	void conserta(int recupera);

	virtual void desenha(int x, int y) {}
};


//-------------------Castelo-------------------------
class Castelo :public Edificio {

public:
	Castelo(int x, int y, string sis) :Edificio(x, y, sis) { hp = 200; hpMax = 200; }
	//Castelo (const Castelo & c){id=c.id; hp=c.hp; cordX=c.cordX; cordY=c.cordY;} construtor copia 
	void desenha(int x, int y);
};

//-------------Quinta--------------------------------
class Quinta :public Edificio {

public:
	Quinta(int x, int y, string sis) :Edificio(x, y, sis) { hp = 80; hpMax = 80; }

	void desenha(int x, int y);
};

//-------------Torre--------------------------------
class Torre :public Edificio {

public:
	Torre(int x, int y, string sis) :Edificio(x, y, sis) { hp = 50; hpMax = 50; }

	void desenha(int x, int y);
};


#endif