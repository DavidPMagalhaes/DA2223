#include "Network.h"
#include "NetworkControl.h"
#include "fstream"

#include <utility>


using namespace std;

Network::Network() = default;

Network::Network(string stationA, string stationB, int capacity, string service) {
    this->stationA  = stationA;
    this->stationB= stationB;
    this->capacity = capacity;
    this->service = service;
}

Network::Network(basic_string<char, char_traits<char>, allocator<char>> basicString) {

}

std::unordered_set<Network, NetworkHash> Network::readNetworks() {
    std::string filename = "dataset/Networks.csv";
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return {};
    }

    std::unordered_set<Network, NetworkHash> Networks;
    std::string line;
    getline(file,line);
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::vector<std::string> data = NetworkControl::split(line, ',');
        Network net(data[0], data[1], (int) data[2], data[3]);
        Networks.insert(net);
    }
    return Networks;

}