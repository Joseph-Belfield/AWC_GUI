#ifndef STAT_H
#define STAT_H

#include <QObject>

class Stat : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int baseValue READ baseValue WRITE setBaseValue NOTIFY baseValueChanged)
    Q_PROPERTY(int currentValue READ currentValue NOTIFY currentValueChanged)
    Q_PROPERTY(int flatModifier READ flatModifier WRITE setFlatModifier NOTIFY flatModifierChanged)

public:

    enum Type { STR, END, AGI, INT, DIP, LUC, PER, STE, WIL };
    Q_ENUM(Type)

    explicit Stat(Type type, int baseValue = 0, QObject *parent = nullptr);

    // getters...
    QString name() const;
    Type type() const;
    int baseValue() const;
    int currentValue() const;  // current value is the current ROLLED value only (as this is dynamic) -> (baseValue + rolledModifier)
    int flatModifier() const;

public slots:   // functions that can be called automatically in response to a signal

    // setters!
    void setBaseValue(int value);
    void setFlatModifier(int value);    // sets the flat modifier outright to specified value (ignoring current value)
    void addFlatModifier(int value);    // adds cumulatively to current flat modifier
    void setRolledModifier(int value);
    void addRolledModifier(int value);

    // kinda like one big setter
    void clearModifiers();

signals:                            // these signal to the program that the GUI needs to be refreshed as data has changed
    void baseValueChanged();
    void currentValueChanged();
    void flatModifierChanged();

private:
    Type mType;
    int mBaseValue;        // the base value of the modifier (in terms of the no. of sides of the dice rolled to calculate the value)
    int mFlatModifier;     // a temporary modifier (or stat bonus) -> this is the flat modifier (as in unrolled constant additions)
    int mRolledModifier;   // a temporary modifier (or stat bonus) -> rolled modifier must be rolled each time
};

#endif // STAT_H
