
#include "Mapa.h"

Mapa::Mapa(int x, int y)
{
	dimx = x;
	dimy = y;
}

void Mapa::setX(int x){ dimx =x;}
void Mapa::setY(int y) {dimy=y;}



void Mapa::PopInGrid(int colMax, int colMin, int linhaMax, int linhaMin) 
{

	int l, c;
	for (l = linhaMin; l <= linhaMax; l++)
	{
		for (c = colMin; c <= colMin; c++)
		{
			for (auto pop = populacoes.begin(); pop != populacoes.end(); ++pop)
			{
				(pop)->getBuildingList.BuildingInPosition(colMin, linhaMin, colMax, linhaMax);
				pop->getUnitList.UnitInPosition(colMin, linhaMin, colMax, linhaMax);
			}
		}
	}
}




