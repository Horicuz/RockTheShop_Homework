#include "raportari.h"

void topAngajatNrComenzi(map<int, Angajat *> angajati, ofstream &out)
{ // angajatul cu cele mai multe comenzi procesate
    out.close();
    out.open("reports/raport1.csv", ofstream::out | ofstream::trunc);

    int max123 = 0;
    int id = -1;
    for (auto angajat : angajati)
    {
        if (dynamic_cast<OperatorComenzi *>(angajat.second))
        {
            OperatorComenzi *op = dynamic_cast<OperatorComenzi *>(angajat.second);
            if (op->GetIstoricComenzi().size() >= max123)
            {
                max123 = op->GetIstoricComenzi().size();
                id = op->GetID();
            }
        }
    }

    // cream raportul in fisier .csv
    if (id == -1)
    {
        cout << "Nu exista nicio comanda procesata!" << endl;
        return;
    }
    out << "ID,Nume,Prenume,Numar comenzi procesate" << endl;
    out << id << "," << angajati[id]->GetNume() << "," << angajati[id]->GetPrenume() << "," << max123 << endl;
}

void top3AngajatiComenzi(map<int, Angajat *> angajati, ofstream &out)
{
    // top 3 angajati care au gestionat cele mai valoroase comenzi (in valoare sunt incluse
    // costurile de impachetare si livrare) – ordonati descrescator in functie de valoarea comenzii
    out.close();
    out.open("reports/raport2.csv", ofstream::out | ofstream::trunc);

    vector<OperatorComenzi *> operatori;
    for (auto angajat : angajati)
    {
        if (dynamic_cast<OperatorComenzi *>(angajat.second))
            if (dynamic_cast<OperatorComenzi *>(angajat.second)->GetIstoricComenzi().size() > 0)
                operatori.push_back(dynamic_cast<OperatorComenzi *>(angajat.second));
    }

    if (operatori.size() < 3)
    {
        cout << "Nu sunt cel putin 3 operatori cu o comanda procesata in istoric!" << endl;
        return;
    }
    // sortam angajatii dupa numarul de comenzi procesate
    sort(operatori.begin(), operatori.end(), [](OperatorComenzi *a, OperatorComenzi *b)
         { return a->GetIstoricComenzi().top()->GetTotalFinal() > b->GetIstoricComenzi().top()->GetTotalFinal(); });

    // cream raportul in fisier .csv
    out << "ID,Nume,Prenume,ValoareComanda" << endl;
    for (int i = 0; i < 3; i++)
    {
        out << operatori[i]->GetID() << "," << operatori[i]->GetNume() << "," << operatori[i]->GetPrenume() << "," << operatori[i]->GetIstoricComenzi().top()->GetTotalFinal() << endl;
    }
}

void top3salariu(map<int, Angajat *> angajati_map, ofstream &out)
{
    out.close();
    out.open("reports/raport3.csv", ofstream::out | ofstream::trunc);

    vector<Angajat *> angajati_vec;
    for (auto angajat : angajati_map)
    { // trademark horicuz
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