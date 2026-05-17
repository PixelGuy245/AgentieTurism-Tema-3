#pragma once
#include <iostream>
#include <string>
#include "Turist.h"

class Serviciu {
    protected:

    std::string nume_serviciu, locatie, data_plecare, data_intoarcere;
    double cost;
    int locuri_disponibile;

    public:

    Serviciu(const std::string& nume, const std::string& locatie, const std::string& data_plecare, const std::string& data_intoarcere, double cost, int locuri);
    
    void afiseazaServiciu() const;

    virtual Serviciu* clone() const = 0;

    virtual double getCost(const Turist& turist) const = 0;

    std::string getNumeServiciu() const;
    std::string getLocatie() const;
    std::string getDataPlecare() const;
    std::string getDataIntoarcere() const;
    double getCost() const;
    int getLocuriDisponibile() const;

    void setNumeServiciu(const std::string& nume);
    void setLocatie(const std::string& locatie);
    void setDataPlecare(const std::string& data_plecare);
    void setDataIntoarcere(const std::string& data_intoarcere);
    void setCost(double cost);
    void setLocuriDisponibile(int locuri);

    virtual ~Serviciu() = default;
};