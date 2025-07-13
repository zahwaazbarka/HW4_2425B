#pragma once

#include "Monster.h"
#include <vector>

class Pack: public Monster{
private:
std::vector<std::shared_ptr<Monster>> monsters;
public:
void addMonster(std::shared_ptr<Monster> monster){
	monsters.push_back(monster);
}
int getCombatPower() const override{
	int sumPower =0;
	for(const auto& m:monsters) sumPower+= m->getCombatPower();
	return sumPower;
}

int getLoot() const override{
	int sumLoot =0;
	for(const auto& m:monsters) sumLoot+= m->getLoot();
	return sumLoot;
}

int getCombatPower() const override{
	int sumDamage =0;
	for(const auto& m:monsters) sumDamage+= m->getDamage();
	return sumDamage;
}
std::string getDescription() const override{
	return "Pack";
}

};
