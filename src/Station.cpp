/**
 * Implementation for a Station object with methods to get and set its properties.
 * @param code Integer representing the code of the station.
 * @param name Name of the station.
 * @param district District where station is located.
 * @param municipality Name of the municipality where the station is located.
 * @param township Specific township where the station is located.
 * @param line Train line that the station belongs to.
 */
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

Station::Station(){
    this->code = 000;
}

int Station::getCode() const {
    return code;
}

void Station::setCode(int code) {
    Station::code = code;
};

std::string Station::getStationName() const{
    return name;
}

std::string Station::getStationMunicipality() const{
    return municipality;
}
std::string Station::getStationTownship() const{
    return township;
}

std::string Station::getStationLine() const{
    return line;
}
