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
	string getId const() { return id; }
	int getHP const() { return hp; }
	int getHPMax const() { return hpMax; }
	int getCordX const() { return cordX; }
	int getCordY const() { return cordY; }

	//funcoes set
	void perdeHP(int dano) { hp = hp - dano; }
	void conserta(int recupera);
	virtual void desenha(int x, int y) {}
};


//-------------------Castelo-------------------------
class Castelo :public Edificio {

public:
	Castelo(int x, int y, string sis) :Edificio(x, y, sis) { hp = 200; hpMax = 200; }
	//Castelo (const Castelo & c){id=c.id; hp=c.hp; cordX=c.cordX; cordY=c.cordY;} construtor copia 
	void desenha(int x, int y) // por a funcao num cpp a receber o tipo de edificio por parametro
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

//-------------Quinta--------------------------------
class Quinta :public Edificio {

public:
	Quinta(int x, int y, string sis) :Edificio(x, y, sis) { hp = 80; hpMax = 80; }

	void desenha(int x, int y)//Aumentar castelo
	{
		x = x * 3 + 1;
		y = y * 3 + 1;

		Consola::setTextColor(Consola::CINZENTO);

		Consola::gotoxy(x - 1, y - 1);
		cout << (char)197 << (char)197 << (char)197;
		Consola::setTextColor(Consola::VERMELHO);
		Consola::gotoxy(x - 1, y);
		Consola::setTextColor(Consola::VERDE);
		cout << (char)42;
		Consola::setTextColor(Consola::VERMELHO);
		cout << (char)177;
		Consola::setTextColor(Consola::VERDE);
		cout << (char)42 << endl;
		Consola::setTextColor(Consola::VERMELHO);
		Consola::gotoxy(x - 1, y + 1);
		cout << (char)177 << (char)178 << (char)177 << endl;
		Consola::setTextColor(Consola::PRETO);
	}
};


#endif

