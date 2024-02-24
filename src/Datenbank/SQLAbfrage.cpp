#include "SQLAbfrage.hpp"
#include <cstdlib>
#include <exception>
#include <sstream>
#include <stdexcept>
#include <string>
#include <system_error>

SQLAbfrage::SQLAbfrage(std::string playerName)
{
    PlayerName = playerName;
    GameID = 0;

    Player = std::make_unique<PlayerTable>(playerName);
    GameInfo = std::make_unique<GameOverviewTable>(playerName);
    GameField = std::make_unique<FieldTable>();
}

std::string SQLAbfrage::to_string(std::vector<std::vector<char>>& Field, std::string& final_string, size_t zeile, size_t spalte) 
{
    // soll das Field von einem 2-Dimensionalen Vektor in einen std::string nach Schema "fffufffufff" umwandeln. Die Zeitkomplexität ist O(n²).   
    if(Field.size()-1 == zeile && Field[zeile].size()-1 == spalte) // fügt, wenn im letzten feld, dieses an den std::string an und gibt diesen zurück
    {
        final_string.push_back(Field[zeile][spalte]);
        return final_string;
    }

    if(Field[zeile].size()-1 == spalte) // wenn eine zeile zuende ist, wird auch ein 'U' an den std::string angehängt, um dies anzuzeigen
    {
        final_string.push_back(Field[zeile][spalte]); // zeichen wird an std::string angehängt
        final_string.push_back('U'); //signalisiert neue Zeile
        return to_string(Field, final_string, zeile+1, 0); // setzt die Spalte zurück und inkrementiert die Zeile
    }

    else
    { // bei felder, welche nicht am Ende der Zeile sind, wird das Element angehängt und die Spalte inkrementiert
        final_string.push_back(Field[zeile][spalte]);
        return to_string(Field, final_string, zeile, spalte+1);
    }
}

std::vector<std::vector<char>> SQLAbfrage::to_vector(std::string& Field, std::vector<std::vector<char>>& final_vector, size_t zeile)
{
    if(Field.empty())
    {
        return final_vector;
    }

    if(Field.front() == 'U')
    {
        Field.erase(Field.begin()); // entfernen von U
        final_vector.push_back({Field.front()}); //erstellen der neuen Zeile im Vector
        Field.erase(Field.begin());        //entfernen des ersten Zeichens
        return to_vector(Field, final_vector, zeile+1);
    }

    final_vector[zeile].push_back(Field.front());
    Field.erase(Field.begin());
    return to_vector(Field, final_vector, zeile);
}

std::vector<std::vector<char>> SQLAbfrage::getField(int FieldID)
{
    std::vector<std::vector<char>> Spielfeld{{}};

    if(GameField == nullptr)
    {
        GameField = std::make_unique<FieldTable>();
    }

    std::string s{GameField->getField(FieldID)}; 

    return to_vector(s, Spielfeld, 0);
}

void SQLAbfrage::setField(int FieldID, std::vector<std::vector<char>> Field)
{
    std::string temp = "";// Damit wir eine Speicheradresse haben
    temp = to_string(Field, temp, 0, 0);

    if(GameField == nullptr)
    {
        GameField = std::make_unique<FieldTable>();
    }
    
    GameField->setField(temp, FieldID);
}

void SQLAbfrage::updateMoveCount(int gameID)
{
    if(GameInfo == nullptr)
    {
        GameInfo = std::make_unique<GameOverviewTable>(PlayerName);
    }

    GameInfo->updateMoveCount(gameID);
}

std::vector<std::string> SQLAbfrage::getOtherPlayerNamesFromGame(int gameID)
{
    if(GameInfo == nullptr)
    {
        GameInfo = std::make_unique<GameOverviewTable>(PlayerName);
    }

    return GameInfo->getOtherPlayerNames(gameID);
}

std::map<std::string, int> SQLAbfrage::getPlayerProfile()
{
    if(Player == nullptr)
    {
        Player = std::make_unique<PlayerTable>(PlayerName);
    }

    std::map<std::string, int> playerProfile;

    playerProfile["XP"] = Player->getXP();
    playerProfile["Skin"] = Player->getSkin();
    playerProfile["ID"] = Player->getID();

    return playerProfile;
}

int SQLAbfrage::getPlayerSkin()
{
    if(Player == nullptr)
    {
        Player = std::make_unique<PlayerTable>(PlayerName);
    }

    return Player->getSkin();
}

int SQLAbfrage::createNewPlayer(std::string playerName, std::string Password)
{
    if(Player == nullptr)
    {
        Player = std::make_unique<PlayerTable>(PlayerName);
    }

    return Player->createNewPlayer(playerName, Password);
}

