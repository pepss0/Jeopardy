#include <iostream>
#include <string>
#include "domande.h"
#include "GameEngine.h"

using namespace std;

int main() {
    int nSquadre;

    system("cls");
    cout << "Quante squadre giocano? (Massimo " << MAX_SQUADRE << "): ";
    cin >> nSquadre;

    if (nSquadre > MAX_SQUADRE) {
        nSquadre = MAX_SQUADRE;
    }


    GameEngine gioco;
    
    for (int i = 0; i < nSquadre; i++) {
        string nomeSquadra;
        cout << "Inserisci il nome per la Squadra " << i + 1 << ": ";
        cin >> nomeSquadra;
        gioco.aggiungi_concorrente(nomeSquadra);
    }



    string nomiCategorie[MAXEL] = { "STORIA", "LOGICA", "INFORMATICA"};
    int valoriPunti[MAXEL_PUNTI] = { 200, 400};
    //string nomiCategorie[MAXEL] = { "STORIA", "LOGICA", "INFORMATICA", "SPORT", "ARTE" };
    //int valoriPunti[MAXEL_PUNTI] = { 200, 400, 600, 800, 1000 };
    Interfaccia tabellone(nomiCategorie, valoriPunti);
    gioco.aggiorna_tabellone(tabellone);

    Domanda elenco[MAXEL][MAXEL_PUNTI];
    for (int i = 0; i < MAXEL; i++) {
        for (int j = 0; j < MAXEL_PUNTI; j++) {
            elenco[i][j] = Domanda("Domanda di " + nomiCategorie[i] + " valore " + to_string(valoriPunti[j]), nomiCategorie[i] + to_string(valoriPunti[j]));
        }
    }

    gioco.aggiorna_domande(elenco);

    //inizia la partita
    gioco.start();

    cout << gioco.get_classifica();

    Concorrente vincitore = gioco.get_vincitore();
    cout << "il vincitore e':" << endl << vincitore.To_string();
}