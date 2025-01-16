#pragma once
#include "Disc.h"
#include "DiscuriVintage.h"
#include "ArtVest.h"
#include "CD.h"
#include "Vinil.h"
#include <vector>
#include <ctime>
#include <map>

using namespace std;

void AdaugaProdus(map<int, Produs *> &);
void AfisareProduse(map<int, Produs *>);
void ModificaStocProdus(map<int, Produs *>, int ID);
void StergeProdus(map<int, Produs *> &, int ID);
void AfisareProdus(map<int, Produs *>, int ID);