void SQLAbfrage::deletePlayer(std::string playerName)
{
    Player->deletePlayer();

    Player.release();
}

void SQLAbfrage::resetPassword(std::string newPassword)
{
    if(Player == nullptr)
    {
        Player = std::make_unique<PlayerTable>(PlayerName);
    }

    Player->setPassword(newPassword);
}

std::string SQLAbfrage::getPassword()
{
    if(Player == nullptr)
    {
        Player = std::make_unique<PlayerTable>(PlayerName);
    }

    return Player->getPassword();
}

void SQLAbfrage::updateXP(int XPAmountToAdd)
{
    if(Player == nullptr)
    {
        Player = std::make_unique<PlayerTable>(PlayerName);
    }

    Player->setXP(Player->getXP()+XPAmountToAdd);
}

int SQLAbfrage::getXP()
{
    if(Player == nullptr)
    {
        Player = std::make_unique<PlayerTable>(PlayerName);
    }

    return Player->getXP();
}
    
std::vector<int> SQLAbfrage::getActiveGames()
{
    //XXX: Sammeln der Activen Spiele
}

std::map<std::string, std::string> SQLAbfrage::getGameOverview(int gameID)
{
   return GameInfo->getGameOverview(gameID);
}

int SQLAbfrage::createNewGame(int GameTyp, int LevelOfDifficulty, std::vector<std::string> PlayerNames)
{
    if(GameInfo == nullptr)
    {
        GameInfo = std::make_unique<GameOverviewTable>(PlayerName);
    }

    if(GameField == nullptr)
    {
        GameField = std::make_unique<FieldTable>();
    }

    std::string field;

    if (GameTyp== 1) {
        field = "fffUfffUfff"; //3*3 Feld
    }

    else {
        field = "fffffffffUfffffffffUfffffffffU"; //9*9 Feld
    }

    for(int i=0; i<LevelOfDifficulty; i++)
    {
        int sonderfaellt = rand() % field.size();
        char sonderfealltmarker[2]{'n', 'b'};

        if(field[sonderfaellt] == 'U')
        {
            i--;
        }

        else {
         field[sonderfaellt] = sonderfealltmarker[rand() % 2];
        }
    }

    int fieldID = GameField->createNewField(field);
    GameInfo->createNewGame(GameTyp, LevelOfDifficulty, PlayerNames, fieldID);
}

void SQLAbfrage::deleteGame(int gameID)
{
    if(GameField != nullptr)
    {
        if(GameInfo != nullptr)
        {
            GameField->deleteField(GameInfo->getFieldID(gameID));

            GameField.release();

            GameInfo->deleteGame(gameID);

            GameInfo.release();
        }
        
        throw std::runtime_error("SQLAbfrage::deleteGame(int gameID): Nicht möglich Game richtig zu löschen.");
    }

    if(GameInfo != nullptr)
    {
        GameInfo->deleteGame(gameID);

        GameInfo.release();
    }
}

void SQLAbfrage::setGameIDTo(int gameID)
{
    GameID = gameID;
}

int SQLAbfrage::getInternalGameID()
{
    return GameID;
}

std::map<std::string, std::string> SQLAbfrage::getGameOverview()
{
    if(GameInfo == nullptr)
    {
        GameInfo = std::make_unique<GameOverviewTable>(PlayerName);
    }

   return GameInfo->getGameOverview(GameID);
}

std::vector<std::string> SQLAbfrage::getOtherPlayerNamesFromGame()
{
    if(GameInfo == nullptr)
    {
        GameInfo = std::make_unique<GameOverviewTable>(PlayerName);
    }

    return GameInfo->getOtherPlayerNames(GameID);
}

void SQLAbfrage::updateMoveCount()
{
    if(GameInfo == nullptr)
    {
        GameInfo = std::make_unique<GameOverviewTable>(PlayerName);
    }
    
    GameInfo->updateMoveCount(GameID);
}

void SQLAbfrage::deleteGame()
{
    if(GameField != nullptr)
    {
        if(GameInfo != nullptr)
        {
            GameField->deleteField(GameInfo->getFieldID(GameID));

            GameField.release();

            GameInfo->deleteGame(GameID);

            GameInfo.release();
        }
        
        throw std::runtime_error("SQLAbfrage::deleteGame(): Nicht möglich Game richtig zu löschen.");
    }

    if(GameInfo != nullptr)
    {
        GameInfo->deleteGame(GameID);

        GameInfo.release();
    }
}