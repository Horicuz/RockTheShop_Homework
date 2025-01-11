#include "Vinil.h"

Vinil::Vinil() : Disc() {}
Vinil::Vinil(string denumire, int stoc, float baseprice, string casa_de_discuri, time_t data_lansare, string trupa, string album) : Disc(denumire, stoc, baseprice, casa_de_discuri, data_lansare, trupa, album) {}
void Vinil::AfisareProdus()
{
    cout << "-------------------------" << endl;
    cout << "Produs: Vinil" << endl;
    cout << "-------------------------" << endl;
    Disc::AfisareProdus();
}