#ifndef __MAPA_H__
#define __MAPA_H__

#include "colonia.h"

using namespace std;

class Mapa
{
	int dimx;
	int dimy;
public:
	Mapa(int x=50, int y=50);
	vector <Colonia*> populacoes;
	void UnitsInGrid(int colMax, int colMin, int linhaMax, int linhaMin);
	void BuildingsInGrid(int colMax, int colMin, int linhaMax, int linhaMin);
	void setX(int x);
	void setY(int y);
	
	Colonia* getPop(char p);
	int getX(){return dimx;}
	int getY(){return dimy;}

};

#endif