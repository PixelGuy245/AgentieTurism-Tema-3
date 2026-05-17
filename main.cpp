#include <iostream>
#include <vector>
#include "Turist.h"
#include "Cazare.h"
#include "Zbor.h"
#include "Tranzactie.h"
#include "Exceptii.h"

int main() {
    Serviciu* hotel = nullptr;
    Serviciu* zbor = nullptr;
    Serviciu* hotelEpuizat = nullptr;

    try {
        Turist t1("Popescu", "Andrei", "0722111222", 35);
        Turist t2("Ionescu", "Maria", "0744333444", 10);

        hotel = new Cazare("Hotel Hilton", "Viena", "10-05-2026", "17-05-2026", 1500, 20, true);
        zbor = new Zbor("Zbor RO-FR", "Paris", "20-06-2026", "20-06-2026", 800, 150, false , "AirFrance");
        hotelEpuizat = new Cazare("Pensiunea Mica", "Bran", "01-12-2026", "05-12-2026", 500, 0, false);

        Tranzactie tr1("26-04-2026", 1600, t1, hotel);
        Tranzactie tr2("26-04-2026", 800, t2, zbor);

        tr1.proceseazaTranzactie(t1);

        tr2.proceseazaTranzactie(t2);

        Tranzactie trCopie = tr1; 
        trCopie = tr2;

        try {
            Tranzactie trEroareSuma("26-04-2026", -100, t1, hotel);
        } catch (const ExceptieAgentie& e) {
            std::cout << e.what() << "\n";
        }

        try {
            Tranzactie trEroareLocuri("26-04-2026", 500, t1, hotelEpuizat);
        } catch (const ExceptieAgentie& e) {
            std::cout << e.what() << "\n";
        }

    } 
    catch (const std::exception& e) {

        std::cout << "Eroare de sistem: " << e.what() << "\n";
    }

    std::cout << "Numar total de tranzactii valide inregistrate: " << Tranzactie::getNrTranzactii() << "\n";
    delete hotel;
    delete zbor;
    delete hotelEpuizat;

    return 0;
}