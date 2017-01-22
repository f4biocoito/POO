
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

void Seres::desenha(int x, int y)
{
	x = x * 3 + 1;
	y = y * 3 + 1;


	Consola::setTextColor(Consola::CINZENTO);

	Consola::gotoxy(x - 1, y - 1);
	cout << (char)0 << (char)124;
	Consola::setTextColor(Consola::VERMELHO);
	cout << (char)62 << endl;
	Consola::setTextColor(Consola::CINZENTO);
	Consola::gotoxy(x - 1, y);
	cout << (char)47 << (char)95 << (char)92 << endl;
	Consola::gotoxy(x - 1, y + 1);
	cout << (char)124 << (char)42 << (char)124 << endl;
	Consola::setTextColor(Consola::PRETO);
}