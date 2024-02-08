#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>

class PlayerTable
{
    std::string PlayerName;

public:
    PlayerTable(std::string PlayerName);

    std::string getPassword();

    void setPassword(std::string Password);

    int getXP();

    void setXP(int newXP);

    int getID();

    int createNewPlayer(std::string Password);

    void deletePlayer();

    std::string getSkin();
};