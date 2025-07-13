
#include "Job.h"
#include "Player.h"

class Magician :public Job{
public:
	int getCombatPower(const Player& player) const override{
		return player.getForce() + player.getLevel();
	}
	std::string getJobName() const override{
		return "Magician";
	}
	void onScolarEclipse(Player& player) const{
		player.addForce();
	}

	bool isRanged() const override{
		return true;
	}


};