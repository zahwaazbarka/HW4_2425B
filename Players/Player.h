
#pragma once

#include <string>
#include "Jobs/Job.h"
#include "CharacterType.h"

using std::string;
class Event;
class Player {
public:

	virtual bool hasWon() const = 0;
	virtual bool isKnockedOut() const = 0;

    virtual std::string getName() const=0;
    virtual int getLevel() const=0;
    virtual int getForce() const=0;
    virtual int getHealthPoints() const=0;
    virtual int getMaxHealthPoints() const=0;
    virtual int getCoins() const=0;
    virtual Job* getJob() const =0;
    virtual CharacterType* getCharacter() const =0;

	virtual void addForce(int amount)=0;
    virtual void subtractForce(int amount)=0;

	virtual void heal(int amount) =0;
	virtual void damage(int amount) =0;
	virtual void levelUp(int amount) =0;
	virtual void pay(int amount) =0;
	virtual void earn(int amount) =0;

    virtual void playTurn(Event* event) =0;
	virtual std::string getDescription() const = 0;


    virtual ~Player() = default;
};
