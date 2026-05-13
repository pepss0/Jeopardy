#pragma once
#include<iostream>
#include <string>
using namespace std;


class Domanda {
private:
    string testo;
    bool giaScelta;


public:
    Domanda();
    Domanda(string t);

    string mostraDomanda();
};


