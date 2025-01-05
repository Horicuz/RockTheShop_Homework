#include "Asistent.h"

Asistent::Asistent()
{
}

Asistent::Asistent(string nume, string prenume, string CNP, time_t DataAngajare) : Angajat(nume, prenume, CNP, DataAngajare)
{
}

Asistent::Asistent(const Asistent &asistent) : Angajat(asistent)
{
}

void Asistent::AfisareAngajat()
{
    cout << "Pozitie: Asistent" << endl;
    cout << "-------------------------" << endl;
    Angajat::AfisareAngajat();
}

void Asistent::CitireAngajat(istream &dev)
{
    Angajat::CitireAngajat(dev);
}

void Asistent::CalculeazaSalariu()
{
    Angajat::CalculeazaSalariu();
    salariu *= 0.75; // Asistent are coeficient 1.1
    if (CheckBirthDay(CNP))
    {
        salariu += 100;
    }
}

bool Asistent::CheckBirthDay(string CNP)
{
    int month = stoi(CNP.substr(3, 2)); // Luna de nastere
    // Verificam daca luna aceasta primeste bonus sau nu
    time_t now = time(0);
    tm *ltm = localtime(&now);
    if (ltm->tm_mon + 1 == month)
    {
        return true;
    }
    return false;
}