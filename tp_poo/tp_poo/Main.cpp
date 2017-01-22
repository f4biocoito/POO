
#include "Load.h"

using namespace std;

int scrollX = 0, scrollY = 0;
char car;

int main() {

	Consola::setTextSize(15, 15);
	Consola::setScreenSize(31, 60);

	Consola::setTextColor(Consola::PRETO);
	Consola::setBackgroundColor(Consola::BRANCO);
	Consola::clrscr();

	Colonia* jogador = new Colonia('a'); //cria colonia do jogador - obrigatoria
	map.populacoes.push_back(jogador);

	oponentes = 0;
	int j;
	do {
		j = menu();
		if (j == 1) {

			while (1) {

				if (!jogoIniciado)
				{
					Consola::clrscr();
					leComandosMenu();
					system("PAUSE > NULL");
				}
				else if (jogoIniciado)
				{

					Consola::clrscr();
					desenhaTab();
					map.BuildingsInGrid(scrollX + 8, scrollX, scrollY + 8, scrollY);
					map.UnitsInGrid(scrollX + 8, scrollX, scrollY + 8, scrollY);

					
					car =Consola::getch();

					if (car == Consola::ESCAPE) break;
					if ((car != Consola::ESQUERDA) && (car != Consola::DIREITA) && (car != Consola::CIMA) && (car != Consola::BAIXO)) {
						if (car == Consola::ENTER) continue; //equivale ao comando NEXT
						else {
							leComandosJogo();
							//jogadaPC(jogadasPC);
							//jogadasPC++;
							continue;
						}
					}
				
					
					scroll(car); //actualiza scroll
					system("PAUSE > NULL");
				}


				else if (jogoTerminado) {
					break;
				}

			}

		}
	} while (j != 0);
	return 0;
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

void desenhaTab()
{
	for (int i = scrollX; i < scrollX + LINHAMAX; i++)
	{
		for (int j = scrollY; j < scrollY + COLUNAMAX; j++)
		{
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))
				Consola::quadricula(i - scrollX, j - scrollY);
		}
	}
}

