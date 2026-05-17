#pragma once
#include "Serviciu.h"

class Excursie : public Serviciu {
protected:
    bool ghid_inclus;
    int cost_ghid;

public:

    Excursie(const std::string& nume, const std::string& locatie, const std::string& data_plecare, const std::string& data_intoarcere, double cost, int locuri,  bool ghid, int cost_ghid);

    Serviciu* clone() const override;

    double getCost(const Turist& turist) const override;

    bool getGhidInclus() const;
    int getCostGhid() const;

    void setCostGhid(int cost_ghid);
    void setGhidInclus(bool ghid);
};