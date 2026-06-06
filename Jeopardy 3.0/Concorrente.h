#pragma once

#include <string>
#include "Buzzer.h"

using namespace std;

#define MAX_SQUADRE 5

class Concorrente {
private:
    string nome;
    int punteggio;
    Buzzer buzzer;

public:
    Concorrente();
    Concorrente(string nomeIniziale);
    string getNome();
    int getPunteggio();
    void aggiornaPunteggio(int variazione);
    void premiBuzzer();
    void resetBuzzer();
    bool haPremutoBuzzer();
    bool convalidaScommessa(int cifraScommessa);
    string To_string();
};