#include "domande.h"
#include "Risposte.h"
#include <iostream>

using namespace std;

// --- Implementazione di DOMANDA ---

Risposta::Risposta() {
    risposta_fornita = "";
}

Risposta::Risposta(string r) {
    risposta_fornita = r;
}

void Risposta::leggiRispota() {
    cout << "INSERISCI RISPOTA" << endl;
    cin >> risposta_fornita;
}

bool Risposta::verificaRisposta(Domanda d)
{
    bool risposta = false;
    if (risposta_fornita == d.mostraRisposta())
    {
        cout << rispostaCorretta << endl;
        risposta = true;
    }
    return risposta;
}