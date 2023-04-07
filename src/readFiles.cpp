#include "readFiles.h"

using namespace std;

Graph<Station> g;



/**
 * Reads station data from CSV file and creates Station objects, which are added to a vector and returned.
 *
 * @return The function `readStations` returns a vector of pointers to `Station` objects.
 */
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

/**
 * Finds a station object with a given name in a vector of station objects.
 * @param name The name of the station that we are searching for.
 * @param stations A vector of pointers to Station objects.
 *
 * @return a pointer to a Station object. If the station with the given name is found in the vector of stations, a pointer
 * to that station is returned. If not, the function returns a null pointer.
 */
Station* findStation(string name, vector<Station*> stations){
    for (int i = 0; i < stations.size(); i++) {
        Station st = *stations[i];
        string s = stations[i]->getStationName();
        transform(name.begin(),name.end(), name.begin(), ::tolower);
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if (s == name)
            return stations[i];
    }
    return NULL;
}

/**
 * Splits a string into a vector of substrings based on a given delimiter character.
 *
 * @param str The input string that needs to be split into substrings based on the delimiter.
 * @param del The delimiter character used to split the input string into smaller substrings.
 *
 * @return a vector of strings that contains the substrings of the input string that were separated by the specified
 * delimiter character.
 */
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

/**
 * Reads network data from a CSV file and creates Network objects based on the data, while also adding edges
 * to a graph and returning a vector of Network pointers.
 *
 * @param stations A vector of pointers to Station objects.
 *
 * @return The function `readNetworks` returns a vector of pointers to `Network` objects.
 */
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

