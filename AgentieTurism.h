#pragma once
#include <string>

class AgentieTurism {
    private:

    std::string nume_agentie;

    AgentieTurism() : nume_agentie("mlem") {}
    AgentieTurism(const AgentieTurism&) = delete;
    AgentieTurism& operator=(const AgentieTurism&) = delete;

    public:

    static AgentieTurism& getInstance() {
        static AgentieTurism instance;
        return instance;
    }

    std::string getNume() const
    {
        return nume_agentie;
    }
};