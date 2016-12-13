
#include "Mapa.h"

Mapa::Mapa(int x, int y):dimx(x<10?10:x),dimy(y<10?10:y)
{
	
}

bool Mapa::desenhaTabuleiro(vector <Colonia*> c)
{
	Consola::setTextColor(Consola::BRANCO);
	Consola::gotoxy(1, 1);

}