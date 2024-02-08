#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>

class SQLAbfragen
{
    std::string PlayerName;

    std::string to_string(std::vector<std::vector<char>>& Field, std::string& final_string, size_t zeile, size_t spalte);

    std::vector<std::vector<char>> to_vector(std::string& Field, std::vector<std::vector<char>>& final_vector, size_t zeile);

public:
    SQLAbfragen(std::string playerName);
    
    std::vector<std::vector<char>> getField(int FieldID);

    void setField(int FieldID, std::vector<std::vector<char>> Field);

    std::string getPassword();

    std::vector<std::string> getPlayerProfile();

    std::string getPlayerSkin();

    int createNewPlayer(std::string PlayerName, std::string Passwort);

    void deletePlayer(std::string PlayerName);

    void resetPasswort(std::string sewPasswort);

    void updatePlayerXP(int XPAmountToAdd);

    int getXP();
    
    std::vector<int> getActiveGames();

    std::map<std::string, std::string> getGameOverview(int gameID);

    int createNewGame(int GameTyp, int LevelOfDifficulty, std::string PlayerNames)
};