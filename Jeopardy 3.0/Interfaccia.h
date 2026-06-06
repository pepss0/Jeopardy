#pragma once
#include <string>
using namespace std;
#define MAXEL 3
#define MAXEL_PUNTI 2

class Interfaccia
{
private:
	int punti[MAXEL_PUNTI];
	string nomeCategoria[MAXEL];
public:
	Interfaccia();
	Interfaccia(string nome[], int punti[]);
	int get_punteggio_domanda(int i_punti);
	string toString();
};
