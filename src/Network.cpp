#include "Network.h"

using namespace std;


Network::Network(int codeA, int codeB, int capacity, string service){
    this->codeA  = codeA;
    this->codeB = codeB;
    this->capacity = capacity;
    this->service = service;
}

int Network::getCodeA() const {
    return codeA;
}

void Network::setCodeA(int codeA) {
    Network::codeA = codeA;
}

int Network::getCodeB() const {
    return codeB;
}

void Network::setCodeB(int codeB) {
    Network::codeB = codeB;
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
