#ifndef __ELF_H__
#define __ELF_H__

#include "hostile.h"

class Elf : public Hostile {
  public:
    Elf();
    char to_char() const;
};

#endif
