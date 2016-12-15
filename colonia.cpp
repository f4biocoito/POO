
#include "colonia.h"

Colonia::Colonia(char name) {
	id = name; 
	castExiste = false; 

	numQuint = 0;
	numUnits = 0; 
	numBuildings = 0; 
	moedas = 100;
}

int Colonia::pesquisaUnidade(string id)
{
         
    for(auto it = UnitList.begin(); it != UnitList.end(); ++it) 
    {
            if((*it)->getId()==id)
            {
                return 1;
            }
    }
    return 0;
}

//adicionar e remover edificios
void Colonia::addCastle(int x, int y, string name)//propria funcao verifica quantos castelos existem
{
	bool cast = getcastExiste();
	if (!cast)
	{
		Edificio* e = new Castelo(x, y, name);
		BuildingList.push_back(e);
		setcastExiste(true);
		incNumBuildings();
	}
}

void Colonia::addFarm(int x, int y, string name) 
{

}
void Colonia::addTower(int x, int y, string name) 
{

}
void Colonia::removeCastle() 
{

}


//adicionar seres
void Colonia::addSer(int x, int y, string name)
{

}

//void Colonia::mkeSer(string name)
//{
//    for(vector<Edificio*>::iterator it = BuildingList.begin(); it != BuildingList.end(); ++it) 
//    {
//        if(((*it)->getId()).at(0)=='Q')
//        {
//            Seres* u = new Soldado((*it)->getCordX(),(*it)->getCordY(),name);
//            UnitList.push_back(u);
//            incNumUnits();
//        }
//    }
//}

//verifica posicoes e desenha
void Colonia::UnitInPosition(int x, int y, int xMax, int yMax, vector <Seres *> UList)
{
    for(vector<Seres*>::iterator it = UList.begin(); it != UList.end(); ++it) {
        if((*it)->getCordX()==x&&(*it)->getCordY()==y)
        {(*it)->desenha(x-xMax,y-yMax);}
    }
}
void Colonia::BuildingInPosition(int x, int y,int xMax, int yMax, vector <Edificio *> BList)
{
    for(vector<Edificio*>::iterator it = BList.begin(); it != BList.end(); ++it) {
        if((*it)->getCordX()==x&&(*it)->getCordY()==y)
        {(*it)->desenha(x-xMax,y-yMax);}
    }
}


//movimento
void Colonia::moveUnits()
{
    for(vector<Seres*>::iterator it = UnitList.begin(); it != UnitList.end(); ++it) {
        (*it)->move();
    }
}

//conserta
void Colonia::setRepair(string idu,string ide)// mudar o destino do ser para o edificio
{
    vector<Seres*>::iterator it;
    vector<Edificio*>::iterator et;
    int x, y;
   
      for(it = UnitList.begin(); it != UnitList.end(); ++it) 
        {
            if((*it)->getId()==idu)
            {
                for(et = BuildingList.begin(); et != BuildingList.end(); ++et) 
                {
                    if((*et)->getId()==ide)
                    {
                        x=(*et)->getCordX();
                        y=(*et)->getCordY();
                     //   (*it)->repair(ide,x,y);
                    }
                }
            }
        }
}
 
//void Colonia::repair(string ide, int x, int y)//reparar só se já estiver no destino
//{
//	vector<Seres*>::iterator it;
//	for (it = UnitList.begin(); it != UnitList.end(); ++it)
//	{
//		if (((*it)->getId()).at(0) == 'P' || ((*it)->getId()).at(0) == 'B')
//		{
//			if ((*it)->getIdBuilding() != "")
//			{
//
//				for (vector<Edificio*>::iterator et = BuildingList.begin(); et != BuildingList.end(); ++et)
//				{
//					if ((*it)->getIdBuilding() == (*et)->getId())
//					{
//						(*et)->conserta((*it)->conserta());
//						if ((*et)->getHP() == (*et)->getHPMax())
//						{
//							(*it)->setConserta("", (*it)->getCordX(), (*it)->getCordY());
//						}
//						break;
//					}
//				}
//
//			}
//		}
//	}
//}

//ataques
int Colonia::getXFromUnitID(string idu)
{
	vector <Seres*>::iterator alvo;
	int x;
	for (alvo = UnitList.begin(); alvo != UnitList.end(); alvo++)
	{
		if ((*alvo)->getId() == idu)
		{
			x = (*alvo)->getCordX();
			return x;
		}
	}
	return 0;
}

int Colonia::getYFromUnitID(string idu)
{
	vector <Seres*>::iterator alvo;
	int y;
	for (alvo = UnitList.begin(); alvo != UnitList.end(); alvo++)
	{
		if ((*alvo)->getId() == idu)
		{
			y = (*alvo)->getCordY();
			return y;
		}
	}
	return 0;
}
void Colonia::setAttack(string idu, string idAlvo, int x, int y)
{
	vector <Seres*>::iterator un;
	vector <Seres*>::iterator alvo;

	for (un = UnitList.begin(); un != UnitList.end(); un++)
	{
		if ((*un)->getId() == idu)
		{
			(*un)->setAtacar(x, y, idAlvo);
		}
	}
}

int Colonia::ataca(string atacante)
{
	vector <Seres*>::iterator unidade;

	for (unidade = UnitList.begin(); unidade != UnitList.end(); unidade++)
	{
		if ((*unidade)->getId() == atacante)
		{
			return (*unidade)->getDano();
		}
	}
	return 0;
}

void Colonia::atacado(string vitima, int dano) //retira hp a vitima
{
	vector <Seres*> ::iterator alvo;

	for (alvo = UnitList.begin(); alvo != UnitList.end(); alvo++)
	{
		if ((*alvo)->getId() == vitima)
		{
			(*alvo)->setHP((*alvo)->getHP() - dano + (*alvo)->getDefesa());
		}
	}
}

//constroi
void Colonia::setBuild(string idu, string nome, int x, int y)
{

}
int Colonia::build(int numBuilds) 
{
	return 0;
}

//informa??o
int Colonia:: printBuildingList()
{
    int y = 12;
    vector<Edificio*>::iterator it;
    for(it = BuildingList.begin(); it != BuildingList.end(); ++it) 
    {
        Consola::gotoxy(28,y);
        cout<<(*it)->getHP()<<"\t"<<(*it)->getId()<<"   ("<<(*it)->getCordX()<<','<<(*it)->getCordY()<<")";
 
        y++;
    }
    Consola::gotoxy(28,y);
     
    Consola::gotoxy(0,31);
    return y;
}
 
void Colonia :: printUnitList(int y)
{
    vector<Seres*>::iterator it;
    for(it = UnitList.begin(); it != UnitList.end(); ++it) 
    {
        Consola::gotoxy(28,y);
        cout<<(*it)->getHP()<<"\t"<<(*it)->getId()<<"    ("<<(*it)->getCordX()<<','<<(*it)->getCordY()<<")";
 
        y++;
    }
}

string infoSel(string nome)
{
	ostringstream oss;
	oss << "a" << endl;
	return oss.str();
}

