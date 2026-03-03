#include "stat.h"

// constructor
Stat::Stat(Type type, int baseValue, QObject *parent)
    : QObject{parent},
    mType{type},
    mBaseValue{baseValue},
    mFlatModifier{0},
    mRolledModifier{0}
{}

QString Stat::name() const
{
    switch(mType)
    {
        case(STR):  return "Strength";
        case(END):  return "Endurance";
        case(AGI):  return "Agility";
        case(INT):  return "Intelligence";
        case(DIP):  return "Diplomacy";
        case(LUC):  return "Luck";
        case(PER):  return "Perception";
        case(STE):  return "Stealth";
        case(WIL):  return "Willpower";
    }
}

Stat::Type Stat::type() const
{
    return mType;
}

int Stat::baseValue() const
{
    return mBaseValue;
}

int Stat::currentValue() const
{
    return mBaseValue + mRolledModifier;
}

int Stat::flatModifier() const
{
    return mFlatModifier;
}

void Stat::setBaseValue(int value)
{
    // if the values are already the same, nothing changes
    if (mBaseValue == value)
    {
        return;
    }

    //  else change the value accordingly
    mBaseValue = value;

    // send out signals that the value has changed
    emit baseValueChanged();
    emit currentValueChanged();
}

void Stat::setFlatModifier(int value)
{
    if (mFlatModifier == value)
    {
        return;
    }

    mFlatModifier = value;

    emit flatModifierChanged();
}

void Stat::addFlatModifier(int value)
{
    if (value == 0)
    {
        return;
    }

    mFlatModifier += value;

    emit flatModifierChanged();
}

void Stat::setRolledModifier(int value)
{
    if (mRolledModifier == value)
    {
        return;
    }

    mRolledModifier = value;

    emit currentValueChanged();
}

void Stat::addRolledModifier(int value)
{
    // if the addative value is 0, nothing changes and the function can end
    if (value == 0)
    {
        return;
    }

    // current modifier has value added
    mRolledModifier += value;

    // current value changed, so signal to update
    emit currentValueChanged();
}

void Stat::clearModifiers()
{
    if (mRolledModifier != 0)
    {
        mRolledModifier = 0;
        emit currentValueChanged();
    }

    if (mFlatModifier != 0)
    {
        mFlatModifier = 0;
        emit flatModifierChanged();
    }
}

