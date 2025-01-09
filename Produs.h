#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;

class Produs
{
protected:
    static int counter; // numarul de tipuri de produse
    string denumire;
    int stoc;
    float baseprice;
    float price;
    int ID; // ID este unic

public:
    Produs(); // constructor fara parametri
    Produs(string denumire, int stoc, float baseprice);
    Produs(const Produs &produs); // constructor de copiere
    virtual void AfisareProdus(); // afiseaza datele produsului
    virtual void CitireProdus(istream &dev);

    void SetDenumire(string denumire);
    void SetStoc(int stoc);
    void SetBasePrice(float baseprice);

    string GetDenumire();
    int GetStoc();
    float GetBasePrice();
    float GetPrice();
    int GetID();

    virtual bool CompletInregistrat(); // verifica daca produsul este complet inregistrat
    virtual void CalculeazaPret()      // calculeaza pretul produsului
    {
        price = baseprice;
    }
};
