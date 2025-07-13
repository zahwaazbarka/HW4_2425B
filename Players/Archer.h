
#include "Job.h"
#include "Player.h"

class Archer :public Job{
public:
	Archer()= default;

	int getCombatPower(const Player& player) const override{
		return player.getForce() + player.getLevel();
	}
	std::string getJobName() const override{
		return "Archer";
	}
	void onScolarEclipse(Player& player) const{
		player.subtractForce(1);
	}


	bool isRanged() const override{
		return true;
	}


};