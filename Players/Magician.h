
#include "Job.h"
#include "Player.h"

class Magician :public Job{
public:
	Magician()= default;

	int getCombatPower(const Player& player) const override{
		return player.getForce() + player.getLevel();
	}
	std::string getJobName() const override{
		return "Magician";
	}
	void onScolarEclipse(Player& player) const{
		player.addForce(1);
	}

	bool isRanged() const override{
		return true;
	}


};