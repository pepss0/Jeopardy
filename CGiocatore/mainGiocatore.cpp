#include <iostream>
#include "Giocatore.h"
using namespace std;

const int MAXGIOCATORI = 4;

void main() {
    Giocatore squadra[MAXGIOCATORI] = {
        Giocatore("Mario"),
        Giocatore("Luigi"),
        Giocatore("Peach")
    };

    squadra[0].aggiungiPunti(10);
    squadra[1].aggiungiPunti(25);

    cout << "--- CLASSIFICA ---" << endl;
    for (int i = 0; i < MAXGIOCATORI; i++) {
        cout << squadra[i].toString() << endl;
    }
}