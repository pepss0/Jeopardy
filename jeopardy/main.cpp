#include <iostream>
#include <string>
#include "domande.h"
#include "Interfaccia.h"
#include "Squadre.h"
#include "Risposte.h"

using namespace std;

const int MAX_SQUADRE = 10;

int main() {
    int nSquadre;

    system("cls");
    cout << "Quante squadre giocano? (Massimo " << MAX_SQUADRE << "): ";
    cin >> nSquadre;

    if (nSquadre > MAX_SQUADRE) {
        nSquadre = MAX_SQUADRE;
    }

    Squadre partecipanti[MAX_SQUADRE];

    for (int i = 0; i < nSquadre; i++) {
        string nomeSquadra;
        cout << "Inserisci il nome per la Squadra " << i + 1 << ": ";
        cin >> nomeSquadra;
        partecipanti[i].setNome(nomeSquadra);
    }

    string nomiCategorie[MAXEL] = { "STORIA", "LOGICA", "INFORMATICA", "SPORT", "ARTE" };
    int valoriPunti[MAXEL] = { 200, 400, 600, 800, 1000 };
    Interfaccia tabellone(nomiCategorie, valoriPunti);

    Domanda elenco[25];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            elenco[(i * 5) + j] = Domanda("Domanda di " + nomiCategorie[i] + " valore " + to_string(valoriPunti[j]));

        }
    }

    int turno = 0;
    bool inCorso = true;

    while (inCorso) {
        system("cls");
        int corrente = turno % nSquadre;

        cout << "TURNO DI: " << partecipanti[corrente].getNome() << endl;
        cout << "PUNTEGGIO ATTUALE: " << partecipanti[corrente].getPunteggio() << endl << endl;

        cout << tabellone.toString() << endl;

        int sceltaI, sceltaJ;
        cout << "\nScegli Categoria (0-4) o -1 per uscire: ";
        cin >> sceltaI;

        if (sceltaI == -1) {
            inCorso = false;
        }
        else if (sceltaI >= 0 && sceltaI < 5) {
            cout << "Scegli Difficolta' (0-4): ";
            cin >> sceltaJ;

            if (sceltaJ >= 0 && sceltaJ < 5) {
                system("cls");

                int posizione = (sceltaI * 5) + sceltaJ;

                cout << elenco[posizione].mostraDomanda() << endl;

                Risposta risp;
                risp.leggiRispota();

                risp.verificaRisposta(elenco[posizione], partecipanti[corrente]);

                elenco[posizione].mostraRisposta();

                turno++;
            }
        }
    }

    system("cls");
    cout << "--- CLASSIFICA FINALE ---" << endl;
    for (int i = 0; i < nSquadre; i++) {
        cout << partecipanti[i].getNome() << ": " << partecipanti[i].getPunteggio() << " punti" << endl;
    }

    return 0;
}
