#include "engine.h"

Engine::Engine() {}


void Engine::updateWounds(int wounds[3])
{
    // upgrading IW
    if (wounds[0] >= 5)
    {
        wounds[1] += wounds[0] / 5; // upgrades wounds to SW for each lot of 5 IWs  (using DIV)
        wounds[0] %= 5;             // removes as many multiples of 5 as possible from IW (using MOD)
    }

    // upgrading SW
    if (wounds[1] >= 3)
    {
        wounds[2] += wounds[1] / 3;
        wounds[1] %= 3;
    }
}
