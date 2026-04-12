#define DOMANDE_H
#include<iostream>
#include <string>
using namespace std;

// --- CLASSE DOMANDA ---
class Domanda {
private:
    string testo;
    string rispostaCorretta;
    int punteggio;
    bool giaScelta;

public:
    // Costruttore di default necessario per l'array
    Domanda();
    Domanda(string t,string r, int p);

    void mostraDomanda();
    void mostraRisposta();
    int getPunteggio();
};


