#pragma once
#include "CharacterType.h"

class RiskTaking: public CharacterType{
public:
	RiskTaking()= default;
	std::string getCharacterType() const override{
		return "RiskTaking";
	}
	int shouldBuyPotion(int currentHp,int maxHp,int coins)const override{
		if(currentHp < 50 && coins >= 10)
		{
			return 1;
		}
		return 0;
	}
};
