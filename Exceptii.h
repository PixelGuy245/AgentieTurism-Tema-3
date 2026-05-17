#pragma once
#include <exception>
#include <string>

class ExceptieAgentie : public std::exception {
    protected:

    std::string mesaj_eroare;

    public:
    ExceptieAgentie(const std::string& msj) : mesaj_eroare("Eroare: " + msj) {}
    virtual const char* what() const noexcept override {
        return mesaj_eroare.c_str();
    }
};

class ExceptieDataInvalida : public ExceptieAgentie {
    public:
    ExceptieDataInvalida() : ExceptieAgentie("Data de plecare invalida!") {}
};

class ExceptieCapacitate : public ExceptieAgentie {
public:
    ExceptieCapacitate() : ExceptieAgentie("Nu mai sunt locuri disponibile!") {}
};

class ExceptieCost : public ExceptieAgentie {
public:
    ExceptieCost() : ExceptieAgentie("Costul trebuie sa fie pozitiv!") {}
};