#include "Buzzer.h"

Buzzer::Buzzer() {
    attivo = false;
}

void Buzzer::attiva() {
    attivo = true;
}

void Buzzer::disattiva() {
    attivo = false;
}

bool Buzzer::isAttivo() {
    return attivo;
}