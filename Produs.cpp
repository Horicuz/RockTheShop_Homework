#include "Produs.h"

int Produs::counter = 0;

Produs::Produs()
{
    counter++;
    ID = counter;
    denumire = "";
    stoc = -1;
    baseprice = 0;
    price = 0;
}

Produs::Produs(string denumire, int stoc, float baseprice)
{
    try
    {
        if (denumire.length() < 3 || denumire.length() > 30)
        {
            throw std::length_error("Denumirea trebuie sa aiba minim 3 caractere dar nu mai mult de 30");
        }
        if (stoc < 0)
        {
            throw std::invalid_argument("Stocul nu poate fi negativ");
        }
        if (baseprice < 0)
        {
            throw std::invalid_argument("Pretul de baza nu poate fi negativ");
        }
    }
    catch (const std::length_error &e)
    {
        cout << e.what() << endl;
        return;
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl;
        return;
    }
    counter++;
    ID = counter;
    this->denumire = denumire;
    this->stoc = stoc;
    this->baseprice = baseprice;
    CalculeazaPret();
}

Produs::Produs(const Produs &produs)
{
    counter++;
    ID = counter;
    denumire = produs.denumire;
    stoc = produs.stoc;
    baseprice = produs.baseprice;
    price = produs.price;
}

void Produs::AfisareProdus()
{
    cout << "ID: " << ID << endl;
    cout << "Denumire: " << denumire << endl;
    cout << "Stoc: " << stoc << endl;
    cout << "Pret de baza: " << baseprice << endl;
    cout << "Pret: " << price << endl;
}

void Produs::CitireProdus(istream &dev)
{
    string denumire;
    int stoc;
    float baseprice;

    cout << "Denumire: ";
    dev >> denumire;
    if (denumire.length() < 3 || denumire.length() > 30)
    {
        cout << "Denumirea trebuie sa aiba minim 3 caractere dar nu mai mult de 30" << endl;
        return;
    }

    cout << "Stoc: ";
    dev >> stoc;
    if (stoc < 0)
    {
        cout << "Stocul nu poate fi negativ" << endl;
        return;
    }

    cout << "Pret de baza: ";
    dev >> baseprice;
    if (baseprice < 0)
    {
        cout << "Pretul de baza nu poate fi negativ" << endl;
        return;
    }

    this->denumire = denumire;
    this->stoc = stoc;
    this->baseprice = baseprice;
    CalculeazaPret();
}

void Produs::SetDenumire(string denumire)
{
    try
    {
        if (denumire.length() < 3 || denumire.length() > 30)
        {
            throw std::length_error("Denumirea trebuie sa aiba minim 3 caractere dar nu mai mult de 30");
        }
    }
    catch (const std::length_error &e)
    {
        cout << e.what() << endl;
        return;
    }
    this->denumire = denumire;
}

void Produs::SetStoc(int stoc)
{
    try
    {
        if (stoc < 0)
        {
            throw std::invalid_argument("Stocul nu poate fi negativ");
        }
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl;
        return;
    }
    this->stoc = stoc;
}

void Produs::SetBasePrice(float baseprice)
{
    try
    {
        if (baseprice < 0)
        {
            throw std::invalid_argument("Pretul de baza nu poate fi negativ");
        }
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl;
        return;
    }
    this->baseprice = baseprice;
    CalculeazaPret();
}

string Produs::GetDenumire()
{
    return denumire;
}

int Produs::GetStoc()
{
    return stoc;
}

float Produs::GetBasePrice()
{
    return baseprice;
}

float Produs::GetPrice()
{
    return price;
}

int Produs::GetID()
{
    return ID;
}

bool Produs::CompletInregistrat()
{
    if (denumire == "" || stoc == -1 || baseprice == 0)
    {
        return false;
    }
    return true;
}
