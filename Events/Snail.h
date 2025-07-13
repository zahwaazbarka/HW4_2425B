
#include "Monster.h"

class Snail :public Monster{
public:
	Snail()= default;

	int getCombatPower() const override{
		return 5;
	}
	int getLoot() const override{
		return 2;
	
	}
	int getDamage() const override{
		return 10;
	}
	std::string getDescription() const override {return "Snail";}






};