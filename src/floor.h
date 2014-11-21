#ifndef __FLOOR_H__
#define __FLOOR_H__

#include <iostream>

#include "chamber.h"

class Floor {
    Chamber *chamber[5];
    TextDisplay *display;
    Cell **grid;
  public:
    Floor(TextDisplay *display, char *configuration_file = NULL);
    Floor(const Floor &floor);
    ~Floor();

    void generate();

    friend std::istream &operator>>(std::istream &in, const &Floor floor);
};

#endif