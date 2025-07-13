
#include "Monster.h"

class Balrog :public Monster{
private:
	int balrogCombatPower = 9001;
public:
	Balrog()= default;
	int getCombatPower() const override{
		return 15;
	}
	int getLoot() const override{
		return 100;
	
	}
	int getDamage() const override{
		return balrogCombatPower;
	}
	std::string getDescription() const override {return "Balrog";}
	void addCombatpower(){
		balrogCombatPower +=2;
	}




};