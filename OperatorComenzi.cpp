#include "OperatorComenzi.h"
using namespace std;

OperatorComenzi::OperatorComenzi() : Angajat()
{
}

OperatorComenzi::OperatorComenzi(string nume, string prenume, string CNP, time_t DataAngajare) : Angajat(nume, prenume, CNP, DataAngajare)
{
}

OperatorComenzi::OperatorComenzi(const OperatorComenzi &operatorcomenzi) : Angajat(operatorcomenzi)
{
}

void OperatorComenzi::AfisareAngajat()
{
    cout << "Pozitie: Operator comenzi" << endl;
    cout << "-------------------------" << endl;
    Angajat::AfisareAngajat();
}

void OperatorComenzi::CitireAngajat(istream &dev)
{
    Angajat::CitireAngajat(dev);
}

void OperatorComenzi::CalculeazaSalariu()
{
    Angajat::CalculeazaSalariu();
    salariu *= 1; // OperatorComenzi are coeficient 1
    if (CheckBirthDay(CNP))
    {
        salariu += 100;
    }
    // se adauga si de la comenzi...
}

bool OperatorComenzi::CheckBirthDay(string CNP)
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
