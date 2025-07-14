#pragma once

#include <string>

class Player;

class Job{
public:

virtual int getCombatPower(const Player& player) const=0;

virtual std::string getJobName () const=0;

virtual void onSolarEclipse(Player& player) const=0;

virtual bool isRanged() const=0;

virtual ~Job() = default;


};