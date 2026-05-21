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
    string getNome() const;
    int getPunteggio() const;
    void aggiornaPunteggio(int variazione);
    void premiBuzzer();
    void resetBuzzer();
    bool haPremutoBuzzer() const;
    bool convalidaScommessa(int cifraScommessa) const;
};