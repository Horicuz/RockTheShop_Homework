#pragma once
#include "OperatorComenzi.h"

void intrareComenzi(ifstream &, map<int, Produs *>, priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>> &);
void AfisareComenzi(priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>>);
void AfisareComanda(priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>>, int);
void AdaugaComanda(map<int, Produs *>, priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>> &);
void StergeComanda(priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>> &, int);

void Procesare(map<int, Angajat *> &, priority_queue<comanda *, vector<comanda *>, function<bool(comanda *, comanda *)>> &, map<int, Produs *> &, time_t &, int &);