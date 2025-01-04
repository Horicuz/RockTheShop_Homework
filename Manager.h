#include "Angajat.h"
#pragma once

using namespace std;

class Manager : public Angajat
{
private:
public:
    Manager();
    Manager(string nume, string prenume, string CNP, time_t DataAngajare);
    Manager(const Manager &manager);
    void AfisareAngajat();
    void CalculeazaSalariu();
    friend istream &operator>>(istream &in, Manager &manager);
};