#include "Angajat.h"
#include "comanda.h"
#include <queue>
#pragma once

using namespace std;

class OperatorComenzi : public Angajat
{
    queue<comanda *> comenzi;
    vector<comanda *> comenzi_istoric;
    int comenzi_curente = 0;

public:
    OperatorComenzi();
    OperatorComenzi(string, string, string, time_t);
    OperatorComenzi(const OperatorComenzi &);
    void AfisareAngajat();
    void CitireAngajat(istream &);
    void SetCNP(string);
    void CalculeazaSalariu();
    bool CheckBirthDay(string);

    int GetComenziCurente();
    void AdaugaComanda(comanda *);
    void StergeComanda();
};