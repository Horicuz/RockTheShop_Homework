#include "OperatorComenzi.h"
#include "Manager.h"
#include "Asistent.h"
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>

using namespace std;

void topAngajatNrComenzi(map<int, Angajat *> angajati, ofstream &);
void top3AngajatiComenzi(map<int, Angajat *> angajati, ofstream &);
void top3salariu(map<int, Angajat *> angajati, ofstream &s);