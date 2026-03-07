#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "types.h"

#include <string>
#include <vector>
#include <map>
#include <iostream>

// injuries are single instances of a wound or status. however, one action may cause multiple injuries (a cut which also burns will apply a wound + bleed and a burn)
struct Injury
{
    int ID; // ID number for this specific injury
    BodyLocation location;
    WoundLevel wound;
    StatusEffect status;
    bool isTreated;

    std::string description;
};

// body parts track injuries induvidually by accumulating them in a vector
struct BodyPart
{
    BodyLocation location;
    std::vector<Injury> injuries;   // a list of all the injuries currently held by the body part
    bool isFunctional;              // can the limb be used?
    bool isSevered;                 // is the limb still attached? (if no, automatically set isFunctional to false)
};

// the basic item struct ->  anything that can be held by the player. will have many subclasses
struct Item
{
    std::string name;           // use name to find item in JSON!
    std::string description;
    float weight;               // in kilograms! (it's Europe after all)
    float price;                // in Riem (standard currency of Albria)
};

// will be the basis of any container (including inventory)
class Container : Item
{
public:
    float maxWeight;                // maximum weight of items a container can hold

    static float calculateWeight(std::vector<Item> items, std::vector<int> amounts)
    {
        float totalWeight = 0;
        for (int i = 0; i < items.size(); ++i)
        {
            totalWeight += items[i].weight * amounts[i];
        }
        return totalWeight;
    }

    // isStacked refers to whether the new item should be added to the stack of existing versions of itself, or be logged seperately
    void addItem(Item item, int amount)
    {
        // if addition of items doesn't exceeed the weight limit
        if ((calculateWeight(mItems, mItemAmounts) + (item.weight * amount)) <= maxWeight)
        {
            // find the index of the first occourance of this item
            auto itemPtr = std::find(mItems.begin(), mItems.end(), item);

            // if an index was found, increase its amount accordingly
            if (itemPtr != mItems.end())
            {
                int index = std::distance(mItems.begin(), itemPtr);
                mItemAmounts[index] += amount;
            }
            else
            {
                // else if the item wasn't already present, add the item anew to the back of the vector
                mItems.push_back(item);
                mItemAmounts.push_back(amount);
            }
        }
        else
        {
            std::cout << "ERROR! Adding item exceeds weight limit!" << std::endl;
        }
    }

    void removeItem(Item item, int amount)
    {
        auto itemPtr = std::find(mItems.begin(), mItems.end(), item);

        // if the item is in the list
        if (itemPtr != mItems.end())
        {
            // if there are more items than the amount to be removed
            int index = std::distance(mItems.begin(), itemPtr);
            if (amount < mItemAmounts[index])
            {
                // remove that many items
                mItemAmounts[index] -= amount;
            }
            else
            {
                // else delete that item from the vector entirely
                mItems.erase(mItems.begin() + index);
                mItemAmounts.erase(mItemAmounts.begin() + index);
            }
        }
        else
        {
            std::cout << "ERROR! Item not in containter!" << std::endl;
        }
    }

private:
    std::vector<Item> mItems;        // every item in container
    std::vector<int> mItemAmounts;   // amount of each item at corresponding index
};

struct Ammo : Item
{
    std::vector<GunType> weaponOptions;     // types of weapon that can use the ammo
    int bore;                               // bore of the ammo (heavy muskets only) -> ignore bore value unless heavy muskey ammo
    StatusEffect appliedStatus;             // for if firing hollowed/incindiery rounds
};

struct Weapon : Item
{
    WeaponType type;                // ie. gun, melee or thrown
    Stat abilityCheck;              // stat used for ability checks (hit roll)
    int woundRatio[3];              // wound die is the sum of the wound ratio
    int startingAptitude;           // beginning aptitude modifier (added to D12 roll to hit BEFORE adding ability check bonus)]
    float range[3];                 // there are 3 numbers in the range section in the doc?
    bool isPenetrative;             // determines if bleed is applied
    StatusEffect appliedStatus;     // does the weapon apply a status (other than bleed) when it hits?
};

struct Gun : Weapon
{
    GunType gunType;
    int shotsPerAction;         // shots fired per action
    int clipSize;               // size of clip (can be modified)
    int jamChance;              // if the roll to hit is less than this, check if the gun jams
    bool isJammed;              // tracks whether gun is currently jammed (same as malfunctioned)
    Ammo ammoType;              // type of ammo taken
};

struct Melee : Weapon
{
    Stat alternateAbilityCheck;     // another stat that can be used for ability checks
    int alternateWoundRatio[3];     // wound ratios for the alternate stat
    int swingsPerAction;
};

struct Grenade : Weapon
{
    float timer;                                        // timer on bomb after pin pulled (can be changed to 0.0 for timerless grenades)
    float explosionRangeBounds[4];                      // distances affected by each type of explosion (direct hit, close, medium, far)
    bool isContactDetonated;                            // will it detonate when exposed to large amounts of pressure (on contact)?
    std::map<ExplosionLevel, float[3]> woundRatios;     // wound ratio per range boundary (assume default wound ratios for direct hit)
};


#endif // DEFINITIONS_H
