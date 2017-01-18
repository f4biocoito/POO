
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
		else return nullptr;
}

void Mapa::UnitsInGrid(int colMax, int colMin, int linhaMax, int linhaMin) 
{

	int l, c;
	for (l = linhaMin; l <= linhaMax; l++)
	{
		for (c = colMin; c <= colMin; c++)
		{
			for (auto pop = populacoes.begin(); pop != populacoes.end(); ++pop)
			{
				//(*pop)->getBuildingList.BuildingInPosition(colMin, linhaMin, colMax, linhaMax);
				//(*pop)->getUnitList.UnitInPosition(colMin, linhaMin, colMax, linhaMax);
				(*pop)->UnitInPosition(colMin, linhaMin, colMax, linhaMax, (*pop)->getUnitList());
			}
		}
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
			}
		}
	line++;
	}
	
}




