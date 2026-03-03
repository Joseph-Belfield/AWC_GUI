#include "character.h"

#include "stat.h"

// constructor -> add more information later when availible
Character::Character(QString forname, QString surname, QObject *parent)
    : QObject{parent},

    // IDENTITY
    mForname{forname},
    mSurname{surname},

    // STATS -> by passing 'this', Qt knows these Stat objects are part of Character object, and will delete them if the Character object is deleted
    mStrength{STR, 0, this},
    mEndurance{END, 0, this},
    mAgility{AGI, 0, this},
    mIntelligence(INT, 0, this),
    mDiplomacy(DIP, 0, this),
    mLuck{LUC, 0, this},
    mPerception{PER, 0, this},
    mStealth{STE, 0, this},
    mWillpower{WIL, 0, this}
{}
