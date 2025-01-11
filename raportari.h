#include "OperatorComenzi.h"
#include "Manager.h"
#include "Asistent.h"
#include <vector>
#include <algorithm>

using namespace std;

void topAngajatNrComenzi(map<int, Angajat *> angajati, ofstream &);
void top3AngajatiComenzi(map<int, Angajat *> angajati, ofstream &);
void top3salariu(map<int, Angajat *> angajati, ofstream &);