#ifndef __COLONIA_H__
#define __COLONIA_H__
 
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <sstream>
 
#include "Edificios.h"
#include "Seres.h"
using namespace std;
 
class Colonia
{
    string id;
	string idAlvo;
    int numUnits;
    int numBuildings;
	vector <Seres*> UnitList;
    vector <Edificio*> BuildingList;
    int moedas;
    bool castExiste;
    int numTorres;
    int numQuint;
public:
	//Constructor
     
	Colonia(string name = "");
	
	int pesquisaUnidade(string id);
 // gets
    vector <Seres*> getUnitList (){ return UnitList; }
    vector <Edificio*> getBuildingList (){ return BuildingList; }
    int getNumUnits (){ return numUnits; }
    string getId (){ return id; }
	int getMoedas () { return moedas; }
    
    int getNumBuildings(){return numBuildings;}
  
//verifica se castelo ja existe
    bool getcastExiste (){return castExiste;}
	void setcastExiste(bool existecast){castExiste=existecast;}

//set
    void setMoedas(int coins){ moedas = coins; }

//incrementa e decrementa unidades e edificios
    void incNumUnits(){numUnits++;}
    void decNumUnits(){numUnits--;}
    void incNumBuildings(){numBuildings++;}
    void decNumBuildings(){numBuildings--;}

  //adicionar e remover edificios
    void addCastle(int x, int y, string name);
    void addFarm(int x, int y, string name); //adicionar n units possivel
    void addTower(int x, int y, string name);
    void removeCastle();
 
//adicionar unidades - NAO E BEM ISTO MAS FICA A IDEIA - faltam os perfis / caracteristicas
    void addSer(int x, int y, string name);
 //   void mkeSer(string name);

 //verifica posicoes
	void UnitInPosition(int x,int y,int xMax, int yMax);
    void BuildingInPosition(int x, int y,int xMax, int yMax);

//movimento
    void moveUnits();

 //conserta
	void setRepair(string idu,string ide);
//	void repair(string ide, int x, int y);

//ataques
    int getXFromUnitID(string idu);
    int getYFromUnitID(string idu);
    void setAttack(string idu, string idAlvo,int x, int y);
    int ataca(string idu);
    void atacado(string idu, int dano);

 //constroi
    void setBuild(string idu,string nome,int x,int y);
    int build (int numBuilds);
   
 //informa??o
    int printBuildingList();
    void printUnitList(int y);
  //  string infoSel(string nome);
 
};
#endif  