bool leComandosMenu()
{
	string frase, ident_comando, primeiro_parametro, segundo_parametro, terceiro_parametro, quarto_parametro;
	istringstream iss;
	ostringstream oss;
	Consola::gotoxy(0, 1);
	cout << "Comando: ";

	fflush(stdin);
	fflush(stdout);

	getline(cin, frase);

	iss.str(frase);
	while (!iss.eof())
	{
		iss >> ident_comando;

		if (ident_comando == "dim")
		{
			maxX = 40;
			maxY = 40;
			iss >> primeiro_parametro;
			if (primeiro_parametro != "")
				maxX = stoi(primeiro_parametro);

			iss >> segundo_parametro;
			if (segundo_parametro != "")
				maxY = stoi(segundo_parametro);

			if ((maxX<30 || maxX>500) || (maxY<30 || maxY>500))
			{
				Consola::gotoxy(0, 31);
				cout << "Insira valores validos. (30 a 500)\n";
				return false;
			}
		
			map.setX(maxX);
			map.setY(maxY);

			cout << "Dimensao atualizada." << endl;
				
			return true;
		}

		else if (ident_comando == "moedas") {
			iss >> primeiro_parametro;
			int coins=stoi(primeiro_parametro);
			for (auto pop = map.populacoes.begin(); pop != map.populacoes.end(); ++pop)
			{
				(*pop)->setMoedas(coins);
			}
			cout << "Definidas as moedas para o jogo. ";
			return true;
		}

		else if (ident_comando == "oponentes") {
			iss >> primeiro_parametro;
			oponentes = stoi(primeiro_parametro);
			if (oponentes > 0 && oponentes < 5) {
				int bb = 98;//ascii para b
				char cc;
				int x, y;

				for (int i = 0; i < oponentes; i++) {
					string nom = "cast";
					cc = static_cast<char>(bb++);
					x = rand() % 40; //é preciso verificar se ja existe algum nessa posicao
					y = rand() % 40;
					ostringstream oos;
					oos.clear();
					oos << (i + 2);
					nom += oos.str();
					cout << cc << " " << nom << endl;
					Colonia* jogador = new Colonia(cc); //cria colonia dos oponentes
					jogador->addCastle(x, y, nom); //adicionar um castelo para o jogador
					map.populacoes.push_back(jogador);
				}
				cout << "Criados os oponentes." << endl;
				return true;
			}
			else
				oponentes = 0;
			return false;
		}

		else if (ident_comando == "comandos") {
		
			//Consola::setTextColor(Consola::AZUL);
			Consola::gotoxy(0, 1);
			//Consola::setTextColor(Consola::PRETO);
			cout << getComandos();
			return true;
		}

		else if (ident_comando == "castelo") {
			iss >> primeiro_parametro; //faccao
			iss >> segundo_parametro; //x
			iss >> terceiro_parametro; //y 

			const char *c=primeiro_parametro.c_str();
			//Colonia* aux = map.getPop(*(c)); 

			//int x, y;
			//x = stoi(segundo_parametro);
			//y = stoi(terceiro_parametro);

			//aux->addCastle(x, y, "cast1");
			//map.populacoes.push_back(aux); 

			if (map.getPop(*(c))->getcastExiste() == false) {
				int x, y;
				x = stoi(segundo_parametro);
				y = stoi(terceiro_parametro);
				map.getPop(*(c))->addCastle(x, y, "cast1");
				cout << "Criado o castelo." << endl;
				return true;
			}
			
			return false;
		}

		else if (ident_comando == "mkperfil") {
			cout << "nao implementado" << endl;
			return true;
		}

		else if (ident_comando == "addperfil") {
			cout << "nao implementado" << endl;
			return true;
		}

		else if (ident_comando == "subperfil") {
			cout << "nao implementado" << endl;
			return true;
		}

		else if (ident_comando == "rmperfil") {
			cout << "nao implementado" << endl;
			return true;
		}

		else if (ident_comando == "load") {
			file = true;
			iss>>primeiro_parametro;
			cout << "primeiro";
			ifstream dados(primeiro_parametro);
			string linha;

			if (!dados.is_open()) {
				return false;
			}

			while (!dados.eof())
			{
				getline(dados, linha);
				leComandosMenu();
			}
			dados.close();
			return true;
		}

		else if (ident_comando == "inicio") {
			
			if (oponentes == 0) {
				cout << "Precisas de oponentes para jogar" << endl;
				return false;
			}
			else {
				int bb = 97;//ascii para a
				char cc;
				for (int i = 0; i < oponentes; i++) {
					cc = static_cast<char>(bb++);
					if (map.getPop(cc)->getcastExiste() == false) { //ver se existe castelo
						string nom = "cast";
						int x, y;
						x = rand() % 40; //é preciso verificar se ja existe algum nessa posicao
						y = rand() % 40;
						ostringstream oos;
						oos.clear();
						oos << (i + 1);
						nom += oos.str();
						cout << cc << " " << nom << endl;
						map.getPop(cc)->addCastle(x, y, nom);

					}
				}
				jogoIniciado = true;
				cout << "Vamos dar inicio ao jogo.";
				Consola::printText(10, 10, "Guerra dos Clas");
				Consola::printText(10, 12, "Rafael Falcao e Fabio Coito");
				Consola::printText(10, 14, "Trabalho de POO");

				system("PAUSE > NULL");
				Consola::clrscr();
				return true;
			}
			return false;
		}
	}
	return false;
} 

