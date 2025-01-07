#include "Angajat.h"
#pragma once

class Asistent : public Angajat
{
public:
    Asistent();
    Asistent(string nume, string prenume, string CNP, time_t DataAngajare);
    Asistent(const Asistent &asistent);
    void AfisareAngajat();
    void CitireAngajat(istream &dev);
    void SetCNP(string NPC);
    void CalculeazaSalariu();
    bool CheckBirthDay(string CNP);
};