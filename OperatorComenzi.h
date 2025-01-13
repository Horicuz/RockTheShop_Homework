#pragma once
#include "Angajat.h"
#include "comanda.h"
#include <queue>
#include <functional>

using namespace std;

class OperatorComenzi : public Angajat
{
    queue<comanda *> comenzi;
    priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>> comenzi_istoric{
        [](comanda *a, comanda *b)
        {
            return a->GetTotalFinal() < b->GetTotalFinal();
        }};

public:
    OperatorComenzi();
    OperatorComenzi(string, string, string, time_t);
    OperatorComenzi(const OperatorComenzi &);
    void AfisareAngajat();
    void CitireAngajat(istream &);
    void SetCNP(string);
    void CalculeazaSalariu();
    bool CheckBirthDay(string);

    queue<comanda *> GetComenzi();
    void SetComenzi(queue<comanda *>);
    priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>> GetIstoricComenzi();
    void setIstoricComenzi(priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>>);

    void AdaugaComanda(comanda *);
    void StergeComanda();
};
