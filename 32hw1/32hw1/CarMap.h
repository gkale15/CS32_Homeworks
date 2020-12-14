#ifndef CARMAP_H
#define CARMAP_H

#include "Map.h"
#include <iostream>

class CarMap
  {
    public:
      CarMap();       
      bool addCar(std::string license);
      double miles(std::string license) const;
      bool drive(std::string license, double distance);
      int fleetSize() const;
      void print() const;

    private:
      Map m_map;
  };

#endif


