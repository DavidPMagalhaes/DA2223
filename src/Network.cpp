#include "Network.h"
#include "fstream"
#include <iostream>
#include <cstring>
#include <utility>
#include <string>
#include <vector>
#include <sstream>



using namespace std;


Network::Network(string stationA, string stationB, string capacity, string service) {
    this->stationA  = stationA;
    this->stationB= stationB;
    this->capacity = capacity;
    this->service = service;
}
