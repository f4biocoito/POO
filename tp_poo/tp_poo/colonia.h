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
    char id;
	char idAlvo;
    int numUnits;
    int numBuildings;
	vector <Seres* > UnitList;
    vector <Edificio* > BuildingList;
    int moedas;
    bool castExiste;
    int numTorres;
    int numQuint;
public:
	//Constructor

	Colonia(char name);
	
	int pesquisaUnidade(string id);
 // gets
    vector <Seres* > getUnitList (){ return UnitList; }
    vector <Edificio* > getBuildingList (){ return BuildingList; }
    int getNumUnits (){ return numUnits; }
    char getId (){ return id; }
	int getMoedas () { return moedas; }

	int getXcast();
	int getYcast();
    int getNumBuildings(){return numBuildings;}
  
//verifica se castelo ja existe
    bool getcastExiste (){return castExiste;}
	void setcastExiste(bool existecast){castExiste=existecast;}

//set
    void setMoedas(int coins){ moedas =+ coins; }

//incrementa e decrementa unidades e edificios
    void incNumUnits(){numUnits++;}
    void decNumUnits(){numUnits--;}
    void incNumBuildings(){numBuildings++;}
    void decNumBuildings(){numBuildings--;}

  //adicionar e remover edificios
    void addCastle(int x, int y, string name);
    void addFarm(int x, int y, string name); 
    void addTower(int x, int y, string name);
    void removeCastle();
 
	//adicionar seres
	void addSer(int x, int y, string nome);

 //verifica posicoes
	void UnitInPosition(int x,int y,int xMax, int yMax, vector <Seres* > UList);
	void BuildingInPosition(int x, int y, vector <Edificio *> BList);

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

   
 //informacao
    int printBuildingList();
    void printUnitList(int y);
  //  string infoSel(string nome);
 
};
#endif  


