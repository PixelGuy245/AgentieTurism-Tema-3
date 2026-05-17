#pragma once
#include <string>
#include <iostream>

class Turist {
private:
    std::string nume;
    std::string prenume;
    std::string nr_telefon;
    int varsta;

public:
    Turist(const std::string& nume, const std::string& prenume, const std::string& tel, int varsta);

    std::string getNume() const;
    std::string getPrenume() const;
    std::string getTelefon() const;
    int getVarsta() const;

    void setNume(const std::string& nume);
    void setPrenume(const std::string& prenume);
    void setTelefon(const std::string& tel);
    void setVarsta(int varsta);

    void afiseazaTurist() const;

    friend std::ostream& operator<<(std::ostream& os, const Turist& t) {
        os << t.nume << " " << t.prenume << " (Varsta: " << t.varsta << ")";
        return os;
    }
};