#ifndef CHARACTER_H
#define CHARACTER_H

#include "types.h"

#include <map>
#include <vector>
#include <string>

// forward declarations
struct Stat;
struct BodyPart;

class Character
{
public:
    Character();

private:

    // IDENTITY
    std::string forname;        // first & middle names
    std::string surname;        // surname
    std::string sobriquet;      // nickname


    // STATS
    std::vector<Stat> stats;


    // HEALTH
    std::map<BodyLocation, BodyPart> body;              // map containing each of the character's body parts
    int netWoundCount[3];                               // tallies the total amount of each type of wound, upgrading where necessary (IW, SW, MW)
    int blood;                                          // a character's current amount of blood (ml)
    std::map<StatusEffect, int> statuses;               // keeps track of players global (full-body) statuses, and their level

    bool isConscious;
    bool isAlive;

    int stressPoints;





};

#endif // CHARACTER_H
