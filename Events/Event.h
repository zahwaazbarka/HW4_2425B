
#pragma once

#include "../Players/Player.h"

class Event {
public:
    virtual std::string apply(Player* Player)=0;
    virtual std::string getDescription() const=0;
    virtual ~Event() = default;
};
