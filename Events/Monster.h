#pragma once
#include "Monster.h"
#include <string>
class Event;

class Monster{
public:
virtual int getCombatPower() const=0;
virtual int getLoot () const=0;
virtual int getDamage () const=0;
virtual std::string getDescription() const =0;

virtual ~Monster() = default;


};