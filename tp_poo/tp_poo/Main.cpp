#include <string>
#include <iostream>
using namespace std;

#include "Load.h"

void scroll(char car);

bool sair=false;
int scrollX = 0, scrollY = 0;
int maxX = 9, maxY = 9;

int main() {

	//char car;
	Consola::setTextSize(12, 12);
	Consola::setScreenSize(40, 55);

	Consola::setTextColor(Consola::PRETO);
	Consola::setBackgroundColor(Consola::BRANCO_CLARO);
	Consola::clrscr();

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