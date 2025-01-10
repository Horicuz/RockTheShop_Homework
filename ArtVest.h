#pragma once
#include "Produs.h"

class ArtVest : public Produs
{
protected:
    string culoarea;
    string marca;

public:
    ArtVest();
    ArtVest(string, int, float, string, string);
    ArtVest(const ArtVest &);
    void AfisareProdus();
    void CitireProdus(istream &);

    void SetCuloare(string);
    void SetMarca(string);

    string GetCuloare();
    string GetMarca();

    bool CompletInregistrat();
    void CalculeazaPret();
};