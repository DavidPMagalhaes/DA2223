
#include <iostream>
#include <vector>
#include "istream"
#include "readFiles.h"
#include <unordered_set>
#include <set>

using namespace std;

void option1(vector<Station *> stations);
void option2(vector<Station *> stations);
void option3(vector<Station *> stations);
void option4(vector<Station *> stations);
void option5(vector<Station *> stations, vector <Network*> networks);
void option6(vector<Station *> stations);

void check();


Graph<Station*> subgraph(vector<Station *> vector1, Station *origem, Station *destino);

/**
 * Displays the main menu on the console
 */
void menu() {
    cout << "|---------------------------------------------------------------------------------------|" << endl;
    cout << "|     _____       _ _                       __  __                                      |" << endl;
    cout << "|    |  __ \\     (_) |                     |  \\/  |                                     |" << endl;
    cout << "|    | |__) |__ _ _| |_      ____ _ _   _  | \\  / | __ _ _ __   __ _  __ _  ___ _ __    |" << endl;
    cout << "|    |  _  // _` | | \\ \\ /\\ / / _` | | | | | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '__|   |" << endl;
    cout << "|    | | \\ \\ (_| | | |\\ V  V / (_| | |_| | | |  | | (_| | | | | (_| | (_| |  __/ |      |" << endl;
    cout << "|    |_|  \\_\\__,_|_|_| \\_/\\_/ \\__,_|\\__, | |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_|      |" << endl;
    cout << "|                                    __/ |                            __/ |             |" << endl;
    cout << "|                                   |___/                            |___/              |" << endl;
    cout << "|---------------------------------------------------------------------------------------|" << endl;
    cout << "(1) View max number of trains that can simultaneously travel between two specific stations (T2.1)" << endl;
    cout << "(2) View shortest path between two stations" << endl;
    cout << "(3) Determine which pairs of stations require most amount of trains (T2.2)" << endl;
    cout << "(4) Report the max number of trains that can simultaneously arrive at a given station (T2.4)" << endl;
    cout << "(5) Calculate the max number of trains that can simultaneously travel between two stations at minimum cost" << endl;
    cout << "(6) Calculate the max number of trains that can simultaneously travel between two stations at reduced connectivity" << endl;
    cout << "(0) Exit" << endl;
    cout << "->";
}

/**
 * The shortestPath function calculates the shortest path between two stations in a graph and prints that path.
 *
 * @param g A pointer to a Graph object that contains a network of stations and their connections.
 * @param origem The "origem" parameter is a pointer to the starting station of the shortest path that we want to find.
 * @param destino The "destino" parameter is a pointer to the destination station in a graph of stations. It is used in the
 * "shortestPath" function to find the shortest path from the "origem" (source) station to the "destino" station using an
 * unweighted shortest path algorithm.
 */
void shortestPath(Graph<Station*> *g, Station *origem, Station *destino){
    g->unweightedShortestPath(origem);
    vector<Station*> s = g->getPath(destino);
    for (int i = 0; i < s.size(); i++){
        cout << s[i]->getStationName() << endl;
    }
}

/**
 * The maxNumberTrains function calculates the max number of trains that can pass together between two given stations using Dijkstra's
 * shortest path algorithm.
 *
 * @param g A pointer to a graph object of type `Graph<Station>`. This graph represents a network of train stations, where
 * each station is a vertex in the graph and each train route between stations is an edge in the graph.
 * @param origem The parameter "origem" is a pointer to an object of the class "Station", which represents the starting
 * point of a train journey.
 * @param destino The "destino" parameter is a pointer to the destination station in a graph of train stations. It is used
 * in the function "maxNumberTrains" to calculate the maximum number of trains that can pass together between the origin
 * station and the destination station using Dijkstra's shortest path algorithm.
 */
void maxNumberTrains(Graph<Station*> *g, Station *origem, Station *destino) {
    g->unweightedShortestPath(origem);
    vector<Station*> v = g->getPath(destino);
    for (auto s : v){
        cout << s->getStationName() << endl;
    }
    if (v.size() == 0){
        cout << "There is no path between both stations" << endl;
    } else
        cout << "Max Number of Trains that can pass together: " << g->maxNumberTrain(origem, destino) << endl;
}

