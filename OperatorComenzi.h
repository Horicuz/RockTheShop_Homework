#include "Angajat.h"
#pragma once

using namespace std;

class OperatorComenzi : public Angajat
{
private:
public:
    OperatorComenzi();
    OperatorComenzi(string nume, string prenume, string CNP, time_t DataAngajare);
    OperatorComenzi(const OperatorComenzi &operatorcomenzi);
    void AfisareAngajat();
    void CitireAngajat(istream &dev);
    void CalculeazaSalariu();
    bool CheckBirthDay(string CNP);
};