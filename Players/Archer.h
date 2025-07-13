
#include "Job.h"
#include "Player.h"

class Archer :public Job{
public:
	int getCombatPower(const Player& player) const override{
		return player.getForce() + player.getLevel();
	}
	std::string getJobName() const override{
		return "Archer";
	}
	void onScolarEclipse(Player& player) const{
		player.subtractForce();
	}


	bool isRanged() const override{
		return true;
	}


};