#pragma once
#include "Network.h"
#include "fstream"
#include "Graph/Graph.h"
#include <iostream>
#include <cstring>
#include <utility>
#include <string>
#include <vector>
#include <sstream>

extern Graph<Station> g;

vector<Network*> readNetworks(vector<Station*> stations);

vector<Station*> readStations();

Station* findStation(string name, vector<Station*> stations);