/**
 * This function calculates the maximum number of trains that can travel from a set of stations to a destination station
 * using Dijkstra's shortest path algorithm.
 *
 * @param g A pointer to a graph object of type `Graph<Station>`. This graph represents the train stations and their
 * connections.
 * @param destino The "destino" parameter is a pointer to a Station object that represents the destination station.
 * @param stations The "stations" parameter is a vector of pointers to Station objects. It is a list of all stations
 */
void maxNumberTrainsAllStations(Graph<Station*> *g, Station *destino, vector<Station*> stations)  {
    int sum = 0;
    for (auto s: stations) {
        g->unweightedShortestPath(s);
        vector<Station*> v = g->getPath(destino);
        int w = g->maxNumberTrain(s, destino);
        if (w > sum) {
            sum = g->maxNumberTrain(s, destino);
        }
    }
    cout << sum << endl;
}

/*
void allPaths(Graph<Station> *g, Station *origem, Station *destino, vector<Network*> networks){
    g->unweightedShortestPath(*origem);
    vector<Station> s = g->getPath(*destino);
    g->notUnweightedShortestPath(*origem, *destino);
    vector<Station> s2 = g->getPath(*destino);

    int sum = 0;
    for (auto a : s){if (findNetwork(g->findVertex(a)->getInfo(), networks)->getService() == "STANDARD")
            sum +=2;
        else
            sum +=4;
    }
    int sum2 = 0;
    for (auto a : s2){
        if (findNetwork(g->findVertex(a)->getInfo(), networks)->getService() == "STANDARD")
            sum2 += 2;
        else
            sum2 += 4;
    }
    cout << "sum " << sum << endl;
    cout << "sum2 " << sum2 << endl;
    if (sum >= sum2){
        cout << "entrou" << endl;
        for (int i = 0; i < s.size(); i++){
            cout << s[i].getStationName() << endl;
        }
    }
    else{
        cout << "entrou2" << endl;
        for (int i = 0; i < s2.size(); i++){
            cout << s2[i].getStationName() << endl;
        }
    }
}*/

/**
 * This function finds the pair of stations with the highest capacity of trains between them using Dijkstra's shortest path
 * algorithm.
 *
 * @param g A pointer to a graph object of type Graph<Station>, which represents a network of train stations and their
 * connections.
 * @param stations A vector containing pointers to all the stations in the graph.
 */
void mostAmount(Graph<Station*> *g, vector<Station*> stations) {
    Station *origem;
    Station *destino;
    int weight=0;
    Station *maxO, *maxD;
    int maxW=0;
    for (int i = 1; i < stations.size(); ++i) {
        cout << "Station: " << stations[i]->getStationName() << endl;
        cout << "Loading...";
        for (int j = i+1; j < stations.size(); ++j) {
            origem= stations[i];
            destino=stations[j];
            weight = g->dijkstraShortestPath3(origem, destino);
            if (j%20==0) {
                cout << ".";
            }
        }
        cout << endl;
        if (maxW<weight) {
            maxW=weight;
            maxO=origem;
            maxD=destino;
        }
    }
    cout << "Most amount of trains happen in pair: " << maxO->getStationName() << " and " << maxD->getStationName() << endl;
    cout << "Capacity of pair:" << maxW << endl;
}

template<typename T>
struct GenericHash {
    size_t operator()(const T& station) const {
        // use the hash function for std::string as the basis for the hash
        return std::hash<std::string>()(station->getStationName());
    }
};


template<typename T>
vector<vector<T>> getAllPaths(T source, T destination, Graph<T> graph) {

    vector<vector<T>> paths;
    recursive(source, destination, paths, std::unordered_set<T,GenericHash<T>>(), &graph);
    return paths;
}

