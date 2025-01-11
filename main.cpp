#include "raportari.h"
#include "GestionariAngajati.h"
#include "GestionariProduse.h"
#include <cstdlib>

using namespace std;

ofstream raportare1("raport1.csv");
ofstream raportare2("raport2.csv");
ofstream raportare3("raport3.csv");

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
            cout << "Introduceti ID-ul angajatului: ";
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
            cout << "Introduceti ID-ul angajatului: ";
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
            cout << "Introduceti ID-ul angajatului: ";
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

void procesareComenzi()
{
    cout << "Procesare comenzi" << endl;
    cout << "-----------------" << endl;
    cout << "1. Adauga comanda" << endl;
    cout << "2. Afiseaza comenzi" << endl;
    cout << "3. Modifica comanda" << endl;
    cout << "4. Sterge comanda" << endl;
    cout << "0. Inapoi" << endl;
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
            // Angajatul cu cele mai multe comenzi procesate
        }
        if (option == 2)
        {
            // Top 3 angajati cu cele mai valoroase comenzi
        }
        if (option == 3)
        {
            system("clear");
            top3salariu(angajati, raportare3);
            cout << "Raportul a fost generat cu succes!" << endl;
            cout << "Fisierul raport3.csv a fost creat!" << endl;
            cout << "Apasati orice tasta pentru a continua...";
            char c;
            cin >> c;
        }
    }
}

void verificaFunctionalitateaMagazinului(map<int, Angajat *> angajati, map<int, Produs *> catalog)
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
        return;
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
        return;
    }

    cout << "Magazinul poate functiona!" << endl;
    return;
}
void meniu(map<int, Angajat *> angajati, map<int, Produs *> catalog)
{
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
            procesareComenzi();
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

    Manager *Yes = new Manager("John", "Smith", "5050205460021", time(0) - 50000000);
    Asistent *No = new Asistent("Jane", "Doe", "2950101460021", time(0) - 70000000);
    OperatorComenzi *Maybe = new OperatorComenzi("Jinn", "Darr", "1850202460021", time(0) - 80000000);
    OperatorComenzi *Maybe2 = new OperatorComenzi("Joey", "Sarr", "2750303460021", time(0) - 400000);
    OperatorComenzi *Maybe3 = new OperatorComenzi("Jinn", "Darr", "1850202460021", time(0) - 80000000);
    OperatorComenzi *Maybe4 = new OperatorComenzi("Joey", "Sarr", "2750303460021", time(0) - 400000);

    angajati[Yes->GetID()] = Yes;
    angajati[No->GetID()] = No;
    angajati[Maybe->GetID()] = Maybe;
    angajati[Maybe2->GetID()] = Maybe2;
    angajati[Maybe3->GetID()] = Maybe3;
    angajati[Maybe4->GetID()] = Maybe4;

    Vinil *vinil1 = new Vinil("Vinil1", 10, 100, "casa1", time(0) - 10000000, "trupa1", "album1");
    CD *cd1 = new CD("CD1", 10, 150, "casa2", time(0) - 20000000, "trupa2", "album2");
    DiscuriVintage *discuriVintage1 = new DiscuriVintage("DiscuriVintage1", 10, 25, false, 3);
    ArtVest *artVest1 = new ArtVest("ArtVest1", 10, 35, "culoare1", "marca1");

    catalog[vinil1->GetID()] = vinil1;
    catalog[cd1->GetID()] = cd1;
    catalog[discuriVintage1->GetID()] = discuriVintage1;
    catalog[artVest1->GetID()] = artVest1;

    // angajati[1] = new OperatorComenzi("Jane", "Does", "2950101460021", time(0) - 50000000);
    // angajati[2] = new OperatorComenzi("Jinn", "Darr", "1850202460021", time(0) - 70000000);
    // angajati[3] = new OperatorComenzi("Joey", "Sarr", "2750303460021", time(0) - 80000000);
    // angajati[4] = new Asistent("Assistent", "John", "1650404460021", time(0) - 400000);

    // Asistent Horia;
    // Horia.CitireAngajat(cin);
    // Horia.AfisareAngajat();
    // Horia.SetNume("Mihai");
    // Horia.SetCNP("5020102460021");
    // Horia.AfisareAngajat();
    // Horia.SetCNP("5050101460021");
    // Horia.SetDataAngajare(time(0));
    // Horia.AfisareAngajat();
    // angajati[5] = new Asistent(Horia);
    // angajati[6] = &Horia; // nu asa se adauga in vector

    // for (auto angajat : angajati)
    // {
    //     angajat->AfisareAngajat();
    // }

    vector<Angajat *> AngajatiMagazin;

    meniu(angajati, catalog);

    return 0;
}