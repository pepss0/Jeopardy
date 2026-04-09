#include "Squadre.h"

Squadre::Squadre() {
    punteggio = 0;
    nome = "";
}

void Squadre::setNome(string n) {
    nome = n;
}

void Squadre::modificaPunteggio(int valore, bool corretta) {
    if (corretta) {
        punteggio += valore;
    }
    else {
        punteggio -= valore;
    }
}

string Squadre::getNome() {
    return nome;
}

int Squadre::getPunteggio() {
    return punteggio;
}