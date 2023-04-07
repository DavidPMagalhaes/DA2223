/**
 * Implementation for a network with code A, code B, capacity, and service.
 *
 * @param codeA An integer representing the code of the first node in the network.
 * @param codeB Aan integer variable that represents the code of the second node in a network connection.
 * @param capacity The capacity parameter represents the maximum amount of data that can be transmitted through the network
 * connection. It is usually measured in bits per second (bps) or bytes per second (Bps).
 * @param service The service parameter is a string that represents the type of network service being provided, such as
 * "internet", "phone", or "cable TV".
 */

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
