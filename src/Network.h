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
/**
 * @brief The Network class represents a network of railway stations and trains that connect them.
 */
class Network {
public:
    Station codeA;
    Station codeB;

    /**
     * @brief Getter for the first station code.
     * @return The first station code.
     */
    const Station &getCodeA() const;

    /**
     * @brief Getter for the second station code.
     * @return The second station code.
     */
    const Station &getCodeB() const;

    /**
     * @brief Setter for the first station code.
     * @param codeA The new code for the first station.
     */
    void setCodeA1(const Station &codeA);

    /**
     * @brief Setter for the second station code.
     * @param codeB The new code for the second station.
     */
    void setCodeB1(const Station &codeB);

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

    Network(Station* codeA, Station* codeB, int capacity, string service);


    const int getCapacity() const;
};

