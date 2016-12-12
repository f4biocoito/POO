
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