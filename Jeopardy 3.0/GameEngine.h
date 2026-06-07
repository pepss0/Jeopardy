#include <iostream>
using namespace std;

#include "Interfaccia.h"
#include "domande.h"
#include "Concorrente.h"


class GameEngine
{
public:

	GameEngine();
	void aggiungi_concorrente(string nome);
	void aggiorna_tabellone(Interfaccia tab);
	void aggiorna_domande(Domanda mat[MAXEL][MAXEL_PUNTI]);
	void start();
	Concorrente get_vincitore();
	string get_classifica();
	~GameEngine();

private:
	Interfaccia Tabellone;
	Concorrente Partecipanti[MAX_SQUADRE];
	Domanda Matrice_Domande[MAXEL][MAXEL_PUNTI];
	int n_partecipanti;
	int leggi_tra(int min, int max, string msg);
};