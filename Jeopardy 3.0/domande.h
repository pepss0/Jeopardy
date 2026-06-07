#pragma once
#include<iostream>
#include <string>
using namespace std;


class Domanda {
private:
    string testo_risposta;
    string domanda_corretta;
    bool giaScelta;


public:
    Domanda();
    Domanda(string testo_risposta, string domanda_corretta);
    bool verfica_Domanda(string r);
    string mostraRisposta();
    string mostra_Domanda();
    bool get_giaScelta();
};


