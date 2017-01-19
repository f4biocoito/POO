
#include "Caracteristicas.h"

Caracteristicas::Caracteristicas(int i, int c, int f) //acho que é preciso comparar cada nome para inicializar com os valores corretos
{
	id = i;
	custo = c;
	forca = f;
}

void Caracteristicas::setID(int i) 
{
	id = i;
}

void Caracteristicas::setCusto(int c)
{
	custo = c;
}

void Caracteristicas::setForca(int f)
{
	forca = f;
}

