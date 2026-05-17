#include "Cazare.h"

Cazare::Cazare(const std::string& nume, const std::string& locatie, const std::string& data_plecare, const std::string& data_intoarcere, double cost, int locuri, bool mic_dejun)
: Serviciu(nume, locatie, data_plecare, data_intoarcere, cost, locuri), mic_dejun_inclus(mic_dejun) {}

Serviciu* Cazare::clone() const {
    return new Cazare(*this);
}

double Cazare::getCost(const Turist& turist) const {
    double cost_calculat = cost;
    if (mic_dejun_inclus) {
        cost_calculat += 100;
    }
    if (turist.getVarsta() < 18) {
        cost_calculat *= 0.8;
    }
    return cost_calculat;
}

bool Cazare::getMicDejun() const { 
    return mic_dejun_inclus; 
}

void Cazare::setMicDejun(bool mic_dejun) {
    mic_dejun_inclus = mic_dejun;
}