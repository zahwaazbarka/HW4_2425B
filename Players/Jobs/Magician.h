#pragma once 
#include "Job.h"
#include "../Player.h"

class Magician :public Job{
public:
	Magician()= default;

	int getCombatPower(const Player& player) const override{
		return player.getForce() + player.getLevel();
	}
	std::string getJobName() const override{
		return "Magician";
	}
	int onSolarEclipse(Player& player) const override{
		player.addForce(1);
		return 1;
	}

	bool isRanged() const override{
		return true;
	}


};
