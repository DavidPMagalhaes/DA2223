#include <iostream>
#include "menu.h"
#include "Network.h"
#include "Stations.h"
#include <vector>
#include <sstream>
#include "istream"

using namespace std;

void Menu::displayMenuInicial(){

    auto trips = Trip::readTrip();
    auto stations = Station::readStation();
    auto codeCityPairs = CodeCityPair::readCodeCityPairs();
    bool loop = true;
    while (loop) {
        cout << "--------------------------" << endl;
        cout << "       TRIP MANAGER       " << endl;
        cout << "--------------------------" << endl;
        cout << "(1) View fastest route" << endl;
        cout << "(2) Browse Station Info" << endl;
        cout << "(0) Exit" << endl;
        cout << "->";

        vector<int> inputs_menu_principal = {0, 1, 2, 3};
        int input_menu_principal;
        std::cin >> input_menu_principal;

        switch(input_menu_principal){
            case 1:{
                cout << "Starting Station:";
                string inPartida;
                getline(cin, inPartida);
                cout << endl;
                cout << "Destination Station:"<< endl;
                cout << "->";
                string inChegada;
                getline(cin, inChegada);
                cout << endl;
                    if (inPartida.size() > 3 ){
                        inPartida = CodeCityPair::stationToStation(inPartida);
                    }
                    if (inChegada.size() > 3 ){
                        inChegada = CodeCityPair::stationToStation(inChegada);
                    }
                    try {
                            unordered_map<string, vector<std::pair<std::string, double>>> graph = StationGraph::createGraph();
                            vector<string> path = StationGraph::getShortestPath(inPartida,inChegada);
                            std::cout << "Shortest path from " << inPartida << " to " << inChegada << ": " << endl;
                            for (const auto& station : path) {
                                std::cout  << " -> " << station;
                            }
                            std::cout << std::endl;
                            for (const auto& station : path) {
                                string stationName = CodeCityPair::stationToStation(station);
                                std::cout  << " -> " << stationName;
                            }
                            std::cout << std::endl;
                    }
                }
                break;
            }
            case 2:{
                while (loop) {
                cout << "Station:" << endl;
                cout << "->";
                string inStation;
                cin >> inStation;
                if (inStation.size() > 3){
                    inStation = CodeCityPair::stationToStation(inStation);
                }
                cout << endl;
                cout << "--------------------------" << endl;
                cout << "       STATION INFO       " << endl;
                cout << "--------------------------" << endl;
                cout << "(1) View number of trip" << endl;
                cout << "(2) View number of destinations" << endl;
                //Change to instead show all possible destinations
                cout << "(0) Exit" << endl;
                cout << "->";
                int inMenuStation;
                cin >> inMenuStation;
                cout << endl;
                switch(inMenuStation){
                    case 1:{
                        unordered_map<string, vector<std::pair<std::string, double>>> graph = StationGraph::createGraph();
                        string stationName = CodeCityPair::stationToStation(inStation);
                        std::size_t num_edges = StationGraph::numConnectedEdgesGoingOut(inStation);
                        std::cout << "Number of trips going out of " << stationName << "(" << inStation << ")" << " is " << num_edges << std::endl;
                        break;
                    }
                    case 2:{
                        unordered_map<string, vector<std::pair<std::string, double>>> graph = StationGraph::createGraph();
                        std::size_t num_connected = StationGraph::numConnectedNodes(inStation);
                        std::cout << "Number of destinations you can get to from " << inStation << " is " << num_connected << std::endl;
                        break;
                    }
                    case 0:
                        loop = false;
                        break;
                    default:{
                        cout << "Por favor insira uma opção válida." << endl;
                    }
            }
            case 0:
                loop = false;
                break;
            default:{
                cout << "Por favor insira uma opção válida." << endl;
            }
        }
    }
}