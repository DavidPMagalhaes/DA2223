#include <iostream>
#include "Network.h"
#include "Station.h"
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
int shortestPath(Graph<Station> *g, Station *origem, Station *destino){
    g->dijkstraShortestPath(*origem);
    vector<Station> v = g->getPath(*destino);
    cout << "tamanho do vetor " << v.size() << endl;
    return 0;
}



typedef pair<double, int> pdi;

const double INF = numeric_limits<double>::max();

vector<int> dijkstra(const Graph &graph, int src, int dst) {
    vector<double> dist(graph.getNumVertex(), INF);
    vector<int> parent(graph.getNumVertex(), -1);
    priority_queue<pdi, vector<pdi>, greater<pdi>> pq;

    dist[src] = 0;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (u == dst) {
            break;
        }

        for (auto edge : graph.getVertexSet()[u]->getAdj()) {
            int v = edge->getDest()->getId();
            double w = edge->getWeight();
            double capacity = edge->getWeight();

            double new_dist = dist[u] + capacity;
            if (new_dist < dist[v] && w >= capacity) {
                dist[v] = new_dist;
                parent[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    vector<int> path;
    int v = dst;
    while (v != -1) {
        path.push_back(v);
        v = parent[v];
    }
    reverse(path.begin(), path.end());

    return path;
}

void dijkstraShortestPath(Graph &graph, int startId, int endId, vector<int> &path, double &distance) {
    // set up priority queue for Dijkstra's algorithm
    auto cmp = [](const pair<double, Vertex *> &left, const pair<double, Vertex *> &right) {
        return left.first > right.first;
    };
    priority_queue<pair<double, Vertex *>, vector<pair<double, Vertex *>>, decltype(cmp)> pq(cmp);
    // initialize distances and previous vertex maps
    unordered_map<Vertex *, double> dist;
    unordered_map<Vertex *, Vertex *> prev;
    // set all distances to infinity and all previous vertices to null
    for (auto vertex : graph.getVertexSet()) {
        dist[vertex] = numeric_limits<double>::infinity();
        prev[vertex] = nullptr;
    }
    // set distance to start vertex to 0
    auto startVertex = graph.findVertex(startId);
    dist[startVertex] = 0;
    // add start vertex to priority queue
    pq.push(make_pair(0, startVertex));

    // Dijkstra's algorithm
    while (!pq.empty()) {
        auto u = pq.top().second;
        pq.pop();
        // stop if end vertex is reached
        if (u->getId() == endId) {
            break;
        }
        // relax edges of u
        for (auto edge : u->getAdj()) {
            auto v = edge->getDest();
            double alt = dist[u] + edge->getWeight();
            if (alt < dist[v]) {
                dist[v] = alt;
                prev[v] = u;
                pq.push(make_pair(alt, v));
            }
        }
    }
    // construct path and distance
    path.clear();
    auto endVertex = graph.findVertex(endId);
    if (prev[endVertex] != nullptr || endVertex == startVertex) {
        for (auto v = endVertex; v != nullptr; v = prev[v]) {
            path.push_back(v->getId());
        }
        reverse(path.begin(), path.end());
        distance = dist[endVertex];
    } else {
        distance = -1;
    }
}

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
        cout << "(1) View max number of trains that can simultaneously travel between two specific stations" << endl;
        cout << "(2) View shortest path between two stations" << endl;
        cout << "(3) View maximum number of trains that can simultaneously arrive at a given station" << endl;
        //cout << "(6) Indicate where management should..." << endl;
        cout << "(0) Exit" << endl;
        cout << "->";

        vector<int> inputs_menu_principal = {0, 1, 2, 3};
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
            Station *src = findStation(start, stations);
            Station *dest = findStation(end, stations);
            //maxNumberTrains(g, src, dest)
            break;
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
            Station *src = findStation(start, stations);
            Station *dest = findStation(end, stations);
            shortestPath(&g, src, dest);
            break;
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
        case 3:
        {
            cout << "Selected fifth option" << endl;
            cout << "View maximum number of trains that can simultaneously arrive at a given station" << endl;
            // ToDo
        }
        }
    }
}