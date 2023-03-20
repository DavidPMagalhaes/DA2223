
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Network.h"
#include "readFiles.h"

using namespace std;

vector<Station> readStations()
{
    string fname = "/home/bianca/Documents/DA/DA2223/Project1Data/stations.csv";

    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream file (fname, ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();

            stringstream str(line);
            getline(str, word, ',');
            while(getline(str, word, ',')) {
                row.push_back(word);
            }

            Station stat(stoi(row[0]), row[1], row[2], row[3], row[4]);
            g.addVertex(stat);
            stations.push_back(stat);
        }
    }
    else
        cout<<"Could not open the file\n";

    return stations;
}

Station findStation(string name){
    for (int i = 0; i < stations.size(); i++){
        if (stations[i].name == name)
            return stations[i]
    }
}

vector<Network> readNetworks()
{
    string fname = "/home/bianca/Documents/DA/DA2223/Project1Data/network.csv";

    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream file (fname, ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();

            stringstream str(line);
            getline(str, word, ',');
            while(getline(str, word, ',')) {
                row.push_back(word);
            }

            Network net(findStation(row[0]), findStation(row[1]), stoi(row[2]), row[3]);
            g.addEdge(net.stationA, net.stationB, net.capacity);
            networks.push_back(net);
        }
    }
    else
        cout<<"Could not open the file\n";

    return networks;
}

