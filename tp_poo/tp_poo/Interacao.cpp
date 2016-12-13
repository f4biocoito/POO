

#include "Interacao.h"

Interacao::Interacao()
{

}

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

void Interacao::verCaracteristicas()
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
				mapa->setX(x1);
				mapa->setY(y1);
			}
			else {
				cout << "Valor Invalido" << endl;
				mapa->setX(-1);
				mapa->setY(-1);
			}

		}
		return true;
	}

	else if (cmd[0] == "moedas") {
		istringstream iss(cmd[1]);
		int x;
		iss >> x;
		if (iss) {
			if (x >= 0) {
				mapa->mapaAlteraColonia_economia(x);
				flag_moeda = true;
			}
			else {
				cout << "Valor Invalido" << endl;
			}
		}
		return true;
	}

	else if (cmd[0] == "oponentes") {
		istringstream iss(cmd[1]);
		int x;
		iss >> x;
		if (iss) {
			if (x < 1) { // defeito
				cout << "Valor invalido" << endl;
			}
			else {
				for (unsigned int i = 0; i < x + 1; i++) {
					mapa->AdicionaColonia(new Colonia);
				}
			}
			return true;
		}
	}

	else if (cmd[0] == "castelo") {
		istringstream iss(cmd[1]);
		char x;
		iss >> x;
		if (iss) {
			if (mapa->pesquisaColonia(x) != -1) {
				istringstream iss1(cmd[2]);
				istringstream iss2(cmd[3]);
				int x1, y1;
				iss1 >> x1;
				iss2 >> y1;
				if (iss1 && iss2) {
					mapa->mapaAlteraColonia_castelo(x, x1, y1);
				}
			}
		}
		return true;
	}

	else if (cmd[0] == "mkperfil") {
		istringstream iss(cmd[1]);
		char x;
		iss >> x;
		if (iss) {
			mapa->AdicionaPerfil(new Perfil(x));
		}
		return true;
	}

	else if (cmd[0] == "addperfil") {
		istringstream iss(cmd[1]);
		char x;
		iss >> x;
		if (iss) {
			istringstream iss1(cmd[2]);
			int y;
			iss1 >> y;
			if (iss1) {
				mapa->mapaAltera_perfil(x, y);
			}

		}

		return true;
	}

	else if (cmd[0] == "subperfil") {

		return true;
	}

	else if (cmd[0] == "rmperfil") {

		return true;
	}

	else if (cmd[0] == "load") {
		bool checkf = false;
		if (Lerficheiro(cmd[1]))
			checkf = true;
		if (!checkf)
			cout << "Leitura nao Efectuada!!" << endl;
		return true;
	}

	else if (cmd[0] == "inicio") {
		flag = 1;

		if (mapa->Ver_size_colonias()<2) {
			for (unsigned int i = 0; i < 2; i++) {
				mapa->AdicionaColonia(new Colonia);
			}
		}

		if (!flag_moeda) {
			mapa->mapaAlteraColonia_economia(25); // defeito
		}

		if (mapa->getX() < 20 || mapa->getY() < 40) {
			mapa->setX(20);
			mapa->setY(40);
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