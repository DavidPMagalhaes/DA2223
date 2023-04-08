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

extern Graph<Station*> g;
/**
 * Reads network data from a CSV file and creates Network objects based on the data, while also adding edges
 * to a graph and returning a vector of Network pointers.
 *
 * @param stations A vector of pointers to Station objects.
 *
 * @return The function `readNetworks` returns a vector of pointers to `Network` objects.
 */
vector<Network*> readNetworks(vector<Station*> stations);

/**
 * Reads station data from CSV file and creates Station objects, which are added to a vector and returned.
 *
 * @return The function `readStations` returns a vector of pointers to `Station` objects.
 */
vector<Station*> readStations();

/**
 * Finds a station object with a given name in a vector of station objects.
 * @param name The name of the station that we are searching for.
 * @param stations A vector of pointers to Station objects.
 *
 * @return a pointer to a Station object. If the station with the given name is found in the vector of stations, a pointer
 * to that station is returned. If not, the function returns a null pointer.
 */
Station* findStation(string name, vector<Station*> stations);


Network* findNetwork(Station name, vector<Network*> network);

/**
 * Splits a string into a vector of substrings based on a given delimiter character.
 *
 * @param str The input string that needs to be split into substrings based on the delimiter.
 * @param del The delimiter character used to split the input string into smaller substrings.
 *
 * @return a vector of strings that contains the substrings of the input string that were separated by the specified
 * delimiter character.
 */
vector<string> split(const string &str, const char del);