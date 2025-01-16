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
    Angajat();                               // constructor fara parametri
    Angajat(string, string, string, time_t); // constructor cu parametri
    Angajat(const Angajat &);                // constructor de copiere
    virtual void AfisareAngajat();           // afiseaza datele angajatului
    virtual void CitireAngajat(istream &);   // citeste datele angajatului

    void SetNume(string);    // daca vrea sa isi schimbe numele
    void SetPrenume(string); // daca vrea sa isi schimbe prenumele

    virtual void SetCNP(string);  // daca vrea sa schimbe CNP-ul (virtual pentru ca in Asistent si OperatorComenzi se verifica si luna de nastere)
    void SetDataAngajare(time_t); // daca vrea sa schimbe data angajarii

    string GetNume();
    string GetPrenume();
    string GetCNP();
    string GetDataAngajare();
    int GetID();
    float GetSalariu();

    virtual void CalculeazaSalariu(); // calculeaza salariul
    bool ValidareCNP(string);         // verifica daca CNP-ul este valid
    bool CompletInregistrat();        // verifica daca angajatul este complet inregistrat
};