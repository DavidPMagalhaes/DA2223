#include "Network.h"

using namespace std;


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

Network::Network(Station* codeA, Station* codeB, int capacity, string service) {
    this->codeA = *codeA;
    this->codeB = *codeB;
    this->capacity = capacity;
    this->service = service;

}

void Network::setCodeA1(const Station &codeA) {
    Network::codeA = codeA;
}

void Network::setCodeB1(const Station &codeB) {
    Network::codeB = codeB;
}

const Station &Network::getCodeA() const {
    return codeA;
}

const Station &Network::getCodeB() const {
    return codeB;
}
