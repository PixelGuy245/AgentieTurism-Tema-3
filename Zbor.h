#pragma once
#include "Serviciu.h"

class Zbor : public Serviciu {
protected:
    int taxa_bagaj;
    bool bagaj_inclus;
public:

    Zbor(const std::string& nume, const std::string& locatie, const std::string& data_plecare, const std::string& data_intoarcere, double cost, int locuri,  int taxa, bool bagaj);

    Serviciu* clone() const override;

    double getCost(const Turist& turist) const override;

    int getTaxa() const;
    bool getBagajInclus() const;

    void setTaxa(int taxa);
    void setBagajInclus(bool bagaj);
};