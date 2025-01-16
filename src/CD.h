#pragma once
#include "Disc.h"

class CD : public Disc
{
public:
    CD();
    CD(string, int, float, string, time_t, string, string);
    void AfisareProdus();
};