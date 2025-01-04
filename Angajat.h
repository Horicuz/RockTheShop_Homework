#pragma once
#include <iostream>
#include <string>
#include <chrono>

using namespace std;

class Angajat
{
    static int ID;       // ID este unic
    string nume;         // minim 3 caractere dar nu mai mult de 30
    string prenume;      // minim 3 caractere dar nu mai mult de 30
    string CNP;          // trebuie sa aiba un CNP valid
    time_t DataAngajare; // data angajarii

    float salariu; // salariul angajatului

public:
    Angajat();                                                             // constructor fara parametri
    Angajat(string nume, string prenume, string CNP, time_t DataAngajare); // constructor cu parametri
    Angajat(const Angajat &angajat);                                       // constructor de copiere
    void AfisareAngajat();                                                 // afiseaza datele angajatului
    void SetNume(string nume);                                             // daca vrea sa isi schimbe numele

    // string GetNume();
    // string GetPrenume();
    // string GetCNP();
    // string GetDataAngajare();
    // int GetID();
    // float GetSalariu();

    bool ValidareCNP(string CNP); // verifica daca CNP-ul este valid
    friend istream &operator>>(istream &in, Angajat &angajat);
};