#include <vector>
#include <string>
#include <memory>
#include <map>

#include "PlayerTable.hpp"
#include "GameOverviewTable.hpp"
#include "FieldTable.hpp"

class SQLAbfrage
{
    std::unique_ptr<PlayerTable> Player;
    std::unique_ptr<GameOverviewTable> GameInfo;
    std::unique_ptr<FieldTable> GameField;

    std::string PlayerName;

    int GameID;

    std::string to_string(std::vector<std::vector<char>>& Field, std::string& final_string, size_t zeile, size_t spalte);

    std::vector<std::vector<char>> to_vector(std::string& Field, std::vector<std::vector<char>>& final_vector, size_t zeile);

public:
    SQLAbfrage(std::string playerName);
    
    std::vector<std::vector<char>> getField(int FieldID);

    void setField(int FieldID, std::vector<std::vector<char>> Field);

    void updateMoveCount(int gameID);

    std::vector<std::string> getOtherPlayerNamesFromGame(int gameID);

    std::map<std::string, int> getPlayerProfile();

    int getPlayerSkin();

    int createNewPlayer(std::string playerName, std::string Password);

    void deletePlayer(std::string playerName);

    void resetPassword(std::string newPassword);

    std::string getPassword();

    void updateXP(int XPAmountToAdd);

    int getXP();
    
    std::vector<int> getActiveGames();

    std::map<std::string, std::string> getGameOverview(int gameID);

    int createNewGame(int GameTyp, int LevelOfDifficulty, std::vector<std::string> PlayerNames);

    void deleteGame(int gameID);

    void setGameIDTo(int gameID);

    int getInternalGameID();

    std::map<std::string, std::string> getGameOverview();

    std::vector<std::string> getOtherPlayerNamesFromGame();

    void updateMoveCount();

    void deleteGame();
};