Graph<Station*> subgraph(vector<Station*> stations, Station* origem, Station* destino) {
    Graph<Station*> subgraph;
    set<Vertex<Station*>*> visited;
    subgraph.addVertex(origem);
    subgraph.addVertex(destino);
    for (auto station : stations) {
        Vertex<Station*>* vertex = g.findVertex(station);
        if (vertex != nullptr && visited.find(vertex) == visited.end()) {
            subgraph.addVertex(vertex->getInfo());
            visited.insert(vertex);
            for (auto adjacent : vertex->getAdj()) {
                if (find(stations.begin(), stations.end(), adjacent->getInfo()) != stations.end()) {
                    subgraph.addVertex(adjacent->getInfo());
                    subgraph.addEdge(vertex->getInfo(), adjacent->getInfo(), vertex->getWeight(adjacent));
                }
            }
        }
    }
    // Add origin and destination stations edges
    for (auto station : stations) {
        if (station != origem && station != destino) {
            continue;
        }
        Vertex<Station*>* vertex = g.findVertex(station);
        if (vertex != nullptr) {
            for (auto adjacent : vertex->getAdj()) {
                if (adjacent->getInfo() == origem || adjacent->getInfo() == destino) {
                    subgraph.addEdge(vertex->getInfo(), adjacent->getInfo(), vertex->getWeight(adjacent));
                }
            }
        }
    }
    return subgraph;
}



template<typename T>
void recursive(T current, T destination, vector<vector<T>>& paths, std::unordered_set<T,GenericHash<T>>  path, Graph<T> *graph) {
    path.insert(current);
    if (current == destination) {
        paths.push_back(vector<T>(path.begin(), path.end()));
        path.erase(current);
        return;
    }
    for (Edge<T> e : g.findVertex(current)->adj) {
        if (path.count(e.dest->getInfo()) == 0) {
            recursive(e.dest->getInfo(), destination, paths, path, graph);
        }
    }
    path.erase(current);
}


void allPath(Station* source, Station* destination, Graph<Station*> *graph){
    vector<vector<Station*>> v = getAllPaths(source, destination, *graph);
    int i = 0;
    cout << "size" << v.size() << endl << endl;
    cout << " " << endl;
    for (auto s : v){
        i++;
        cout << endl;
        cout << "Caminho: " << i << endl;
        for (auto x : s){
            cout << x->getStationName() << endl;
        }
    }
}




/**
 * @brief Main function of the program
 * The main function of the program. Creates two graphs - station and network, reads
 * all stations and networks, presents a menu of options for the user to choose from.
 */
int main(int argc, char const *argv[])
{
    //Create two graphs - station and network
    //Read all stations
    //Read all networks
    bool loop = true;

    vector <Station*> stations = readStations();
    vector <Network*> networks = readNetworks(stations);
    while (loop)
    {
        menu();
        int input_menu_principal;
        std::cin >> input_menu_principal;
        switch (input_menu_principal)
        {
            case 1:
            {
                option1(stations);
                check();
                break;
            }
            case 2:
            {
                option2(stations);
                check();
                break;
            }
            case 3:
            {
                option3(stations);
                check();
                break;
            }
            case 4: {
                option4(stations);
                check();
                break;
            }
            case 5: {
                option5(stations, networks);
                check();
                break;
            }
            case 6: {
                option6(stations);
                check();
                break;
            }
            case 0: {
                std::cout << "Exiting program..." << std::endl;
                return 0;
            }
            default:
                std::cout << "Number not found" << std::endl;
        }
    }
}



/**
 * @brief Ask user whether to continue or exit the program
 *
 * Prints a prompt to the console asking the user whether to continue
 * running the program or exit. If user enters 0, the function will
 * print a message indicating that the program is exiting and exit the program.
 */
void check() {
    cout << "Continue?";
    cout << "(1) Yes" << endl;
    cout << "(0) No" << endl;
    int input;
    cin >> input;
    if (input==0) {
        std::cout << "Exiting program..." << std::endl;
        exit(0);
    }
}

/**
 * @brief Select option 1
 *
 * Allows the user to view the maximum number of trains that can simultaneously travel between two specific stations.
 * Asks for starting and destination stations and prints the result to the console.
 *
 * @param stations Vector of pointers to Station objects
 */
