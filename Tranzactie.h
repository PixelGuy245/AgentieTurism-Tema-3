#pragma once
#include <string>
#include <algorithm>
#include "Serviciu.h"
#include "Turist.h"

class Tranzactie {
private:
    std::string data_tranzactie;
    double suma_tranzactie;
    Turist beneficiar;
    Serviciu* serviciul_ales;
    static int numar_total_tranzactii;

public:
    Tranzactie(const std::string& data, double suma, const Turist& turist, const Serviciu* serv);

    Tranzactie(const Tranzactie& other);

    friend void swap(Tranzactie& first, Tranzactie& second) noexcept {
        using std::swap;
        swap(first.beneficiar, second.beneficiar);
        swap(first.suma_tranzactie, second.suma_tranzactie);
        swap(first.data_tranzactie, second.data_tranzactie);
        swap(first.serviciul_ales, second.serviciul_ales);
    }

    Tranzactie& operator=(Tranzactie other);

    std::string getDataTranzactie() const;
    double getSumaTranzactie() const; 
    Serviciu* getServiciu() const; 
    Turist getTurist() const; 
    static int getNrTranzactii();

    void setDataTranzactie(const std::string& data);
    void setSumaTranzactie(double suma);
    void setServiciu(const Serviciu* serv);
    void setTurist(const Turist& turist);

    void proceseazaTranzactie(const Turist& turist) const;

    ~Tranzactie();
};