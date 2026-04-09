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

// --- CLASSE CATEGORIA ---
class Categoria {
private:
	string nome;
	Domanda listaDomande[5]; // Array fisso invece del vector
	int numeroDomande;       // Contatore interno

public:
	Categoria(string n);
	void aggiungiDomanda(Domanda d);
	void selezionaCasella(int puntiSelezionati);
};
