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

