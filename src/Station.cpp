#include "Station.h"

using namespace std;

Station::Station(string name, string district, string municipality, string township, string line){
    this->name = name;
    this->district = district;
    this->municipality = municipality;
    this->township = township;
    this->line = line;
};

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

Station::Station() {}
