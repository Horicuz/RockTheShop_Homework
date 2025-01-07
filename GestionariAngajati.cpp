#include "GestionariAngajati.h"

void AdaugaAngajat(vector<Angajat *> &angajati)
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
                angajati.push_back(manager);
            }
            return;
        }
        if (optiune == 2)
        {
            OperatorComenzi *operatorComenzi = new OperatorComenzi();
            operatorComenzi->CitireAngajat(cin);
            if (operatorComenzi->CompletInregistrat())
            {
                angajati.push_back(operatorComenzi);
            }
            return;
        }
        if (optiune == 3)
        {
            Asistent *asistent = new Asistent();
            asistent->CitireAngajat(cin);
            if (asistent->CompletInregistrat())
            {
                angajati.push_back(asistent);
            }
            return;
        }
    }
}

void AfisareAngajati(vector<Angajat *> angajati)
{
    if (angajati.size() == 0)
    {
        cout << "Nu exista angajati!" << endl;
        return;
    }
    for (auto angajat : angajati)
    {
        angajat->AfisareAngajat();
    }
}

void ModificaNumeAngajat(vector<Angajat *> angajati, int ID)
{
    for (auto angajat : angajati)
    {
        if (angajat->GetID() == ID)
        {
            string nume;
            cout << "Noul nume: ";
            cin >> nume;
            angajat->SetNume(nume);
            return;
        }
    }
    cout << "Angajatul nu a fost gasit!" << endl;
}

void StergeAngajat(vector<Angajat *> &angajati, int ID)
{
    for (int i = 0; i < angajati.size(); i++)
    {
        if (angajati[i]->GetID() == ID)
        {
            angajati.erase(angajati.begin() + i);
            return;
        }
    }
    cout << "Angajatul nu a fost gasit!" << endl;
}

void AfiseazaDateleUnuiAngajat(vector<Angajat *> angajati, int ID)
{
    for (auto angajat : angajati)
    {
        if (angajat->GetID() == ID)
        {
            angajat->AfisareAngajat();
            return;
        }
    }
    cout << "Angajatul nu a fost gasit!" << endl;
}
