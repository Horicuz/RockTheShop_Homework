#pragma once
#include "Produs.h"

class Disc : public Produs
{
protected:
    string casa_de_discuri;
    time_t data_lansare;
    string trupa;
    string album;

public:
    Disc();
    Disc(string, int, float, string, time_t, string, string);
    Disc(const Disc &);
    void AfisareProdus();
    void CitireProdus(istream &);

    void SetCasaDeDisc(string);
    void SetDataLansare(time_t);
    void SetTrupa(string);
    void SetAlbum(string);

    string GetCasaDeDisc();
    time_t GetDataLansare();
    string GetTrupa();
    string GetAlbum();

    bool CompletInregistrat();
    void CalculeazaPret();
};