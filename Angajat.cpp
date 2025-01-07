#include "Angajat.h"

int Angajat::counter = 0;

Angajat::Angajat()
{
    nume = "";
    prenume = "";
    CNP = "";
    DataAngajare = time(0) + 10;
    counter++;
    ID = counter;
    salariu = 0;
}

Angajat::Angajat(string lastname, string firstname, string NPC, time_t Date)
{
    try
    {
        if (lastname.length() < 3 || lastname.length() > 30)
        {
            throw std::length_error("Numele trebuie sa aiba minim 3 caractere dar nu mai mult de 30");
        }
        if (lastname.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-") != string::npos)
        {
            throw std::invalid_argument("Numele nu trebuie sa contina decat litere sau -");
        }
        if (firstname.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-") != string::npos)
        {
            throw std::invalid_argument("Prenumele nu trebuie sa contina decat litere sau -");
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
    counter++;
    ID = counter;
    CalculeazaSalariu();
}

Angajat::Angajat(const Angajat &angajat)
{
    nume = angajat.nume;
    prenume = angajat.prenume;
    CNP = angajat.CNP;
    DataAngajare = angajat.DataAngajare;
    ID = angajat.ID + 1;
    counter++;
    salariu = angajat.salariu;
}

void Angajat::AfisareAngajat()
{
    cout << "Nume: " << nume << endl;
    cout << "Prenume: " << prenume << endl;
    cout << "CNP: " << CNP << endl;
    if (DataAngajare > time(0))
    {
        cout << "Data angajarii: " << "Inca neangajat!" << endl;
    }
    else
    {
        struct tm *timeinfo = localtime(&DataAngajare);
        cout << "Data angajarii: " << (timeinfo->tm_year + 1900) << "-"
             << (timeinfo->tm_mon + 1) << "-"
             << timeinfo->tm_mday << endl;
    }
    cout << "ID: " << ID << endl;
    cout << "Salariu: " << salariu << endl;
}

void Angajat::CitireAngajat(istream &dev)
{
    string nume, prenume, CNP;
    int day, month, year;
    struct tm tm = {0};

    // validare NUME
    cout << "Nume: ";
    dev >> nume;
    if (nume.length() < 3 || nume.length() > 30 || nume.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-") != string::npos)
    {
        cout << "Nume invalid!" << endl;
        return;
    }

    // validare PRENUME
    cout << "Prenume: ";
    dev >> prenume;
    if (prenume.length() < 3 || prenume.length() > 30 || prenume.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-") != string::npos)
    {
        cout << "Prenume invalid!" << endl;
        return;
    }

    // validare CNP
    cout << "CNP: ";
    dev >> CNP;
    if (!ValidareCNP(CNP))
    {
        return;
    }

    // validare DATA ANGAJARII
    cout << "Data angajarii: (ziua luna anul)" << endl;
    dev >> day >> month >> year;
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900)
    {
        cout << "Data angajarii invalida!" << endl;
        return;
    }

    tm.tm_mday = day;
    tm.tm_mon = month - 1;
    tm.tm_year = year - 1900;

    this->nume = nume;
    this->prenume = prenume;
    this->CNP = CNP;
    this->DataAngajare = mktime(&tm);
    CalculeazaSalariu();
}

void Angajat::SetNume(string lastname)
{
    if (lastname.length() < 3 || lastname.length() > 30)
    {
        cout << "Numele trebuie sa aiba minim 3 caractere dar nu mai mult de 30" << endl;
        return;
    }
    if (lastname.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-") != string::npos)
    {
        cout << "Numele nu trebuie sa contina decat litere sau -" << endl;
        return;
    }
    nume = lastname;
}

void Angajat::SetPrenume(string firstname)
{
    if (firstname.length() < 3 || firstname.length() > 30)
    {
        cout << "Prenumele trebuie sa aiba minim 3 caractere dar nu mai mult de 30" << endl;
        return;
    }
    if (firstname.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-") != string::npos)
    {
        cout << "Prenumele nu trebuie sa contina decat litere sau - " << endl;
        return;
    }
    prenume = firstname;
}

void Angajat::SetCNP(string NPC)
{
    if (!ValidareCNP(NPC))
    {
        cout << "CNP invalid" << endl;
        return;
    }
    CNP = NPC;
}

void Angajat::SetDataAngajare(time_t Date)
{
    DataAngajare = Date;
    CalculeazaSalariu();
}

string Angajat::GetNume()
{
    return nume;
}

string Angajat::GetPrenume()
{
    return prenume;
}

float Angajat::GetSalariu()
{
    return salariu;
}

string Angajat::GetCNP()
{
    return CNP;
}

string Angajat::GetDataAngajare()
{
    struct tm *timeinfo = localtime(&DataAngajare);
    return to_string(timeinfo->tm_year + 1900) + "-" + to_string(timeinfo->tm_mon + 1) + "-" + to_string(timeinfo->tm_mday);
}

int Angajat::GetID()
{
    return ID;
}

bool Angajat::ValidareCNP(string CNP)
{
    if (CNP.length() != 13)
    {
        cout << "Trebuie sa fie exact 13 caractere!" << endl;
        return false;
    }
    for (int i = 0; i < CNP.length(); i++)
    {
        if (!isdigit(CNP[i]))
        {
            cout << "CNP contine doar cifre!" << endl;
            return false;
        }
    }

    // Extract birth date from CNP
    int year = stoi(CNP.substr(1, 2));
    if (year < 0 || year > 99)
    {
        cout << "CNP invalid!" << endl;
        return false;
    }
    int month = stoi(CNP.substr(3, 2));
    if (month < 1 || month > 12)
    {
        cout << "CNP invalid!" << endl;
        return false;
    }
    int day = stoi(CNP.substr(5, 2));
    if (day < 1 || day > 31)
    {
        cout << "CNP invalid!" << endl;
        return false;
    }

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
        cout << "CNP invalid!" << endl;
        return false;
    }
    year += century;

    // Check if the person is over 18 years old
    time_t now_c = time(0);
    struct tm *parts = localtime(&now_c);

    int current_year = 1900 + parts->tm_year;
    int current_month = 1 + parts->tm_mon;
    int current_day = parts->tm_mday;

    if (current_year - year < 18)
    {
        cout << "Persoana nu are 18 ani!" << endl;
        return false;
    }
    else if (current_year - year == 18)
    {
        if (current_month < month)
        {
            cout << "Persoana nu are 18 ani!" << endl;
            return false;
        }
        else if (current_month == month)
        {
            if (current_day < day)
            {
                cout << "Persoana nu are 18 ani!" << endl;
                return false;
            }
        }
    }

    return true; // CNP is valid
}

void Angajat::CalculeazaSalariu()
{
    if (CompletInregistrat() == false)
        return;

    // Salariul de baza este 3500
    salariu = 3500;
    // Pentru fiecare an de vechime la companie se adauga 100 de lei la salariu
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int current_year = 1900 + ltm->tm_year;
    int current_month = 1 + ltm->tm_mon;
    int current_day = ltm->tm_mday;

    struct tm *timeinfo = localtime(&DataAngajare);
    int year = 1900 + timeinfo->tm_year;
    int month = 1 + timeinfo->tm_mon;
    int day = timeinfo->tm_mday;

    int vechime = current_year - year;
    if (current_month < month)
    {
        vechime--;
    }
    else if (current_month == month)
    {
        if (current_day < day)
        {
            vechime--;
        }
    }
    salariu += vechime * 100;
}

bool Angajat::CompletInregistrat()
{
    if (nume == "" || prenume == "" || CNP == "" || DataAngajare > time(0))
    {
        cout << "Angajatul " << ID << " nu este complet inregistrat!" << endl;
        return false;
    }
    return true;
}