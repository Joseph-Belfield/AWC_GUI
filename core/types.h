#ifndef TYPES_H
#define TYPES_H

// This file defines key enums and structs for types of damage, status effect, etc.
// if something ranks something's difficulty, level, etc -> use the suffix 'level'

enum class DifficultyLevel
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

enum class Stat
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

enum class WoundLevel
{
    INSIGNFICANT,
    SEVERE,
    MORTAL,
    STATUS          // indicates the injury is just a status applied locally (no actual wound)
    // isTreated can be stored as a bool later
};

enum class BodyLocation
{
    HEAD,
    TORSO,
    LEFT_ARM,
    RIGHT_ARM,
    LEFT_LEG,
    RIGHT_LEG,
    ALL             // allows for global attacks, status effects, etc
};

// maybe make this a flag later
enum class StatusEffect
{
    NONE,  // for when there is a wound, but no accompanying status

    // 2.1
    BLEEDING,
    INFECTED,
    BURNING_MAJOR,  // AKA. large fire
    BURNING_MINOR,  // AKA. small fire
    ANXIETY_MINOR,
    ANXIETY_MAJOR,
    CONFUSION_MINOR,
    CONFUSION_MAJOR,
    LETHARGY,

    // 2.2
    RESTLESSNESS,
    ILLNESS_MINOR,
    ILLNESS_MAJOR,
    MIGRAINES,
    WEAKNESS,
    INDIGESTION,
    HYPOTHERMIA,
    NECROSIS,
    SENSORY_DEPRAVATION,
    MOTOR_ISSUES,
    HORMONALISM,
    // stress will have its own struct

    // 2.4
    LIMP,
    HEARING_IMPAREMENT, // half-deaf, but more general (post-shelling hearing imparement, etc)
    VISUAL_IMPAREMENT,  // one-eyed, but more general (could be cataracts, etc)
    UGLY,
};

enum class EnvironmentLevel
{
    SIMPLE,
    DIFFICULT,
    VERY_DIFFICULT,
    UNAVIGABLE,
    PAVED,
    SETTLEMENT
};

// this may be deleted/changed later for a different system (not enum)
enum class Environment
{
    // terrains
    PLAINS,
    DESERT,
    WOODS,
    BEACH,
    HILLS,
    MARSHES,
    LOW_MOUNTAIN,
    CAVES,
    PEAKS,

    // path types
    PATH,
    ROAD,
    RAIL,

    // settlements
    VILLIAGE,
    TOWN,
    CITY,
    CAPITAL
};

enum class WeatherLevel
{
    MILD,
    MEDIUM,
    HARSH
};

enum class Weather
{
    TEMPERATE,
    RAINING,        // light_rain
    POURING,        // rain
    STORMING,       // heavy_rain
    COLD,
    FREEZING,
    HAILING,
    FOG
};

enum class RestLevel
{
    COMFORTABLE,
    SAFE,
    UNSAFE,
    SLEEPLESS
};

enum class Scar
{
    FINE_LINE,
    KELOID,
    CONTRACTURE
};

// this may be deleted/changed later for a different system (not enum)
enum class Mania
{
    ANXIETY,    // (pretty sure) this is different from (wound) anxiety (?)
    DEPRESSION,
    SCHIZOPHRENIA,
    EATING_DISORDER,
    DISSOCIAL_DISORDER,
    PHOBIA,
    ADDICTION
};

enum class DrugType
{
    DEPRESSANT,
    STIMLANT,
    OPIATE,
    PSYCHADELIC
};

enum class MovementLevel
{
    WALKING,
    JOGGING,
    RUNNING,
    SPRINTING
};

enum class ArmorLevel
{
    PRIMITIVE,  // includes damaged armor
    FULL,       // includes half armor
    HEAVY       // shields grant the same effect as heavy armor
};

// traits will have a struct and then use a JSON

// this may be deleted/changed later for a different system (not enum)
enum class Language
{
    // 1.1
    ALBRIAN,
    ESLIN,
    SOLLIAN,
    NORLIN,
    KUDOSKI,
    BORDUNIC,
    TORDE,
    VOSEL,
    SUDONILL,
    VILNIC,
    HUDIAN,

    // 2.4
    VIGANI,
    ASL,        // Alberian Sign Language
    SSL,        // Sollanian Sign Language
    MYSTER,
    TREDOLLE,
    CARPETANIAN,
    SUDENIC,
    QUISILVE,
    SOLDRILE,
    HILLEVANE
};

// this should technically probably be RankLevel according to my own rules, but Rank does the job
enum class Rank
{
    CADET,
    PRIVATE,
    LANCE_SERGEANT,
    COLOR_SERGEANT,
    WARRANT_OFFICER,

    // officer ranks
    LIEUTENANT,
    CAPTAIN,
    MAJOR,
    BRIGADIER,
    MARSHALL
};

// roles will have a class

enum class WeaponType
{
    GUN,
    MELEE,
    THROWN
};

enum class GunType
{
    MUSKET,         // rifle
    PISTOL,
    HEAVY_MUSKET,   // shotgun
    AUTO_MUSKET,    // machine gun
    MISC
};

enum class ExplosionLevel
{
    DIRECT,
    CLOSE,
    MEDIUM,
    FAR
};

enum class Currency
{
    // Alberia + Bordun + Vilna + Hudia
    RIEM,           // Albarian standard currency. Worth 50 pounds. Standard currency for all prices in the game.
    DRIER,          // Sub-unit of Riem. 100 Drier to 1 Riem.

    // Solania + Vesterland
    SLIDE,
    // missing unit!

    // Norlin + Hudia
    RODE,
    // missing unit!

    // Karthilin
    VESOK,
    // missing unit!

    // Torderllia & Dorburia
    ADFAN,
    // missing unit!

    // Vosel + Suden
    GOLEN
    // missing unit!
};


#endif // TYPES_H
