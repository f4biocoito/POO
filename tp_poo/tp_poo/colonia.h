#ifndef Colonia_H
#define Colonia_H
 
using namespace std;
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <sstream>
 
 
#include "Edificio.h"
#include "Seres.h"
 
class Faccao{
private:
    string id;
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
     
    Faccao (string name=""){id=name;castExiste=false; quartExiste=false; numQuint=0; 
	numUnits=0;numBuildings=0; moedas=100;}
	
 int pesquisaUnidade(string id);
    // gets
    vector <Unidade*> getUnitList(){return UnitList;}
    vector <Edificio*> getBuildingList(){return BuildingList;}
    int getNumUnits(){return numUnits;}
    string getId(){return id;}
    int getMoedas(){return moedas;
    
    int getNumBuildings(){return numBuildings;}
  
//verifica se castelo ja existe
    bool getcastExiste(){return castExiste;}

 void setcastExiste( bool existecast){castExiste=existecast;}

//set

    void setMoedas(int coins){pedra=coins;}

//incrementa e decrementa unidades e edificios
    void incNumUnits(){numUnits++;}
    void decNumUnits(){numUnits--;}
    void incNumBuildings(){numBuildings++;}
    void decNumBuildings(){numBuildings--;}

  //adicionar e remover edificios e unidades
    void addCastle(int x, int y, string name);
    void addFarm(int x, int y, string name); //adicionar n units possivel
    void addTower(int x, int y, string name);
    void removeCastle();
 
//adicionar unidades - NAO E BEM ISTO MAS FICA A IDEIA - faltam os perfis / caracteristicas
    void mkeSoldier(string name);

 //verifica posicoes
    void UnitInPosition(int x,int y,int xMax, int yMax);
    void BuildingInPosition(int x, int y,int xMax, int yMax);

//movimento
    void moveUnits();

 //conserta
    void repair();  
    void setRepair(string idu,string ide);

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
    string infoSel(string nome);
 
};
#endif  


