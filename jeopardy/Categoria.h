#pragma once
#include <string>
using namespace std;
#define MAXEL 5

class Categoria
{
private:
	int punti[MAXEL];
	string nomeCategoria[MAXEL];
public:
	Categoria();
	Categoria(string nome[], int punti[]);

	string toString();
};