#include "readFiles.h"

using namespace std;

Graph<Station> g;
vector<Network> networks;
vector<Station> stations;

vector<Station> readStations()
{
    string fname = "/home/bianca/Documents/DA/DA2223/Data/stations.csv";

    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream file (fname, ios::in);
    if(file.is_open())
    {
        int i = 0;
        while(getline(file, line))
        {

            row.clear();

            stringstream str(line);

            while(getline(str, word, ',')) {
                row.push_back(word);
            }
            Station stat(i, row[0], row[1], row[2], row[3], row[4]);
            g.addVertex(stat);
            stations.push_back(stat);
            i++;
        }
    }
    else
        cout<<"Could not open the file\n";

    return stations;
}

Station findStation(string name){
    for (int i = 0; i < stations.size(); i++){
        if (stations[i].name == name)
            return stations[i];
    }
    return Station();
}

vector<string> split(const string &str, const char del) { // del= delimitador
    vector<string> splitted;
    string tmp;
    for(char i : str) {
        if(i!=del) {
            tmp += i;
        } else {
            splitted.push_back(tmp);
            tmp = "";
        }
    }

    splitted.push_back(tmp);

    return splitted;
}

vector<Network> readNetworks()
{
    string fname = "/home/bianca/Documents/DA/DA2223/Data/network.csv";

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

            while (std::getline(file, line)) {
                if (line.empty()) continue;
                vector<string> row = split(line, ',');
                Network net(findStation(row[0]).getCode(), findStation(row[1]).getCode(), stoi(row[2]), row[3]);
                g.addEdge(findStation(row[0]), findStation(row[1]), net.getCapacity());
                networks.push_back(net);
            }
        }
    }
    else
        cout<<"Could not open the file\n";

    return networks;
}

