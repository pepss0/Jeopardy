#include "GameEngine.h"
#include <iostream>
using namespace std;

GameEngine::GameEngine()
{
	for (int i = 0; i < MAX_SQUADRE; i++)
	{
		this->Partecipanti[i] = Concorrente();
	}

	for(int i = 0; i < MAXEL; i++)
		for (int j = 0; j < MAXEL_PUNTI; j++)
		{
			this->Matrice_Domande[i][j] = Domanda();
		}

	this->n_partecipanti = 0;
}

void GameEngine::aggiungi_concorrente(string nome)
{
	if (this->n_partecipanti < MAX_SQUADRE)
	{
		Concorrente new_partecipante(nome);
		this->Partecipanti[n_partecipanti] = new_partecipante;
		this->n_partecipanti++;
	}
}

void GameEngine::aggiorna_tabellone(Interfaccia tab)
{
	this->Tabellone = tab;
}

void GameEngine::aggiorna_domande(Domanda mat[MAXEL][MAXEL_PUNTI])
{
	for(int i = 0; i < MAXEL; i++)
		for (int j = 0; j < MAXEL_PUNTI; j++)
		{
			this->Matrice_Domande[i][j] = mat[i][j];
		}
}

void GameEngine::start()
{
    int turno = 0;
    bool inCorso = true;
    string domanda = "";

    while (inCorso && turno != (MAXEL * MAXEL_PUNTI)) {

        int corrente = turno % this->n_partecipanti;

        cout << "nTURNO: " << turno + 1 << endl;
        cout << "TURNO DI: " << Partecipanti[corrente].getNome() << endl;
        cout << "PUNTEGGIO ATTUALE: " << Partecipanti[corrente].getPunteggio() << endl << endl;

        cout << Tabellone.toString() << endl;

        int sceltaI, sceltaJ;
        
        cout << "\nScegli Categoria (1-" + to_string(MAXEL) + ") o -1 per uscire: ";
        cin >> sceltaI;

        if (sceltaI == -1) {
            inCorso = false;
        }
        else if (sceltaI >= 1 && sceltaI <= MAXEL) 
        {
            cout << "Scegli Difficolta' (1-" + to_string(MAXEL_PUNTI) + "): ";
            cin >> sceltaJ;

            if (sceltaJ >= 1 && sceltaJ <= MAXEL_PUNTI) 
            {
                // HOST TASKS
                if (this->Matrice_Domande[sceltaI - 1][sceltaJ - 1].get_giaScelta())
                {
                    cout << "gia scelta" << endl;
                }
                else
                {
                    int soldi_agg = 0;
                    int punteggio_scommessa = this->Tabellone.get_punteggio_domanda(sceltaJ - 1);
                    if (this->Partecipanti[corrente].getPunteggio() > 0)
                    {
                        do
                        {
                            cout << "quanto vuoi scommettere in aggiunta (max =" + to_string(this->Partecipanti[corrente].getPunteggio()) + "): " << endl;
                            cin >> soldi_agg;
                            if (!this->Partecipanti[corrente].convalidaScommessa(soldi_agg))
                                cout << "non puoi scommettere soldi aggiuntivi" << endl;
                        } while (!this->Partecipanti[corrente].convalidaScommessa(soldi_agg));
                        punteggio_scommessa += soldi_agg;
                    }
                    
                    this->Matrice_Domande[sceltaI - 1][sceltaJ - 1].mostraRisposta();

                    this->Partecipanti[corrente].premiBuzzer();

                    cout << "inserisci domanda: ";
                    cin >> domanda;

                    if (this->Matrice_Domande[sceltaI - 1][sceltaJ - 1].verfica_Domanda(domanda))
                    {
                        //è corretta
                        cout << "risposta corretta" << endl;
                        this->Partecipanti[corrente].aggiornaPunteggio(punteggio_scommessa);
                        //Partecipanti[]=aggiornaPunteggio(this->Matrice_Domande)
                    }
                    else
                    {
                        //è sbagliata
                        cout << "risposta sbagliata" << endl;
                        cout << "la risposta corretta: " << endl;
                        this->Matrice_Domande[sceltaI - 1][sceltaJ - 1].mostra_Domanda();
                        this->Partecipanti[corrente].aggiornaPunteggio(-punteggio_scommessa);
                    }
                    
                    this->Partecipanti[corrente].resetBuzzer();

                    turno++;
                
                }
            }
        }
    }

    cout << "--- CLASSIFICA FINALE ---" << endl;
    for (int i = 0; i < this->n_partecipanti; i++) {
        cout << Partecipanti[i].getNome() << ": " << Partecipanti[i].getPunteggio() << " punti" << endl;
    }
}

Concorrente GameEngine::get_vincitore()
{
	Concorrente vincitore = Concorrente();
	for (int i = 0; i < this->n_partecipanti; i++)
	{
		if (this->Partecipanti[i].getPunteggio() > vincitore.getPunteggio())
			vincitore = this->Partecipanti[i];
	}
	return vincitore;
}

GameEngine::~GameEngine()
{
}
//string nomiCategorie[MAXEL] = { "STORIA", "LOGICA", "INFORMATICA", "SPORT", "ARTE" };
//int valoriPunti[MAXEL] = { 200, 400, 600, 800, 1000 };
//Interfaccia tabellone(nomiCategorie, valoriPunti);