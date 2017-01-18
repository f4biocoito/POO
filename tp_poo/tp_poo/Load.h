#ifndef LOAD_H
#define LOAD_H



#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Caracteristicas.h"
#include "colonia.h"
#include "Configuracao.h"
#include "Consola.h"
#include "Defines.h"
#include "Edificios.h"
#include "Mapa.h"
#include "Seres.h"
#include "Simulacao.h"

#define LINHAMAX 20
#define COLUNAMAX 10

using namespace std;



bool jogoIniciado = false;
bool jogoTerminado = false;

void scroll(char car);
bool leComandosMenu();
bool leComandosJogo();
string getComandos();
string getCaracteristicas();
Mapa map; 

bool sair = false;
int menu();
bool file = false;
int maxX = 100, maxY = 100;
int xini = 10, yini = 10;


void desenhaTab();

#endif