
#include "Monster.h"

class Slime :public Monster{
public:
	int getCombatPower() const override{
		return 12;
	}
	int getLoot() const override{
		return 5;
	
	}
	int getDamage() const override{
		return 25;
	}
	std::string getDescription() const override {return "Slime";}






};