#include "Colonia.h"
void Faccao :: setAttack(string idu, string idAlvo,int x,int y)
{
    vector<Unidade*> :: iterator un;
    vector<Unidade*> :: iterator alvo;
    for(un=UnitList.begin();un!=UnitList.end();un++)
    {
        if((*un)->getId()==idu)
        {
            (*un)->setAtacar(x,y,idAlvo);
        }
    }
}
 

int Colonia:: ataca(string atacante)
{
    vector <Unidade*> :: iterator unidade;
     
    for(unidade=UnitList.begin();unidade!=UnitList.end();unidade++)
    {
        if((*unidade)->getId()==atacante)
        {
            return (*unidade)->getDano();
        }
    }
    return 0;
}

void Colonia::atacado(string vitima, int dano) //retira hp a vitima
{
    vector <Unidade*> :: iterator alvo;
 
    for(alvo=UnitList.begin();alvo!=UnitList.end();alvo++)
    {
        if((*alvo)->getId()==vitima)
        {
            (*alvo)->setHP(  (*alvo)->getHP()-dano + (*alvo)->getDefesa() );
        }
    }
}

//saber posicoes
int Colonia:: getXFromUnitID(string idu)
{
    vector <Unidade*> :: iterator alvo;
    int x;
    for(alvo=UnitList.begin();alvo!=UnitList.end();alvo++)
    {
        if((*alvo)->getId()==idu)
        {
            x=(*alvo)->getCordX();
            return x;
        }
    }
    return 0;
}
int Colonia:: getYFromUnitID(string idu)
{
    vector <Unidade*> :: iterator alvo;
    int y;
    for(alvo=UnitList.begin();alvo!=UnitList.end();alvo++)
    {
        if((*alvo)->getId()==idu)
        {
            y=(*alvo)->getCordY();
            return y;
        }
    }
    return 0;
}

int Colonia::pesquisaUnidade(string name)
{
         
    for(vector<Unidade*>::iterator it = UnitList.begin(); it != UnitList.end(); ++it) 
    {
            if((*it)->getId()==name)
            {
                return 1;
            }
    }
    return 0;
}
 
//adicionar edificios
void Colonia::addCastle(int x, int y, string name) //propria funcao verifica quantos castelos existem
{
        bool cast=getcastExiste();
        if(!cast) 
        {
            Edificio* e = new Castelo(x,y,name);
            BuildingList.push_back(e);
            setcastExiste(true);
            incNumBuildings();
        }
}

//adicionar unidades
void Colonia::mkeSoldier(string name)
{
    for(vector<Edificio*>::iterator it = BuildingList.begin(); it != BuildingList.end(); ++it) 
    {
        if(((*it)->getId()).at(0)=='Q')
        {
 
            Unidade* u = new Soldado((*it)->getCordX(),(*it)->getCordY(),name);
            UnitList.push_back(u);
            incNumUnits();
        }
    }
}


void Colonia::UnitInPosition(int x, int y,int xMax, int yMax)//alterar para desenho
{
    for(vector<Unidade*>::iterator it = UnitList.begin(); it != UnitList.end(); ++it) {
        if((*it)->getCordX()==x&&(*it)->getCordY()==y)
        {(*it)->desenha(x-xMax,y-yMax);}
    }
}
void Colonia::BuildingInPosition(int x, int y,int xMax, int yMax) //alterar para desenho
{
    for(vector<Edificio*>::iterator it = BuildingList.begin(); it != BuildingList.end(); ++it) {
        if((*it)->getCordX()==x&&(*it)->getCordY()==y)
        {(*it)->desenha(x-xMax,y-yMax);}
    }
     
}



void Colonia::moveUnits()
{
    for(vector<Unidade*>::iterator it = UnitList.begin(); it != UnitList.end(); ++it) {
        (*it)->move();
    }
}

void Colonia :: setRepair(string idu,string ide)// mudar o destino do ser para o edificio
{
 
     
    vector<Unidade*>::iterator it;
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
                        (*it)->setConserta(ide,x,y);
                    }
                }
            }
        }
}
 
void Colonia::repair()//reparar só se já estiver no destino
{
    vector<Unidade*>::iterator it;
    for(it = UnitList.begin(); it != UnitList.end(); ++it) 
    {
        if(((*it)->getId()).at(0)=='P'||((*it)->getId()).at(0)=='B')
        {
            if((*it)->getIdBuilding()!="")
            {
 
                for(vector<Edificio*>::iterator et = BuildingList.begin(); et != BuildingList.end(); ++et)
                {
                    if((*it)->getIdBuilding()==(*et)->getId())
                    {
                        (*et)->conserta((*it)->conserta());
                        if((*et)->getHP()==(*et)->getHPMax())
                        {
                            (*it)->setConserta("",(*it)->getCordX(),(*it)->getCordY());
                        }
                        break;
                    }
                }
 
            }
        }
    }


//Print de info

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
   
    vector<Unidade*>::iterator it;
    for(it = UnitList.begin(); it != UnitList.end(); ++it) 
    {
        Consola::gotoxy(28,y);
        cout<<(*it)->getHP()<<"\t"<<(*it)->getId()<<"    ("<<(*it)->getCordX()<<','<<(*it)->getCordY()<<")";
 
        y++;
    }
}




