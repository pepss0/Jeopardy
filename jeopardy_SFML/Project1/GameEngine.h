#pragma once

#include "InterfacciaUtente.h"
#include <string>

using namespace std;

// ============================================================
//  GameEngine
//
//  Classe che gestisce il test del blackjack.
//  Per ora non usa ancora le classi Carta, Mazzo, Mano.
//  Simula solo il ciclo "dammi carta?".
// ============================================================

class GameEngine {
public:
    GameEngine(InterfacciaUtente& ui, wstring nomeGiocatore);

    void run();
	int getNumeroDomande();

private:
    InterfacciaUtente& ui;
    wstring nomeGiocatore;
    int numeroDomande;
    wstring testoCategorie[5];
    wstring risposteCat1Val100[4];

    void aggiungiSfondo();
    void disegnaCampoEDomanda(wstring domanda);
	void mostraDomandaConRisposte(wstring domanda, wstring risposte[], int numEl);
};
