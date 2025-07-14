#pragma once
#include "Player.h"
#include "../Jobs/Job.h"
#include "CharacterType.h"
#include <string>

class GamePlayer :public Player{
private:
	std::string playerName;
	int playerLevel;
	int playerForce;
	int playerCurrentHP;
	int playerMaxHP;
	int playerCoins;

	Job* playerJob;
	CharacterType* playerCharacter;
public:
	GamePlayer(const std::string& name,Job* job,CharacterType* character);

	std::string getName() const override;
	int getLevel() const override;
	int getForce() const override;
	int getHealthPoints() const override;
	int getMaxHealthPoints() const override;
	int getCoins() const override;

	Job* getJob() const override{return playerJob;}
	CharacterType* getCharacter() const override{return playerCharacter;}
	void addForce(int amount)  override;
	void subtractForce(int amount) override;
	void heal(int amount) override;
	void damage(int amount) override;
	void levelUp(int amount) override;
	void pay(int amount) override;
	void earn(int amount) override;

	void playTurn(Event* event)override;
	std::string getDescription() const override;
	bool isKnockedOut() const override;
	bool hasWon() const override;


	~GamePlayer() override= default;

};
