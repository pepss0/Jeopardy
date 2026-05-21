#include "Concorrente.h"

Concorrente::Concorrente(string nomeIniziale) {
    nome = nomeIniziale;
    punteggio = 0;
}

string Concorrente::getNome() const {
    return nome;
}

int Concorrente::getPunteggio() const {
    return punteggio;
}

void Concorrente::aggiornaPunteggio(int variazione) {
    punteggio += variazione;
}

void Concorrente::premiBuzzer() {
    buzzer.attiva();
}

void Concorrente::resetBuzzer() {
    buzzer.disattiva();
}

bool Concorrente::haPremutoBuzzer() const {
    return buzzer.isAttivo();
}

bool Concorrente::convalidaScommessa(int cifraScommessa) const {
    if (cifraScommessa < 0) {
        return false;
    }
    if (punteggio > 0 && cifraScommessa > punteggio) {
        return false;
    }
    if (punteggio <= 0 && cifraScommessa > 1000) {
        return false;
    }
    return true;
}