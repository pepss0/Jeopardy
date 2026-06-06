#include "Interfaccia.h"

Interfaccia::Interfaccia()
{
	for (int i = 0; i < MAXEL; i++)
	{
		this->nomeCategoria[i] = "";
	}
	for (int i = 0; i < MAXEL_PUNTI; i++)
	{
		this->punti[i] = 0;
	}
}

Interfaccia::Interfaccia(string nome[], int punti[])
{
	for (int i = 0; i < MAXEL; i++)
	{
		this->nomeCategoria[i] = nome[i];
	}
	for (int i = 0; i < MAXEL_PUNTI; i++)
	{
		this->punti[i] = punti[i];
	}
}

int Interfaccia::get_punteggio_domanda(int i_punti)
{
	return this->punti[i_punti];
}

string Interfaccia::toString()
{
	string s = "";
	for (int i = 0; i < MAXEL; i++)
	{
		s += "\t" + nomeCategoria[i] + "\t";
	}
	for (int i = 0; i < MAXEL_PUNTI; i++)
	{
		s += "\n";
		s += "\n";
		s += "\n";

		for (int j = 0; j < MAXEL; j++)
		{
			s += "    \t" + to_string(punti[i]) + "\t" + "\t";
		}
	}
	return s;
}
