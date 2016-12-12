
#include "Seres.h"

void Seres::move()
{
	for (int i = 0; i<velocidade;i++)
	{
		if (cordX != cordDestinoX&&cordY != cordDestinoY)
		{
			if (cordX>cordDestinoX&&cordY>cordDestinoY)
			{
				cordX--;
				cordY--;
			}
			else if (cordX>cordDestinoX&&cordY<cordDestinoY)
			{
				cordX--;
				cordY++;
			}
			else if (cordX<cordDestinoX&&cordY>cordDestinoY)
			{
				cordX++;
				cordY--;
			}
			else if (cordX<cordDestinoX&&cordY<cordDestinoY)
			{
				cordX++;
				cordY++;
			}
		}
		else if (cordX != cordDestinoX&&cordY == cordDestinoY)
		{
			if (cordX>cordDestinoX)
			{
				cordX--;
			}
			else if (cordX<cordDestinoX)
			{
				cordX++;
			}
		}
		else if (cordY != cordDestinoY&&cordX == cordDestinoX)
		{
			if (cordY>cordDestinoY)
			{
				cordY--;
			}
			else if (cordY<cordDestinoY)
			{
				cordY++;
			}
		}
		else
		{
		}
	}
}

void Seres::setAtacar(int xAlvo, int yAlvo, string nome)
{
	alvo = nome;
	cordAlvoX = xAlvo;
	cordAlvoY = yAlvo;
	cordDestinoX = xAlvo;
	cordDestinoY = yAlvo;
}

