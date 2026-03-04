#include "character.h"

#include "stat.h"

// constructor -> add more information later when availible
Character::Character(QString forname, QString surname, QObject *parent)
    : QObject{parent},

    // IDENTITY
    mForname{forname},
    mSurname{surname},

    // STATS -> by passing 'this', Qt knows these Stat objects are part of Character object, and will delete them if the Character object is deleted
    mStrength{Stat::STR, 0, this},
    mEndurance{Stat::END, 0, this},
    mAgility{Stat::AGI, 0, this},
    mIntelligence(Stat::INT, 0, this),
    mDiplomacy(Stat::DIP, 0, this),
    mLuck{Stat::LUC, 0, this},
    mPerception{Stat::PER, 0, this},
    mStealth{Stat::STE, 0, this},
    mWillpower{Stat::WIL, 0, this}
{}
