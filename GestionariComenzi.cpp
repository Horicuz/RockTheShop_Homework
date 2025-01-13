#include "GestionariComenzi.h"

void intrareComenzi(ifstream &dev, map<int, Produs *> catalog, priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>> &comenzi)
{
    int nr_comenzi;
    dev >> nr_comenzi;
    for (int i = 0; i < nr_comenzi; i++)
    {
        comanda *com = new comanda();
        com->CitireComanda(dev, catalog);
        if (com->completInregistrat())
        {
            comenzi.push(com);
        }
        else
        {
            cout << "Comanda nu s-a putut inregistra!" << endl;
            delete com;
        }
    }
}

void AfisareComenzi(priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>> comenzi)
{
    priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>> comenzi_copy = comenzi;
    while (!comenzi_copy.empty())
    {
        comenzi_copy.top()->AfisareComanda();
        comenzi_copy.pop();
    }
}
void AfisareComanda(priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>> comenzi, int id)
{
    priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>> comenzi_copy = comenzi;
    while (!comenzi_copy.empty())
    {
        if (comenzi_copy.top()->GetID() == id)
        {
            comenzi_copy.top()->AfisareComandaDetaliata();
            return;
        }
        comenzi_copy.pop();
    }
    cout << "Comanda nu exista!" << endl;
}

void AdaugaComanda(map<int, Produs *> catalog, priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>> &comenzi)
{
    comanda *com = new comanda();
    com->CitireComandaAcum(cin, catalog);
    if (com->completInregistrat())
    {
        comenzi.push(com);
    }
    else
    {
        cout << "Comanda nu s-a putut inregistra!" << endl;
        delete com;
    }
}

void StergeComanda(priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>> &comenzi, int id)
{
    vector<comanda *> aux;
    while (!comenzi.empty())
    {
        if (comenzi.top()->GetID() != id)
        {
            aux.push_back(comenzi.top());
        }
        comenzi.pop();
    }
    for (auto &i : aux)
    {
        comenzi.push(i);
    }
}

void Procesare(map<int, Angajat *> &angajati, priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>> &comenzi, map<int, Produs *> &catalog, time_t &clock, int &proc)
{

    if (comenzi.empty())
    {
        proc = 1;
    }
    if (proc == 1) // suntem in stadiul in care operatorii nu mai pot primi comenzi si trebuie sa asteptam sa livreze
    {
        int ok = 0;
        clock += 3600;
        for (auto angajat : angajati)
        {
            if (dynamic_cast<OperatorComenzi *>(angajat.second))
            {
                if (dynamic_cast<OperatorComenzi *>(angajat.second)->GetComenzi().size() > 0)
                {
                    ok = 1;
                    OperatorComenzi *op = dynamic_cast<OperatorComenzi *>(angajat.second);
                    if (op->GetComenzi().front()->GetDurata() == 3600)
                    {
                        comanda *com = op->GetComenzi().front();
                        op->StergeComanda();
                        cout << "A fost finalizata comanda: " << endl;
                        com->AfisareComanda();
                        cout << "De la operatorul: " << op->GetNume() << " " << op->GetPrenume() << endl;
                        cout << "-------------------------" << endl;
                        cout << endl;
                        delete com;
                        proc = 0;
                    }
                    else
                    {
                        op->GetComenzi().front()->SetDurata();
                        cout << "Asteptam... (+ 1h)" << endl;
                    }
                }
            }
        }
        if (ok == 0)
        {
            proc = 0;
            cout << "Nu mai sunt comenzi nici in curs de procesare nici in asteptare!" << endl;
            cout << "Mai adauga alte comenzi!" << endl;
        }

        return;
    }
    if (proc == 0) // suntem in stadiul in care presupunem ca putem incarca un operator cu o comanda
    {
        int gasit = -1;
        int min = 3;
        for (auto angajat : angajati)
        {
            if (dynamic_cast<OperatorComenzi *>(angajat.second))
            {
                if (dynamic_cast<OperatorComenzi *>(angajat.second)->GetComenzi().size() < min)
                {
                    min = dynamic_cast<OperatorComenzi *>(angajat.second)->GetComenzi().size();
                    gasit = angajat.first;
                }
            }
        }
        if (gasit == -1)
        {
            cout << "Momentan nu se mai poate procesa nicio comanda!" << endl;
            proc = 1; // suntem in stadiul in care toti operatorii au deja 3 comenzi
        }
        else
        {
            OperatorComenzi *op = dynamic_cast<OperatorComenzi *>(angajati[gasit]);
            // queue<comanda *> aux = op->GetComenzi();
            // priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>> aux2{
            //     [](comanda *a, comanda *b)
            //     {
            //         return a->GetTotalFinal() < b->GetTotalFinal();
            //     }};
            // aux2 = op->GetIstoricComenzi();
            comanda *com = comenzi.top();
            if (com->procesabila() == false)
            {
                cout << "O comanda nu este procesabila! (A fost stearsa!)" << endl;
                cout << "Proceseaza din nou comenzile!" << endl;
                comenzi.pop();
                return;
            }
            comenzi.pop();
            op->AdaugaComanda(com);
            cout << "S-a adaugat comanda " << endl;
            com->AfisareComanda();
            cout << "La operatorul " << op->GetNume() << " " << op->GetPrenume() << endl;
            cout << "care are momentan: " << op->GetComenzi().size() << " comenzi in lucru" << endl;

            for (auto produs : com->GetProduse())
            {
                catalog[produs.second->GetID()]->SetStoc(catalog[produs.second->GetID()]->GetStoc() - produs.first);
            }
        }
    }
}
