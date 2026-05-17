#include "Zbor.h"

Zbor::Zbor(const std::string& nume, const std::string& locatie, const std::string& data_plecare, const std::string& data_intoarcere, double cost, int locuri, int taxa, bool bagaj)
: Serviciu(nume, locatie, data_plecare, data_intoarcere, cost, locuri), taxa_bagaj(taxa), bagaj_inclus(bagaj) {}

Serviciu* Zbor::clone() const {
    return new Zbor(*this);
}

double Zbor::getCost(const Turist& turist) const {
    double cost_final = cost;
    if (bagaj_inclus) {
        cost_final += taxa_bagaj;
    }
    if (turist.getVarsta() < 18) {
        cost_final *= 0.8;
    }
    return cost_final;
}

bool Zbor::getBagajInclus() const { 
    return bagaj_inclus; 
}

int Zbor::getTaxa() const { 
    return taxa_bagaj; 
}

void Zbor::setBagajInclus(bool bagaj) {
    bagaj_inclus = bagaj;
}

void Zbor::setTaxa(int taxa) {
    taxa_bagaj = taxa;
}