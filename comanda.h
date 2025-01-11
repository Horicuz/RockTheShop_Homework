#pragma once
#include "Disc.h"
#include "DiscuriVintage.h"
#include "ArtVest.h"
#include "CD.h"
#include "Vinil.h"
#include <vector>
#include <ctime>
#include <map>

using namespace std;

class comanda
{
    static int counter;
    int ID;
    vector<pair<int, Produs *>> produse; // nr de produse si produsul in sine
    float total_base;
    float total_final;
    time_t data_creare_comanda;
    time_t durata;

public:
    comanda();
    comanda(vector<pair<int, Produs *>>, time_t, time_t);
    comanda(const comanda &);

    void AfisareComanda();
    void CitireComanda(istream &, map<int, Produs *>);

    time_t GetDataCreareComanda();
    time_t GetDurata();
    int GetID();
    vector<pair<int, Produs *>> GetProduse();
    float GetTotalBase();
    float GetTotalFinal();

    void calculeazaBase();
    void calculeazaFinal();
    bool completInregistrat();
    bool procesabila();

    friend bool operator<(const comanda &c1, const comanda &c2)
    {
        return c1.total_final < c2.total_final;
    }

    friend bool operator>(const comanda &c1, const comanda &c2)
    {
        return c1.total_final > c2.total_final;
    }
};