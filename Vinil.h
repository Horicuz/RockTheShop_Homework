#pragma once
#include "Disc.h"

class Vinil : public Disc
{
public:
    Vinil();
    Vinil(string, int, float, string, time_t, string, string);
    void AfisareProdus();
};