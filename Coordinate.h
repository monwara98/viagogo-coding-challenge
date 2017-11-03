#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>
#include <math.h>

using namespace std;

class Coordinate {

public:
    int xCoord = 0;
    int yCoord = 0;
    int distance = 0;

    Coordinate(int x, int y)
      : xCoord(x),
        yCoord(y) {
    }

    int getX() const {
      return xCoord;
    }

    int getY() const {
      return yCoord;
    }

    int checkX(int value) {
      if (value > 10) {
        xCoord = 10;
      } else if (value < -10) {
        xCoord = -10;
      }

      return xCoord;
    }

    int checkY(int value) {
      if (value > 10) {
        yCoord = 10;
      } else if (value < -10) {
        yCoord = -10;
      }

      return yCoord;
    }

    int manhattanDistance(Coordinate c) {
      distance = fabs(checkX(xCoord) - c.checkX(c.getX())) + fabs(checkY(yCoord) - c.checkY(c.getY()));
      return distance;
    }

};

    std::ostream& operator<<(std::ostream& os, const Coordinate& obj) {
        return os << "(" << obj.xCoord << "," << obj.yCoord << ")";
}



class Event {

public:
    int id = 0;
    int tickets = 0;
    double price = 0;
    Coordinate coord;

    Event(int uniqueID, int t, double dollars, Coordinate c)
      : id(uniqueID),
        tickets(t),
        price(dollars),
        coord(c) {
    }

    int getID() {
      return id;
    }

    int getX() {
      return coord.getX();
    }

    int getY() {
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
