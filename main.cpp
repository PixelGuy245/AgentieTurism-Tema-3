#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Observer.h"
#include "Iterator.h"
#include "Catalog.h"
#include "Logger.h"
#include "Turist.h"
#include "Cazare.h"
#include "Excursie.h"
#include "Zbor.h"
#include "Tranzactie.h"
#include "Exceptii.h"

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void afiseazaMeniu() {
    std::cout << "\n========== CATALOG ==========\n"
              << " 0.  Iesire\n"
              << " 1.  Adauga Turist nou\n"
              << " 2.  Adauga Tranzactie noua\n"
              << " 3.  Adauga Serviciu nou\n"
              << " 4.  Adauga Turist in Catalog\n"
              << " 5.  Afiseaza Catalog Turisti\n"
              << " 6.  Adauga Tranzactie in Catalog\n"
              << " 7.  Afiseaza Catalog Tranzactii\n"
              << " 8.  Adauga Serviciu in Catalog\n"
              << " 9.  Afiseaza Catalog Servicii\n"
              << "10.  Afiseaza Turisti\n"
              << "=============================\n"
              << "Optiune: ";
}

int main()
{
    std::vector<Turist>    turisti;
    std::vector<Serviciu*> servicii;
    std::vector<Tranzactie> tranzactii;

    LoggerTurist    logT;
    LoggerServiciu  logServ;
    LoggerTranzactie logTr;

    Catalog<Turist>      catalogTuristi("Catalog Clienti");
    Catalog<Serviciu*>   catalogServicii("Catalog Servicii");
    Catalog<Tranzactie>  catalogTranzactii("Catalog Tranzactii");

    catalogTuristi.adaugaObserver(&logT);
    catalogServicii.adaugaObserver(&logServ);
    catalogTranzactii.adaugaObserver(&logTr);

     int optiune = -1;

      while (optiune != 0) {
        afiseazaMeniu();
        std::cin >> optiune;
        clearInput();
 
        switch (optiune) {
 
        case 1: {
            std::string nume, prenume, telefon;
            int varsta;
            std::cout << "Nume: ";        std::getline(std::cin, nume);
            std::cout << "Prenume: ";     std::getline(std::cin, prenume);
            std::cout << "Telefon: ";     std::getline(std::cin, telefon);
            std::cout << "Varsta: ";      std::cin >> varsta; clearInput();
 
            turisti.emplace_back(nume, prenume, telefon, varsta);
            break;
        }
 
        case 2: {

            std::cout << "Turisti disponibili:\n";
            for (size_t i = 0; i < turisti.size(); ++i) {
                std::cout << "  [" << i << "] ";
                turisti[i].afiseazaTurist();
                std::cout << "\n";
            }

            int idxT;
            std::cout << "Index turist: "; std::cin >> idxT; clearInput();
            if (idxT < 0 || idxT >= (int)turisti.size()) {
                std::cout << "Index invalid.\n"; break;
            }

            std::cout << "Servicii disponibile:\n";
            for (size_t i = 0; i < servicii.size(); ++i) {
                std::cout << "  [" << i << "] ";
                servicii[i]->afiseazaServiciu();
                std::cout << "\n";
            }

            int idxS;
            std::cout << "Index serviciu: "; std::cin >> idxS; clearInput();
            if (idxS < 0 || idxS >= (int)servicii.size()) {
                std::cout << "Index invalid.\n"; break;
            }
 
            std::string data;
            double suma;
            std::cout << "Data tranzactiei: "; std::getline(std::cin, data);
            std::cout << "Suma: "; std::cin >> suma; clearInput();
 
            tranzactii.emplace_back(data, suma, turisti[idxT], servicii[idxS]);
            break;
        }

        case 3: {
            std::cout << "Tip serviciu:\n  1. Cazare\n  2. Zbor\n  3. Excursie\n Optiune: ";
            int tip; std::cin >> tip; clearInput();
 
            std::string denumire, destinatie, dataI, dataF;
            double pret;
            int capacitate;
 
            std::cout << "Denumire: ";                    std::getline(std::cin, denumire);
            std::cout << "Destinatie: ";                  std::getline(std::cin, destinatie);
            std::cout << "Data plecare: ";  std::getline(std::cin, dataI);
            std::cout << "Data intoarcere: "; std::getline(std::cin, dataF);
            std::cout << "Cost: ";      std::cin >> pret;      clearInput();
            std::cout << "Locuri: ";    std::cin >> capacitate; clearInput();
 
            if (tip == 1) {
                bool micDejun;
                std::cout << "Include mic dejun?: ";
                std::cin >> micDejun; clearInput();
                servicii.push_back(new Cazare(denumire, destinatie, dataI, dataF,pret, capacitate, micDejun));
 
            } else if (tip == 2) {
                int taxa;
                bool bagajInclus;
                std::cout << "Taxa bagaj: ";               std::cin >> taxa;       clearInput();
                std::cout << "Bagaj inclus?: "; std::cin >> bagajInclus; clearInput();
                servicii.push_back(new Zbor(denumire, destinatie, dataI, dataF, pret, capacitate, taxa, bagajInclus));
 
            } else if (tip == 3) {
                bool ghidInclus;
                int costGhid;
                std::cout << "Ghid inclus?: "; std::cin >> ghidInclus; clearInput();
                std::cout << "Cost ghid: ";                   std::cin >> costGhid;   clearInput();
                servicii.push_back(new Excursie(denumire, destinatie, dataI, dataF, pret, capacitate, ghidInclus, costGhid));
 
            } else {
                std::cout << "Tip invalid.\n"; break;
            }
            break;
        }
 
        case 4: {
            if (turisti.empty()) {
                std::cout << "Nu exista turisti creati.\n"; break;
            }
            std::cout << "Turisti disponibili:\n";
            for (size_t i = 0; i < turisti.size(); ++i) {
                std::cout << "  [" << i << "] ";
                turisti[i].afiseazaTurist();
                std::cout << "\n";
            }
            int idx;
            std::cout << "Index: "; std::cin >> idx; clearInput();
            if (idx < 0 || idx >= (int)turisti.size()) {
                std::cout << "Index invalid.\n"; break;
            }
            catalogTuristi.adauga(turisti[idx]);
            break;
        }
 
        case 5: {
            catalogTuristi.afiseazaCatalog();
 
            Iterator<Turist>* it = catalogTuristi.getIterator();
            for (it->first(); !it->isDone(); it->next()) {
                it->current().afiseazaTurist();
                std::cout << "\n";
            }
            delete it;
            break;
        }
 
        case 6: {
            if (tranzactii.empty()) {
                std::cout << "Nu exista tranzactii create (optiunea 2).\n"; break;
            }
            std::cout << "Tranzactii disponibile:\n";
            for (size_t i = 0; i < tranzactii.size(); ++i) {
                std::cout << "  [" << i << "] Tranzactie " << i << "\n";
            }
            int idx;
            std::cout << "Index: "; std::cin >> idx; clearInput();
            if (idx < 0 || idx >= (int)tranzactii.size()) {
                std::cout << "Index invalid.\n"; break;
            }
            catalogTranzactii.adauga(tranzactii[idx]);
            break;
        }

        case 7: {
            catalogTranzactii.afiseazaCatalog();
 
            Iterator<Tranzactie>* it = catalogTranzactii.getIterator();
            for (it->first(); !it->isDone(); it->next()) {
                Tranzactie& tr = it->current();
                tr.proceseazaTranzactie(tr.getTurist());
                std::cout << "\n";
            }
            delete it;
            break;
        }
 
        case 8: {
            if (servicii.empty()) {
                std::cout << "Nu exista servicii create.\n"; break;
            }
            std::cout << "Servicii disponibile:\n";
            for (size_t i = 0; i < servicii.size(); ++i) {
                std::cout << "  [" << i << "] ";
                servicii[i]->afiseazaServiciu();
                std::cout << "\n";
            }
            int idx;
            std::cout << "Index: "; std::cin >> idx; clearInput();
            if (idx < 0 || idx >= (int)servicii.size()) {
                std::cout << "Index invalid.\n"; break;
            }
            catalogServicii.adauga(servicii[idx]);
            break;
        }

        case 9: {
            catalogServicii.afiseazaCatalog();
 
            Iterator<Serviciu*>* it = catalogServicii.getIterator();
            for (it->first(); !it->isDone(); it->next()) {
                it->current()->afiseazaServiciu();
                std::cout << "\n";
            }
            delete it;
            break;
        }
 
        case 10: {
            afiseazaElemente(catalogTuristi);
            std::cout << "\n";
            break;
        }

        case 0:
        default:
            break;
        }
    }
 
    for (Serviciu* s : servicii)
        delete s;
 
    return 0;
}