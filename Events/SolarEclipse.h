#include "Event.h"
#include "../Players/Player.h"

class SolarEclipse :public Event{
public:
void apply(Player* player) override{
	player->getJob()->onSolarEclipse(*player);
}
std::string getDescription() const override{
	return "SolarEclipse";
}

};