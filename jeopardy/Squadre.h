#pragma once
#include <string>

using namespace std;

class Squadre {
private:
    string nome;
    int punteggio;

public:

    Squadre();
    void setNome(string n);
    void modificaPunteggio(int valore, bool corretta);
    string getNome();
    int getPunteggio();
};