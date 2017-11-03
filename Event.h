#ifndef EVENT_H
#define EVENT_H

#include "Coordinate.h"
#include <iostream>
#include <math.h>

using namespace std;

class Event {

public:
    int id = 0;
    int tickets = 0;
    int price = 0;
    Coordinate coord;

    Event(int uniqueID, int t, int dollars, Coordinate c)
      : id(uniqueID),
        tickets(t),
        price(dollars),
        coord(c) {
    }

    int getID() const {
      return id;
    }

    int getX() const {
      return coord.getX();
    }

    int getY() const {
      return coord.getY();
    }

    int manhattanDistance(int x, int y) {
      int distance = fabs(coord.checkX(coord.getX()) - x) + fabs(coord.checkY(coord.getY()) - y);
      return distance;
    }
};

    std::ostream& operator<<(std::ostream& os, const Event& obj) {
        return os << "Event " << obj.id << " - " << "$" << obj.price;
    }

#endif
