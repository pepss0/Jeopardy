#include "domande.h"
#include <iostream>

using namespace std;

Domanda::Domanda() {
    giaScelta = false; 
    testo="";
}

Domanda::Domanda(string t) {
    testo = t;
    giaScelta = false;
}

string Domanda::mostraDomanda() {
    if (giaScelta==true) {
       return "";
    }
    else {
        giaScelta=true;
        return testo;
      
    }
}