void option1(vector<Station *> stations) {
    cout << "Selected first option" << endl;
    cout << "View max number of trains that can simultaneously travel between two specific stations" << endl;
    cout << "Input starting station" << endl;
    cout << "->";
    string start;
    cin.ignore();
    getline(std::cin, start);
    cout << "Input destination station: " << endl;
    string end;
    getline(std::cin, end);
    cout << "Starting station: " << start << std::endl;
    cout << "Destination station: " << end << std::endl;
    Station *src = findStation(start, stations);
    Station *dest = findStation(end, stations);
    maxNumberTrains(&g, src, dest);
}

/**
 * @brief Select option 2
 *
 * Allows the user to view the shortest path between two stations.
 * Asks for starting and destination stations and prints the result to the console.
 *
 * @param stations Vector of pointers to Station objects
 */
void option2(vector<Station *> stations) {
    cout << "Selected second option" << endl;
    cout << "View shortest path between two stations" << endl;
    cout << "Input starting station" << endl;
    cout << "->";
    string start;
    cin.ignore();
    getline(std::cin, start);
    cout << "Input destination station: " << endl;
    string end;
    getline(std::cin, end);
    cout << "Starting station: " << start << std::endl;
    cout << "Destination station: " << end << std::endl;
    Station *src = findStation(start, stations);
    Station *dest = findStation(end, stations);
    shortestPath(&g, src, dest);
}

/**
 * @brief Select option 3
 *
 * Allows the user to determine which pairs of stations require the most amount of trains.
 * Prints the result to the console.
 *
 * @param stations Vector of pointers to Station objects
 */
void option3(vector<Station *> stations) {
    cout << "Selected fourth option" << endl;
    cout << "Determine which pairs of stations require most amount of trains" << endl;
    mostAmount(&g, stations);
}

/**
 * @brief Select option 4
 *
 * Allows the user to report the max number of trains that can simultaneously arrive at a given station
 * Asks for destination station and prints the result to the console.
 *
 * @param stations Vector of pointers to Station objects
 */
void option4(vector<Station *> stations) {
    cout << "Selected fourth option" << endl;
    cout << "Report the maximum number of trains that can simultaneously arrive at a given station,\n"
            "taking into consideration the entire railway grid." << endl;
    cout << "Input destination station: " << endl;
    string end;
    cin.ignore();
    getline(std::cin, end);
    Station *dest = findStation(end, stations);
    maxNumberTrainsAllStations(&g, dest, stations);
}
/**
 * @brief Select option 5
 *
 * Allows the user to alculate the max number of trains that can simultaneously travel
 * between two stations at minimum cost to the company.
 *
 * @param stations
 * @param networks
 */
void option5(vector<Station *> stations, vector <Network*> networks) {
    cout << "Selected sixth option" << endl;
    cout << "Calculate the max amount of trains that can simultaneously travel between two specific "
            "stations with minimum cost for the company. Note that your system should also take any valid "
            "source and destination stations as input;" << endl;
    cout << "Input destination station: " << endl;
    cout << "Input starting station" << endl;
    cout << "->";
    string start;
    cin.ignore();
    getline(std::cin, start);
    cout << "Input destination station: " << endl;
    string end;
    getline(std::cin, end);
    cout << "Starting station: " << start << std::endl;
    cout << "Destination station: " << end << std::endl;
    Station *src = findStation(start, stations);
    Station *dest = findStation(end, stations);
    allPath(src, dest, &g);
}

void option6(vector<Station *> stations) {
    cout << "Selected sixth option" << endl;
    cout << "Calculate the max number of trains that can simultaneously travel between two stations at reduced connectivity" << endl;
    cout << "Input starting station" << endl;
    cout << "->";
    string start;
    cin.ignore();
    getline(std::cin, start);
    cout << "Input destination station: " << endl;
    string end;
    getline(std::cin, end);
    cout << "Starting station: " << start << std::endl;
    cout << "Destination station: " << end << std::endl;
    Station *src = findStation(start, stations);
    Station *dest = findStation(end, stations);

    Graph<Station*> soup = subgraph(stations, src, dest);
    cout << "Subgraph created successfully" << endl;
    maxNumberTrains(&soup, src, dest);

}