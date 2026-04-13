#include "domande.h"
#include "Risposte.h"
#include <iostream>

using namespace std;

// --- Implementazione di RISPOSTA ---

Risposta::Risposta() {
    risposta_fornita = "";
}

Risposta::Risposta(string r) {
    risposta_fornita = r;
}

void Risposta::leggiRispota() {
    cout << "INSERISCI RISPOSTA" << endl;
    cin >> risposta_fornita;
}

void Risposta::verificaRisposta(Domanda d, Squadre s)
{
    if (risposta_fornita == d.mostraRisposta())//secondo il principio Tell Don't Ask questo andrebbe fatto nella classe Domanda
    {
        cout << "risposta Corretta!!!" << endl;
        s.modificaPunteggio(d.getPunteggio(), true);
    }
    else
    {
        cout << "risposta Sbagliata!!!" << endl;
        s.modificaPunteggio(d.getPunteggio(), false);
    }
}