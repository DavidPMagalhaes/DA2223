#include <iostream>
#include "menu.h"
#include <vector>
#include <sstream>
#include "istream"
#include "readFiles.h"

using namespace std;
/*
Functionalities to be implemented
-Calculate all possible paths between two stations
    -Give:
        -Name Origin
        -Name Destination
    -Store:
        -Amount of stations passed
        -Maximum capacity of path
-View max number of trains (capacity) that can simultaneously travel between two specific stations
    -Calculate all paths while recording capacity for each
        -Maximum capacity is smallest capacity between two stations in path
        -Select path with maximum maximum capacity
    -View all stations passed in selected path
    -View capacity of path
-View shortest path between two stations, aka with least stations
    -Give:
        -Name Origin
        -Name Destination
    -View all stations passed, including start and finish
    -View capacity of path
-View longest path between two stations
    -Similar to shortest
-View highest capacity path between ANY TWO STATIONS
    -Calculate all paths between two stations
        -Select path with highest capacity
    -Move on to next pair of stations
    -Ensure no repeats
-View maximum number of trains that can simultaneously arrive at a given station
    -Give:
        -Name Station
    -Sum capacity of all direct paths (only two stations) that contain station
-Indicate where management should assign larger budgets for the purchasing and
maintenance of trains. That is, your implementation should be able to report the top-k municipalities
and districts, regarding their transportation needs
    -I don't know how to do this
*/
int shortestPath(Graph<Station> g, Station origem, Station destino){
    g.dijkstraShortestPath(origem);
    vector<Station> v = g.getPath(destino);
    cout << "tamanho do vetor " << v.size() << endl;

    for (int i = 0; i < v.size(); i++){
         cout << v[i].getCode() << endl;
    }
    return 0;
}


int main(int argc, char const *argv[])
{
    //Create two graphs - station and network
    //Read all stations
    //Read all networks
    bool loop = true;
    readNetworks();
    readStations();
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
        cout << "(1) View max number of trains that can simultaneously travel between two specific stations" << endl;
        cout << "(2) View shortest path between two stations" << endl;
        cout << "(3) View longest path between two stations" << endl;
        cout << "(4) View highest capacity path between any two stations" << endl;
        cout << "(5) View maximum number of trains that can simultaneously arrive at a given station" << endl;
        //cout << "(6) Indicate where management should..." << endl;
        cout << "(0) Exit" << endl;
        cout << "->";

        vector<int> inputs_menu_principal = {0, 1, 2, 3, 4, 5};
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
            cin >> start;
            cout << "Input destination station" << endl;
            cout << "->";
            string end;
            cin >> end;
            // ToDo
        }
        case 2:
        {
            cout << "Selected second option" << endl;
            cout << "View shortest path between two stations" << endl;
            cout << "Input starting station" << endl;
            cout << "->";
            string start;
            cin >> start;
            cout << "Input destination station" << endl;
            cout << "->";
            string end;
            cin >> end;
            Station src = findStation(start);
            Station dest = findStation(end);
            shortestPath(g, src, dest);
        }
        case 3:
        {
            cout << "Selected third option" << endl;
            cout << "View longest path between two stations" << endl;
            cout << "Input starting station" << endl;
            cout << "->";
            string start;
            cin >> start;
            cout << "Input destination station" << endl;
            cout << "->";
            string end;
            cin >> end;
            // ToDo
        }
        case 4:
        {
            cout << "Selected fourth option" << endl;
            cout << "View highest capacity path between any two stations" << endl;
            // ToDo
        }
        case 5:
        {
            cout << "Selected fifth option" << endl;
            cout << "View maximum number of trains that can simultaneously arrive at a given station" << endl;
            // ToDo
        }
        }
    }
}