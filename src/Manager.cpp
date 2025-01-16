#include "Manager.h"

Manager::Manager()
{
}

Manager::Manager(string nume, string prenume, string CNP, time_t DataAngajare) : Angajat(nume, prenume, CNP, DataAngajare)
{
    CalculeazaSalariu();
}

Manager::Manager(const Manager &manager) : Angajat(manager)
{
}

void Manager::AfisareAngajat()
{
    cout << "-------------------------" << endl;
    cout << "Pozitie: Manager" << endl;
    cout << "-------------------------" << endl;
    Angajat::AfisareAngajat();
    cout << "-------------------------" << endl;
    cout << endl;
}

void Manager::CitireAngajat(istream &dev)
{
    Angajat::CitireAngajat(dev);
}

void Manager::SetCNP(string NPC)
{
    if (!ValidareCNP(NPC))
    {
        cout << "CNP invalid" << endl;
        return;
    }
    CNP = NPC;
}

void Manager::CalculeazaSalariu()
{
    if (CompletInregistrat() == false)
        return;
    Angajat::CalculeazaSalariu();
    salariu *= 1.25; // Manager are coeficient 1.25
}
