#include <iostream>
#include "Giocatore.h"
using namespace std;
int main() {
    const int MAX_GIOCATORI = 4;
    Giocatore squadra[MAX_GIOCATORI] = {
        Giocatore("Mario"),
        Giocatore("Luigi"),
        Giocatore("Peach")
    };

    squadra[0].aggiungiPunti(10);
    squadra[1].aggiungiPunti(25);

    cout << "--- CLASSIFICA ---" << endl;
    for (int i = 0; i < MAX_GIOCATORI; i++) {
        cout << squadra[i].toString() << endl;
    }

    return 0;
}
