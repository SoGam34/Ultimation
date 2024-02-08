#include <string>
#include

class GameOverviewTable
{
    std::string PlayerName;

public:
    GameOverviewTable(std::string PlayerName);

    std::string getOtherPlayerName();

    std::string getFieldID(int gameID);

    std::map<std::string, std::string> getGameOverview(int gameID);

    void updateMoveCount(int gameID, int moveCount);

    int createNewGame(int GameTyp, int LevelOfDifficulty, std::string PlayerNames, std::string FieldID);

    void deleteGame(int gameID);
};


