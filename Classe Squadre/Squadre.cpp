#include "Squadre.h"
#include <string>

Squadre::Squadre()
{
	this->n_squadre = 0;
	this->punteggio[0] = 0;
	this->nome[0] = "";
}

Squadre::~Squadre()
{

}

int Squadre::conta_N_Squadre()
{
	return this->n_squadre;
}

int Squadre::agg_Punteggio_Squadra(int punteggio, int indice)
{
	if (indice < this->n_squadre)
	{
		this->punteggio[indice] += punteggio;
		return 1;
	}
	else
		return -1;
}

int Squadre::togli_Punteggio_Squadra(int punteggio, int indice)
{
	if (indice < this->n_squadre)
	{
		this->punteggio[indice] -= punteggio;
		return 1;
	}
	else
		return -1;
}

int Squadre::agg_squadra(string nome)
{
	if (this->n_squadre < MAX_SQUADRE)
	{
		this->n_squadre++;
		this->nome[n_squadre - 1] = nome;
		this->punteggio[n_squadre - 1] = 0;
		return this->n_squadre - 1;
	}
	else
		return -1;	
}

void Left_Shift(string nome[], int punteggio[], int indice, int n_squadre)
{
	for (int i = indice; i < n_squadre - 1; i++)
	{
		nome[i] = nome[i + 1];
		punteggio[i] = punteggio[i + 1];
	}
	n_squadre--;
}

int Squadre::togli_squadra(int N_squadra)
{
	if (N_squadra < this->n_squadre)
	{	
		Left_Shift(this->nome, this->punteggio, N_squadra, this->n_squadre);
		this->n_squadre--;
		return this->n_squadre;
	}
	else
		return -1;
}

string Squadre::To_String(int N_squadra)
{
	if (N_squadra >= this->n_squadre)
	{
		return "errore";
	}
	string msg = "N: "+to_string(N_squadra) +"\t"+ this->nome[N_squadra] +"\t punti:"+ to_string(this->punteggio[N_squadra]);
	return msg;
}