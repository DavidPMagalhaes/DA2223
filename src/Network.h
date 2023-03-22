#include <list>
#include <stack>
#include "fstream"
#include <iostream>
#include <cstring>
#include <utility>
#include <string>
#include <vector>
#include <sstream>
#include "Station.h"


using namespace std;

class Network {



    Station stationA;
    Station stationB;
    int capacity;
    string service;

    bool operator==(const Network& other) const {
        return stationA == other.stationA &&
                stationB == other.stationB &&
                capacity == other.capacity &&
                service == other.service;
    }

    void setStationA(const Station &stationA);

    void setStationB(const Station &stationB);

    void setCapacity(const int &capacity);

    const string &getService() const;

    void setService(const string &service);
public:
    Network(Station stationA, Station stationB, int capacity, string service);

    const Station &getStationA() const;

    const Station &getStationB() const;

    const int getCapacity() const;
};

