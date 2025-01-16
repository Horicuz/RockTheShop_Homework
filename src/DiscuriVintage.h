#include "Produs.h"
#pragma once

class DiscuriVintage : public Produs
{
protected:
    bool mint;
    float coeficient_raritate;

public:
    DiscuriVintage();
    DiscuriVintage(string, int, float, bool, float);
    DiscuriVintage(const DiscuriVintage &);
    void AfisareProdus();
    void CitireProdus(istream &);

    void SetMint(bool);
    void SetCoeficientRaritate(float);

    bool GetMint();
    float GetCoeficientRaritate();

    bool CompletInregistrat();
    void CalculeazaPret();
};