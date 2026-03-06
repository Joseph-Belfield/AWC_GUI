#ifndef CHARACTER_H
#define CHARACTER_H

#include "types.h"

#include <map>
#include <vector>
#include <string>

// forward declarations
struct BodyPart;


class Character
{
public:
    Character();

private:

    int ID; // ID of the character

    // IDENTITY
    std::string forname;        // first & middle names
    std::string surname;        // surname
    std::string sobriquet;      // nickname


    // HEALTH
    std::map<BodyLocation, BodyPart> body;      // map containing each of the character's body parts
    bool isConscious;
    bool isAlive;
    int netWoundCount[3];                       // tallies the total amount of each type of wound, upgrading where necessary
    int blood;                                  // a character's current amount of blood (ml)
    std::vector<StatusEffect> statusEffects;    // global statuses (applied to whole character)


};

#endif // CHARACTER_H
