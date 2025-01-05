#include "Angajat.h"

using namespace std;

class Asistent : public Angajat
{
private:
public:
    Asistent();
    Asistent(string nume, string prenume, string CNP, time_t DataAngajare);
    Asistent(const Asistent &asistent);
    void AfisareAngajat();
    void CitireAngajat(istream &dev);
    void CalculeazaSalariu();
    bool CheckBirthDay(string CNP);
};