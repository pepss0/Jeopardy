#include "Giocatore.h"
using namespace std;

Giocatore::Giocatore() {
    nome = "Sconosciuto";
    punteggio = 0;
}

Giocatore::Giocatore(string nomeIniziale) {
    nome = nomeIniziale;
    punteggio = 0;
}

void Giocatore::aggiungiPunti(int puntiAggiunti) {
    if (puntiAggiunti > 0) {
        punteggio += puntiAggiunti;
    }
}

void Giocatore::resettaPunteggio() {
    punteggio = 0;
}

string Giocatore::getNome() {
    return nome;
}

int Giocatore::getPunteggio() {
    return punteggio;
}

string Giocatore::toString() {
    string str;
    str += nome + " ha " + to_string(punteggio) + " punti";
    return str;
}