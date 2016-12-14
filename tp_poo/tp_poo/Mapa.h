#ifndef __MAPA_H__
#define __MAPA_H__

#include "colonia.h"

using namespace std;

class Mapa
{
	int dimx;
	int dimy;
	vector <Colonia > populacoes;
private:
	Mapa(int x=0, int y=0);
	bool desenhaTabuleiro(int cmax, int cmin, int lmax, int lmin);
	void PopInGrid(int colMax, int colMin, int linhaMax, int linhaMin);
	void setX(int x) { dimx = x; }
	void setY(int y) { dimx = y; }


};

#endif