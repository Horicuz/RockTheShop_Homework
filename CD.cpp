#include "CD.h"

CD::CD() : Disc() {}
CD::CD(string denumire, int stoc, float baseprice, string casa_de_discuri, time_t data_lansare, string trupa, string album) : Disc(denumire, stoc, baseprice, casa_de_discuri, data_lansare, trupa, album) {}
void CD::AfisareProdus()
{
    cout << "-------------------------" << endl;
    cout << "Produs: CD" << endl;
    cout << "-------------------------" << endl;
    Disc::AfisareProdus();
}