
#include "Caracteristicas.h"

Caracteristicas::Caracteristicas(int i, int c, int f) //acho que é preciso comparar cada nome para inicializar com os valores corretos
{
	id = i;
	custo = c;
	forca = f;
	/*
	const char * c = n.c_str();
	if (strcmp(c, "Bandeira"))
	{
		nome = n;
		id = 1;
		custo = 1;
		forca = 0;
	}
	else if (strcmp(c, "Superior"))
	{
		nome = n;
		id = 2;
		custo = 1;
		forca = 1;
	}



	else
		cout << "caracteristica nao existe !!!" << endl;
		*/
}

/*
Bandeira	
Superior	
PeleDura	
Armadura
Faca	
Espada	
Agresao	Ecologico	
HeatSeeker
BuildSeeker	
Walker	
Remedio	
SecondChance
*/