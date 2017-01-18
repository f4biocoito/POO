
#include "Edificios.h"

void Edificio::conserta(int recupera)
{
	hp = hp + recupera;
	if (hp > hpMax)
		hp = hpMax;
}

void Castelo::desenha(int x, int y)
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

void Quinta::desenha(int x, int y)
{
	x = x * 3 + 1;
	y = y * 3 + 1;

	Consola::setTextColor(Consola::CINZENTO);

	Consola::gotoxy(x - 1, y - 1);
	cout << (char)197 << (char)197 << (char)197;
	Consola::setTextColor(Consola::VERMELHO);
	Consola::gotoxy(x - 1, y);
	Consola::setTextColor(Consola::VERDE);
	cout << (char)42;
	Consola::setTextColor(Consola::VERMELHO);
	cout << (char)177;
	Consola::setTextColor(Consola::VERDE);
	cout << (char)42 << endl;
	Consola::setTextColor(Consola::VERMELHO);
	Consola::gotoxy(x - 1, y + 1);
	cout << (char)177 << (char)178 << (char)177 << endl;
	Consola::setTextColor(Consola::PRETO);
}

void Torre::desenha(int x, int y)
{
	x = x * 3 + 1;
	y = y * 3 + 1;

	Consola::setTextColor(Consola::CINZENTO);

	Consola::gotoxy(x - 1, y - 1);
	cout << (char)197 << (char)197 << (char)197;
	Consola::setTextColor(Consola::VERMELHO);
	Consola::gotoxy(x - 1, y);
	Consola::setTextColor(Consola::VERDE);
	cout << (char)42;
	Consola::setTextColor(Consola::VERMELHO);
	cout << (char)177;
	Consola::setTextColor(Consola::VERDE);
	cout << (char)42 << endl;
	Consola::setTextColor(Consola::VERMELHO);
	Consola::gotoxy(x - 1, y + 1);
	cout << (char)177 << (char)178 << (char)177 << endl;
	Consola::setTextColor(Consola::PRETO);
}