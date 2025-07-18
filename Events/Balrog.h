
#include "Monster.h"

class Balrog :public Monster{
private:
	int balrogCombatPower = 15;
public:
	Balrog()= default;
	int getCombatPower() const override{
		return balrogCombatPower;
	}
	int getLoot() const override{
		return 100;
	
	}
	int getDamage() const override{
		return 9001;
	}
	std::string getDescription() const override {return "Balrog";}
	void addCombatpower(){
		balrogCombatPower +=2;
	}
	virtual void onPostCombat() override{
		addCombatpower();
	} 





};