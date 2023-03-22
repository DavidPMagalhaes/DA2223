#include "Station.h"

using namespace std;

Station::Station(int code, string name, string district, string municipality, string township, string line){
    this->code = code;
    this->name = name;
    this->district = district;
    this->municipality = municipality;
    this->township = township;
    this->line = line;
}

int Station::getCode() const {
    return code;
}

void Station::setCode(int code) {
    Station::code = code;
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
