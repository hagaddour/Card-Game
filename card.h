#ifndef __CARD_H__
#define __CARD_H__

#include <string>
#include <vector>

class Card
{
    std::string name;
    int cost;
    std::string type;
    std::string descrip;

public:
    //getters
    std::string getName();
    int getCost();
    std::string getType();
    std::string getDescrip();
    //setters
    void setName(std::string oName);
    void setCost(int oCost);
    void setType(std::string oType);
    void setDescrip(std::string oDescrip);

    Card(std::string name, int cost, std::string type, std::string descrip);
    //pure virtual ascii since each card type will have its own ascii. makes card astract
    virtual std::vector<std::string> getAscTemp() = 0;
    //print function to display the card
    void print(std::vector<std::string> cardAsc);
};

#endif
