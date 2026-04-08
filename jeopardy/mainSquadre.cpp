#include <Windows.h>
#include <conio.h>
#include "Squadre.h"

int main()
{
	Squadre s = Squadre();
	int scelta, punteggio;
	bool ris_op;
	string nome, squadra_cercata;
	do
	{
		system("CLS");//cancella lo schermo
		cout << "cosa vuoi fare ?" << endl;
		cout << "1) Aggiungere una squadra" << endl;
		cout << "2) Togliere una squadra" << endl;
		cout << "3) Aggiorna Punteggio" << endl;
		cout << "4) Dammi il numero di squadre" << endl;
		cout << "5) Stampa Classifica" << endl;
		cout << "-1) Terminare" << endl;
		cin >> scelta;
		switch (scelta)
		{
		case 1:
			cout << "Inserisci il nome della squadra che vuoi aggiungere: " << endl;
			cin >> nome;
			ris_op = s.agg_squadra(nome);
			if (ris_op)
				cout << "Squadra aggiunta con successo " << endl;
			else
				cout << "Massimo elementi inseriti/nome scorretto " << endl;
			break;
		case 2:
			cout << "Inserisci il nome della squadra che vuoi togliere: " << endl;
			cin >> nome;
			ris_op = s.togli_squadra(nome);
			if (ris_op)
				cout << "Squadra tolta " << endl;
			else
				cout << "Squadra inesistente " << endl;
			break;
		case 3:
			cout << "Inserisci il punteggio e il nome della squadra: " << endl;
			cin >> punteggio;
			cin >> nome;
			ris_op = s.cambia_Punteggio_Squadra(punteggio, nome);
			if (ris_op)
				cout << "Punteggio Aggiornato " << endl;
			else
				cout << "Squadra inesistente " << endl;
			break;
		case 4:
			cout << "Nsquadre: " << s.conta_N_Squadre() << endl;
			break;
		case 5:
			cout << s.To_String();
			break;
		default:
			break;
		}
		cout << "inserisci un tasto qualunque per continuare..." << endl;
		_getch();
	} while (scelta != -1);
	
}