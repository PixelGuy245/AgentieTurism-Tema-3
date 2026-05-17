#include "Turist.h"

Turist::Turist(const std::string& nume, const std::string& prenume, const std::string& tel, int varsta)
    : nume(nume), prenume(prenume), nr_telefon(tel), varsta(varsta) {}

std::string Turist::getNume() const { return nume; }
std::string Turist::getPrenume() const { return prenume; }
std::string Turist::getTelefon() const { return nr_telefon; }
int Turist::getVarsta() const { return varsta; }

void Turist::setNume(const std::string& n) { nume = n; }
void Turist::setPrenume(const std::string& p) { prenume = p; }
void Turist::setTelefon(const std::string& tel) { nr_telefon = tel; }
void Turist::setVarsta(int v) {varsta = v;}

void Turist::afiseazaTurist() const {
    std::cout << "Nume: " << nume << " " << prenume << "\n";
    std::cout << "Varsta: " << varsta << "\n";
    std::cout << "Numar telefon: " << nr_telefon << "\n";
}