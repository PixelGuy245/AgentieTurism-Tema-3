#pragma once
#include <vector>
#include <iostream>
#include <string>

template <typename T>
class Catalog {
private:
    std::vector<T> elemente;
public:
    void adauga(const T& elem) {
        elemente.push_back(elem);
    }

    void afiseazaCatalog(const std::string& nume) const {
        std::cout  << nume << "\n";
        for (const auto& elem : elemente) {
            std::cout << " * " << elem << "\n";
        }
    }
};

template <typename T>
T aplicaDiscount(T valoare_initiala, double procent_discount) {
    return valoare_initiala - static_cast<T>(valoare_initiala * (procent_discount / 100.0));
}