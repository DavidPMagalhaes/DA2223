#include "readFiles.h"

using namespace std;

Graph<Station> g;



vector<Station*> readStations()
{
    string fname = "../Data/stations.csv";

    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    vector<Station *> stations;

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
            Station* stat = new Station(i,row[0],row[1],row[2],row[3], row[4]);
            // no final do codigo pra cada station fazer "delete station"
            g.addVertex(*stat);
            stations.push_back(stat);
            i++;
        }
    }
    else
        cout<<"Could not open the file\n";

    return stations;
}

Station* findStation(string name, vector<Station*> stations){
    for (int i = 0; i < stations.size(); i++) {
        Station st = *stations[i];
        string s = stations[i]->getStationName();
        if (s == name)
            return stations[i];
    }
    return NULL;
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

vector<Network *> readNetworks(vector<Station*> stations)
{
    string fname = "../Data/network.csv";

    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    vector<Network *> networks;

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
                Station *src = findStation(row[0], stations);
                Station *dest = findStation(row[1], stations);
                Network *net = new Network(src->getCode(), dest->getCode(), stoi(row[2]), row[3]);
                g.addEdge(*src, *dest, net->getCapacity());
                networks.push_back(net);
            }
        }
    }
    else
        cout<<"Could not open the file\n";

    return networks;
}

