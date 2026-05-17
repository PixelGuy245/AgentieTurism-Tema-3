#include "Excursie.h"

Excursie::Excursie(const std::string& nume, const std::string& locatie, const std::string& data_plecare, const std::string& data_intoarcere, double cost, int locuri, bool ghid, int cost_ghid)
: Serviciu(nume, locatie, data_plecare, data_intoarcere, cost, locuri), ghid_inclus(ghid), cost_ghid(cost_ghid) {}

Serviciu* Excursie::clone() const {
    return new Excursie(*this);
}

double Excursie::getCost(const Turist& turist) const {
    double cost_calculat = cost;
    if (ghid_inclus) {
        cost_calculat += cost_ghid;
    }
    if (turist.getVarsta() < 18) {
        cost_calculat *= 0.8;
    }
    return cost_calculat;
}

bool Excursie::getGhidInclus() const { 
    return ghid_inclus; 
}

int Excursie::getCostGhid() const {
    return cost_ghid;
}

void Excursie::setGhidInclus(bool ghid) {
    ghid_inclus = ghid;
}

void Excursie::setCostGhid(int cost_g) {
    cost_ghid = cost_g;
}