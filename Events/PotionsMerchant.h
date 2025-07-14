#pragma once

#include "Event.h"
#include "../Players/Player.h"
#include "../Utilities.h"
class PotionsMerchant: public Event
{
public:
	std::string apply(Player* player) override{
		int count =player->getCharacter()->shouldBuyPotion(player->getHealthPoints()
		,player->getMaxHealthPoints(),
		player->getCoins());
		int cost = count *5;
		int heal = count * 10;
		if(count>0 && player->getCoins() >=cost)
		{
			player->pay(cost);
			player->heal(heal);
		}
		return getPotionsPurchaseMessage(*player, count);
	}
	std::string getDescription()const override{
		return "PotionsMerchant";
	}
};

