#include <string>
#include <iostream>



using namespace std;

#include "Load.h"



int scrollX = 0, scrollY = 0;



int main() {
	Mapa map;
	string a;
	Consola::setTextSize(15, 15);
	Consola::setScreenSize(31, 60);

	Consola::setTextColor(Consola::PRETO);
	Consola::setBackgroundColor(Consola::BRANCO);
	Consola::clrscr();


	menu();
	
	while (!sair) 
	{	
		
		if(!jogoIniciado)
		{
			Consola::clrscr();
			leComandosMenu(a, map);
			system("PAUSE");
		}
		else if(jogoIniciado)
		{

			Consola::clrscr();
			desenhaTab();
			leComandosJogo(a, map);
			system("PAUSE");
		}
		else if(jogoTerminado){}

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


void jogar(){}


bool leComandosMenu(string comando,  Mapa map)
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
			break;
		}
		
		map.setX(maxX);
		map.setY(maxY);
				
		return true;
	}

	else if (ident_comando == "moedas") {
		iss >> primeiro_parametro;
		int coins=stoi(primeiro_parametro);
		for (auto pop = map.populacoes.begin(); pop != map.populacoes.end(); ++pop)
		{
			(*pop)->setMoedas(coins);
		}
		cout << "moedas";
		return true;
	}

	else if (ident_comando == "oponentes") {

		return true;
	}

	else if (ident_comando == "comandos") {
		
		Consola::setTextColor(Consola::AZUL);
		Consola::gotoxy(5, 0);
				
		Consola::setTextColor(Consola::PRETO);
		cout << getComandos();
	}


	else if (ident_comando == "castelo") {
		iss >> primeiro_parametro; //faccao
		iss >> segundo_parametro; //x
		iss >> terceiro_parametro; //y 

		const char *c=primeiro_parametro.c_str();

		
		
			Colonia* aux = new Colonia(c[0]); //ja temos um mapa que tem colonias temos que por esta la dentro


			int x, y;
			x = stoi(segundo_parametro);
			y = stoi(terceiro_parametro);

			aux->addCastle(x, y, "cast1");

		
		return true;
	}

	else if (ident_comando == "mkperfil") {

		return true;
	}

	else if (ident_comando == "addperfil") {

		return true;
	}

	else if (ident_comando == "subperfil") {

		return true;
	}

	else if (ident_comando == "rmperfil") {

		return true;
	}

	else if (ident_comando == "load") {
		file = true;
		iss>>primeiro_parametro;
		ifstream dados(primeiro_parametro);
		string linha;

		if (!dados.is_open()) {
			return false;
		}

		while (!dados.eof())
		{
			getline(dados, linha);
			leComandosMenu(linha, map);
		}
		dados.close();
		return true;
	}

	else if (ident_comando == "inicio") {
		jogoIniciado = true;
		cout << "Vamos dar inicio ao jogo.";
		Consola::printText(10, 10, "Guerra dos Clas");
		Consola::printText(10, 12, "Rafael Falcao e Fabio Coito");
		Consola::printText(10, 14, "Trabalho de POO");

		
		system("PAUSE");
		Consola::clrscr();
	

		return true;
	}
	}
	return false;
} 


bool leComandosJogo(string comando, Mapa map)
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