#include "GameEngine.h"

// ============================================================
//  Costanti schermata
// ============================================================

const int RIGA_TITOLO = 1;

const int RIGA_DOMANDA_CAT = 3;
const int COL_DOMANDA_CAT = 25;

const int RIGA_GIOCATORE = 11;
const int COL_GIOCATORE = 8;

const int RIGA_DOMANDA = 22;
const int COL_DOMANDA = 4;

const int RIGA_RISPOSTA = 23;
const int COL_RISPOSTA = 4;

GameEngine::GameEngine(InterfacciaUtente& ui, wstring nomeGiocatore)
    : ui(ui)    // qui GameEngine usa un riferimento a InterfacciaUtente, 
                // quindi nel costruttore è necessario usare la lista di inizializzazione : ui(ui)
{
    this->nomeGiocatore = nomeGiocatore;
    this->numeroDomande = 0;
    this->testoCategorie[0] = L"CITTA";
    this->testoCategorie[1] = L"SPORT";
    this->testoCategorie[2] = L"AMBIENTE";
    this->testoCategorie[3] = L"CANTANTI";
    this->testoCategorie[4] = L"SCIENZE";

    this->risposteCat1Val100[0] = L"Quale è la capitale della Francia?";
    this->risposteCat1Val100[1] = L"Quale è il capoluogo del Molise?";
    this->risposteCat1Val100[2] = L"Quale è la città ai piedi della Grigna?";
    this->risposteCat1Val100[3] = L"Quale è la città dove si trova la 'madunina'?";
}

int GameEngine::getNumeroDomande()
{
    return numeroDomande;
}

void GameEngine::run() {
    bool continua = true;
    int categoria;
    int valore;
    int numRisposta;

    // In questo ciclo di gioco, 
    while (continua == true) {
		// prima si prepara la scena da mostrare al giocatore (mostraCampoGioco)
		// con la visualizzazione della domanda "Vuoi una carta?".
		disegnaCampoEDomanda(L"Quale categoria? (1/2/3/4/5):");

		// Poi si aspetta la risposta del giocatore (leggiTastoBloccante) e si agisce di conseguenza.
        categoria = ui.leggiTastoBloccante();

        if (categoria == TASTO_ESC) {
            continua = false;
        }
        else {
            // Si chiede il valore della domanda
            // e si aspetta la risposta del giocatore
            valore = ui.leggiIntero(Posizione(RIGA_RISPOSTA-1, COL_RISPOSTA),
                Posizione(RIGA_RISPOSTA, COL_RISPOSTA), L"Quale valore? (100/200/300/400/500):", 100, 100, 500);

            if ((categoria == '1') && (valore == 100)) {
			    // In base alla categoria e al valore, si visualizza una domanda 
                // seguita dalle possibili risposte
                mostraDomandaConRisposte(L"E' la città di Lecco.", this->risposteCat1Val100, 4);
                numRisposta = ui.leggiTastoBloccante();
                // Si aggiorna il numero di domande a cui si è risposto correttamente.
                if (numRisposta == '3')
                    numeroDomande = numeroDomande + 1;
            }
        }
    }
}

void GameEngine::aggiungiSfondo() {
    // Titolo
    ui.aggiungiTestoAlCentro(RIGA_TITOLO, L"JEOPARDY");

    // visualizza i nomi delle categorie
    for (size_t c = 0; c < 5; c++)
    {
        wstring categoriaTxt = this->testoCategorie[c];
        ui.aggiungiRettangoloVuotoRigCol(Posizione(2, 10 + (c * 6)), 6, 1, FG_GIALLO);
        ui.aggiungiTestoRigCol(Posizione(2, 11 + (c * 6)), categoriaTxt);
    }

    // disegna una matrice con 5 colonne e 5 righe 
    // contenente nella prima riga il numero 100
    // nella seconda 200 e così via
    int valore = 100;
    for (size_t r = 0; r < 5; r++)
    {
        for (size_t c = 0; c < 5; c++)
        {
            ui.aggiungiRettangoloVuotoRigCol(Posizione(3 + (r * 3), 10 + (c * 6)), 6, 3, FG_GIALLO);
            ui.aggiungiNumeroRigCol(Posizione(4 + (r * 3), 12 + (c * 6)), valore);
        }
        valore += 100;
    }
    ui.aggiungiTestoRigCol(Posizione(RIGA_GIOCATORE + 8, COL_GIOCATORE), L"Numero domande a cui si è risposto correttamente:");
    ui.aggiungiNumeroRigCol(Posizione(RIGA_GIOCATORE + 8, COL_GIOCATORE + 27), numeroDomande);
}


void GameEngine::disegnaCampoEDomanda(wstring domanda)
{
    ui.pulisci();

    // si aggiunge lo sfondo con la griglia
    aggiungiSfondo();
    // e la domanda
    ui.aggiungiTestoRigCol(Posizione(RIGA_DOMANDA, COL_DOMANDA), domanda);

    ui.disegna();
}

void GameEngine::mostraDomandaConRisposte(wstring domanda, wstring risposte[], int numEl)
{
    string imgFileName = "./images/sfondoJeopardy.png";
    sf::Image image;

    if (image.loadFromFile(imgFileName))
    {
        unsigned int larghezzaImmagine = image.getSize().x;
        unsigned int altezzaImmagine = image.getSize().y;

        float scalaFinaleX = static_cast<float>(ui.getLarghezza()) / larghezzaImmagine;
        float scalaFinaleY = static_cast<float>(ui.getAltezza()) / altezzaImmagine;
        float scalaIniziale = 0.2f;

        float centroX = ui.getLarghezza() / 2.0f;
        float centroY = ui.getAltezza() / 2.0f;

        int num_passi = 18;
        for (int i = 0; i <= num_passi; i++)
        {
            float t = static_cast<float>(i) / num_passi;

            float scalaX = scalaIniziale + t * (scalaFinaleX - scalaIniziale);
            float scalaY = scalaIniziale + t * (scalaFinaleY - scalaIniziale);

            // In ogni passo dell'animazione, si pulisce la schermata
            ui.pulisci();

            // e si aggiunge lo sfondo sempre più ingrandito.
            ui.aggiungiImmagine(Punto(centroX, centroY), "./images/sfondoJeopardy.png", scalaX, scalaY);
            // la domanda
            ui.aggiungiTestoRigCol(Posizione(i, 10), domanda);
            // e le risposte
            for (int r = 0; r < numEl; r++)
            {
                wstring testoRisposta =
                    to_wstring(r + 1) + L") " + risposte[r];

                ui.aggiungiTestoRigCol(Posizione(i + 1 + r, 10), testoRisposta);
            }

            // Si mostra il frame corrente.
            ui.disegna();

            // Per rallentare l'animazione, si può inserire una breve pausa.
            ui.sleep(50); // usando la funzione sleep definita in InterfacciaUtente
        }
    }
}
