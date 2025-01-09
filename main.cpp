#include "raportari.h"
#include "GestionariAngajati.h"
#include <cstdlib>

using namespace std;

ofstream raportare1("raport1.csv");
ofstream raportare2("raport2.csv");
ofstream raportare3("raport3.csv");

void gestiuneAngajati(vector<Angajat *> angajati)
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

void gestiuneStoc()
{
    cout << "Gestiune stoc" << endl;
    cout << "-----------------" << endl;
    cout << "1. Adauga produs" << endl;
    cout << "2. Afiseaza produse" << endl;
    cout << "3. Modifica produs" << endl;
    cout << "4. Sterge produs" << endl;
    cout << "0. Inapoi" << endl;
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

void raportare(vector<Angajat *> angajati)
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

void verificaFunctionalitateaMagazinului(vector<Angajat *> angajati)
{
    // verificare: minim 1 manager, minim 3 operatori, minim 1 asistent
    int manageri = 0, operatori = 0, asistenti = 0;
    for (auto angajat : angajati)
    {
        if (dynamic_cast<Manager *>(angajat))
        {
            manageri++;
        }
        if (dynamic_cast<OperatorComenzi *>(angajat))
        {
            operatori++;
        }
        if (dynamic_cast<Asistent *>(angajat))
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
}

void meniu(vector<Angajat *> angajati)
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
            gestiuneStoc();
        }
        if (option == 3)
        {
            procesareComenzi();
        }
        if (option == 4)
        {
            system("clear");
            raportare(angajati);
        }
        if (option == 5)
        {
            system("clear");
            verificaFunctionalitateaMagazinului(angajati);
        }
    }
}

int main()

{ // testare
    vector<Angajat *> angajati;
    ofstream RaportSalarii("raport1.csv");

    Manager *Yes = new Manager("John", "Smith", "5050205460021", time(0) - 50000000);
    Asistent *No = new Asistent("Jane", "Doe", "2950101460021", time(0) - 70000000);
    OperatorComenzi *Maybe = new OperatorComenzi("Jinn", "Darr", "1850202460021", time(0) - 80000000);
    OperatorComenzi *Maybe2 = new OperatorComenzi("Joey", "Sarr", "2750303460021", time(0) - 400000);
    OperatorComenzi *Maybe3 = new OperatorComenzi("Jinn", "Darr", "1850202460021", time(0) - 80000000);
    OperatorComenzi *Maybe4 = new OperatorComenzi("Joey", "Sarr", "2750303460021", time(0) - 400000);
    angajati.push_back(Yes);
    angajati.push_back(No);
    angajati.push_back(Maybe);
    angajati.push_back(Maybe2);
    angajati.push_back(Maybe3);
    angajati.push_back(Maybe4);
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

    meniu(angajati);

    return 0;
}