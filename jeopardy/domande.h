#pragma once
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
    string rispostaCorretta;

public:
    Domanda();
    Domanda(string t,string r, int p);

    void mostraDomanda();
    void mostraRisposta();
    int getPunteggio();
    string getRispostaCorretta();
};


