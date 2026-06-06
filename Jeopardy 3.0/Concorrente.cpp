#include "Concorrente.h"
#include <string>

Concorrente::Concorrente()
{
    this->nome = "";
    this->punteggio = 0;
    this->buzzer = Buzzer();
}

Concorrente::Concorrente(string nomeIniziale) {
    this->nome = nomeIniziale;
    this->punteggio = 0;
    this->buzzer = Buzzer();
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
    if (punteggio <= 0) {
        return false;
    }
    return true;
}

string Concorrente::To_string()
{
    string msg = "";
    msg += "nome:\t" + this->nome + "\n";
    msg += "punteggio:\t" + to_string(this->punteggio);
    return msg;
}
