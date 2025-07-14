
#include "Job.h"
#include "../Player.h"

class Warrior :public Job{
public:
	Warrior()= default;

	int getCombatPower(const Player& player) const override{
		return player.getForce() * 2 + player.getLevel();
	}
	std::string getJobName() const override{
		return "Warrior";
	}
	int onSolarEclipse(Player& player) const override{
		player.subtractForce(1);
		return -1;
	}

	bool isRanged() const override{
		return false;
	}

};