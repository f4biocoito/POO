
#include "Perfil.h"

Perfil::Perfil() { 
	carac = nullptr; quantas = 0; 
}

void Perfil::setNome(char n) 
{ 
	nome = n; 
}

void Perfil::addCarac(string car) 
{
	string * aux = new string[quantas + 1];
	if (aux == nullptr) return;
	for (int i = 0; i < quantas; i++)
		aux[i] = carac[i];
	aux[quantas] = car;
	quantas++;
	delete[]carac;
	for (int i = 0; i < quantas; i++)
		carac[i] = aux[i];
}

void Perfil::subCarac(string car)
{
	string * aux = new string[quantas - 1];
	if (aux == nullptr) return;
	for (int i = 0; i < quantas; i++)
		if(carac[i]!=car)
			aux[i] = carac[i];
	quantas--;
	delete[]carac;
	for (int i = 0; i < quantas; i++)
		carac[i] = aux[i];
}