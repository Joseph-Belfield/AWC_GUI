#ifndef TYPES_H
#define TYPES_H

// This file defines key enums and structs for types of damage, status effect, etc.

enum Difficulty
{
    CAUSUAL = 4,
    EASY = 6,
    MEDIUM = 8,
    HARD = 10,
    VERY_HARD = 12,
    EXTREME = 14,
    IMPLAUSIBLE = 16,
    NEAR_IMPOSSIBLE = 18,
    ALL_BUT_IMPOSSIBLE = 20
};

enum StatType
{
    STR,        // strength
    END,        // endurance
    AGI,        // agility
    INT,        // intelligence
    DIP,        // diplomacy
    LUC,        // luck
    PER,        // perception
    STE,        // stealth
    WIL         // willpower
};

enum WoundLevel { INSIGNFICANT, SEVERE, MORTAL };

enum LimbLocation
{
    HEAD,
    TORSO,
    LEFT_ARM,
    RIGHT_ARM,
    LEFT_LEG,
    RIGHT_LEG
};

// maybe make this a flag later
enum StatusEffect
{
    BLEEDING,
    INFECTED,
    BURNED,

    ANXIETY
};




#endif // TYPES_H
