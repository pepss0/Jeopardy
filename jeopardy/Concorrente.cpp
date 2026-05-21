#include "Concorrente.h"

Concorrente::Concorrente(string nomeIniziale) {
    nome = nomeIniziale;
    punteggio = 0;
}

string Concorrente::getNome() {
    return nome;
}

int Concorrente::getPunteggio() {
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

bool Concorrente::haPremutoBuzzer() {
    return buzzer.isAttivo();
}

bool Concorrente::convalidaScommessa(int cifraScommessa) {
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