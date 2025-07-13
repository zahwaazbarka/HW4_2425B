#include "Event.h"
#include "Monster.h"

class MonsterEncounter:public Event
{
private:
std::shared_ptr<Monster>monsters;

public:
	MonsterEncounter(std::shared_ptr<Monster> monster):monsters(monster){}
	void apply(Player* player) override;

	std::string getDescription() const override{
		return "MonsterEncounter: " + monsters->getDescription();
	}
};

