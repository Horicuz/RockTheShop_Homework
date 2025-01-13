#include "GestionariAngajati.h"

void AdaugaAngajat(map<int, Angajat *> &angajati)
{
    int optiune;
    cout << "1. Manager" << endl;
    cout << "2. Operator comenzi" << endl;
    cout << "3. Asistent" << endl;
    cout << "Introduceti optiunea: ";
    cin >> optiune;
    if (optiune < 1 || optiune > 3)
    {
        cout << "Optiune invalida!" << endl;
    }
    else
    {
        if (optiune == 1)
        {
            Manager *manager = new Manager();
            manager->CitireAngajat(cin);
            if (manager->CompletInregistrat())
            {
                angajati[manager->GetID()] = manager;
            }
            else
            {
                delete manager;
            }
            return;
        }
        if (optiune == 2)
        {
            OperatorComenzi *operatorComenzi = new OperatorComenzi();
            operatorComenzi->CitireAngajat(cin);
            if (operatorComenzi->CompletInregistrat())
            {
                angajati[operatorComenzi->GetID()] = operatorComenzi;
            }
            else
            {
                delete operatorComenzi;
            }
            return;
        }
        if (optiune == 3)
        {
            Asistent *asistent = new Asistent();
            asistent->CitireAngajat(cin);
            if (asistent->CompletInregistrat())
            {
                angajati[asistent->GetID()] = asistent;
            }
            else
            {
                delete asistent;
            }
            return;
        }
    }
}

void AfisareAngajati(map<int, Angajat *> angajati)
{
    if (angajati.size() == 0)
    {
        cout << "Nu exista angajati!" << endl;
        return;
    }
    for (auto angajat : angajati)
    {
        angajat.second->AfisareAngajat();
    }
}

void ModificaNumeAngajat(map<int, Angajat *> angajati, int ID)
{
    if (angajati.find(ID) != angajati.end())
    {
        angajati[ID]->CitireAngajat(cin);
        return;
    }
    else
    {
        cout << "Angajatul nu a fost gasit!" << endl;
    }
}

void StergeAngajat(map<int, Angajat *> &angajati, int ID)
{
    if (angajati.find(ID) != angajati.end())
    {
        angajati.erase(ID);
        return;
    }
    else
    {
        cout << "Angajatul nu a fost gasit!" << endl;
    }
}

void AfiseazaDateleUnuiAngajat(map<int, Angajat *> angajati, int ID)
{
    if (angajati.find(ID) != angajati.end())
    {
        angajati[ID]->AfisareAngajat();
        return;
    }
    else
    {
        cout << "Angajatul nu a fost gasit!" << endl;
    }
}
