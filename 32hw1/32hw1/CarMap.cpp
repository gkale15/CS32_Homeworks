#include "CarMap.h"
#include "Map.h"
#include <iostream>

CarMap::CarMap()
:m_map()
{
}       // Create an empty car map.


bool CarMap::addCar(std::string license) {
  // If a car with the given license plate is not currently in the map,
  // and there is room in the map, add an entry for that car recording
  // that it has been driven 0 miles, and return true.  Otherwise,
  // make no change to the map and return false.
    
    if (m_map.insert(license, 0.0)) {
        return true;
    }
    return false;
}

double CarMap::miles(std::string license) const {
  // If a car with the given license plate is in the map, return how
  // many miles it has been driven; otherwise, return -1.
    double miles = -1;
    if (m_map.get(license, miles)) {
        return miles;
    }
    return miles;
}

bool CarMap::drive(std::string license, double distance) {
  // If no car with the given license plate is in the map or if
  // distance is negative, make no change to the map and return
  // false.  Otherwise, increase by the distance parameter the number
  // of miles the indicated car has been driven and return true.
    
    //check if key there
    if (!m_map.contains(license)) {
        return false;
    }
    
    //check if distance negative
    double checkIfDouble;
    m_map.get(license, checkIfDouble);
    if (checkIfDouble < 0) {
        return false;
    }
    
    //update mileage
    distance += checkIfDouble;
    m_map.update(license, distance);
    return true;
}

int CarMap::fleetSize() const {
    
 // Return the number of cars in the CarMap.
    return m_map.size();
}

void CarMap::print() const {
  // Write to cout one line for every car in the map.  Each line
  // consists of the car's license plate, followed by one space,
  // followed by the number of miles that car has been driven.  Write
  // no other text.  The lines need not be in any particular order.
    std::string license;
    double distance;
    
    for (int i = 0; i < m_map.size(); i++) {
        m_map.get(i, license, distance);
        std::cout << license << " " << distance << std::endl;
    }
}



