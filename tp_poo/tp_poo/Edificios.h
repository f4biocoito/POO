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
	int nivel;
	int ataque;
	int defesa; 
	int cordX, cordY;
	int gera;
	char tipo;
	int visao;
public:
	Edificio(int x, int y, string sis) { id = sis; cordX = x; cordY = y; }

	//funcoes get
	int getNivel() {return nivel;}
	string getId () const { return id; }
	int getHP () const { return hp; }
	int getHPMax () const { return hpMax; }
	int getCordX () const { return cordX; }
	int getCordY () const { return cordY; }
	char getTipo() {return tipo;}
	//funcoes set

	void upgrade();
	void perdeHP(int dano);
	void conserta(int recupera);

	virtual void desenha(int x, int y) {}
};


//-------------------Castelo-------------------------
class Castelo :public Edificio {

public:
	Castelo(int x, int y, string sis) :Edificio(x, y, sis) { hp = 50; hpMax = 50; nivel=0; tipo='c'; defesa=10; gera=0; visao=0; ataque=0; }
	Castelo (const Castelo & c)=delete; 
	void desenha(int x, int y);
};

//-------------Quinta--------------------------------
class Quinta :public Edificio {
private:
	
public:
	Quinta(int x, int y, string sis) :Edificio(x, y, sis) { hp = 20; hpMax = 20; nivel =0; tipo='q'; defesa=10; gera=1; visao=0; ataque=0; }

	void desenha(int x, int y);
};

//-------------Torre--------------------------------
class Torre :public Edificio {
protected:
	
public:
	Torre(int x, int y, string sis) :Edificio(x, y, sis) { hp = 20; hpMax = 20;nivel=0; visao=0; tipo= 't';defesa=10;gera=2; visao=2; ataque=3;}

	void desenha(int x, int y);
};


#endif