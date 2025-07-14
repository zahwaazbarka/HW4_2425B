

#include "GamePlayer.h"
#include "../Events/Event.h"
#include <stdexcept>

GamePlayer::GamePlayer(const std::string& name,Job* job,CharacterType* character):
playerName(name),playerLevel(1),playerForce(5),playerJob(job),playerCharacter(character)
{
	playerMaxHP = 100;
	if(job->getJobName() == "Warrior")
	{
		playerMaxHP = 150;
		playerCoins = 10;
	}
	else if(job->getJobName() == "Archer")
	{
		playerCoins = 20;
	}
	else if(job->getJobName() == "Magician")
	{
		playerCoins = 10;
	}
	playerCurrentHP = playerMaxHP;

}

std::string GamePlayer::getName() const{
	return playerName;
}
std::string GamePlayer::getDescription() const{
	return playerName + ", " +playerJob->getJobName() +
	   " with " + playerCharacter->getCharacterType() +
	   " character (level " + std::to_string(playerLevel) + ", force "+std::to_string(playerForce)+")";
}

int GamePlayer::getLevel() const{
	return playerLevel;
}

int GamePlayer::getForce() const{
	return playerForce;
}

int GamePlayer::getHealthPoints() const{
	return playerCurrentHP;
}

int GamePlayer::getMaxHealthPoints() const{
	return playerMaxHP;
}

int GamePlayer::getCoins() const{
	return playerCoins;
}

void GamePlayer::addForce(int amount)
{
	playerForce += amount;
}
void GamePlayer::subtractForce(int amount)
{
	playerForce -= amount;
}
void GamePlayer::heal(int amount)
{
	int health = playerCurrentHP + amount;
	if(health > playerMaxHP)
	{
		playerCurrentHP= playerMaxHP;
	}
	else{
		playerCurrentHP = health;
	}

}

void GamePlayer::damage(int amount)
{
	int health = playerCurrentHP - amount;
	if(health < 0)
	{
		playerCurrentHP = 0;
	}
	else{
		playerCurrentHP = health;
	}

}
void GamePlayer::levelUp(int amount)
{
	playerLevel+=amount;
}

void GamePlayer::pay(int amount)
{
	if(playerCoins<amount)
	{
		throw std::runtime_error("Not enough coins!");
	}
	playerCoins-=amount;
}
void GamePlayer::earn(int amount)
{
	playerCoins+=amount;
}

void GamePlayer::playTurn(Event* event)
{
	if(event)
	{
		event->apply(this);

	}
}
bool GamePlayer::isKnockedOut() const {
	return playerCurrentHP <= 0;
}

bool GamePlayer::hasWon() const {
	return playerLevel == 10;
}


