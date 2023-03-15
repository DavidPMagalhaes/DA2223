#include "string"
#include "unordered_set"
using namespace std;
class StationHash;
class Station {

    string code;
    string name;
    string municipality;
    string township;
    string line;


    //Station(string code);
    Station(string code, string name, string municipality, string township, string line);

    string getStationCode();

    string getStationName();

    string getStationMunicipality();

    string getStationTownship();

    string getStationLine();

    static std::unordered_set<Station, StationHash> readStations();

    mutable bool visited;

    bool operator==(const Station &other) const {
        return code == other.code &&
               name == other.name &&
               municipality == other.municipality &&
               township == other.township &&
               line == other.line;
    }


    class StationHash {
        std::size_t operator()(const Station &a) const {
            std::size_t h1 = std::hash<std::string>()(a.code);
            return h1;
        }
    };

public:
    Station();
}