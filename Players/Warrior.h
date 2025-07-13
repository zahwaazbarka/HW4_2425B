
#include "Job.h"
#include "Player.h"

class Warrior :public Job{
public:
	int getCombatPower(const Player& player) const override{
		return player.getForce() * 2 + player.getLevel();
	}
	std::string getJobName() const override{
		return "Warrior";
	}
	void onScolarEclipse(Player& player) const{
		player.subtractForce(1);
	}

	bool isRanged() const override{
		return false;
	}

};