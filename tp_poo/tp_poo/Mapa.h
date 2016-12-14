#ifndef __MAPA_H__
#define __MAPA_H__

#include "colonia.h"

using namespace std;

class Mapa
{
	int dimx;
	int dimy;
	//vector <Colonia> populacoes;
public:
	Mapa(int x=0, int y=0);
	vector <Colonia> populacoes;
	void PopInGrid(int colMax, int colMin, int linhaMax, int linhaMin);
	void setX(int x);
	void setY(int y);

	int getX(){return dimx;}
	int getY(){return dimy;}

};

#endif