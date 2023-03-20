#include "Stations.h"
#include "unordered_set"
#include <utility>
#include <vector>
#include "string"
#include "fstream"

using namespace std;

Station::Station(string name){
    this->name = name;
};


Station::Station(int code, string name, string municipality, string township, string line){
    this->code = code;
    this->name = name;
    this->municipality = municipality;
    this->township = township;
    this->line = line;
};

std::string Station::getStationCode() {
    return code;
}
std::string Station::getStationName() {
    return name;
}

std::string Station::getStationMunicipality() {
    return municipality;
}
std::string Station::getStationTownship() {
    return township;
}

std::string Station::getStationLine() {
    return line;
}
