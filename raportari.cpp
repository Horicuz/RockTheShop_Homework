#include "raportari.h"

void top3salariu(vector<Angajat *> angajati, ofstream &out)
{
    // sortam angajatii dupa salariu
    sort(angajati.begin(), angajati.end(), [](Angajat *a, Angajat *b)
         {
        if (a->GetSalariu() != b->GetSalariu())
            return a->GetSalariu() > b->GetSalariu();
        if (a->GetNume() != b->GetNume())
            return a->GetNume() < b->GetNume();
        return a->GetPrenume() < b->GetPrenume(); });

    // cream raportul in fisier .csv
    out << "Nume,Prenume,Salariu" << endl;
    for (int i = 0; i < 3; i++)
    {
        out << angajati[i]->GetNume() << "," << angajati[i]->GetPrenume() << "," << angajati[i]->GetSalariu() << endl;
    }
}