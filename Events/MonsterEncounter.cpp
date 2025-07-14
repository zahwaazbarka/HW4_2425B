#include "MonsterEncounter.h"
#include "../Players/Player.h"
#include "../Utilities.h"

std::string MonsterEncounter::apply(Player* player)
{
    int playerPower = player->getJob()->getCombatPower(*player);
    int monsterPower = monsters->getCombatPower();

    std::string outcome;
    if (playerPower >= monsterPower) {
        player->levelUp(1);
        int loot = monsters->getLoot();
        if(!player->getJob()->isRanged()) {
            player->damage(10);

        }
        player->earn(loot);
        outcome = getEncounterWonMessage(*player, loot);
    } else {
        int damage = monsters->getDamage();
        player->damage(damage);

        outcome = getEncounterLostMessage(*player, damage);
        if(!player->getJob()->isRanged()) {
            player->damage(10);

        }
    }
    if (monsters->getDescription() == "Balrog") {
        monsters->onPostCombat();
    }

    return outcome;
}



std::string MonsterEncounter::getDescription() const {
    return monsters->getDescription() + " (power " + std::to_string(monsters->getCombatPower()) +
           ", loot " + std::to_string(monsters->getLoot()) +
           ", damage " + std::to_string(monsters->getDamage()) + ")";
}
