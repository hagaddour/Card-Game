#include <ctime>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "airElemental.h"
#include "auraOfPower.h"
#include "apprenticeSummoner.h"
#include "banish.h"
#include "blizzard.h"
#include "boneGolem.h"
#include "darkRitual.h"
#include "deck.h"
#include "disenchant.h"
#include "earthElemental.h"
#include "enrage.h"
#include "fireElemental.h"
#include "giantStrength.h"
#include "haste.h"
#include "potionSeller.h"
#include "magicFatigue.h"
#include "masterSummoner.h"
#include "novicePyromancer.h"
#include "raiseDead.h"
#include "recharge.h"
#include "silence.h"
#include "standstill.h"
#include "unsummon.h"

using namespace std;

Deck::Deck() : name{"default.deck"}
{
    init(name);
}

Deck::Deck(std::string file) : name{file}
{
    init(name);
}

void Deck::init(string filename)
{
    ifstream deckfile;
    deckfile.open(filename);
    string name;
    while (getline(deckfile, name))
    {
        if (name == "Banish")
            cards.emplace_back(make_shared<Banish>());
        else if (name == "Unsummon")
            cards.emplace_back(make_shared<Unsummon>());
        else if (name == "Recharge")
            cards.emplace_back(make_shared<Recharge>());
        else if (name == "Disenchant")
            cards.emplace_back(make_shared<Disenchant>());
        else if (name == "Raise Dead")
            cards.emplace_back(make_shared<RaiseDead>());
        else if (name == "Blizzard")
            cards.emplace_back(make_shared<Blizzard>());
        else if (name == "Giant Strength")
            cards.emplace_back(make_shared<GiantStrength>());
        else if (name == "Enrage")
            cards.emplace_back(make_shared<Enrage>());
        else if (name == "Haste")
            cards.emplace_back(make_shared<Haste>());
        else if (name == "Magic Fatigue")
            cards.emplace_back(make_shared<MagicFatigue>());
        else if (name == "Silence")
            cards.emplace_back(make_shared<Silence>());
        else if (name == "Dark Ritual")
            cards.emplace_back(make_shared<DarkRitual>());
        else if (name == "Aura of Power")
            cards.emplace_back(make_shared<AuraOfPower>());
        else if (name == "Standstill")
            cards.emplace_back(make_shared<Standstill>());
        else if (name == "Air Elemental")
            cards.emplace_back(make_shared<AirElemental>());
        else if (name == "Earth Elemental")
            cards.emplace_back(make_shared<EarthElemental>());
        else if (name == "Bone Golem")
            cards.emplace_back(make_shared<BoneGolem>());
        else if (name == "Fire Elemental")
            cards.emplace_back(make_shared<FireElemental>());
        else if (name == "Potion Seller")
            cards.emplace_back(make_shared<PotionSeller>());
        else if (name == "Novice Pyromancer")
            cards.emplace_back(make_shared<NovicePyromancer>());
        else if (name == "Apprentice Summoner")
            cards.emplace_back(make_shared<ApprenticeSummoner>());
        else if (name == "Master Summoner")
            cards.emplace_back(make_shared<MasterSummoner>());
    }
}

void Deck::shuffle(int p)
{
    for (int i = decksize(); i > 0; --i)
    {
        srand(time(NULL));
        int rindex = rand() % i;
        rindex += p;
        cards.emplace_back(cards[rindex]);
        cards.erase(cards.begin() + rindex);
    }
}

int Deck::decksize()
{
    return cards.size();
}

std::shared_ptr<Card> Deck::draw()
{
    if (decksize() < 1)
        throw "Cannot draw - No cards in deck!"s;
    shared_ptr<Card> rCard = cards.back();
    cards.pop_back();
    return rCard;
}
