

#include "Interacao.h"



int Interacao::menu() 
{
	int opcao = -1;

	cout << "\n 0 - Sair"
		<< "\n 1 - Acrescentar pessoas lidas de ficheiro de texto"
		<< "\n 2 - Acrescentar pessoa lida do teclado"
		<< "\n 3 - Listar"
		<< "\n 4 - Gravar em ficheiro de texto";
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
			break;
		}
		}
	}
}

string Interacao::verCaracteristicas()
{
	ostringstream oss;
	
	oss << "Bandeira	Superior	PeleDura	Armadura \n"<<
		"Faca	Espada	Agresao	Ecologico	HeatSeeker \n"<<
		"BuildSeeker	Walker	Remedio	SecondChance \n"<< endl;

	return oss.str();
}

void Interacao::inicio() {
	string cmd;
	while (1) {
		cout << getComandos();
		if (flag = 1) { // inicio programa
			break;
		}

		cout << "[COMANDO]: ";
		//cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		getline(cin, cmd);
		if (cmd == "comando") {
			cout << getComandos();
		}
		else if (!VerificaComando(cmd)) {
			cout << "!!!Comando invalido!!!\n" << endl;
		}

	}

}

bool Interacao::VerificaComando(string comando) {
	string cmd[5];
	istringstream iss(comando);
	int i = 0;
	for (auto it = istream_iterator<string>(iss); it != istream_iterator<string>() && i < 5; ++it, ++i)
		cmd[i] = *it;


	if (cmd[0] == "dim") {
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
		
		return true;
	}

	else if (cmd[0] == "oponentes") {
		
			return true;
		
	}

	else if (cmd[0] == "castelo") {
		istringstream iss(cmd[1]);
		char x;
		iss >> x;
		if (iss) {
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
		flag = 1;

		//if (map->Ver_size_colonias()<2) {
			//for (unsigned int i = 0; i < 2; i++) {
	//			map->AdicionaColonia(new Colonia);
		//	}
		//}

		if (!flag_moeda) {
	//		map->mapaAlteraColonia_economia(25); // defeito
		}

		if (map->getX() < 20 || map->getY() < 40) {
			map->setX(20);
			map->setY(40);
		}


		return true;
	}

	return false;
}


string Interacao::getComandos() {
	ostringstream oss;

	oss << "dim linhas colunas\n" << "moedas numero\n" <<
		"oponentes numero\n" << "castelo colonia lin col\n" <<
		"mkperfil letra\n" << "addperfil letra caracteristica\n" <<
		"subperfil letra caracteristica\n" << "rmperfil letra\n" <<
		"load ficheiro\n" << "inico\n" << endl;

	return oss.str();

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
		VerificaComando(linha);
	}
	dados.close();
	return true;
}