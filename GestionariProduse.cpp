#include "GestionariProduse.h"

void AdaugaProdus(map<int, Produs *> &catalog)
{
    int optiune;
    cout << "1. Articol Vestimentar" << endl;
    cout << "2. CD" << endl;
    cout << "3. Vinil" << endl;
    cout << "4. Disc Vintage" << endl;
    cout << "Introduceti optiunea: ";
    cin >> optiune;
    if (optiune < 1 || optiune > 4)
    {
        cout << "Optiune invalida!" << endl;
    }
    else
    {
        if (optiune == 1)
        {
            ArtVest *artVest = new ArtVest();
            artVest->CitireProdus(cin);
            if (artVest->CompletInregistrat())
            {
                catalog[artVest->GetID()] = artVest;
            }
            return;
        }
        if (optiune == 2)
        {
            CD *cd = new CD();
            cd->CitireProdus(cin);
            if (cd->CompletInregistrat())
            {
                catalog[cd->GetID()] = cd;
            }
            return;
        }
        if (optiune == 3)
        {
            Vinil *vinil = new Vinil();
            vinil->CitireProdus(cin);
            if (vinil->CompletInregistrat())
            {
                catalog[vinil->GetID()] = vinil;
            }
            return;
        }
        if (optiune == 4)
        {
            DiscuriVintage *discuriVintage = new DiscuriVintage();
            discuriVintage->CitireProdus(cin);
            if (discuriVintage->CompletInregistrat())
            {
                catalog[discuriVintage->GetID()] = discuriVintage;
            }
            return;
        }
    }
}

void AfisareProduse(map<int, Produs *> catalog)
{
    if (catalog.size() == 0)
    {
        cout << "Nu exista produse!" << endl;
        return;
    }
    for (auto produs : catalog)
    {
        produs.second->AfisareProdus();
    }
}

void ModificaStocProdus(map<int, Produs *> catalog, int ID)
{
    if (catalog[ID] == NULL)
    {
        cout << "Produsul nu a fost gasit!" << endl;
        return;
    }
    else
    {
        int stoc;
        cout << "Noul stoc: ";
        cin >> stoc;
        catalog[ID]->SetStoc(stoc);
    }
}

void StergeProdus(map<int, Produs *> &catalog, int ID)
{
    if (catalog[ID] == NULL)
    {
        cout << "Produsul nu a fost gasit!" << endl;
        return;
    }
    else
    {
        delete catalog[ID];
        catalog.erase(ID);
    }
}

void AfisareProdus(map<int, Produs *> catalog, int ID)
{
    if (catalog[ID] == NULL)
    {
        cout << "Produsul nu a fost gasit!" << endl;
        return;
    }
    else
    {
        catalog[ID]->AfisareProdus();
    }
}
