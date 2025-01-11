#include "DiscuriVintage.h"

DiscuriVintage::DiscuriVintage() : Produs()
{
    mint = false;
    coeficient_raritate;
}

DiscuriVintage::DiscuriVintage(string denumire, int stoc, float baseprice, bool mint, float coeficient_raritate) : Produs(denumire, stoc, baseprice)
{
    this->mint = mint;
    try
    {
        if (coeficient_raritate < 0 || coeficient_raritate > 5)
        {
            throw std::invalid_argument("Coeficientul de raritate trebuie sa fie intre 0 si 5");
        }
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl;
        return;
    }
    this->coeficient_raritate = coeficient_raritate;
    CalculeazaPret();
}

DiscuriVintage::DiscuriVintage(const DiscuriVintage &discuri) : Produs(discuri)
{
    mint = discuri.mint;
    coeficient_raritate = discuri.coeficient_raritate;
}

void DiscuriVintage::AfisareProdus()
{
    cout << "-------------------------" << endl;
    cout << "Produs: Discuri vintage" << endl;
    cout << "-------------------------" << endl;
    Produs::AfisareProdus();
    cout << "Mint: " << mint << endl;
    cout << "Coeficient raritate: " << coeficient_raritate << endl;
    cout << "-------------------------" << endl;
    cout << endl;
}

void DiscuriVintage::CitireProdus(istream &dev)
{
    float coef;
    Produs::CitireProdus(dev);
    cout << "Mint (1/0): ";
    dev >> mint;
    cout << "Coeficient raritate: ";
    dev >> coef;
    if (coef < 0 || coef > 5)
    {
        cout << "Coeficientul de raritate trebuie sa fie intre 0 si 5" << endl;
        return;
    }
    coeficient_raritate = coef;
    CalculeazaPret();
}

void DiscuriVintage::SetMint(bool mint)
{
    this->mint = mint;
}

void DiscuriVintage::SetCoeficientRaritate(float coeficient_raritate)
{
    try
    {
        if (coeficient_raritate < 0 || coeficient_raritate > 5)
        {
            throw std::invalid_argument("Coeficientul de raritate trebuie sa fie intre 0 si 5");
        }
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl;
        return;
    }
    this->coeficient_raritate = coeficient_raritate;
}

bool DiscuriVintage::GetMint()
{
    return mint;
}

float DiscuriVintage::GetCoeficientRaritate()
{
    return coeficient_raritate;
}

bool DiscuriVintage::CompletInregistrat()
{
    if (Produs::CompletInregistrat() == false)
        return false;
    if (coeficient_raritate == -1)
    {
        cout << "Coeficientul de raritate trebuie sa fie intre 0 si 5" << endl;
        return false;
    }
    return true;
}

void DiscuriVintage::CalculeazaPret()
{
    if (CompletInregistrat() == false)
        return;
    price = baseprice;
    price = price + 15 * coeficient_raritate;
}
