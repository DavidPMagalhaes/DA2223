#include "Network.h"
#include "Stations.h"
#include "fstream"
#include "Graph/Graph.h"
#include <iostream>
#include <cstring>
#include <utility>
#include <string>
#include <vector>
#include <sstream>


Graph<Station> g;
vector<Network> networks;
vector<Station> stations;

vector<Network> readNetworks();

vector<Station> readStations();