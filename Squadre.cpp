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

int Squadre::cerca_Squadra(string nome)
{
	int i_nome_squadra = -1;
	for (int i = 0; i < this->n_squadre; i++)
	{
		if(nome == this->nome[i])
			i_nome_squadra = i;
	}
	return i_nome_squadra;
}

bool Squadre::cambia_Punteggio_Squadra(int punteggio, string nome)
{
	bool esecuzione = false;
	int indice = cerca_Squadra(nome);
	if (indice != -1)
	{
		this->punteggio[indice] += punteggio;
		esecuzione = true;
	}
	return esecuzione;
}

bool Squadre::agg_squadra(string nome)
{
	bool esecuzione = false;
	if (this->n_squadre < MAX_SQUADRE)
	{
		this->n_squadre++;
		this->nome[n_squadre - 1] = nome;
		this->punteggio[n_squadre - 1] = 0;
		esecuzione = true;
	}
	return esecuzione;
}

void Squadre::Left_Shift(int indice)
{
	for (int i = indice; i < this->n_squadre - 1; i++)
	{
		this->nome[i] = this->nome[i + 1];
		this->punteggio[i] = this->punteggio[i + 1];
	}
	this->n_squadre--;
}

int Squadre::togli_squadra(string nome)
{
	int i_tolta = -1;
	int i_squadra = cerca_Squadra(nome);
	if (i_squadra != -1)
	{	
		Left_Shift(i_squadra);
		i_tolta = this->n_squadre;
	}
	return i_tolta;
}

string Squadre::To_String()
{
	string msg = "";
	for (int i = 0; i < this->n_squadre; i++)
	{
		msg += "N: " + to_string(i) + "\t" + this->nome[i] + "\t punti:" + to_string(this->punteggio[i]) + "\n";
	}
	return msg;
}