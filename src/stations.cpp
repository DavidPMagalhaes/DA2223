



#include "stations.h"
#include "unordered_set"
#include "FlightControl.h"
#include <utility>
#include <vector>
#include "string"
#include "fstream"
#include "StationGraph.h"

using namespace std;


Station(string code, string name, string municipality, string township, string line) {
    this->code = code;
    this->name = name;
    this->municipality = municipality);
    this->township = township;
    this->line = line;
};

string Station::getStationCode() {
    return code;
}
string Station::getStationName() {
    return name;
}

string Station::getStationMunicipality() {
    return municipality;
}
string Station::getStationTownship() {
    return township;
}

string Station::getStationLine() {
    return line;
}


unordered_set<Station, StationHash> readStations() {
    string filename = "dataset/Stations.csv";
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return {};
    }

    unordered_set<Station, StationHash> Stations;
    string line;
    getline(file,line);
    while (getline(file, line)) {
        if (line.empty()) continue;
        vector<string> data = FlightControl::split(line, ',');
        Station x = {data[0], data[1], data[2], data[3], data[4], data[5]};
        Stations.insert(x);

    }
    return Stations;

}
