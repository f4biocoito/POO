
#include "Mapa.h"

Mapa::Mapa(int x, int y)
{
	dimx = x;
	dimy = y;
}

void Mapa::setX(int x){ dimx =x;}
void Mapa::setY(int y) {dimy=y;}

void Mapa::setFocoX(int x) { focoX = x; }
void Mapa::setFocoY(int y) { focoY = y; }

Colonia* Mapa::getPop(char p)
{
	for (auto it = populacoes.begin(); it <= populacoes.end(); ++it)
		if (p == (*it)->getId()) {	
			return (*it);
		}
	return nullptr;
}

void Mapa::UnitsInGrid(int colMax, int colMin, int linhaMax, int linhaMin) 
{

	int l, c;
	l = linhaMin;

	while (l<linhaMax)
	{
		for (c = colMin; c <= colMin; c++)
		{
			for (auto pop = populacoes.begin(); pop != populacoes.end(); ++pop)
			{
				(*pop)->UnitInPosition(colMin, linhaMin, colMax, linhaMax, (*pop)->getUnitList());
			}
		}
		l++;
	}
}

void Mapa::BuildingsInGrid(int colMax, int colMin, int linhaMax, int linhaMin)
{

	int line, col;
	line = linhaMin;

	while (line<linhaMax)
	{
		for ( col = colMin; col <= colMax; col++)
		{
			for (auto pop = populacoes.begin(); pop != populacoes.end(); ++pop)
			{
				(*pop)->BuildingInPosition(colMin, linhaMin, (*pop)->getBuildingList());
				//(*pop)->BuildingInPosition(colMin, linhaMin, colMax, linhaMax, (*pop)->getBuildingList());
			}
		}
		line++;
	}
	
}




