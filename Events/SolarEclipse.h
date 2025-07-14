
#pragma once
#include "Event.h"
#include "../Players/Player.h"
#include "../Utilities.h"
class SolarEclipse :public Event{
public:
std::string apply(Player* player) override{
	int amount = player->getJob()->onSolarEclipse(*player);
	return getSolarEclipseMessage(*player, amount);

}
std::string getDescription() const override{
	return "SolarEclipse";
}

};
