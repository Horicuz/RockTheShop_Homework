#include "raportari.h"

void topAngajatNrComenzi(map<int, Angajat *> angajati, ofstream &out)
{ // angajatul cu cele mai multe comenzi procesate
    out.close();
    out.open("raport1.csv", ofstream::out | ofstream::trunc);

    int max = -1;
    int id = -1;
    for (auto angajat : angajati)
    {
        if (dynamic_cast<OperatorComenzi *>(angajat.second))
        {
            OperatorComenzi *op = dynamic_cast<OperatorComenzi *>(angajat.second);
            if (op->GetIstoricComenzi().size() > max)
            {
                max = op->GetIstoricComenzi().size();
                id = op->GetID();
            }
        }
    }

    // cream raportul in fisier .csv
    out << "ID,Nume,Prenume,Numar comenzi procesate" << endl;
    out << id << "," << angajati[id]->GetNume() << "," << angajati[id]->GetPrenume() << "," << max << endl;
}

void top3AngajatiComenzi(map<int, Angajat *> angajati, ofstream &out)
{
    // top 3 angajați care au gestionat cele mai valoroase comenzi (în valoare sunt incluse
    // costurile de impachetare și livrare) – ordonați descrescător in funcție de valoarea comenzii
    out.close();
    out.open("raport2.csv", ofstream::out | ofstream::trunc);

    vector<Angajat *> angajati_vec;
    for (auto angajat : angajati)
    {
        angajati_vec.push_back(angajat.second);
    }
    // sortam angajatii dupa numarul de comenzi procesate
    sort(angajati_vec.begin(), angajati_vec.end(), [](Angajat *a, Angajat *b)
         {
        if (dynamic_cast<OperatorComenzi *>(a) && dynamic_cast<OperatorComenzi *>(b))
            return dynamic_cast<OperatorComenzi *>(a)->GetIstoricComenzi().top()->GetTotalFinal() > dynamic_cast<OperatorComenzi *>(b)->GetIstoricComenzi().top()->GetTotalFinal();
        return false; });

    // cream raportul in fisier .csv
    out << "ID,Nume,Prenume,ValoareComanda" << endl;
    for (int i = 0; i < 3; i++)
    {
        out << angajati_vec[i]->GetID() << "," << angajati_vec[i]->GetNume() << "," << angajati_vec[i]->GetPrenume() << "," << dynamic_cast<OperatorComenzi *>(angajati_vec[i])->GetIstoricComenzi().top()->GetTotalFinal() << endl;
    }
}

void top3salariu(map<int, Angajat *> angajati_map, ofstream &out)
{
    out.close();
    out.open("raport3.csv", ofstream::out | ofstream::trunc);

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