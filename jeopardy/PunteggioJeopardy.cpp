#include "PunteggioJeopardy.h"
#include iostream

using namespace std;

PunteggioJeopardy::PunteggioJeopardy(string nome) {
	nomeGiocatore = nome;
	totale = 0;
	domandeRisposte = 0;
}

void PunteggioJeopardy::rispostaCorretta(int valoreDomanda) {
	totale += valoreDomanda;
	domandeRisposte++;
}

void PunteggioJeopardy::rispostaErrata(int valoreDomanda) {
	totale -= valoreDomanda;
	domandeRisposte++;
}

int PunteggioJeopardy::getTotale() const {
	return totale;
}

string PunteggioJeopardy::getNome() const {
	return nomeGiocatore;
}

string PunteggioJeopardy::toString() const {
	stringstream ss;
	ss << "[" << nomeGiocatore << "] Punti: " << totale
		<< " | Domande: " << domandeRisposte;
	return ss.str();