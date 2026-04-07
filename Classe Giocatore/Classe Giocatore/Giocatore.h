#pragma once
#include <string>
using namespace std;

class Giocatore {
private:

    string nome;
    int punteggio;

public:

    Giocatore();
    Giocatore(string nomeiniziale);
    void aggiungiPunti(int puntiAggiunti);
    void resettaPunteggio();
    string getNome();
    int getPunteggio();
    string toString();

};
