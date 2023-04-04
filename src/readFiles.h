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
extern vector<Network> networks;
extern vector<Station> stations;

vector<Network> readNetworks();

vector<Station> readStations();

Station findStation(string name);