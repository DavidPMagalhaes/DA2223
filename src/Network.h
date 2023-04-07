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



    int codeA;
    int codeB;
    int capacity;
    string service;

    bool operator==(const Network& other) const {
        return codeA == other.codeA &&
                codeB == other.codeB &&
                capacity == other.capacity &&
                service == other.service;
    }


    void setCapacity(const int &capacity);

    const string &getService() const;

    void setService(const string &service);
public:
    Network(int codeA, int codeB, int capacity, string service);


    const int getCapacity() const;

    int getCodeA() const;

    void setCodeA(int codeA);

    int getCodeB() const;

    void setCodeB(int codeB);
};

