
#include "Mapa.h"


Mapa::Mapa(int x, int y)
{
	dimx = x;
	dimy = y;
}

bool Mapa::desenhaTabuleiro(int cmax, int cmin, int lmax, int lmin)
{
	Consola::setTextColor(Consola::BRANCO);
	Consola::gotoxy(1, 1);

	PopInGrid(cmax, cmin, lmax, lmin);
	

}

void Mapa::PopInGrid(int colMax, int colMin, int linhaMax, int linhaMin) 
{

	int l, c;
	for (l = linhaMin; l <= linhaMax; l++)
	{
		for (c = colMin; c <= colMin; c++)
		{
			for (auto pop = populacoes.begin(); pop != populacoes.end(); ++pop)
			{
				pop->getBuildingList.BuildingInPosition(colMin, linhaMin, colMax, linhaMax);
				pop->getUnitList.UnitInPosition(colMin, linhaMin, colMax, linhaMax);
				
			}
		}
	}
}




