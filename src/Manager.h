#include "Angajat.h"
#pragma once

class Manager : public Angajat
{
public:
    Manager();
    Manager(string, string, string, time_t);
    Manager(const Manager &);
    void AfisareAngajat();
    void CitireAngajat(istream &);
    void SetCNP(string);
    void CalculeazaSalariu();
};