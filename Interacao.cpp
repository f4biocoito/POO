
#include "Interacao.h"

Interacao::Interacao() {
	
}

void Interacao::setJogoIniciado(bool b)
{
	jogoIniciado = b;
}

void Interacao::jogar() {
	 
	{
		c->printText(10, 10, "Jogo");
		c->printText(10, 12, "Rafael e F�bio");
		c->printText(10, 14, "Trabalho de POO");

		c->clrscr();
		system("PAUSE");

		


	}


}

int Interacao::menu() 
{
	int opcao = -1;

	cout << "\n 0 - Sair"
		<< "\n 1 - Configuracao"
		;
	do {
		cout << "\n opcao > ";
		string s;
		cin >> s;
		istringstream iss(s);
		iss >> opcao;
		if (!iss) opcao = -1; // se nao extaraiu um int vai tentar de novo
	} while (opcao < 0 || opcao > 4);
	return opcao;
}

void Interacao::corre()
{
	int opcao = -1;
	while (opcao != 0) {
		opcao = menu();
		switch (opcao) {
		case 0: cout << "\nSair\n";
			break;
		case 1:
		{
			
			cout << "iniciar" << endl;
			inicio();
			break;
		}
		}
	}
}



void Interacao::inicio() 
{
	string cmd;
	while (!getJogoIniciado() ) {
		if (iniciar) { // inicio programa
			break;
		}
		cout << "Config>>: ";
		cin.clear();
		getline(cin, cmd);
		if (cmd == "comandos") {
			cout << getComandos();
		}
		else if (!VerificaComandoIniciais(cmd)) {
			cout << "!!!Comando invalido!!!\n" << endl;
		}
	}
}

bool Interacao::VerificaComandoIniciais(string comando) 
{
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
				map.setY(y1);
				
			}
			else {
				cout << "Valor Invalido" << endl;
				map.setX(-1);
				map.setY(-1);
			}

		}
		return true;
	}

	else if (cmd[0] == "moedas") {
		
		Consola::gotoxy(20, 20);
		cout << cmd[0];
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
			Colonia* aux = new Colonia(c);



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
		if (!Lerficheiro(cmd[1]))
			cout << "Leitura nao Efectuada!!" << endl;
		return true;
	}

	else if (cmd[0] == "inicio") {
		iniciar = true;
		
		//if (map->Ver_size_colonias()<2) {
			//for (unsigned int i = 0; i < 2; i++) {
	//			map->AdicionaColonia(new Colonia);
		//	}
		//}

		//if (!flag_moeda) {
	//		map->mapaAlteraColonia_economia(25); // defeito
		//}
		

		if (map.getX() < 20 || map.getY() < 40) {
			map.setX(20);
			map.setY(40);
		}
		setJogoIniciado(true);
		jogar();

		return false;
	}
	return false;
}



bool Interacao::Lerficheiro(string nome)
{
	ifstream dados(nome);
	string linha;

	if (!dados.is_open()) {
		return false;
	}

	while (!dados.eof())
	{
		getline(dados, linha);
		VerificaComandoIniciais(linha);
	}
	dados.close();
	return true;
}

string Interacao::getComandos() 
{
	ostringstream oss;
	 
	oss << "dim linhas colunas\n" << "moedas numero\n" <<
		"oponentes numero\n" << "castelo colonia lin col\n" <<
		"mkperfil letra\n" << "addperfil letra caracteristica\n" <<
		"subperfil letra caracteristica\n" << "rmperfil letra\n" <<
		"load ficheiro\n" << "inicio\n" << endl;

	return oss.str();
}

string Interacao::getCaracteristicas()
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