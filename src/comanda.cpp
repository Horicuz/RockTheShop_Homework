#include "comanda.h"

int comanda::counter = 0;

comanda::comanda()
{
    counter++;
    ID = counter;
    total_base = 0;
    total_final = 0;
    data_creare_comanda;
    durata = -1;
}

comanda::comanda(vector<pair<int, Produs *>> produse, time_t data_creare_comanda, time_t durata)
{
    counter++;
    ID = counter;
    this->produse = produse;
    this->data_creare_comanda = data_creare_comanda;
    if (durata < 0 || durata > 100 * 3600)
    {
        cout << "Durata invalida!" << endl;
        return;
    }
    this->durata = durata;
    calculeazaBase();
    calculeazaFinal();
}

comanda::comanda(const comanda &comanda)
{
    counter++;
    ID = counter;
    produse = comanda.produse;
    total_base = comanda.total_base;
    total_final = comanda.total_final;
    data_creare_comanda = comanda.data_creare_comanda;
    durata = comanda.durata;
}

void comanda::AfisareComandaDetaliata()
{
    cout << "-------------------------" << endl;
    cout << "Comanda: " << ID << endl;
    cout << "-------------------------" << endl;
    cout << "Data creare comanda: ";
    struct tm *timeinfo = localtime(&data_creare_comanda);
    cout << (timeinfo->tm_year + 1900) << "-"
         << (timeinfo->tm_mon + 1) << "-"
         << timeinfo->tm_mday << endl;
    cout << "Durata: " << durata / 3600 << " ore" << endl;
    cout << "-------------------------" << endl;
    cout << "Produse comandate: " << endl;
    for (auto &i : produse)
    {
        cout << "-------------------------" << endl;
        cout << "Produs: " << i.second->GetDenumire() << endl;
        cout << "Numar exemplare comandate: " << i.first << endl;
        cout << "Pret unitar: " << i.second->GetPrice() << " RON" << endl;
        cout << "Pret total: " << i.first * i.second->GetPrice() << " RON" << endl;
        cout << "-------------------------" << endl;
    }
    cout << "Total base: " << total_base << " RON" << endl;
    cout << "Total final: " << total_final << " RON" << endl;
    cout << "-------------------------" << endl;
    cout << endl;
}

void comanda::AfisareComanda()
{
    cout << "-------------------------" << endl;
    cout << "Comanda: " << ID << endl;
    cout << "-------------------------" << endl;
    cout << "Data creare comanda: ";
    struct tm *timeinfo = localtime(&data_creare_comanda);
    cout << (timeinfo->tm_year + 1900) << "-"
         << (timeinfo->tm_mon + 1) << "-"
         << timeinfo->tm_mday << endl;
    cout << "Durata: " << durata / 3600 << " ore" << endl;
    cout << "Total base: " << total_base << " RON" << endl;
    cout << "Total final: " << total_final << " RON" << endl;
    cout << "-------------------------" << endl;
    cout << endl;
}

void comanda::CitireComanda(istream &dev, map<int, Produs *> catalog)
{
    int nr_produse;
    // cout << "Numar produse: ";
    dev >> nr_produse;
    if (nr_produse < 1)
    {
        cout << "Numar produse invalid!" << endl;
        return;
    }
    for (int i = 0; i < nr_produse; i++)
    {
        int ID;
        // cout << "ID produs: ";
        dev >> ID;
        if (catalog.find(ID) == catalog.end())
        {
            cout << "Produsul nu exista!" << endl;
            return;
        }
        Produs *produs = catalog[ID];
        int nr;
        // cout << "Numar exemplare produs dorit: ";
        dev >> nr;
        produse.push_back(make_pair(nr, produs));
    }
    int day1, month1, year1;
    // cout << "Data creare comanda: ";
    dev >> day1 >> month1 >> year1;
    if (day1 < 1 || day1 > 31 || month1 < 1 || month1 > 12 || year1 < 1900)
    {
        cout << "Data invalida!" << endl;
        return;
    }
    struct tm tm = {0};
    tm.tm_mday = day1;
    tm.tm_mon = month1 - 1;
    tm.tm_year = year1 - 1900;
    data_creare_comanda = mktime(&tm);
    int hours;
    // cout << "Durata: ";
    dev >> hours;
    if (hours < 1)
    {
        cout << "Durata invalida!" << endl;
        return;
    }

    durata = hours * 3600;
    calculeazaBase();
    calculeazaFinal();
}

