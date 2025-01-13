#include "raportari.h"
#include "GestionariAngajati.h"
#include "GestionariProduse.h"
#include "GestionariComenzi.h"
#include <cstdlib>

using namespace std;

ofstream raportare1("raport1.csv");
ofstream raportare2("raport2.csv");
ofstream raportare3("raport3.csv");

bool verificaFunctionalitateaMagazinului(map<int, Angajat *> angajati, map<int, Produs *> catalog)
{
    // verificare: minim 1 manager, minim 3 operatori, minim 1 asistent
    int manageri = 0, operatori = 0, asistenti = 0;
    for (auto angajat : angajati)
    {
        if (dynamic_cast<Manager *>(angajat.second))
        {
            manageri++;
        }
        if (dynamic_cast<OperatorComenzi *>(angajat.second))
        {
            operatori++;
        }
        if (dynamic_cast<Asistent *>(angajat.second))
        {
            asistenti++;
        }
    }
    if (manageri < 1 || operatori < 3 || asistenti < 1)
    {
        cout << "Magazinul nu poate functiona!" << endl;
        cout << "Manageri: " << manageri << endl;
        cout << "Operatori: " << operatori << endl;
        cout << "Asistenti: " << asistenti << endl;
        cout << "! Magazinul trebuie sa aiba minim 1 manager, minim 3 operatori si minim 1 asistent !" << endl;
        char c;
        cout << "Apasati orice tasta pentru a continua...";
        cin >> c;
        return false;
    }
    // Dacă magazinul nu are în stoc măcar 2 produse din fiecare tip nu poate funcționa
    int artVest = 0, discuri = 0, discuriVintage = 0;
    for (auto produs : catalog)
    {
        if (dynamic_cast<ArtVest *>(produs.second))
        {
            artVest++;
        }
        if (dynamic_cast<CD *>(produs.second))
        {
            discuri++;
        }
        if (dynamic_cast<Vinil *>(produs.second))
        {
            discuri++;
        }
        if (dynamic_cast<DiscuriVintage *>(produs.second))
        {
            discuriVintage++;
        }
    }

    if (artVest < 2 || discuri < 2 || discuriVintage < 2)
    {
        cout << "Magazinul nu poate functiona!" << endl;
        cout << "Prea putine produse" << endl;
        return false;
    }

    cout << "Magazinul poate functiona!" << endl;
    return true;
}

void gestiuneAngajati(map<int, Angajat *> &angajati)
{
    while (1)
    {
        system("clear");
        cout << "Gestiune angajati" << endl;
        cout << "-----------------" << endl;
        cout << "1. Adauga angajat" << endl;
        cout << "2. Afiseaza toti angajatii" << endl;
        cout << "3. Modificare nume angajat" << endl;
        cout << "4. Sterge angajat" << endl;
        cout << "5. Afiseaza datele unui angajat" << endl;
        cout << "0. Inapoi" << endl;
        cout << "-----------------" << endl;
        cout << "Introduceti optiunea: ";
        int option;
        cin >> option;
        if (option < 0 || option > 5)
        {
            cout << "Optiune invalida! Introduceti optiunea: ";
        }
        if (option == 0)
        {
            return;
        }
        if (option == 1)
        {
            system("clear");
            AdaugaAngajat(angajati);
            cout << "----------------------------------------" << endl;
            cout << "Apasati orice tasta pentru a continua...";
            char c;
            cin >> c;
        }
        if (option == 2)
        {
            system("clear");
            AfisareAngajati(angajati);
            cout << endl;
            cout << "----------------------------------------" << endl;
            cout << "Apasati orice tasta pentru a continua...";
            char c;
            cin >> c;
        }
        if (option == 3)
        {
            system("clear");
            cout << "Introduceti ID-ul angajatului: ";
            int ID;
            cin >> ID;
            ModificaNumeAngajat(angajati, ID);
            cout << endl;
            cout << "----------------------------------------" << endl;
            cout << "Apasati orice tasta pentru a continua...";
            char c;
            cin >> c;
        }
        if (option == 4)
        {
            system("clear");
            cout << "Introduceti ID-ul angajatului: ";
            int ID;
            cin >> ID;
            StergeAngajat(angajati, ID);
            cout << endl;
            cout << "----------------------------------------" << endl;
            cout << "Apasati orice tasta pentru a continua...";
            char c;
            cin >> c;
        }
        if (option == 5)
        {
            system("clear");
            cout << "Introduceti ID-ul angajatului: ";
            int ID;
            cin >> ID;
            AfiseazaDateleUnuiAngajat(angajati, ID);
            cout << endl;
            cout << "----------------------------------------" << endl;
            cout << "Apasati orice tasta pentru a continua...";
            char c;
            cin >> c;
        }
    }
}