bool leComandosJogo()
{
	string frase, ident_comando, primeiro_parametro, segundo_parametro, terceiro_parametro, quarto_parametro;
	istringstream iss;
	ostringstream oss;
	Consola::gotoxy(0, 30);
	cout << "Comando de jogo: ";

	fflush(stdin);
	fflush(stdout);

	getline(cin, frase);

	iss.str(frase);
	while (!iss.eof())
	{
		iss >> ident_comando;



		if (ident_comando == "foco")
		{
			iss >> primeiro_parametro;
			if (primeiro_parametro != "")
				xini = stoi(primeiro_parametro);
			else
				return false;
			iss >> segundo_parametro;
			if (segundo_parametro != "")
				yini = stoi(segundo_parametro);
			else
				return false;
			if ((xini<0 || xini>maxX) || (yini<0 || yini>maxY))
			{
				Consola::gotoxy(0, 31);
				cout << "Insira valores validos.\n";
				break;
			}
			map.setFocoX(xini);
			map.setFocoY(yini);
			return true;
		}

		//setmoedas colonia num

		if (ident_comando == "build") 
		{
			iss >> primeiro_parametro; //nome edificio
			iss >> segundo_parametro; //linha
			iss >> terceiro_parametro; //coluna 
		
			const char *c = "a";
			Colonia* aux = map.getPop(*(c));
			int x, y;
			x = stoi(segundo_parametro);
			y = stoi(terceiro_parametro);
			if (primeiro_parametro == "torre") 
			{
				aux->addTower(x, y, primeiro_parametro);
				int moedas = aux->getMoedas();
				aux->setMoedas(moedas - 30);
			}
			if (primeiro_parametro == "quinta") 
			{
				aux->addFarm(x, y, primeiro_parametro);
				int moedas = aux->getMoedas();
				aux->setMoedas(moedas - 20);
			}
			
			map.populacoes.push_back(aux);
			return true;
		}

		if (ident_comando == "list")
		{
			iss >> primeiro_parametro; //qual colonia 
	
			const char (*c) = primeiro_parametro.c_str();
			for (auto pop = map.populacoes.begin(); pop != map.populacoes.end(); ++pop)
			{
				if ( (*c) == (*pop)->getId() )
				{
					
					Consola::clrscr();
					
					Consola::setTextColor(Consola::AZUL);
					Consola::gotoxy(0, 0);
					cout << "Estado do Jogo:";
					Consola::gotoxy(0, 3);
					Consola::setTextColor(Consola::PRETO);
					cout<< "Moedas: " << (*pop)->getMoedas();
					cout<< "\nNumero de Edificios: " << (*pop)->getNumBuildings();
					cout << "\nNumero de Unidades : " << (*pop)->getNumUnits();
					
					(*pop)->printBuildingList();
					int altura=(*pop)->getNumBuildings();
					(*pop)->printUnitList( altura +6);
					system("PAUSE > NULL");
					Consola::clrscr();
				}
			}
		}

		if (ident_comando == "listp") {

			return true;
		}

		if (ident_comando == "listallp") {

			return true;
		}

		if (ident_comando == "mkbuild") {

			return true;
		}

		if (ident_comando == "repair") {

			return true;
		}

		if (ident_comando == "upgrade") {

			return true;
		}

		if (ident_comando == "sell") {

			return true;
		}

		if (ident_comando == "ser") {

			return true;
		}

		if (ident_comando == "next") {

			return true;
		}

		//nextn num

		if (ident_comando == "ataca") {

			return true;
		}

		if (ident_comando == "recolhe") {

			return true;
		}

		//save nome
		//restore nome
		//erase nome
		//load ficheiro

		if (ident_comando == "sair") {
			jogoIniciado=false;
			jogoTerminado=true;
			return true;
		}
		
	}
	return false;
}

int menu()
{
	int opcao = -1;

	cout << "\n0 - Sair"
		 << "\n1 - Nova configuracao"
	;
	do {
		cout << "\n opcao > ";
		string s;
		cin.clear();
		cin >> s;
		istringstream iss(s);
		iss >> opcao;
		if (!iss) opcao = -1; 
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

