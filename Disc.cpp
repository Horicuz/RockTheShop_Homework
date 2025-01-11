#include "Disc.h"

Disc::Disc() : Produs()
{
    casa_de_discuri = "";
    data_lansare = time(0) + 10;
    trupa = "";
    album = "";
}

Disc::Disc(string denumire, int stoc, float baseprice, string casa_de_discuri, time_t data_lansare, string trupa, string album) : Produs(denumire, stoc, baseprice)
{
    this->casa_de_discuri = casa_de_discuri;
    this->data_lansare = data_lansare;
    this->trupa = trupa;
    this->album = album;
    CalculeazaPret();
}

Disc::Disc(const Disc &disc) : Produs(disc)
{
    casa_de_discuri = disc.casa_de_discuri;
    data_lansare = disc.data_lansare;
    trupa = disc.trupa;
    album = disc.album;
}

void Disc::AfisareProdus()
{
    Produs::AfisareProdus();
    cout << "Casa de discuri: " << casa_de_discuri << endl;
    struct tm *timeinfo = localtime(&data_lansare);
    cout << "Data lansare: " << (timeinfo->tm_year + 1900) << "-"
         << (timeinfo->tm_mon + 1) << "-"
         << timeinfo->tm_mday << endl;
    cout << "Trupa: " << trupa << endl;
    cout << "Album: " << album << endl;
    cout << "-------------------------" << endl;
    cout << endl;
}

void Disc::CitireProdus(istream &dev)
{
    Produs::CitireProdus(dev);
    cout << "Casa de discuri: ";
    dev >> casa_de_discuri;
    cout << "Data lansare: ";
    int day, month, year;
    struct tm tm = {0};
    dev >> day >> month >> year;
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900)
    {
        cout << "Data lansarii invalida!" << endl;
        return;
    }
    tm.tm_mday = day;
    tm.tm_mon = month - 1;
    tm.tm_year = year - 1900;
    cout << "Trupa: ";
    dev >> trupa;
    cout << "Album: ";
    dev >> album;
    data_lansare = mktime(&tm);
    CalculeazaPret();
}

void Disc::SetCasaDeDisc(string casa_de_discuri)
{
    this->casa_de_discuri = casa_de_discuri;
}

void Disc::SetDataLansare(time_t data_lansare)
{
    this->data_lansare = data_lansare;
}

void Disc::SetTrupa(string trupa)
{
    this->trupa = trupa;
}

void Disc::SetAlbum(string album)
{
    this->album = album;
}

string Disc::GetCasaDeDisc()
{
    return casa_de_discuri;
}

time_t Disc::GetDataLansare()
{
    return data_lansare;
}

string Disc::GetTrupa()
{
    return trupa;
}

string Disc::GetAlbum()
{
    return album;
}

bool Disc::CompletInregistrat()
{
    if (Produs::CompletInregistrat() == false || casa_de_discuri == "" || data_lansare > time(0) || trupa == "" || album == "")
    {
        return false;
    }
    return true;
}

void Disc::CalculeazaPret()
{
    price = baseprice;
    price += 5; // Discurile au un adaos de 5 lei pentru livrare CD sau Vinil
}