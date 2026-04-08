#pragma once
#include <iostream>
using namespace std;
const int MAX_SQUADRE = 5;
class Squadre //SOSTITUIRE TUTTI I PARAMETRI INDICE CON LA STRINGA NOME E DENTRO LE FUNZIONI RICHIMARE "CERCA_SQUADRA"
{
public:
	Squadre();
	int conta_N_Squadre();// serve per contare il numero di squadre 
	int cerca_Squadra(string nome);//trova una squadra in base al nome
	bool cambia_Punteggio_Squadra(int punteggio, string nome);// serve per aggiungere il punteggio a una squadra
	//bool togli_Punteggio_Squadra(int punteggio, string nome);//serve per togliere il punteggio a una squadra
	bool agg_squadra(string nome);//serve per aggiungere una squadra
	int togli_squadra(string nome);//serve per togliere una squadra
	string To_String();
	~Squadre();
private:
	string nome[MAX_SQUADRE];// serve per il nome della squadra
	int punteggio[MAX_SQUADRE];// serve per il mantenere il punteggio
	int n_squadre;// serve per mantenere il numero delle squadre
	void Left_Shift(int indice);
};