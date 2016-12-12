
#include "LerFicheiro.h"


bool lerFicheiroDeTexto(string nomeFicheiro) 
{
	ifstream dados(nomeFicheiro);
	string linha;

	if (!dados.is_open()) {
		return false;
	}

	// ler dados de todas as pessoas
	// uma por linha

	while (!dados.eof()) {
		// ler string com os dados
		getline(dados, linha);
		// a funcao interpretaLinha chama-se para uma linha da dados
		// lida do teclado ou do ficheiro de texto
		interpretaLinha(linha);
	}
	dados.close();
	return true;
}

void interpretaLinha(string linha) 
{
	istringstream iss(linha);
	string comandos;

	iss >> comandos;

	// se correu bem a leitura ...
	if (iss) {
		interpretaComandos(comandos);
	}
}

void interpretaComandos(string comandos)
{

}

bool executaComando(string comandop, int narg, char* varg[])
{
	//comandop(int nargc, char* varg[]);
}

void alertaComandoInes(string comando)
{
	Consola::setTextColor(Consola::AMARELO);
	Consola::gotoxy(1, 10);
	cout << "!!O comando" << comando << "nao existe!!" << endl;
}