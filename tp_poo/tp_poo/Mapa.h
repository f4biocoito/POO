#ifndef __MAPA_H__
#define __MAPA_H__

#include "colonia.h"

using namespace std;


class Mapa
{
	int dimx;
	int dimy;

private:
	Mapa(int x, int y);
	bool desenhaTabuleiro(vector <Colonia*> c);

};

#endif