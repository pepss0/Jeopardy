#include "Giocatore.h"

Giocatore::Giocatore()
{
	this->punteggio = 0;
}

Giocatore::Giocatore(string nome, int punteggio)
{
	this->nome = nome;
	this->punteggio = punteggio;
}

string Giocatore::toString()
{
	string s;
	
	s += "\t" + nome + " ha " + to_string(punteggio) + " punti " + "\t";
	return s;
}