void gestiuneStoc(map<int, Produs *> &catalog)
{
    while (1)
    {
        system("clear");
        cout << "Gestiune stoc" << endl;
        cout << "-----------------" << endl;
        cout << "1. Adauga produs" << endl;
        cout << "2. Afiseaza produse" << endl;
        cout << "3. Modifica stoc produs" << endl;
        cout << "4. Sterge produs" << endl;
        cout << "5. Afiseaza produs" << endl;
        cout << "0. Inapoi" << endl;
        cout << "-----------------" << endl;
        cout << "Introduceti optiunea: ";
        int option;
        cin >> option;
        if (option < 0 || option > 5)
        {
            cout << "Optiune invalida! Introduceti optiunea: ";
        }
        if (option == 0)
        {
            return;
        }
        if (option == 1)
        {
            system("clear");
            AdaugaProdus(catalog);
            cout << "----------------------------------------" << endl;
            cout << "Apasati orice tasta pentru a continua...";
            char c;
            cin >> c;
        }
        if (option == 2)
        {
            system("clear");
            AfisareProduse(catalog);
            cout << endl;
            cout << "----------------------------------------" << endl;
            cout << "Apasati orice tasta pentru a continua...";
            char c;
            cin >> c;
        }
        if (option == 3)
        {
            system("clear");
            cout << "Introduceti ID-ul produsului: ";
            int ID;
            cin >> ID;
            ModificaStocProdus(catalog, ID);
            cout << endl;
            cout << "----------------------------------------" << endl;
            cout << "Apasati orice tasta pentru a continua...";
            char c;
            cin >> c;
        }
        if (option == 4)
        {
            system("clear");
            cout << "Introduceti ID-ul produsului: ";
            int ID;
            cin >> ID;
            StergeProdus(catalog, ID);
            cout << endl;
            cout << "----------------------------------------" << endl;
            cout << "Apasati orice tasta pentru a continua...";
            char c;
            cin >> c;
        }
        if (option == 5)
        {
            system("clear");
            cout << "Introduceti ID-ul produsului: ";
            int ID;
            cin >> ID;
            AfisareProdus(catalog, ID);
            cout << endl;
            cout << "----------------------------------------" << endl;
            cout << "Apasati orice tasta pentru a continua...";
            char c;
            cin >> c;
        }
    }
}

