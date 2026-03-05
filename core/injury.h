#ifndef INJURY_H
#define INJURY_H

#include <QObject>

// groups together wounds and status effects -> things that can occour to a body part
struct Injury
{
    // types of injury
    enum Type { INSIGNIFICANT, SEVERE, MORTAL, INSTAKILL, STATUS };

    Type wound;                 // type of wound
    QString description;        // description of status  (change this later once an actual status system has been implemented)
};

#endif // INJURY_H
