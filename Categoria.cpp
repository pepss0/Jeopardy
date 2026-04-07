#include "Categoria.h"

Categoria::Categoria()
{
	for (int i = 0; i < MAXEL; i++)
	{
		this->punti[i] = 0;
		this->nomeCategoria[i] = "";
	}
}

Categoria::Categoria(string nome[], int punti[])
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

string Categoria::toString()
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