void procesareComenzi(map<int, Angajat *> &angajati, priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>> &comenzi, map<int, Produs *> &catalog, time_t &clk, int &proc)
{
    while (1)
    {
        system("clear");
        cout << "Procesare comenzi" << endl;
        cout << "-----------------" << endl;
        cout << "1. Intrare Comenzi (din comenzi.txt)" << endl;
        cout << "2. Afiseaza toate comenzile" << endl;
        cout << "3. Afiseaza comanda (by ID)" << endl;
        cout << "4. Adauga comanda" << endl;
        cout << "5. Sterge comanda (by ID)" << endl;
        cout << " -----------------" << endl;
        cout << "6. INCEPE PROCESAREA!" << endl;
        cout << "0. Inapoi" << endl;
        cout << "-----------------" << endl;
        cout << "Introduceti optiunea: ";
        int option;
        cin >> option;
        if (option < 0 || option > 6)
        {
            cout << "Optiune invalida! Introduceti optiunea: ";
        }
        if (option == 0)
        {
            return;
        }
        if (option == 1)
        {
            ifstream comenzi_text("comenzi.txt");
            system("clear");
            intrareComenzi(comenzi_text, catalog, comenzi);
            comenzi_text.close();
            cout << "Apasati orice tasta pentru a continua...";
            char c;
            cin >> c;
        }
        if (option == 2)
        {
            system("clear");
            AfisareComenzi(comenzi);
            cout << "Apasati orice tasta pentru a continua...";
            char c;
            cin >> c;
        }
        if (option == 3)
        {
            system("clear");
            cout << "Introduceti ID-ul comenzii: ";
            int ID;
            cin >> ID;
            AfisareComanda(comenzi, ID);
            cout << "Apasati orice tasta pentru a continua...";
            char c;
            cin >> c;
        }

        if (option == 4)
        {
            system("clear");
            AdaugaComanda(catalog, comenzi);
            cout << "Apasati orice tasta pentru a continua...";
            char c;
            cin >> c;
        }
        if (option == 5)
        {
            system("clear");
            cout << "Introduceti ID-ul comenzii: ";
            int ID;
            cin >> ID;
            StergeComanda(comenzi, ID);
            cout << "Apasati orice tasta pentru a continua...";
            char c;
            cin >> c;
        }
        if (option == 6)
        {
            if (verificaFunctionalitateaMagazinului(angajati, catalog) == false)
            {
                cout << "NU poti procesa!" << endl;
                cout << "Apasati orice tasta pentru a continua...";
                char c;
                cin >> c;
            }
            while (1)
            {
                system("clear");
                tm *ltm = localtime(&clk);
                int opt;
                cout << "-----------------" << endl;
                cout << "Data si ora curenta: ";
                cout << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << " ";
                cout << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
                cout << "-----------------" << endl;
                cout << "1. Procesare comenzi" << endl;
                cout << "2. Pause and exit" << endl;
                cout << "-----------------" << endl;
                cout << "Introduceti optiunea: ";
                cin >> opt;
                if (opt == 1)
                {
                    Procesare(angajati, comenzi, catalog, clk, proc);
                    char s;
                    cout << "Apasati orice tasta pentru a continua...";
                    cin >> s;
                }
                if (opt == 2)
                {
                    break;
                }
            }
            cout << endl;
            cout << "Apasati orice tasta pentru a continua...";
            char c;
            cin >> c;
        }
    }
}

void raportare(map<int, Angajat *> angajati, map<int, Produs *> catalog)
{
    while (1)
    {
        system("clear");
        cout << "Raportare" << endl;
        cout << "-----------------" << endl;
        cout << "1. Angajatul cu cele mai multe comenzi procesate" << endl;
        cout << "2. Top 3 angajati cu cele mai valoroase comenzi" << endl;
        cout << "3. Top 3 angajati cu cel mai mare salariu" << endl;
        cout << "0. Inapoi" << endl;
        cout << "-----------------" << endl;
        cout << "Introduceti optiunea: ";
        int option;
        cin >> option;
        if (option < 0 || option > 3)
        {
            cout << "Optiune invalida! Introduceti optiunea: ";
        }
        if (option == 0)
        {
            return;
        }
        if (option == 1)
        {
            system("clear");
            topAngajatNrComenzi(angajati, raportare1);
            cout << "Fisierul raport1.csv a fost creat!" << endl;
            cout << "Apasati orice tasta pentru a continua...";
            char c;
            cin >> c;
        }
        if (option == 2)
        {
            system("clear");
            top3AngajatiComenzi(angajati, raportare2);
            cout << "Fisierul raport2.csv a fost creat!" << endl;
            cout << "Apasati orice tasta pentru a continua...";
            char c;
            cin >> c;
        }
        if (option == 3)
        {
            system("clear");
            top3salariu(angajati, raportare3);
            cout << "Fisierul raport3.csv a fost creat!" << endl;
            cout << "Apasati orice tasta pentru a continua...";
            char c;
            cin >> c;
        }
    }
}

