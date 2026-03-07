#ifndef ITEMREGISTRY_H
#define ITEMREGISTRY_H

#include "definitions.h"

#include <map>
#include <string>

// a class that holds the "blueprints" for all items in the game. loads them from JSON upon program start
class ItemRegistry
{
public:
    static void loadData(const std::string& filepath);

    static const Weapon& getWeapon(std::string itemName);
private:

    // effectively-global maps initialized in header. item name used as map key, with correlated item struct
    static inline std::map<std::string, Weapon> mWeapons;   // list of all weapons

    // add other specific item maps here

    static inline std::map<std::string, Item> mItems;       // this holds all items that don't fit the other catagories
};

#endif // ITEMREGISTRY_H
