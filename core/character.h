#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>

// data-holding structs


// actual classes
#include "stat.h"

// forward declarations



class Character : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString forname READ forname WRITE setForname NOTIFY fornameChanged FINAL)
    Q_PROPERTY(QString surname READ surname WRITE setSurname NOTIFY surnameChanged FINAL)

public:
    explicit Character(QString forname = "Jane", QString surname = "Doe", QObject *parent = nullptr);  // constructor

    // getters
    QString forname() const {return mForname;};
    QString surname() const {return mSurname;};


public slots:

    // setters
    void setForname(QString name);
    void setSurname(QString name);

signals:
    void fornameChanged();
    void surnameChanged();

private:
    // IDENTITY -> who are you?
    QString mForname;       // first AND middle names
    QString mSurname;       // last name
    QString mSobriquet;     // nickname
    uint mServiceNumber;    // 8 digits

    // country


    // NOTABLE FEATURES -> physical features of a character that (generally) won't affect gameplay. if you're missing your dogtag, how do they ID you?
    bool mSex;  // I'm so sorry please forgive me
    uint mAge;
    uint mHeight;
    QString mEyeColor;
    QString mHairColor;
    QString mFacialHair;
    QString mOtherFeatures;     // other notable features about your character

    // SERVICE HISTORY -> do later

    // RANK -> do later. make class for rank and have commendations as a vector of commendation enums.

    // ROLE -> do later. make a class for roles.

    // STATS -> the stat modifiers for roles respective to each stat. permenant modifiers are saved as rolled additions to the D12 stat check.
    Stat mStrength;
    Stat mEndurance;
    Stat mAgility;
    Stat mIntelligence;
    Stat mDiplomacy;
    Stat mLuck;
    Stat mPerception;
    Stat mStealth;
    Stat mWillpower;

    // APTITUDES -> how do I do this? have a weapon class, and then record aptitudes in there, with subclasses for each weapon?

    // INJURY
    // create a health manager (HM) class, which stores a list of body part objects, which store their own armor class and injuries. these can be summed by HM

    // EQUIPMENT -> create an inventory class, and also a general equipment/item class, with many subclasses. this stuff is just all JSON
    // this includes weapons, kits, rations, etc.

    // TRAITS -> create a trait class

};

#endif // CHARACTER_H
