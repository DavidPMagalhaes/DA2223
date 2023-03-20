#include "string"
#include "unordered_set"
using namespace std;
class StationHash;
class Station {
public:
    int code;
    string name;
    string municipality;
    string township;
    string line;


    Station(int code, string name, string municipality, string township, string line);

    string getStationCode();

    string getStationName();

    string getStationMunicipality();

    string getStationTownship();

    string getStationLine();


    mutable bool visited;

    bool operator==(const Station &other) const {
        return code == other.code &&
               name == other.name &&
               municipality == other.municipality &&
               township == other.township &&
               line == other.line;
    }
};