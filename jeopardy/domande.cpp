#include "domande.h"
#include <iostream>

using namespace std;

// --- Implementazione di DOMANDA ---

Domanda::Domanda() {
    punteggio = 0;
    giaScelta = true; // Una domanda "vuota" non deve essere giocabile
    testo="";
    rispostaCorretta="";
}

Domanda::Domanda(string t, string r, int p) {
    testo = t;
    rispostaCorretta = r;
    punteggio = p;
    giaScelta = false;
}

void Domanda::mostraDomanda() {
    if (giaScelta) {
        cout << "[X] Casella gia' giocata o vuota!" << endl;
    }
    else {
        cout << "--- DOMANDA DA " << punteggio << " PUNTI ---" << endl;
        cout << testo << endl;
        giaScelta = true;
    }
}

void Domanda::mostraRisposta()
{
    cout << "--- RISPOSTA DA " << punteggio << " PUNTI ---" << endl;
    cout << rispostaCorretta << endl;
}

int Domanda::getPunteggio() {
    return punteggio;
}

