#include "string"
#include <utility>
#include <vector>
#include "fstream"

using namespace std;

class Station {
public:
    Station();

    Station(int code, string name, string district, string municipality, string township, string line);

    int code;
    string name;
    string district;
    string municipality;
    string township;
    string line;

    string getStationName();

    string getStationMunicipality();

    string getStationTownship();

    string getStationLine();


    mutable bool visited;

    bool operator==(const Station &other) const {
        return name == other.name &&
               district == other.district &&
               municipality == other.municipality &&
               township == other.township &&
               line == other.line;
    }

    int getCode() const;

    void setCode(int code);
};