#pragma once

#include <string>

class Player;
class Job{
private:

virtual int getCombatPower(const Player& player) const=0;

virtual std::string getJobName () const=0;
virtual void onScolarExlipse(const Player& player) const=0;

virtual bool isRanged(const Player& player) const=0;

virtual ~Job() = default;


};