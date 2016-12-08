
#include "Edificio.h"

#include "Edificio.h"

void Edificio::conserta(int recupera)
{
	hp = hp + recupera;
	if (hp > hpMax)
		hp = hpMax;
}

