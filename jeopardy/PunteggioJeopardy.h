pragma once
#include string

using namespace std;

class PunteggioJeopardy {
private:
	string nomeGiocatore;
	int totale;
	int domandeRisposte;

public:
	PunteggioJeopardy(string nome);

	void rispostaCorretta(int valoreDomanda);
	void rispostaErrata(int valoreDomanda);

	int getTotale() const;
	string getNome() const;

	string toString() const;
};