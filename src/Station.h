#include "string"
#include <utility>
#include <vector>
#include "fstream"

using namespace std;

class Station : public error_code {
public:

    /**
     * @brief Construct a new Station object with default values.
     */
    Station();

    /**
     * @brief Construct a new Station object with the given parameters.
     *
     * @param code The code of the station.
     * @param name The name of the station.
     * @param district The district in which the station is located.
     * @param municipality The municipality in which the station is located.
     * @param township The township in which the station is located.
     * @param line The line to which the station belongs.
     */
    Station(int code, string name, string district, string municipality, string township, string line);

    int code;
    string name;
    string district;
    string municipality;
    string township;
    string line;

    /**
     * @brief Get the name of the station.
     *
     * @return The name of the station.
     */
    string getStationName() const;

    /**
     * @brief Get the municipality in which the station is located.
     *
     * @return The municipality in which the station is located.
     */
    string getStationMunicipality() const;

    /**
     * @brief Get the township in which the station is located.
     *
     * @return The township in which the station is located.
     */
    string getStationTownship() const;

    /**
     * @brief Get the line to which the station belongs.
     *
     * @return The line to which the station belongs.
     */
    string getStationLine() const;


    mutable bool visited;

    /**
     * @brief Check if this Station object is equal to another Station object.
     *
     * @param other The other Station object.
     * @return true if the objects are equal, false otherwise.
     */
    bool operator==(const Station &other) const {
        return name == other.name &&
               district == other.district &&
               municipality == other.municipality &&
               township == other.township &&
               line == other.line;
    }

    /**
     * @brief Get the code of the station.
     *
     * @return The code of the station.
     */
    int getCode() const;

    /**
     * @brief Set the code of the station.
     *
     * @param code The new code of the station.
     */
    void setCode(int code);
};
