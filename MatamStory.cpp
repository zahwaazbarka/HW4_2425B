

#include "MatamStory.h"

#include <memory>
#include <algorithm>

#include "Utilities.h"
#include "Events/MonsterEncounter.h"
#include "Events/PotionsMerchant.h"
#include "Events/SolarEclipse.h"
#include "Events/Snail.h"
#include "Events/Slime.h"
#include "Events/Balrog.h"
#include "Events/Pack.h"
#include "Players/GamePlayer.h"
#include "Players/Warrior.h"
#include "Players/Magician.h"
#include "Players/Archer.h"
#include "Players/Resposible.h"
#include "Players/RiskTaking.h"

#include <sstream>
#include <stdexcept>

using namespace std;

static unique_ptr<Job> createJob(const string& name) {
    if (name == "Warrior") return make_unique<Warrior>();
    if (name == "Magician") return make_unique<Magician>();
    if (name == "Archer") return make_unique<Archer>();
    throw runtime_error("Invalid Players File");
}

static unique_ptr<CharacterType> createCharacter(const string& name) {
    if (name == "Responsible") return make_unique<Responsible>();
    if (name == "RiskTaking") return make_unique<RiskTaking>();
    throw runtime_error("Invalid Players File");
}

static shared_ptr<Monster> createMonster(const string& name) {
    if (name == "Snail") return make_shared<Snail>();
    if (name == "Slime") return make_shared<Slime>();
    if (name == "Balrog") return make_shared<Balrog>();
    throw runtime_error("Invalid Events File");
}

vector<shared_ptr<Event>> parseEvents(istream& in) {
    vector<shared_ptr<Event>> events;
    string line;

    while (getline(in, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string word;
        vector<string> tokens;
        while (ss >> word) {
            tokens.push_back(word);
        }
        if (tokens.empty()) continue;
        if (tokens[0] == "SolarEclipse") {
            events.push_back(make_shared<SolarEclipse>());
        }
        else if (tokens[0] == "PotionsMerchant") {
            events.push_back(make_shared<PotionsMerchant>());
        }
        else if (tokens[0] == "Snail" || tokens[0] == "Slime" || tokens[0] == "Balrog") {
            if (tokens.size() > 1)
                throw runtime_error("Invalid Events File");
            events.push_back(make_shared<MonsterEncounter>(createMonster(tokens[0])));
        } else {
            int counter = 0;
            vector<string> monsterNames;

            for (size_t i = 0; i < tokens.size(); ++i) {
                if (tokens[i] == "Pack") {
                    if (i + 1 >= tokens.size()) throw runtime_error("Invalid Events File");
                    int count = stoi(tokens[i + 1]);
                    counter += count;
                    ++i;
                } else {
                    monsterNames.push_back(tokens[i]);
                }
            }
            if ((int)monsterNames.size() != counter) {
                throw runtime_error("Invalid Events File");
            }

            auto pack = make_shared<Pack>();
            for (const string& name : monsterNames) {
                pack->addMonster(createMonster(name));
            }

            events.push_back(make_shared<MonsterEncounter>(pack));
        }
    }

    if (events.size() < 2) throw runtime_error("Invalid Events File");
    return events;
}

vector<shared_ptr<Player>> parsePlayers(istream& in) {
    vector<shared_ptr<Player>> players;
    string name, job, character;
    while (in >> name >> job >> character) {
        if (name.length() < 3 || name.length() > 15) throw runtime_error("Invalid Players File");
        players.push_back(make_shared<GamePlayer>(name, createJob(job).release(), createCharacter(character).release()));
    }
    if (players.size() < 2 || players.size() > 6) throw runtime_error("Invalid Players File");
    return players;
}

MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream)
    : m_turnIndex(1),
      m_players(parsePlayers(playersStream)),
      m_events(parseEvents(eventsStream)) {}

void MatamStory::playTurn(Player& player) {
    Event& event = *m_events[(m_turnIndex - 1) % m_events.size()];
    printTurnDetails(m_turnIndex, player, event);
    string outcome = event.apply(&player);
    printTurnOutcome(outcome);
    ++m_turnIndex;
}

void MatamStory::playRound() {
    printRoundStart();
    for (auto& p : m_players) {
        if (!p->isKnockedOut() && !p->hasWon()) {
            playTurn(*p);
        }
    }
    printRoundEnd();
    printLeaderBoardMessage();

    sort(m_players.begin(), m_players.end(), [](const shared_ptr<Player>& a, const shared_ptr<Player>& b) {
        if (a->getLevel() != b->getLevel()) return a->getLevel() > b->getLevel();
        if (a->getCoins() != b->getCoins()) return a->getCoins() > b->getCoins();
        return a->getName() < b->getName();
    });

    for (size_t i = 0; i < m_players.size(); ++i) {
        printLeaderBoardEntry(i + 1, *m_players[i]);
    }
    printBarrier();
}

bool MatamStory::isGameOver() const {
    for (const auto& p : m_players) {
        if (!p->isKnockedOut() && !p->hasWon()) {
            return false;
        }
    }
    return true;
}

void MatamStory::play() {
    printStartMessage();
    for (size_t i = 0; i < m_players.size(); ++i) {
        printStartPlayerEntry(i + 1, *m_players[i]);
    }
    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();
    bool winner = false;
    for (const auto& p : m_players) {
        if (p->hasWon()) {
            printWinner(*p);
            winner = true;
        }
    }
    if (!winner) {
        printNoWinners();
    }
}
