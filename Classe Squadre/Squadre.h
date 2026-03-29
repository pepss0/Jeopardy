#pragma once
#include <iostream>
using namespace std;
const int MAX_SQUADRE = 5;
class Squadre
{
public:
	Squadre();
	int conta_N_Squadre();// serve per contare il numero di squadre 
	int agg_Punteggio_Squadra(int punteggio, int N_squadra);// serve per aggiungere il punteggio a una squadra
	int togli_Punteggio_Squadra(int punteggio, int N_squadra);//serve per togliere il punteggio a una squadra
	int agg_squadra(string nome);//serve per aggiungere una squadra
	int togli_squadra(int N_squadra);//serve per togliere una squadra
	string To_String(int N_squadra);
	~Squadre();
private:
	string nome[MAX_SQUADRE];// serve per il nome della squadra
	int punteggio[MAX_SQUADRE];// serve per il mantenere il punteggio
	int n_squadre;
};