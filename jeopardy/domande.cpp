#include "domande.h"
#include <iostream>

using namespace std;

Domanda::Domanda() {
    giaScelta = true; 
    testo="";
}

Domanda::Domanda(string t) {
    testo = t;
    giaScelta = false;
}

int Domanda::mostraDomanda() {
    if (giaScelta==true) {
       return 0;
    }
    else {
        return testo;
        giaScelta=true;
    }
}

