#include "Manager.h"

Manager::Manager()
{
}

Manager::Manager(string nume, string prenume, string CNP, time_t DataAngajare) : Angajat(nume, prenume, CNP, DataAngajare)
{
}

Manager::Manager(const Manager &manager) : Angajat(manager)
{
}

void Manager::AfisareAngajat()
{
    cout << "Pozitie: Manager" << endl;
    cout << "-------------------------" << endl;
    Angajat::AfisareAngajat();
}

void Manager::CitireAngajat(istream &dev)
{
    Angajat::CitireAngajat(dev);
}

void Manager::CalculeazaSalariu()
{
    Angajat::CalculeazaSalariu();
    salariu *= 1.25; // Manager are coeficient 1.25
}
