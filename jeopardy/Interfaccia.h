#pragma once
#include <string>
using namespace std;
#define MAXEL 5

class Interfaccia
{
private:
	int punti[MAXEL];
	string nomeCategoria[MAXEL];
public:
	Interfaccia();
	Interfaccia(string nome[], int punti[]);

	string toString();
};
