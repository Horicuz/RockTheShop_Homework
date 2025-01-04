#include "Angajat.h"

int Angajat::ID = 0;

Angajat::Angajat()
{
    nume = "";
    prenume = "";
    CNP = "";
    ID++;
}

Angajat::Angajat(string lastname, string firstname, string NPC, time_t Date)
{
    try
    {
        if (lastname.length() < 3 || lastname.length() > 30)
        {
            throw std::length_error("Numele trebuie sa aiba minim 3 caractere dar nu mai mult de 30");
        }
        if (firstname.length() < 3 || firstname.length() > 30)
        {
            throw std::length_error("Prenumele trebuie sa aiba minim 3 caractere dar nu mai mult de 30");
        }
        if (!ValidareCNP(NPC))
        {
            throw std::invalid_argument("CNP invalid");
        }
    }
    catch (const std::length_error &e)
    {
        cout << e.what() << endl;
        return;
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl;
        return;
    }
    nume = lastname;
    prenume = firstname;
    CNP = NPC;
    DataAngajare = Date;
    ID++;
}

Angajat::Angajat(const Angajat &angajat)
{
    nume = angajat.nume;
    prenume = angajat.prenume;
    CNP = angajat.CNP;
    DataAngajare = angajat.DataAngajare;
    ID = angajat.ID;
}

void Angajat::AfisareAngajat()
{
    cout << "Nume: " << nume << endl;
    cout << "Prenume: " << prenume << endl;
    cout << "CNP: " << CNP << endl;
    struct tm *timeinfo = localtime(&DataAngajare);
    cout << "Data angajarii: " << (timeinfo->tm_year + 1900) << "-"
         << (timeinfo->tm_mon + 1) << "-"
         << timeinfo->tm_mday << endl;
    cout << "ID: " << ID << endl;
}

void Angajat::SetNume(string lastname)
{
    nume = lastname;
}

bool Angajat::ValidareCNP(string CNP)
{
    if (CNP.length() != 13)
    {
        return false;
    }
    for (int i = 0; i < CNP.length(); i++)
    {
        if (!isdigit(CNP[i]))
        {
            return false;
        }
    }

    // Extract birth date from CNP
    int year = stoi(CNP.substr(1, 2));
    int month = stoi(CNP.substr(3, 2));
    int day = stoi(CNP.substr(5, 2));

    // Determine century
    int century = 0;
    switch (CNP[0])
    {
    case '1':
    case '2':
        century = 1900;
        break;
    case '3':
    case '4':
        century = 1800;
        break;
    case '5':
    case '6':
        century = 2000;
        break;
    default:
        return false;
    }
    year += century;

    // Check if the person is over 18 years old
    auto now = std::chrono::system_clock::now();
    time_t now_c = std::chrono::system_clock::to_time_t(now);
    struct tm *parts = localtime(&now_c);

    int current_year = 1900 + parts->tm_year;
    int current_month = 1 + parts->tm_mon;
    int current_day = parts->tm_mday;

    if (current_year - year < 18)
    {
        return false;
    }
    else if (current_year - year == 18)
    {
        if (current_month < month)
        {
            return false;
        }
        else if (current_month == month)
        {
            if (current_day < day)
            {
                return false;
            }
        }
    }

    return true; // CNP is valid
}

istream &operator>>(istream &in, Angajat &angajat)
{
    cout << "Nume: ";
    in >> angajat.nume;
    cout << "Prenume: ";
    in >> angajat.prenume;
    cout << "CNP: ";
    in >> angajat.CNP;
    cout << "Data angajarii: ";
    in >> angajat.DataAngajare;
    return in;
}
