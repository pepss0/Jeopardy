#pragma once

#include <string>
#include "Buzzer.h"

using namespace std;

class Concorrente {
private:
    string nome;
    int punteggio;
    Buzzer buzzer;

public:
    Concorrente(string nomeIniziale);
    string getNome();
    int getPunteggio();
    void aggiornaPunteggio(int variazione);
    void premiBuzzer();
    void resetBuzzer();
    bool haPremutoBuzzer();
    bool convalidaScommessa(int cifraScommessa);
};