void meniu(map<int, Angajat *> &angajati, map<int, Produs *> &catalog, priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>> &comenzi)
{
    time_t clk = time(0);
    int proc = 0;
    while (1)
    {
        system("clear");
        cout << "---Meniu---" << endl;
        cout << "1. Gestiune angajati" << endl;
        cout << "2. Gestiune stoc" << endl;
        cout << "3. Procesare comenzi" << endl;
        cout << "4. Raportare" << endl;
        cout << "5. Verifica functionalitatea magazinului" << endl;
        cout << "0. Iesire" << endl;

        cout << "Introduceti optiunea: ";
        int option;
        cin >> option;
        while (option < 0 || option > 5)
        {
            cout << "Optiune invalida! Introduceti optiunea: ";
            cin >> option;
        }
        if (option == 0)
        {
            cout << "La revedere!" << endl;
            break;
        }
        if (option == 1)
        {
            gestiuneAngajati(angajati);
        }
        if (option == 2)
        {
            gestiuneStoc(catalog);
        }
        if (option == 3)
        {
            procesareComenzi(angajati, comenzi, catalog, clk, proc);
        }
        if (option == 4)
        {
            system("clear");
            raportare(angajati, catalog);
        }
        if (option == 5)
        {
            system("clear");
            verificaFunctionalitateaMagazinului(angajati, catalog);
            cout << "----------------------------------------" << endl;
            cout << "Apasati orice tasta pentru a continua...";
            char c;
            cin >> c;
        }
    }
}

int main()

{ // testare
    map<int, Angajat *> angajati;
    map<int, Produs *> catalog;
    priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>> comenzi{
        [](comanda *a, comanda *b)
        {
            return a->GetDataCreareComanda() > b->GetDataCreareComanda();
        }};

    Manager *Yes = new Manager("John", "Smith", "5050205460021", time(0) - 50000000);
    Asistent *No = new Asistent("Jane", "Doe", "2950101460021", time(0) - 70000000);
    OperatorComenzi *Maybe = new OperatorComenzi("Jinn", "Jarr", "1850202460021", time(0) - 80000000);
    OperatorComenzi *Maybe2 = new OperatorComenzi("Dirr", "Darr", "2750303460021", time(0) - 400000);
    OperatorComenzi *Maybe3 = new OperatorComenzi("Finn", "Farr", "1850202460021", time(0) - 80000000);
    // OperatorComenzi *Maybe4 = new OperatorComenzi("Loey", "Larr", "2750303460021", time(0) - 400000);

    angajati[Yes->GetID()] = Yes;
    angajati[No->GetID()] = No;
    angajati[Maybe->GetID()] = Maybe;
    angajati[Maybe2->GetID()] = Maybe2;
    angajati[Maybe3->GetID()] = Maybe3;
    // angajati[Maybe4->GetID()] = Maybe4;

    Vinil *vinil1 = new Vinil("Vinil1", 1000, 100, "casa1", time(0) - 10000000, "trupa1", "album1");
    CD *cd1 = new CD("CD1", 1000, 150, "casa2", time(0) - 20000000, "trupa2", "album2");
    DiscuriVintage *discuriVintage1 = new DiscuriVintage("DiscuriVintage1", 1050, 25, false, 3);
    ArtVest *artVest1 = new ArtVest("ArtVest1", 100, 35, "culoare1", "marca1");
    ArtVest *artVest2 = new ArtVest("ArtVest2", 500, 35, "culoare2", "marca2");
    DiscuriVintage *discuriVintage2 = new DiscuriVintage("DiscuriVintage2", 350, 25, false, 3);

    catalog[vinil1->GetID()] = vinil1;
    catalog[cd1->GetID()] = cd1;
    catalog[discuriVintage1->GetID()] = discuriVintage1;
    catalog[artVest1->GetID()] = artVest1;
    catalog[artVest2->GetID()] = artVest2;
    catalog[discuriVintage2->GetID()] = discuriVintage2;

    meniu(angajati, catalog, comenzi);

    return 0;
}