void comanda::CitireComandaAcum(istream &dev, map<int, Produs *> catalog)
{
    int nr_produse;
    cout << "Numar produse: ";
    dev >> nr_produse;
    if (nr_produse < 1)
    {
        cout << "Numar produse invalid!" << endl;
        return;
    }
    for (int i = 0; i < nr_produse; i++)
    {
        int ID;
        cout << "ID produs: ";
        dev >> ID;
        if (catalog.find(ID) == catalog.end())
        {
            cout << "Produsul nu exista!" << endl;
            return;
        }
        Produs *produs = catalog[ID];
        int nr;
        cout << "Numar exemplare produs dorit: ";
        dev >> nr;
        produse.push_back(make_pair(nr, produs));
    }
    int hours;
    cout << "Durata: ";
    dev >> hours;
    if (hours < 1)
    {
        cout << "Durata invalida!" << endl;
        return;
    }
    durata = hours * 3600;
    time_t now = time(0);
    struct tm *ltm = localtime(&now);
    data_creare_comanda = mktime(ltm);
    calculeazaBase();
    calculeazaFinal();
}

time_t comanda::GetDataCreareComanda()
{
    return data_creare_comanda;
}

time_t comanda::GetDurata()
{
    return durata;
}

void comanda::SetDurata()
{
    durata = durata - 3600;
}

int comanda::GetID()
{
    return ID;
}

vector<pair<int, Produs *>> comanda::GetProduse()
{
    return produse;
}

float comanda::GetTotalBase()
{
    return total_base;
}

float comanda::GetTotalFinal()
{
    return total_final;
}

void comanda::calculeazaBase()
{
    total_base = 0;
    for (auto &i : produse)
    {
        total_base += i.first * i.second->GetBasePrice();
    }
}

void comanda::calculeazaFinal()
{
    total_final = 0;
    for (auto &i : produse)
    {
        total_final += i.first * i.second->GetPrice();
    }
}

bool comanda::completInregistrat()
{
    if (produse.size() == 0 || durata == -1)
    {
        return false;
    }
    return true;
}

bool comanda::procesabila()
{
    if (completInregistrat() == false)
    {
        cout << "Comanda nu este complet inregistrata!" << endl;
        return false;
    }
    int discuri = 0; // si discuri normale(CD sau VINIL) si discuri vintage
    int art_vest = 0;
    for (auto &i : produse)
    {
        if (i.second->GetStoc() < i.first)
        {
            cout << "Stoc insuficient pentru produsul: " << i.second->GetDenumire() << endl;
            return false;
        }
        if (dynamic_cast<Vinil *>(i.second) != nullptr)
        {
            discuri++;
            if (discuri > 5)
            {
                cout << "Prea multe discuri!" << endl;
                return false;
            }
        }
        if (dynamic_cast<CD *>(i.second) != nullptr)
        {
            discuri++;
            if (discuri > 5)
            {
                cout << "Prea multe discuri!" << endl;
                return false;
            }
        }
        if (dynamic_cast<DiscuriVintage *>(i.second) != nullptr)
        {
            discuri++;
            if (discuri > 5)
            {
                cout << "Prea multe discuri!" << endl;
                return false;
            }
        }
        if (dynamic_cast<ArtVest *>(i.second) != nullptr)
        {
            art_vest++;
            if (art_vest > 3)
            {
                cout << "Prea multe articole vestimentare!" << endl;
                return false;
            }
        }
    }
    if (total_base < 100)
    {
        cout << "Comanda prea mica!" << endl;
        return false;
    }
    return true;
}