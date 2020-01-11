#include <iostream>
#include "card.h"

using namespace std;

Card::Card(string name, int cost, string type, string descrip) : name{name},
                                                                 cost{cost},
                                                                 type{type},
                                                                 descrip{descrip} {}

string Card::getName()
{
    return name;
}

int Card::getCost()
{
    return cost;
}

string Card::getType()
{
    return type;
}

string Card::getDescrip()
{
    return descrip;
}

void Card::setName(string oName)
{
    name = oName;
}

void Card::setCost(int oCost)
{
    cost = oCost;
}

void Card::setType(string oType)
{
    type = oType;
}

void Card::setDescrip(string oDescrip)
{
    descrip = oDescrip;
}

void Card::print(std::vector<std::string> cardAsc)
{
    for (int i = 0; i < cardAsc.size(); ++i)
    {
        cout << cardAsc[i] << endl;
    }
}
