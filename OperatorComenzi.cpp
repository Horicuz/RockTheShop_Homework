#include "OperatorComenzi.h"

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
    cout << "-------------------------" << endl;
    cout << "Pozitie: Operator comenzi" << endl;
    cout << "-------------------------" << endl;
    Angajat::AfisareAngajat();
    cout << "-------------------------" << endl;
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
    // se adauga si de la comenzi...
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

int OperatorComenzi::GetComenziCurente()
{
    return comenzi_curente;
}

void OperatorComenzi::AdaugaComanda(comanda *comanda)
{
    if (comanda->procesabila() == false)
    {
        cout << "Comanda nu poate fi procesata!" << endl;
        return;
    }
    if (comenzi_curente == 3)
    {
        cout << "Operatorul are deja 3 comenzi in lucru!" << endl;
        return;
    }
    comenzi.push(comanda);
    comenzi_curente++;
}

void OperatorComenzi::StergeComanda()
{
    if (comenzi_curente == 0)
    {
        cout << "Operatorul nu are nicio comanda in lucru!" << endl;
        return;
    }
    comanda *Com = comenzi.front();
    comenzi.pop();
    comenzi_curente--;
    comenzi_istoric.push(Com);
}
