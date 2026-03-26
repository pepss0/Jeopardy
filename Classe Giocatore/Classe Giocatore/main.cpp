#include <iostream>
#include "Giocatore.h"

using namespace std;

const int MAXEL = 5;

void main() {

	int punti = 0;
	string nome = "";
	int numeroDiGiocatori = 0;

	cout << "quanti giocatori giocano?" << endl;
	cin >> numeroDiGiocatori;
	
	Giocatore giocatori[MAXEL];

	for (int i = 0; i < numeroDiGiocatori; i++)
	{
		cout << "Inserisci il tuo nome: " << endl;
		cin >> nome;

		giocatori[i] = Giocatore(nome, punti);

	}
		
	system("cls");

	for (int i = 0; i < 25; i++)
	{
		cout << endl;
	}

	for (int i = 0; i < numeroDiGiocatori; i++)
	{
		cout << giocatori[i].toString();
	}
}