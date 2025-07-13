#include "Event.h"
#include "../Players/Player.h"

class SolarEclipse :public Event{
public:
void apply(Player* player) override{
	player->getJob()->onScolarExlipse(*player);
}
std::string getDescription() const override{
	return "Solar Eclipse";
}

};