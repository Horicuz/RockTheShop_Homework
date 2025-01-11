#include "raportari.h"

void topAngajatNrComenzi(vector<Angajat *> angajati, ofstream &out)
{
    for (auto angajat : angajati)
    {
        if (dynamic_cast<OperatorComenzi *>(angajat))
        {
        }
    }
}
void top3salariu(map<int, Angajat *> angajati_map, ofstream &out)
{
    vector<Angajat *> angajati_vec;
    for (auto angajat : angajati_map)
    {
        angajati_vec.push_back(angajat.second);
    }
    // sortam angajatii dupa salariu
    sort(angajati_vec.begin(), angajati_vec.end(), [](Angajat *a, Angajat *b)
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
        out << angajati_vec[i]->GetNume() << "," << angajati_vec[i]->GetPrenume() << "," << angajati_vec[i]->GetSalariu() << endl;
    }
}