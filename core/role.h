#ifndef ROLE_H
#define ROLE_H

#include <QObject>

// just a regular header, as the role struct simply serves to hold data, and might want to be passed by value sometimes (which Qt classes cannot do)

struct Role
{
    QString name;
    // why on earth am i developing roles first develop everything else first moron

};


#endif // ROLE_H
