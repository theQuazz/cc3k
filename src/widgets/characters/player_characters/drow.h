#ifndef __DROW_H__
#define __DROW_H__

#include "player_character.h"

class Drow : public PlayerCharacter {
  public:
    Drow();
    std::string race();
};

#endif
