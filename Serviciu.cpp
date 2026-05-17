#include "Serviciu.h"

Serviciu::Serviciu(const std::string& nume, const std::string& locatie, const std::string& data_plecare, const std::string& data_intoarcere, double cost, int locuri)
:nume_serviciu(nume), locatie(locatie), data_plecare(data_plecare), data_intoarcere(data_intoarcere), cost(cost), locuri_disponibile(locuri) {}

void Serviciu::afiseazaServiciu() const {

    std::cout << "Detalii Serviciu\n";
    std::cout << "Nume: " << nume_serviciu << "\n";
    std::cout << "Locatie: " << locatie << "\n";
    std::cout << "Perioada: " << data_plecare << " - " << data_intoarcere << "\n";
    std::cout << "Cost de baza: " << cost << "\n";
    std::cout << "Locuri disponibile: " << locuri_disponibile << "\n";
}

std::string Serviciu::getNumeServiciu() const
{
    return nume_serviciu;
}

std::string Serviciu::getLocatie() const
{
    return locatie;
}

std::string Serviciu::getDataPlecare() const
{
    return data_plecare;
}

std::string Serviciu::getDataIntoarcere() const
{
    return data_intoarcere;
}

double Serviciu::getCost() const
{
    return cost;
}

int Serviciu::getLocuriDisponibile() const
{
    return locuri_disponibile;
}

void Serviciu::setNumeServiciu(const std::string& nume) {
    this->nume_serviciu =  nume;
}

void Serviciu::setLocatie(const std::string& locatie) {
    this->locatie = locatie;
}

void Serviciu::setDataPlecare(const std::string& data_plecare) {
    this->data_plecare = data_plecare;
}

void Serviciu::setDataIntoarcere(const std::string& data_intoarcere) {
    this->data_intoarcere = data_intoarcere;
}

void Serviciu::setCost(double cost)
{
    this->cost = cost;
}

void Serviciu::setLocuriDisponibile(int locuri)
{
    this->locuri_disponibile = locuri;
}