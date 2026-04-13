#pragma once
#include<iostream>
#include <string>
#include "Squadre.h"
#include "domande.h"
using namespace std;

// --- CLASSE RISPOSTA ---
class Risposta {
private:
    string risposta_fornita;
public:
    // Costruttore di default necessario per l'array
    Risposta();
    Risposta(string r);
    void leggiRispota();
    void verificaRisposta(Domanda d, Squadre s);
};


