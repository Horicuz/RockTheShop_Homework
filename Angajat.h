#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;

class Angajat
{
protected:
    static int counter;  // numarul de angajati
    int ID;              // ID este unic
    string nume;         // minim 3 caractere dar nu mai mult de 30
    string prenume;      // minim 3 caractere dar nu mai mult de 30
    string CNP;          // trebuie sa aiba un CNP valid
    time_t DataAngajare; // data angajarii
    float salariu;       // salariul

public:
    Angajat();                                                             // constructor fara parametri
    Angajat(string nume, string prenume, string CNP, time_t DataAngajare); // constructor cu parametri
    Angajat(const Angajat &angajat);                                       // constructor de copiere
    virtual void AfisareAngajat();                                         // afiseaza datele angajatului
    virtual void CitireAngajat(istream &dev);                              // citeste datele angajatului

    void SetNume(string nume);       // daca vrea sa isi schimbe numele
    void SetPrenume(string prenume); // daca vrea sa isi schimbe prenumele

    virtual void SetCNP(string CNP);           // daca vrea sa schimbe CNP-ul (virtual pentru ca in Asistent si OperatorComenzi se verifica si luna de nastere)
    void SetDataAngajare(time_t DataAngajare); // daca vrea sa schimbe data angajarii

    string GetNume();
    string GetPrenume();
    string GetCNP();
    string GetDataAngajare();
    int GetID();
    float GetSalariu();

    virtual void CalculeazaSalariu(); // calculeaza salariul
    bool ValidareCNP(string CNP);     // verifica daca CNP-ul este valid
    bool CompletInregistrat();        // verifica daca angajatul este complet inregistrat
};