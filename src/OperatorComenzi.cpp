#include "OperatorComenzi.h"

OperatorComenzi::OperatorComenzi() : Angajat()
{
}

OperatorComenzi::OperatorComenzi(string nume, string prenume, string CNP, time_t DataAngajare) : Angajat(nume, prenume, CNP, DataAngajare)
{
    CalculeazaSalariu();
}

OperatorComenzi::OperatorComenzi(const OperatorComenzi &operatorcomenzi) : Angajat(operatorcomenzi)
{
}

void OperatorComenzi::AfisareAngajat()
{
    cout << "-------------------------" << endl;
    cout << "Pozitie: Operator comenzi" << endl;
    cout << "-------------------------" << endl;
    Angajat::AfisareAngajat();
    cout << "-------------------------" << endl;
    cout << "Comenzi in lucru: " << endl;
    queue<comanda *> comenzi_copy = comenzi;
    while (!comenzi_copy.empty())
    {
        comenzi_copy.front()->AfisareComanda();
        comenzi_copy.pop();
    }
    cout << "-------------------------" << endl;
    cout << "Istoric comenzi: " << endl;
    priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>> comenzi_istoric_copy = comenzi_istoric;
    while (!comenzi_istoric_copy.empty())
    {
        comenzi_istoric_copy.top()->AfisareComanda();
        comenzi_istoric_copy.pop();
    }
    cout << endl;
}

void OperatorComenzi::CitireAngajat(istream &dev)
{
    Angajat::CitireAngajat(dev);
}

void OperatorComenzi::CalculeazaSalariu()
{
    if (CompletInregistrat() == false)
        return;
    Angajat::CalculeazaSalariu();
    salariu *= 1; // OperatorComenzi are coeficient 1
    if (CheckBirthDay(CNP))
    {
        salariu += 100;
    }
}

void OperatorComenzi::SetCNP(string NPC)
{
    if (!ValidareCNP(NPC))
    {
        cout << "CNP invalid" << endl;
        return;
    }
    CNP = NPC;
    CalculeazaSalariu();
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

void OperatorComenzi::AdaugaComanda(comanda *comanda)
{
    if (comanda->procesabila() == false)
    {
        cout << "Comanda nu poate fi procesata!" << endl;
        return;
    }
    if (comenzi.size() == 3)
    {
        cout << "Operatorul are deja 3 comenzi in lucru!" << endl;
        return;
    }
    comenzi.push(comanda);
}

void OperatorComenzi::SetSalariu(int bonus)
{
    salariu += bonus * 0.005;
}

void OperatorComenzi::StergeComanda()
{
    if (comenzi.size() == 0)
    {
        cout << "Operatorul nu are nicio comanda in lucru!" << endl;
        return;
    }
    comanda *Com = comenzi.front();
    comenzi.pop();
    comenzi_istoric.push(Com);
    SetSalariu(Com->GetTotalFinal());
}

queue<comanda *> OperatorComenzi::GetComenzi()
{
    return comenzi;
}

void OperatorComenzi::SetComenzi(queue<comanda *> comenzi2)
{
    comenzi = comenzi2;
}

priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>> OperatorComenzi::GetIstoricComenzi()
{
    return comenzi_istoric;
}

void OperatorComenzi::setIstoricComenzi(priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>> comenzi_istoric2)
{
    comenzi_istoric = comenzi_istoric2;
}
