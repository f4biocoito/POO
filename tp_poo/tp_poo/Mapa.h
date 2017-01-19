#ifndef __MAPA_H__
#define __MAPA_H__

#include "colonia.h"

using namespace std;

class Mapa
{
	int dimx;
	int dimy;
	int focoX; //nao esta a ser usado
	int focoY; //nao esta a ser usado
public:
	Mapa(int x=50, int y=50);
	vector <Colonia*> populacoes;
	void UnitsInGrid(int colMax, int colMin, int linhaMax, int linhaMin);
	void BuildingsInGrid(int colMax, int colMin, int linhaMax, int linhaMin);

	void setX(int x);
	void setY(int y);
	void setFocoX(int x);
	void setFocoY(int y);
	
	Colonia* getPop(char p);
	int getX()const{return dimx;}
	int getY()const{return dimy;}

};

#endif