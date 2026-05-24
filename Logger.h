#pragma once
#include "Observer.h"
#include "Tranzactie.h"
#include "Serviciu.h"
#include "Turist.h"
#include <iostream>

class LoggerTranzactie : public Observer<Tranzactie> {
public:
    void onAdaugare(const Tranzactie& tr) override {
        std::cout << "[LOG] Tranzactie adaugata: "
                  << tr.getDataTranzactie()
                  << " , suma: " << tr.getSumaTranzactie() << "\n";
    }
};

class LoggerTurist : public Observer<Turist> {
public:
    void onAdaugare(const Turist& t) override {
        std::cout << "[LOG] Turist adaugat: "
                  << t.getNume() << " " << t.getPrenume() << "\n";
    }
};

class LoggerServiciu : public Observer<Serviciu*> {
public:
    void onAdaugare(Serviciu* const& s) override {
        std::cout << "[LOG] Serviciu adaugat: "
                  << s->getNumeServiciu()
                  << " , locatie: " << s->getLocatie()
                  << " , cost: " << s->getCost() << "\n";
    }
};