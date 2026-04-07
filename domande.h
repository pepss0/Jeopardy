
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
    int getPunteggio();
};

// --- CLASSE CATEGORIA ---
class Categoria {
private:
   string nome;
    Domanda listaDomande[5]; // Array fisso invece del vector
    int numeroDomande;       // Contatore interno

public:
    Categoria(string n);
    void aggiungiDomanda(Domanda d);
    void selezionaCasella(int puntiSelezionati);
};

