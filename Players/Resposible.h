
#pragma once 

#include <string>

#include "CharacterType.h"

class Responsible: public CharacterType{
public:
	Responsible()= default;

	std::string getCharacterType() const override{
		return "Responsible";
	}
	int shouldBuyPotion(int currentHp,int maxHp,int coins) const override{
		int missingHp = maxHp-currentHp;
		int neededAmountByHealth = (missingHp/10) +1;
		int canAfordByCoins = coins/5;
		if(neededAmountByHealth > canAfordByCoins)
		{
			return canAfordByCoins;
		}
		return neededAmountByHealth;
	}
};