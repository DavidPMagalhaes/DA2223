#include <list>
#include <vector>
#include <iostream>
#include <stack>
#include "string"
#include "Stations.h"
#include "Airport.h"

using namespace std;
class NetworkHash;
class Network {
    Network(basic_string<char, char_traits<char>, allocator<char>> basicString);

    string stationA;
    string stationB;
    int capacity;
    string service;

    Network();
    Network(string stationA, string stationB, int capacity, string service);
    /**
     * @brief Reads a list of Networks from a CSV file and returns them in an unordered set.
     *
     * This function reads a list of Networks from a CSV file with the format
     * "airline_code,source_airport_code,target_airport_code"
     * and returns them in an unordered set of `Network` objects. If the file cannot be opened, an empty
     * unordered set is returned.
     *
     * @return An unordered set of `Network` objects representing the list of Networks read from the file.
     *
     * The complexity of this function is O(n), where n is the number of Networks in the file. It reads
     * through the file and inserts each Network into the unordered set, which has an average case time
     * complexity of O(1) for insertion.
     */
    static std::unordered_set<Network, NetworkHash> readNetworks();

    bool operator==(const Network& other) const {
        return stationA == other.stationA &&
                stationB == other.stationB &&
                capacity == other.capacity &&
                service == other.service;
    }

};

class NetworkHash {
    std::size_t operator()(const Network &a) const {
        std::size_t h1 = std::hash<std::string>()(a.source);
        std::size_t h2 = std::hash<std::string>()(a.target);
        std::size_t h3 = std::hash<std::string>()(a.airline);

        return h1 ^ (h2 << 1) ^ (h3 << 2) ;
    }
};