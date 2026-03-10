#include "itemregistry.h"

#include <nlohmann/json.hpp>
#include <fstream>
#include <string>

void ItemRegistry::loadData(const std::string& filename)
{
    std::ifstream file(filename);

    nlohmann::json data = nlohmann::json::parse(filename);

    std::string name = data["weapons"][0]["name"];
    int force =
}
