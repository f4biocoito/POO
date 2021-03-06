#ifndef LOAD_H
#define LOAD_H

#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>

#include "colonia.h"
#include "Consola.h"
#include "Edificios.h"
#include "Mapa.h"
#include "Perfil.h"
#include "Seres.h"

#define LINHAMAX 20
#define COLUNAMAX 10

using namespace std;

bool jogoIniciado = false;
bool jogoTerminado = false;
int oponentes = 0;


void scroll(char car);
bool leComandosMenu();
bool leComandosJogo();
string getComandos();
string getCaracteristicas();
Mapa map;
vector <Perfil*> caracteristicas;

bool sair = false;
int menu();
bool file = false;
int maxX = 100, maxY = 100;
int xini = 10, yini = 10;


void desenhaTab();

#endif