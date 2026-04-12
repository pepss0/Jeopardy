#pragma once
#include<iostream>
#include <string>
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
    bool verificaRisposta(Domanda d)
};


