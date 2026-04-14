#include <iostream>
#include <string>
#include "domande.h"
#include "Interfaccia.h"
#include "Squadre.h"
#include "Risposte.h"

using namespace std;

int main() {
    // 1. Setup Giocatore
    Squadre giocatore;
    string nomePlayer;
    cout << "Inserisci il nome della Squadra: ";
    cin >> nomePlayer;
    giocatore.setNome(nomePlayer);

    // 2. Setup Interfaccia (I titoli delle colonne e i valori)
    string categorie[MAXEL] = { "STORIA", "LOGICA", "C++", "SPORT", "ARTE" };
    int valori[MAXEL] = { 200, 400, 600, 800, 1000 };
    Interfaccia tabellone(categorie, valori);

    // 3. Setup Domande (Usiamo un array semplice invece della matrice)
    // In questo esempio ne creiamo 5 (una per categoria) per semplicità
    Domanda listaDomande[MAXEL];
    listaDomande[0] = Domanda("Chi fondo' Roma?", "Romolo", 200);
    listaDomande[1] = Domanda("Qual e' il contrario di Vero?", "Falso", 400);
    listaDomande[2] = Domanda("Cosa significa OOP?", "Object Oriented Programming", 600);
    listaDomande[3] = Domanda("Quanti giocatori ha una squadra di calcio?", "11", 800);
    listaDomande[4] = Domanda("Chi dipinse la Gioconda?", "Leonardo", 1000);

    cout << "\n--- INIZIO GIOCO ---" << endl;

    for (int i = 0; i < MAXEL; i++) {
        // Visualizza Tabellone e Punteggio
        cout << "\n" << tabellone.toString() << endl;
        cout << "Punteggio attuale: " << giocatore.getPunteggio() << endl;

        // Selezione della categoria (0-4)
        int scelta;
        cout << "\nScegli una categoria (da 0 a 4): ";
        cin >> scelta;

        if (scelta >= 0 && scelta < MAXEL) {
            // Visualizza la domanda corrispondente
            listaDomande[scelta].mostraDomanda();

            // Gestione della risposta
            Risposta risp;
            risp.leggiRispota();

            // Verifica (Passiamo l'oggetto Squadre per aggiornare il punteggio)
            risp.verificaRisposta(listaDomande[scelta], giocatore);

            // Mostra la risposta corretta
            listaDomande[scelta].mostraRisposta();
        }
        else {
            cout << "Scelta non valida, perdi il turno!" << endl;
        }
    }

    // Finale
    cout << "\n===============================" << endl;
    cout << "PARTITA TERMINATA!" << endl;
    cout << "Squadra: " << giocatore.getNome() << " | Punteggio Finale: " << giocatore.getPunteggio() << endl;
    cout << "===============================" << endl;

    return 0;
}