#include "domande.h"
#include <iostream>

using namespace std;

Domanda::Domanda() {
    this->testo_risposta = "";
    this->giaScelta = false;
    this->domanda_corretta = "";
}

Domanda::Domanda(string testo_risposta, string domanda_corretta) {
    this->testo_risposta = testo_risposta;
    this->giaScelta = false;
    this->domanda_corretta = domanda_corretta;
}

bool Domanda::verfica_Domanda(string r) 
{
    this->giaScelta = true;
    if (r == this->domanda_corretta)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Domanda::mostraRisposta()
{
    if (!giaScelta)
        cout << "RISPOSTA: " << this->testo_risposta << endl;
    else
        cout << "risposta gia' scelta" << endl;
}

void Domanda::mostra_Domanda()
{
    if (this->giaScelta)
        cout << "DOMANDA: " << this->domanda_corretta << endl;
    else
        cout << "devi prima provare ad indovinare la domanda" << endl;
}

bool Domanda::get_giaScelta()
{
    return this->giaScelta;
}
