#include <string>
#include <iostream>
using namespace std;

#include "Load.h"

bool Comando(string comando, Mapa map);
string inicio();
int menu();
string getComandos();
string getCaracteristicas();

bool file = false;

int main() {
	Mapa map;
	string a;
	int opcao = -1;
	while (opcao != 0) {
		opcao = menu();
		switch (opcao) {
		case 0: cout << "\nSair\n";
			break;
		case 1:
		{
			cout << "iniciar" << endl;

			Comando(a, map);
			break;
		}
		}
	}
	//while (!sair) //ciclo principal
	//{
	//// while ciclo de leitura de comandos
	////{le comandos }
	//
	//Consola::clrscr();
	//car=Consola::getch();
	//if (car == Consola::ESCAPE) break;
	//if ((car != Consola::ESQUERDA) && (car != Consola::DIREITA) && (car != Consola::CIMA) && (car != Consola::BAIXO)) 
	//{
	//	if (car == Consola::ENTER) continue;
	//	else 
	//	{
	//		//leComandos();
	//		//joga pc
	//		continue;
	//	}
	//}

	////SCROLL
	//scroll(car);


	//} //FIM DO CICLO WHILE DE SAIR 

}

void scroll(char car) 
{
	if (car == Consola::ESQUERDA) scrollX--;
	if (car == Consola::DIREITA) scrollX++;
	if (car == Consola::CIMA) scrollY--;
	if (car == Consola::BAIXO) scrollY++;
	if (scrollX<0) scrollX++; //nao permite valores negativos 
	if (scrollY<0) scrollY++;
	if (scrollX>maxX - 9) scrollX--;
	if (scrollY>maxY - 9) scrollY--;
}

void desenhaTab(int x, int y)
{
	for (int i = scrollX; i < scrollX + LINHAMAX; i++)
	{
		for (int j = scrollY; i < scrollY + COLUNAMAX; j++)
		{
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 11))
				Consola::quadricula(i - scrollX, j - scrollY);
		}
	}
}


void jogar(){}


bool Comando(string comando,  Mapa map)
{
	while (1) {
		if (jogoiniciado) { // inicio programa
			break;
		}
		if (!file) {
			cout << "Config>>: ";
			cin.clear();
			getline(cin, comando);
			if (comando == "comandos") {
				cout << getComandos();
			}
		}

	string cmd[5];
	istringstream iss(comando);
	int i = 0;
	for (auto it = istream_iterator<string>(iss); it != istream_iterator<string>() && i < 5; ++it, ++i)
		cmd[i] = *it;


	if (cmd[0] == "dim")
	{
		istringstream iss1(cmd[2]);
		istringstream iss2(cmd[3]);
		int x1, y1;
		iss1 >> x1;
		iss2 >> y1;
		if (iss1 && iss2) {
			if (x1 >= 20 && y1 >= 40) {
				map.setX(x1);
				map.setY(y1);}
			else {
				cout << "Valor Invalido" << endl;
				map.setX(-1);
				map.setY(-1);}
		}
		return true;
	}

	else if (cmd[0] == "moedas") {

		cout << "moedas";
		return true;
	}

	else if (cmd[0] == "oponentes") {

		return true;
	}

	else if (cmd[0] == "castelo") {
		istringstream iss(cmd[1]);
		istringstream iss1(cmd[2]);
		istringstream iss2(cmd[3]);
		char c;
		char posx, posy;
		iss >> c;
		iss1 >> posx;
		iss2 >> posy;

		if (iss)
		{
			/*Colonia* aux = map.getPop(c);
			if (aux == nullptr) {
			cout << "Colonia nao encontrada.";
			return false;
			}*/
			Colonia* aux = new Colonia(c); //ja temos um mapa que tem colonias temos que por esta la dentro



			/*if (map->pesquisaColonia(x) != -1) {
			istringstream iss1(cmd[2]);
			istringstream iss2(cmd[3]);
			int x1, y1;
			iss1 >> x1;
			iss2 >> y1;
			if (iss1 && iss2) {
			map->mapaAlteraColonia_castelo(x, x1, y1);
			}
			}*/
			int x, y;
			x = atoi(&posx);
			y = atoi(&posy);

			aux->addCastle(x, y, "cast1");

		}
		return true;
	}

	else if (cmd[0] == "mkperfil") {

		return true;
	}

	else if (cmd[0] == "addperfil") {

		return true;
	}

	else if (cmd[0] == "subperfil") {

		return true;
	}

	else if (cmd[0] == "rmperfil") {

		return true;
	}

	else if (cmd[0] == "load") {
		file = true;
		ifstream dados(cmd[1]);
		string linha;

		if (!dados.is_open()) {
			return false;
		}

		while (!dados.eof())
		{
			getline(dados, linha);
			Comando(linha, map);
		}
		dados.close();
		return true;
	}

	else if (cmd[0] == "inicio") {
		jogoiniciado = true;
		cout << "comecar a jogar";
		Consola::printText(10, 10, "Jogo");
		Consola::printText(10, 12, "Rafael e Fábio");
		Consola::printText(10, 14, "Trabalho de POO");

		Consola::clrscr();
		system("PAUSE");

		if (map.getX() < 20 || map.getY() < 40) {
			map.setX(20);
			map.setY(40);
		}
		
		jogar();

		return false;
	}
	}
	return false;
}

string inicio()
{
	string cmd;
	while (1) {
		if (jogoiniciado) { // inicio programa
			break;
		}
		cout << "Config>>: ";
		cin.clear();
		getline(cin, cmd);
		if (cmd == "comandos") {
			cout << getComandos();
		}
		
		
	}
	return cmd;
}

int menu()
{
	int opcao = -1;

	cout << "\n 0 - Sair"
		<< "\n 1 - Configuracao"
		;
	do {
		cout << "\n opcao > ";
		string s;
		cin.clear();
		cin >> s;
		istringstream iss(s);
		iss >> opcao;
		if (!iss) opcao = -1; // se nao extaraiu um int vai tentar de novo
	} while (opcao < 0 || opcao > 4);
	return opcao;
}

string getComandos()
{
	ostringstream oss;

	oss << "dim linhas colunas\n" << "moedas numero\n" <<
		"oponentes numero\n" << "castelo colonia lin col\n" <<
		"mkperfil letra\n" << "addperfil letra caracteristica\n" <<
		"subperfil letra caracteristica\n" << "rmperfil letra\n" <<
		"load ficheiro\n" << "inicio\n" << endl;

	return oss.str();
}

string getCaracteristicas()
{
	ostringstream oss;

	oss << "Bandeira\n" << "Superior\n" <<
		"PeleDura\n" << "Armadura \n" <<
		"Faca\n" << "Espada\n" <<
		"Agresao\n" << "Ecologico\n" <<
		"HeatSeeker \n" << "BuildSeeker\n" <<
		"Walker\n" << "Remedio\n" <<
		"SecondChance \n" << endl;

	return oss.str();
}