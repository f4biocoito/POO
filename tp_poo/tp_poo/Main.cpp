#include <string>
#include <iostream>
using namespace std;

#include "Load.h"







int main() {
	Interacao jogo;
	jogo.corre();
	
	//while (!sair) //ciclo principal
	//{
	//// while ciclo de leitura de comandos
	////{le comandos }
	//
	//Consola::clrscr();
	//car=Consola::getch();
	//if (car == Consola::ESCAPE) break;
	//if ((car != Consola::ESQUERDA) && (car != Consola::DIREITA) && (car != Consola::CIMA) && (car != Consola::BAIXO)) 
	//{
	//	if (car == Consola::ENTER) continue;
	//	else 
	//	{
	//		//leComandos();
	//		//joga pc
	//		continue;
	//	}
	//}

	////SCROLL
	//scroll(car);


	//} //FIM DO CICLO WHILE DE SAIR 

}

void scroll(char car) 
{
	if (car == Consola::ESQUERDA) scrollX--;
	if (car == Consola::DIREITA) scrollX++;
	if (car == Consola::CIMA) scrollY--;
	if (car == Consola::BAIXO) scrollY++;
	if (scrollX<0) scrollX++; //nao permite valores negativos 
	if (scrollY<0) scrollY++;
	if (scrollX>maxX - 9) scrollX--;
	if (scrollY>maxY - 9) scrollY--;
}

void desenhaTab(int x, int y)
{
	for (int i = scrollX; i < scrollX + LINHAMAX; i++)
	{
		for (int j = scrollY; i < scrollY + COLUNAMAX; j++)
		{
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 11))
				c->quadricula(i - scrollX, j - scrollY);
		}
	}
}