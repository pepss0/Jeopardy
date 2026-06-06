#pragma once

class Buzzer {
private:
    bool attivo;

public:
    Buzzer();
    void attiva();
    void disattiva();
    bool isAttivo();
};