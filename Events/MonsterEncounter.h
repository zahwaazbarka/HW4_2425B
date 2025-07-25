#pragma once

#include "Event.h"
#include "Monster.h"
#include <memory>

class MonsterEncounter:public Event
{
private:
std::shared_ptr<Monster>monsters;

public:
	MonsterEncounter(std::shared_ptr<Monster> monster):monsters(std::move(monster)){}

	std::string apply(Player* player) override;
	~MonsterEncounter() override = default;

	std::string getDescription() const override;
};

