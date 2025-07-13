
#include "Player.h"
#include "Job.h"
#include "CharacterType.h"

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

	void addForce(int amount)  override;
	void subtractForce(int amount) override;
	void heal(int amount) override;
	void damage(int amount) override;
	void levelUp(int amount) override;
	void pay(int amount) override;
	void earn(int amount) override;

	void playTurn(Event* event)override;

	~GamePlayer() override= default;

};