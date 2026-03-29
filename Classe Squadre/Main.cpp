#include "Squadre.h"

int main()
{
	Squadre s = Squadre();
	int scelta, indice, ris, punteggio;
	string nome;
	do
	{
		cout << "cosa vuoi fare ?"<<endl;
		cout << "1) Aggiungere una squadra" << endl;
		cout << "2) Togliere una squadra" << endl;
		cout << "3) Aggiungi Punteggio" << endl;
		cout << "4) Togli Punteggio" << endl;
		cout << "5) Dammi il numero di squadre" << endl;
		cout << "6) Stampa Classifica" << endl;
		cout << "-1) Terminare" << endl;
		cin >> scelta;
		switch (scelta)
		{
		case 1:
			cout << "Inserisci il nome della squadra che vuoi aggiungere: " << endl;
			cin >> nome;
			indice = s.agg_squadra(nome);
			if (indice >= 0)
				cout << "Squadra aggiunta con indice " << indice << endl;
			else
				cout << "Massimo elementi inseriti " << endl;
			break;
		case 2:
			cout << "Inserisci l'indice della squadra che vuoi togliere: " << endl;
			cin >> indice;
			ris = s.togli_squadra(indice);
			if (ris >= 0)
				cout << "Squadra tolta " << endl;
			else
				cout << "Indice errato " << endl;
			break;
		case 3:
			cout << "Inserisci il punteggio e l'indice della squadra: " << endl;
			cin >> punteggio;
			cin >> indice;
			ris = s.agg_Punteggio_Squadra(punteggio, indice);
			if (ris >= 0)
				cout << "Punteggio Aggiornato " << endl;
			else
				cout << "Indice errato " << endl;
			break;
		case 4:
			cout << "Inserisci il punteggio e l'indice della squadra: " << endl;
			cin >> punteggio;
			cin >> indice;
			ris = s.togli_Punteggio_Squadra(punteggio, indice);
			if (ris >= 0)
				cout << "Punteggio Aggiornato " << endl;
			else
				cout << "Indice errato " << endl;
			break;
		case 5:
			cout << "Nsquadre: " << s.conta_N_Squadre() << endl;
			break;
		case 6:
			for (int i = 0; i < s.conta_N_Squadre(); i++)
			{
				cout << s.To_String(i) << endl;;
			}
			break;
		default:
			break;
		}
	} while (scelta != -1);
	
}