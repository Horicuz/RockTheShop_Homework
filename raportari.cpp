#include "raportari.h"

void top3salariu(vector<Angajat *> angajati, ofstream &out)
{
    vector<Angajat *> top3(3, 0);
    for (int i = 0; i < angajati.size(); i++)
    {
        if (angajati[i]->GetSalariu() > top3[0]->GetSalariu())
        {
            top3[2] = top3[1];
            top3[1] = top3[0];
            top3[0] = angajati[i];
        }
        else if (angajati[i]->GetSalariu() > top3[1]->GetSalariu())
        {
            top3[2] = top3[1];
            top3[1] = angajati[i];
        }
        else if (angajati[i]->GetSalariu() > top3[2]->GetSalariu())
        {
            top3[2] = angajati[i];
        }
    }

    // Ordonare alfabetica top3
    for (int i = 0; i < 2; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (top3[i]->GetSalariu() == top3[j]->GetSalariu())
            {
                if (top3[i]->GetNume() > top3[j]->GetNume())
                {
                    Angajat *aux = top3[i];
                    top3[i] = top3[j];
                    top3[j] = aux;
                }
                else if (top3[i]->GetNume() == top3[j]->GetNume())
                {
                    if (top3[i]->GetPrenume() > top3[j]->GetPrenume())
                    {
                        Angajat *aux = top3[i];
                        top3[i] = top3[j];
                        top3[j] = aux;
                    }
                }
            }
        }
    }

    // cream raportul in fisier .csv
    out << "Nume,Prenume,Salariu" << endl;
    for (int i = 0; i < 3; i++)
    {
        out << top3[i]->GetNume() << "," << top3[i]->GetPrenume() << "," << top3[i]->GetSalariu() << endl;
    }
}