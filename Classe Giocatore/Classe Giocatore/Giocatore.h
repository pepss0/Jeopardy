#pragma once
#include <string>
using namespace std;

class Giocatore
{
private:

	int punteggio;
	string nome;

public:
	Giocatore();
	Giocatore(string nome, int punteggio);
	string toString();
};