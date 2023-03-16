#include <list>
#include <vector>
#include <iostream>
#include <stack>
#include "string"
#include "Stations.h"

using namespace std;

class Network {
public:
    Network(string stationA, string stationB, string capacity, string service);

    string stationA;
    string stationB;
    string capacity;
    string service;

    bool operator==(const Network& other) const {
        return stationA == other.stationA &&
                stationB == other.stationB &&
                capacity == other.capacity &&
                service == other.service;
    }

};

