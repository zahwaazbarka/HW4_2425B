
#pragma once

class CharacterType{
public:

	virtual int shouldBuyPotion(int currentHp,int maxHp,int coins) const =0;

	
	virtual ~CharacterType()=default;
};