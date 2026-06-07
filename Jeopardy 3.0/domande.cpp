#include "domande.h"
#include <iostream>
#include <string>

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

string Domanda::mostraRisposta()
{
    string msg = "";
    if (!giaScelta)
        msg += "RISPOSTA: " + this->testo_risposta + "\n";
    else
        msg += "risposta gia' scelta\n";
    return msg;
}

string Domanda::mostra_Domanda()
{
    string msg = "";
    if (this->giaScelta)
        msg += "DOMANDA: " + this->domanda_corretta + "\n";
    else
        msg+= "devi prima provare ad indovinare la domanda\n";
    return msg;
}

bool Domanda::get_giaScelta()
{
    return this->giaScelta;
}
