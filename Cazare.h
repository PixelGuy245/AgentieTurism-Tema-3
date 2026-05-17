#pragma once
#include "Serviciu.h"

class Cazare : public Serviciu {
protected:
    bool mic_dejun_inclus;

public:

    Cazare(const std::string& nume, const std::string& locatie, const std::string& data_plecare, const std::string& data_intoarcere, double cost, int locuri,  bool mic_dejun);

    Serviciu* clone() const override;

    double getCost(const Turist& turist) const override;

    bool getMicDejun() const;

    void setMicDejun(bool mic_dejun);
};