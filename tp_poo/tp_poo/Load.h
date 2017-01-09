#ifndef LOAD_H
#define LOAD_H

#define LINHAMAX 9
#define COLUNAMAX 9

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

using namespace std;

bool jogoIniciado = false;
bool jogoTerminado = false;

void scroll(char car);

bool sair = false;
int scrollX = 0, scrollY = 0;
int maxX = 9, maxY = 9;
void desenhaTab(int x, int y);

#endif