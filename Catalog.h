#pragma once
#include "Iterator.h"
#include "Observer.h"
#include <vector>
#include <iostream>
#include <stdexcept>

template <typename T>
class Catalog {
private:
    std::vector<T> elemente;
    std::string titlu;
    std::vector<Observer<T>*> observatori;

    class IteratorCatalog : public Iterator<T> {
        const std::vector<T>& ref;
        size_t pozitie;
    public:
        IteratorCatalog(const std::vector<T>& v) : ref(v), pozitie(0) {}

        void first() override { pozitie = 0; }

        void next() override {
            if (isDone()) throw std::out_of_range("Iterator epuizat");
            ++pozitie;
        }

        bool isDone() const override { return pozitie >= ref.size(); }

        T& current() const override {
            if (isDone()) throw std::out_of_range("Nu exista element curent");
            return const_cast<T&>(ref[pozitie]);
        }
    };

public:
    Catalog(const std::string& titlu) : titlu(titlu) {}

    void adauga(const T& elem) {
        elemente.push_back(elem);
        notificaObservatori(elem);
    }

    void elimina(int index) {
        if (index >= 0 && index < (int)elemente.size())
            elemente.erase(elemente.begin() + index);
    }

    void adaugaObserver(Observer<T>* obs) {
        observatori.push_back(obs);
    }

    int size() const { return (int)elemente.size(); }

    Iterator<T>* getIterator() const {
        return new IteratorCatalog(elemente);
    }

    void afiseazaCatalog() const {
        std::cout << "=== Catalog: " << titlu
                  << " (" << elemente.size() << " intrari) ===\n";
    }

    template <typename U>
    friend void afiseazaElemente(const Catalog<U>& catalog);

private:
    void notificaObservatori(const T& elem) {
        for (auto* obs : observatori)
            obs->onAdaugare(elem);
    }
};

template <typename U>
void afiseazaElemente(const Catalog<U>& catalog) {
    std::cout << "=== Elemente catalog: " << catalog.titlu << " ===\n";
    for (const auto& elem : catalog.elemente)
        std::cout << elem << "\n";
}