#include "Asistent.h"
#include "Manager.h"
#include "OperatorComenzi.h"
#include <vector>

using namespace std;

void AdaugaAngajat(map<int, Angajat *> &);
void AfisareAngajati(map<int, Angajat *>);
void ModificaNumeAngajat(map<int, Angajat *>, int);
void StergeAngajat(map<int, Angajat *> &, int);
void AfiseazaDateleUnuiAngajat(map<int, Angajat *>, int);
