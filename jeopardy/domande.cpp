#include "domande.h"
#include <iostream>

using namespace std;

// --- Implementazione di DOMANDA ---

Domanda::Domanda() {
    punteggio = 0;
    giaScelta = true; // Una domanda "vuota" non deve essere giocabile
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

int Domanda::getPunteggio() {
    return punteggio;
}

// --- Implementazione di CATEGORIA ---

Categoria::Categoria(string n) {
    nome = n;
    numeroDomande = 0; // Iniziamo da zero domande caricate
}

void Categoria::aggiungiDomanda(Domanda d) {
    if (numeroDomande < 5) {
        listaDomande[numeroDomande] = d;
        numeroDomande++;
    }
    else {
        cout << "Errore: Categoria piena!" << endl;
    }
}

void Categoria::selezionaCasella(int puntiSelezionati) {
    for (int i = 0; i < numeroDomande; i++) {
        if (listaDomande[i].getPunteggio() == puntiSelezionati) {
            listaDomande[i].mostraDomanda();
            
        }
    }

}