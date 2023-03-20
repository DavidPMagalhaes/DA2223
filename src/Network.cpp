#include "Network.h"
#include "fstream"
#include <iostream>
#include <cstring>
#include <utility>
#include <string>
#include <vector>
#include <sstream>



using namespace std;


Network::Network(Station stationA, Station stationB, int capacity, string service) {
    this->stationA  = stationA;
    this->stationB= stationB;
    this->capacity = capacity;
    this->service = service;
}
