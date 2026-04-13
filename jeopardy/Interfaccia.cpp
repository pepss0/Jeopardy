#include "Interfaccia.h"

Interfaccia::Interfaccia()
{
	for (int i = 0; i < MAXEL; i++)
	{
		this->punti[i] = 0;
		this->nomeCategoria[i] = "";
	}
}

Interfaccia::Interfaccia(string nome[], int punti[])
{
	for (int i = 0; i < MAXEL; i++)
	{
		this->nomeCategoria[i] = nome[i];

	}
	for (int i = 0; i < MAXEL; i++)
	{
		this->punti[i] = punti[i];
	}
}

string Interfaccia::toString()
{
	string s = "";
	for (int i = 0; i < MAXEL; i++)
	{
		s += "\t" + nomeCategoria[i] + "\t";
	}
	for (int i = 0; i < MAXEL; i++)
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
