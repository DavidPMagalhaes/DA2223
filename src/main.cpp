
#include <iostream>
#include <vector>
#include "istream"
#include "readFiles.h"

using namespace std;

/**
 * The shortestPath function calculates the shortest path between two stations in a graph and prints that path.
 *
 * @param g A pointer to a Graph object that contains a network of stations and their connections.
 * @param origem The "origem" parameter is a pointer to the starting station of the shortest path that we want to find.
 * @param destino The "destino" parameter is a pointer to the destination station in a graph of stations. It is used in the
 * "shortestPath" function to find the shortest path from the "origem" (source) station to the "destino" station using an
 * unweighted shortest path algorithm.
 */
void shortestPath(Graph<Station> *g, Station *origem, Station *destino){
    g->unweightedShortestPath(*origem);
    vector<Station> s = g->getPath(*destino);
    for (int i = 0; i < s.size(); i++){
        cout << s[i].getStationName();
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
void maxNumberTrains(Graph<Station> *g, Station *origem, Station *destino) {
    cout << "Max Number of Trains that can pass together: " << g->dijkstraShortestPath3(*origem, *destino) << endl;
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
void maxNumberTrainsAllStations(Graph<Station> *g, Station *destino, vector<Station*> stations) {
    int sum = 0;
    for (auto s: stations){
        sum += g->dijkstraShortestPath3(*s, *destino);
    }
    cout << sum << endl;
}

/**
 * This function finds the pair of stations with the highest capacity of trains between them using Dijkstra's shortest path
 * algorithm.
 *
 * @param g A pointer to a graph object of type Graph<Station>, which represents a network of train stations and their
 * connections.
 * @param stations A vector containing pointers to all the stations in the graph.
 */
void mostAmount(Graph<Station> *g, vector<Station*> stations) {
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
            weight = g->dijkstraShortestPath3(*origem, *destino);
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

/**
 * The main function contains a functional menu that allows the user to interact with a railway network and perform various
 * operations such as finding the maximum number of trains that can travel between two stations, finding the shortest path
 * between two stations, and determining which pairs of stations require the most amount of trains.
 */
int main(int argc, char const *argv[])
{
    //Create two graphs - station and network
    //Read all stations
    //Read all networks
    bool loop = true;

    vector <Station*> stations = readStations();
    readNetworks(stations);
    while (loop)
    {
        cout << "---------------------------------------------------------------" << endl;
        cout << "  _______   _         __  __                                   " << endl;
        cout << " |__   __| (_)       |  \\/  |                                  " << endl;
        cout << "    | |_ __ _ _ __   | \\  / | __ _ _ __   __ _  __ _  ___ _ __ " << endl;
        cout << "    | | '__| | '_ \\  | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '__|" << endl;
        cout << "    | | |  | | |_) | | |  | | (_| | | | | (_| | (_| |  __/ |   " << endl;
        cout << "    |_|_|  |_| .__/  |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_|   " << endl;
        cout << "             | |                                __/ |          " << endl;
        cout << "             |_|                               |___/           " << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout << "(1) View max number of trains that can simultaneously travel between two specific stations (T2.1)" << endl;
        cout << "(2) View shortest path between two stations" << endl;
        cout << "(3) View longest path between two stations" << endl;
        cout << "(4) Determine which pairs of stations require most amount of trains (T2.2)" << endl;
        cout << "(5) Report the max number of trains that can simultaneously arrive at a given station (T2.4)" << endl;
        cout << "(6) Calculate the max number of trains that can simultaneously travel between two stations at minimum cost" << endl;
        cout << "(0) Exit" << endl;
        cout << "->";

        vector<int> inputs_menu_principal = {0, 1, 2, 3, 4, 5, 6};
        int input_menu_principal;
        std::cin >> input_menu_principal;

        switch (input_menu_principal)
        {
            case 1:
            {
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
                break;
            }
            case 2:
            {
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
                break;
            }
            case 3:
            {
                cout << "Selected third option" << endl;
                cout << "View longest path between two stations" << endl;
                cout << "Input starting station: ";
                string start;
                cin >> start;
                cin.ignore();
                cout << "Input destination station: ";
                string end;
                getline(std::cin, end);
                cin.ignore();
                cout << "Starting station: " << start << std::endl;
                cout << "Destination station: " << end << std::endl;
                // ToDo
                break;
            }
            case 4:
            {
                cout << "Selected fourth option" << endl;
                cout << "Determine which pairs of stations require most amount of trains" << endl;
                mostAmount(&g, stations);
                break;
            }
            case 5: {
                cout << "Selected fifth option" << endl;
                cout << "Report the maximum number of trains that can simultaneously arrive at a given station,\n"
                        "taking into consideration the entire railway grid." << endl;
                cout << "Input destination station: " << endl;
                string end;
                cin.ignore();
                getline(std::cin, end);
                Station *dest = findStation(end, stations);
                maxNumberTrainsAllStations(&g, dest, stations);
                break;
            }
            case 6: {
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