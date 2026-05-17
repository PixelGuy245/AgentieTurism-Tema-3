#include "Tranzactie.h"
#include "Exceptii.h"
#include "Cazare.h"
#include <iostream>

int Tranzactie::numar_total_tranzactii = 0;

Tranzactie::Tranzactie(const std::string& data, int suma, const Turist& t, const Serviciu* serv) 
    : data_tranzactie(data), suma_tranzactie(suma), beneficiar(t) {
    
    if (suma < 0) {
        throw ExceptieCost();
    }

    if (serv && serv->getLocuriDisponibile() <= 0) {
        throw ExceptieCapacitate();
    }

    serviciul_ales = serv ? serv->clone() : nullptr;
    numar_total_tranzactii++; 
}

Tranzactie::Tranzactie(const Tranzactie& other) 
    : data_tranzactie(other.data_tranzactie), suma_tranzactie(other.suma_tranzactie), beneficiar(other.beneficiar), serviciul_ales(other.serviciul_ales ? other.serviciul_ales->clone() : nullptr) {}

Tranzactie& Tranzactie::operator=(Tranzactie other) {
    swap(*this, other);
    return *this;
}

std::string Tranzactie::getDataTranzactie() const {
    return data_tranzactie;
}

Turist Tranzactie::getTurist() const{
     return beneficiar; 
}

Serviciu* Tranzactie::getServiciu() const {
    return serviciul_ales;
}

int Tranzactie::getSumaTranzactie() const {
    return suma_tranzactie;
}

int Tranzactie::getNrTranzactii() {
    return numar_total_tranzactii;
}

void Tranzactie::setDataTranzactie(const std::string& data) {
    data_tranzactie = data;
}

void Tranzactie::setTurist(const Turist& turist) {
     beneficiar = turist; 
}

void Tranzactie::setServiciu(const Serviciu* serv) {
    delete serviciul_ales; 
    serviciul_ales = serv ? serv->clone() : nullptr; 
}

void Tranzactie::setSumaTranzactie(int suma){
    suma_tranzactie = suma;
}

void Tranzactie::proceseazaTranzactie(const Turist& turist) const {
    std::cout << "Data tranzactiei: " << data_tranzactie << "\n";
    std::cout << "Suma tranzactiei: " << suma_tranzactie << "\n";
    std::cout << "Nume client: " << turist.getNume() << " " << turist.getPrenume() << "\n";
    
    if (serviciul_ales) {
        serviciul_ales->afiseazaServiciu(); 
        if (Cazare* cazare = dynamic_cast<Cazare*>(serviciul_ales)) {
            if (cazare->getMicDejun()) {
                std::cout << "Micul dejun este inclus.\n";
            } else {
                std::cout << "Micul dejun nu este inclus.\n";
            }
        }
        
        std::cout << "Cost total de platit: " 
                  << serviciul_ales->getCost(turist) << "\n";
    } 
    else {
        std::cout << "Eroare: Serviciu invalid\n";
    }
}

Tranzactie::~Tranzactie() {
    delete serviciul_ales;
}