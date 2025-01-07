#include "Angajat.h"
#pragma once

class Manager : public Angajat
{
public:
    Manager();
    Manager(string nume, string prenume, string CNP, time_t DataAngajare);
    Manager(const Manager &manager);
    void AfisareAngajat();
    void CitireAngajat(istream &dev);
    void SetCNP(string NPC);
    void CalculeazaSalariu();
};