#include <string>
#include

class GameOverviewTable
{
    std::string PlayerName;

public:
    GameOverviewTable(std::string PlayerName);

    std::vector<std::string> getOtherPlayerNames(int gameID);

    int getFieldID(int gameID);

    std::map<std::string, std::string> getGameOverview(int gameID);

    void updateMoveCount(int gameID, int moveCount);

    int createNewGame(int GameTyp, int LevelOfDifficulty, std::vector<std::string> PlayerNames, std::string FieldID);

    void deleteGame(int gameID);
};