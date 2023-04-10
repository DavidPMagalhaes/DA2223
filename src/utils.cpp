#include "readFiles.h"
#include <unordered_set>
#include <set>

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


/**
 * @brief Subgraph of a graph.
 *
 * Generates a subgraph of a given graph based on a set of stations, an origin station and a destination station.
 *
 * @param stations Vector containing pointers to the stations that should be included in the subgraph.
 * @param origem Pointer to the origin station.
 * @param destino Pointer to the destination station.
 * @return The subgraph generated from the given graph.
 */
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

/**
* @brief All paths between two stations
*
* Finds all possible paths between two vertices in a given graph.
*
* @tparam T Type of the vertices in the graph
* @param source Starting vertex
* @param destination Ending vertex
* @param graph Graph where to search for paths
*
* @return A vector of all possible paths, each path represented as a vector of vertices in order
*/
template<class T>
std::vector<std::vector<T>> getAllPaths(const T& source, const T& destination, Graph<T> g)  {
    validate(source, destination, g);
    std::vector<std::vector<T>> paths;
    std::unordered_set<T> visited;
    std::vector<T> path;
    recursive(source, destination, paths, visited, path, g);
    return paths;
}

/**
 * @brief Validates source and destination nodes in a graph.
 *
 * @tparam T Type of data stored in the graph.
 * @param source The source node.
 * @param destination The destination node.
 * @param g The graph to be validated.
 * @throws std::out_of_range If the source or destination node does not exist in the graph.
 * @throws std::invalid_argument If the source and destination are the same.
 */

template<class T>
void validate(const T& source, const T& destination, Graph<T> g)  {
    if (g.findVertex(source) == *g.vertexSet.end()) {
        throw std::out_of_range("The source node does not exist.");
    }
    if (g.findVertex(destination) == *g.vertexSet.end()) {
        throw std::out_of_range("The destination node does not exist.");
    }
    if (source == destination) {
        throw std::invalid_argument("The source and destination cannot be the same.");
    }
}

/**
* @brief Recursive function that finds all paths from a source vertex to a destination vertex in a graph
*
* @tparam T Type of vertex in the graph
* @param current Current vertex being visited
* @param destination Destination vertex being searched for
* @param paths Vector of vectors that will hold all the paths found
* @param path Unordered set containing the vertices visited so far
* @param graph Pointer to the graph being searched
*/
template<class T>
void recursive(const T& current, const T& destination, std::vector<std::vector<T>>& paths,
               std::unordered_set<T>& visited, std::vector<T>& path, Graph<T> g)  {
    path.push_back(current);
    if (current == destination) {
        paths.push_back(path);
    } else {
        for (const auto& edge : g.findVertex(current)->adj) {
            const auto& nextNode = edge.dest;

            if (find(path.begin(),path.end(),nextNode->getInfo()) == path.end()) {
                recursive(nextNode->getInfo(), destination, paths, visited, path, g);
            }
        }
    }
    path.pop_back();
}

/**
 * @brief Calculates the price of all the possible paths between two stations.
 *
 * @param source A pointer to the source station.
 * @param destination A pointer to the destination station.
 * @param graph A pointer to the graph containing all the stations.
 * @param network A pointer to the vector of networks containing the information about the stations.
 */
void calculatePrice(Station* source, Station* destination, Graph<Station*> *graph, vector<Network*> *network){
    vector<vector<Station*>> v = getAllPaths(source, destination, *graph);
    int i = 0;
    int sum = 0;
    sort( v.begin(), v.end() );
    v.erase( unique( v.begin(), v.end() ), v.end() );
    for (auto s : v){
        i++;
        cout << endl;
        cout << "Caminho: " << i << " (size=" << s.size() << ")" << endl;
        for (auto x : s){
            if (findNetwork(x, *network)->getService() == "STANDARD")
                sum += 2;
            else
                sum += 4;
            cout << x->getStationName() << endl;
        }
        cout << "Price: " << sum << endl;
        sum = 0;
    }
}