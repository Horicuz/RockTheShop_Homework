#include "ArtVest.h"

ArtVest::ArtVest() : Produs()
{
    culoarea = "";
    marca = "";
}

ArtVest::ArtVest(string denumire, int stoc, float baseprice, string culoarea, string marca) : Produs(denumire, stoc, baseprice)
{
    this->culoarea = culoarea;
    this->marca = marca;
}

ArtVest::ArtVest(const ArtVest &artvest) : Produs(artvest)
{
    culoarea = artvest.culoarea;
    marca = artvest.marca;
}

void ArtVest::AfisareProdus()
{
    cout << "-------------------------" << endl;
    cout << "Produs: Articol vestimentar" << endl;
    cout << "-------------------------" << endl;
    Produs::AfisareProdus();
    cout << "Culoare: " << culoarea << endl;
    cout << "Marca: " << marca << endl;
    cout << "-------------------------" << endl;
}

void ArtVest::CitireProdus(istream &dev)
{
    Produs::CitireProdus(dev);
    cout << "Culoare: ";
    dev >> culoarea;
    cout << "Marca: ";
    dev >> marca;
}

void ArtVest::SetCuloare(string culoare)
{
    this->culoarea = culoare;
}

void ArtVest::SetMarca(string marca)
{
    this->marca = marca;
}

string ArtVest::GetCuloare()
{
    return culoarea;
}

string ArtVest::GetMarca()
{
    return marca;
}

bool ArtVest::CompletInregistrat()
{
    if (Produs::CompletInregistrat() == false)
        return false;
    if (culoarea.length() < 3 || culoarea.length() > 30)
    {
        cout << "Culoarea trebuie sa aiba minim 3 caractere dar nu mai mult de 30" << endl;
        return false;
    }
    if (marca.length() < 3 || marca.length() > 30)
    {
        cout << "Marca trebuie sa aiba minim 3 caractere dar nu mai mult de 30" << endl;
        return false;
    }
    return true;
}

void ArtVest::CalculeazaPret()
{
    Produs::CalculeazaPret();
    price += 20; // ArtVest are un adaos de 20 lei pentru livrare
}
