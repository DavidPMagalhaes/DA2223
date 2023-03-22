#include "Network.h"

using namespace std;


Network::Network(Station stationA, Station stationB, int capacity, string service)
        : stationA(stationA), stationB(stationB) {
    this->stationA  = stationA;
    this->stationB = stationB;
    this->capacity = capacity;
    this->service = service;
}

const Station &Network::getStationA() const {
    return stationA;
}

void Network::setStationA(const Station &stationA) {
    Network::stationA = stationA;
}

const Station &Network::getStationB() const {
    return stationB;
}

void Network::setStationB(const Station &stationB) {
    Network::stationB = stationB;
}

const int Network::getCapacity() const {
    return capacity;
}

void Network::setCapacity(const int &capacity) {
    Network::capacity = capacity;
}

const string &Network::getService() const {
    return service;
}

void Network::setService(const string &service) {
    Network::service = service;
}
