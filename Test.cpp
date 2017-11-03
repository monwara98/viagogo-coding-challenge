#include "Coordinate.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    int retval = 0;
    int id = 0;
    int x;
    int y;

    vector<Event> events;
    vector<Coordinate> coords;
    vector<int> distance;
    vector<Coordinate> temp;
    vector<Event> temp2;

    for (int i = 0; i < 8; i++) {
      int v1 = rand() % 21 - 10;
      int v2 = rand() % 21 - 10;
      Coordinate c(v1, v2);
      coords.push_back(c);

      int v4 = rand() % 101;
      int v5 = rand() % 101;

      Event e(id,v4,v5,c);
      id++;
      events.push_back(e);
    }

    cout << "Enter a value for the X coordinate (between -10 and 10):" << endl;
    cin >> x;
    cout << "Enter a value for the Y coordinate (between -10 and 10):" << endl;
    cin >> y;
    cout << endl;

    if (x > 10) { x = 10; }
    else if (x < -10) { x = -10; }

    if (y > 10) { y = 10; }
    else if (y < -10) { y = -10; }

    Coordinate z(x,y);
    coords.push_back(z);

    for (int i = 0; i < coords.size() - 1; i++) {
      distance.push_back(z.manhattanDistance(coords[i]));
    }

    cout << "Closest Events to (" << x << ", " << y << "):" << endl;
    sort(distance.begin(), distance.end());

    distance.erase(distance.begin() + 5, distance.end());

    for (int i = 0; i < coords.size(); i++) {
      for (int j = 0; j < distance.size(); j++) {
        if (distance[j] == z.manhattanDistance(coords[i])) {
          temp.push_back(coords[i]);
          coords.erase(coords.begin() + i);
        }
      }
    }

    for (int i = 0; i < events.size(); i++) {
      for (int j = 0; j < temp.size(); j++) {
        if ( (temp[j].getX() == events[i].getX()) && (temp[j].getY() == events[i].getY()) ) {
          temp2.push_back(events[i]);
        }
      }
    }

    for (int i = 0; i < temp2.size(); i++) {
      if (temp2[i].getID() == temp2[i+1].getID()) {
        temp2.erase(temp2.begin() + i);

      }
      cout << temp2[i] << " distance " << temp2[i].manhattanDistance(z.getX(), z.getY()) << endl;
    }

    return retval;

}
