#include "Squadre.h"

Squadre::Squadre() {
    punteggio = 0;
    nome = "";
	this->punteggio[0] = 0;
	this->nome[0] = "";

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